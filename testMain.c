#include "string2.h"
#include <stdio.h>

int main(void){

    char * string = "testing"; 
    char * new = substring(string, 1, 5); 

    printf("printing new string from substring: %s\n", substring(string, 1, 5)); // memory leak
    printf("printing new string from substring: %s\n", new); // no memory leak
    free(new); 
    printf("checking endsWith: %d\n", endsWith(string, 'g')); 

    return 0; 
}