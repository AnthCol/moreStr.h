#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char * substring(const char * input, int leftIndex, int rightIndex){
    if (leftIndex > rightIndex || leftIndex < 0 || input == NULL) exit(0); 

    int i, x = 0, length = 0; 

    for (i = 0; input[i] != '\0'; i++){ // I'm sure strlen(input) could be fine here, but I wanted to make it myself. 
        length++; 
    }
    
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

bool endsWith(const char * input, char check){
    int i = 0; 

    while (input[i] != '\0'){
        i++; 
    }

    if (input[i-1] == check) return true; 
    return false; 
}

bool isEmpty (const char * input){
    int length = 0; 

    while (input[length] != '\0'){
        length++; 
    }

    if (length == 0) return true;
    return false; 
}

bool startsWith(const char * input, const char * check){
    int i = 0, x = 0; 
    while (input[i] != '\0'){
        i++; 
    }
    while (check[x] != '\0'){
        x++; 
    }
    if (x > i) exit(0); 

    i = 0; 

    while (check[i] != '\0'){
        if (input[i] != check[i]) return false; 
        i++; 
    }

    return true; 
}



/* Do these two functions below by hand. Get rid of the ctype.h reliance */


char * toLowerCase(char * input){  
    for (int i = 0; input[i] != '\0'; i++){
        if (isupper(input[i])){
            tolower(input[i]); 
        }
    }
    return input; 
}

char * toUpperCase(char * input){
    for (int i = 0; input[i] != '\0'; i++){
        if (islower(input[i])){
            toupper(input[i]); 
        }
    }
    return input; 
}


