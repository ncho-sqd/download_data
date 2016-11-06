#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

#include "gtest/gtest.h"

using namespace std;

bool isalpha_help(char c){return !(isalpha(c));}
bool isalnum_help(char c){return !(isalnum(c));}

bool str_isalpha(const string str) {
    // find_if takes two iterators that bound the region of the container to
    // search and a boolean function; if any of the elements in the container
    // cause the function to return true, find_if returns an iterator to that
    // position; if no elements cause the function to return true, then an
    // iterator at the end position is returned. here, the whole string is
    // alphabetic if the end iterator is returned, so we return the boolean
    // indicating that this is the case.
    return find_if(str.begin(), str.end(), 
                   isalpha_help) == str.end();
}

bool str_isalnum(const string str) {
    // same as above, but with an alphanumeric check
    return find_if(str.begin(), str.end(), 
                   isalnum_help) == str.end();
}




int main()
{
	using namespace std;
	char a[] = "hello world\n";
	cout << a[0];
	cout << str_isalpha("a2bc");
	
	
	if( __cplusplus == 201103L ) std::cout << "C++11\n" ;
	else if( __cplusplus == 19971L ) std::cout << "C++98\n" ;
	else std::cout << "pre-standard C++\n" ;
	return 0;
}