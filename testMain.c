#include "string2.h"

int main(void){

    char * string = "testing"; 
    char * newString = substring(string, 1, 5); 

    printf("printing new string %s\n", newString);
    free(newString); 

    return 0; 
}