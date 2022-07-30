#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char * substring(const char * input, int leftIndex, int rightIndex){
    int i, x = 0, length = 0; 
    for (i = 0; input[i] != '\0'; i++){
        length++; 
    }
    
    if (leftIndex > rightIndex || leftIndex < 0 || input == NULL) exit(0); 
    if (rightIndex > length || leftIndex > length || rightIndex - leftIndex == 0) exit(0); 

    char * newString = (char*)malloc(sizeof(char) * (rightIndex - leftIndex)); 
    // works like the java one, where the rightIndex should be the character after the one you want. 
    for (i = leftIndex; i < rightIndex; i++){
        newString[x] = input[i]; 
        x++; 
    }
    newString[x] = '\0'; 

    return newString; 
}

