#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include <wait.h>

#define PATH_MAX 500


//myPrint
void myPrint(char *msg)
{
    write(STDOUT_FILENO, msg, strlen(msg));
}

//error
void error()
{
  char error_message[30] = "An error has occurred\n";
  write(STDOUT_FILENO, error_message, strlen(error_message));
}
  
//builtin / 1.exit 2.cd 3.pwd

void builtin(char *cmd)
{
  if(!strcmp(cmd,"exit")){ //RR: rid of \n
    exit(0);
  
  }else if(!strcmp(cmd, "cd")){ //RR: rid of \n
    chdir(getenv("HOME"));
  
  }else if(!strcmp(cmd,"pwd")){ //RR: rid of \n
    char pwd[PATH_MAX]; //RR: need PATH_MAX expanding functionality
    getcwd(pwd, sizeof(pwd));
    myPrint(pwd);
    putchar('\n');
 }
  return;
}

//non-builtin commands
void command(char *cmd, char *argv[])
{
  pid_t child;
  
  if(strcmp(cmd,"ls\n")==0 && (child = fork())==0){ //RR: rid of \n
    
    char *arg[3];
    arg[0] = "ls";
    arg[1] = NULL;

    execvp(arg[0],arg);
    error();
    
  }else if(child!=0){
    wait(NULL);
  }
  
  return;
}

//parse
void parse(char *msg, int no)
{

  //pid_t child = fork();
  
  char* string = msg;
  char *token = strchr(string, ';');
  char *token2 = strchr(string, '\n');
  char *token3;
  //unsigned int i;
  //unsigned int j;
  char *arg[no];
  int i;
  
  //initialize arg array
  for(i=0; i<no; arg[i++]=NULL);
  
  //accounting for last cmd & single cmd execution 
  if(token!=NULL){ //case for capturing last cmd under  multiple input 
    *token2 = ';';
  }else if(strlen(string)!=0){ //case for single input ex) pwd\n               
    token = token2;
  }
  
  while (token != NULL){
    
    i=0;
    *token++ = '\0';
    printf("a = %s\n", string);
    token3 = strtok(string, " \t\n\v\f\r");
    
    while(token3 != NULL){
      printf("arg[%d] = %s\n",i,token3);
      arg[i++] = token3;
      token3 = strtok(NULL, " \t\n\v\f\r");
    }
    
    string = token;
    token = strchr(string, ';');
    
    //filtering for builtin case
    if (!strcmp(arg[0],"exit")||!strcmp(arg[0],"pwd"))
      {
	printf("befor exec builtin\n");
	builtin(arg[0]);
      } else if(!strcmp(arg[0],"cd") && arg[1] == NULL) { //filter pure "cd"
      builtin(arg[0]);
    } else if(!strcmp(arg[0],"cd")){ //filter other "cd + path" case
      chdir(arg[1]);
    } else { //non-built-in case (requires forking)
      pid_t child = fork();
      
      if (!child) //child executes given cmd arg[0] with argument "arg" 
      	{
	  execvp(arg[0],arg);
	  error();
	} else {  //parent waits
	wait(NULL);
      }
    }
    for(i=0; i<no; arg[i++]=NULL);
  }
}

/*
  
  while(token != NULL)
  {
  *token++ = '\0';
  //insert \t and white space clearing function here
  int l = strlen(string);
  char temp[l+1];
  j = 0;
  
  for(i=0;i<l+1;i++){
  temp[i] = '\0';
  }
  
  for(i=0;i<l;i++){
  if(string[i]!=' ' && string[i]!='\t')
  temp[j++] = string[i];
  }
  //////////
  



/////////////COMMENTS      
stort for
 char *dummy[] > initilize to \0 since we need to reuse it in second strtok; loop
->ls -la; pwd

ls-la

strtok ;  first part
strtok white space first part
dummy[0]=ls
second part
dummy[1] = -la

esecvp(dumm[0],dumm) ->done works fine

strtok ; second part dummy gois back to \0\0\\0
strtok white space first part
[0]=pwd

inside the loop, ned to do execvp(char * [i,0],char ** [i]

./myshell pwd;    ls -la
argv[0]
argv[1]
argv[1]

    //////////////COMMENTS   
      if(strlen(temp)!=0){
	//printf("%s\n",getenv("HOME"));
	write(STDOUT_FILENO, temp, strlen(temp)); // GLOBAl and pass to fn  
      
      }
      string = token;
      token = strchr(string, ';');
    }
  return;
}

*/





int main(int argc, char *argv[]) 
{
  
    char cmd_buff[514];
    char *pinput;
    
    while (1) {
      myPrint("myshell> ");
      pinput = fgets(cmd_buff, 514, stdin);
	

      //	if(strcmp(str_exit, cmd_buff)==0)
      // exit(0);
      ///////////////
      
      if (!pinput) {
	exit(0);
      }
      //command(cmd_buff);

      // builtin(cmd_buff);

      parse(cmd_buff,10);
      //myPrint(cmd_buff);
    }
}
