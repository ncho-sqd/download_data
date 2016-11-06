#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//===data struct===//
  typedef struct cll cll; //CACHE LINKED LIST
 struct cll {
   long int tag;
   cll *next;
 };

//===Global variables===//
 int hit = 0;
 int miss = 0;
 int evict = 0;

//===Cache list operations===//
cll *cll_cons(long int t,cll *l){
  cll *new=malloc(sizeof(cll));
  if (new==NULL){
    fprintf(stderr,"cll_cons:Heap Empty\n");
    exit(1);
  }
  new->tag=t;
  new->next=l;
  return new;
}

void cll_free(cll *l)
{
  if(l==NULL)
    return;
  else
  cll_free(l->next);
  free(l);
  return;
}

unsigned int member (cll *l,long int t){
  cll *tmp=l; 
  while (tmp!=NULL){
    if(tmp->tag==t)
      return 1;
    tmp=tmp->next;
  }
  return 0;
}


unsigned int length (cll *l){
 cll *tmp=l; 
  unsigned int len=0;
  while(tmp!=NULL){
    len++;
    tmp=tmp->next;
  }
  return len;
}


void cll_show(cll *ss)
{
  cll *tmp=ss;
  int i=1; 
  while(tmp!=NULL){
    printf("%ld\t",tmp->tag);
    i++;
    tmp=tmp->next;
  }
  putchar('\n');
  return;
}

cll *del_miss(cll *l){
  cll *tmp1=l;
  cll *tmp2=NULL;
  cll *new=NULL;

  while (tmp1->next!=NULL){
    tmp2=cll_cons(tmp1->tag,tmp2);
    tmp1=tmp1->next;
  }

  tmp1=tmp2;
 
  while (tmp1!=NULL){
    new=cll_cons(tmp1->tag,new);
    tmp1=tmp1->next;
  }
  cll_free(tmp1);
  cll_free(tmp2);
  return new;
}

cll *del_hit (cll *l,long int t){
  cll *tmp1=l;
  cll *tmp2=NULL;
  cll *new=NULL;

  while (tmp1->tag!=t){
    tmp2=cll_cons(tmp1->tag,tmp2);
    tmp1=tmp1->next;
  }

  tmp1=tmp1->next;
  
 while (tmp1!=NULL){
    tmp2=cll_cons(tmp1->tag,tmp2);
    tmp1=tmp1->next;
  }

  tmp1=tmp2;
 
  while (tmp1!=NULL){
    new=cll_cons(tmp1->tag,new);
    tmp1=tmp1->next;
  }
  cll_free(tmp1);
  cll_free(tmp2);
  return new;
}  

int ipow(int a, int b)
{
  int raw = 1;
  while(b>0){
    raw *= a;
    b--;
  }
  return raw;
}

//===Hit/miss/evict count & linked list array modification===//
void f(char* tp, cll** set, long int add, int s, int E, int b)
{
  long int b_mask = ipow(2,b)-1;
  long int s_mask = (ipow(2,s+b)-1) ^ b_mask;
  long int t_mask = ~0 ^ b_mask ^ s_mask;

  long int s_off = (add & s_mask)>>b;
  long int b_off = add & b_mask;
  long int t_off = (add & t_mask)>>(s+b);

  char* M = "M";
 
  if (member(set[s_off], t_off)) {               //hit case
    set[s_off] =  del_hit(set[s_off], t_off);
    set[s_off] = cll_cons(t_off, set[s_off]);	
    hit += strcmp(M,tp)? 1: 2;
  } 
  else if (length(set[s_off]) < E) {  //miss & empty case
    set[s_off] = cll_cons(t_off, set[s_off]);
    miss++;	
    hit += strcmp(M,tp)? 0: 1;
  } 
  else {                             //miss & full(evict) case  
    set[s_off] = del_miss(set[s_off]);
    set[s_off] = cll_cons(t_off, set[s_off]);
    miss++;
    evict++;
    hit += strcmp(M,tp)? 0: 1;
  }
}

//===Address extraction and iterated input counter===//
void ext(char* fname, int s, int E, int b)
{
  FILE *fp;
  char tp[10]; // L/R/M
  char m[10]; //discard
  long int add; //bcs we assume 64 bit address
  int i;
  cll **set = malloc(sizeof(cll)*ipow(2,s)); // ARRAY OF LINKED LIST, s is the set bit expressed as -s
  
  if(set==NULL){
    fprintf(stderr,"ext:Heap Empty\n");
    exit(1);
  }
   
  fp = fopen(fname, "r");

  if(fp==NULL){
    fprintf(stderr,"open: file load failed\n");
    exit(0);
      }
  
  while(!feof(fp)){
    fscanf(fp,"%s %lx %s\n", tp, &add, m);

    f(tp, set, add, s, E, b);
    
    //  printf("%s\t",tp);
    //  printf("%lx\n",add);
  }
  int j;
  printf("hit %d, miss %d, evict %d\n",hit, miss, evict);
  for (j=0;j<s+1;j++){
    cll_free(set[j]);
  }
  fclose(fp);
}


int main(int argc, char *argv[])
{
  int s,E,b,i;
  char* t;

  for (i=0; i<argc; i++){
    if (strcmp(argv[i],"-s")==0 && i<argc-1){
      s=atoi(argv[i+1]);
    } else if (strcmp(argv[i],"-E")==0 && i<argc-1){
      E=atoi(argv[i+1]);
    } else if (strcmp(argv[i],"-b")==0 && i<argc-1){
      b=atoi(argv[i+1]);
    } else if (strcmp(argv[i],"-t")==0 && i<argc-1){
      t=argv[i+1];
    }
  }
  ext(t, s, E, b);
 return 0;
}


 
