#include <stdlib.h>
#include <ctype.h>


// FIXME To-do list:
// Make sure all of the functions are safe (or at least as safe as they can be)
// Make sure all of the functions 
// get rid of all dependencies on external libraries



char * substring(const char * input, int leftIndex, int rightIndex){

/* maybe it would be better to avoid malloc and stdlib.h alltogether and just have these functions modify the input strings. 
If it was done that way then it would be up to the user entirely to manage their memory in main, while these functions won't touch memory at all. */


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

int endsWith(const char * input, char check){
    int i = 0; 

    while (input[i] != '\0'){
        i++; 
    }

    if (input[i-1] == check) return 1; 
    return 0; 
}

int isEmpty(const char * input){
    int length = 0; 

    while (input[length] != '\0'){
        length++;
    }

    if (length == 0) return 1;
    return 0; 
}

int startsWith(const char * input, const char * check){
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
        if (input[i] != check[i]) return 0; 
        i++; 
    }

    return 1; 
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

int lastIndexOf(const char * input, const char * check){

    int lengthInput = 0, lengthCheck = 0, i = 0, x = 0, start; 
    while (input[lengthInput] != '\0'){
        lengthInput++; 
    }
    while (check[lengthCheck] != '\0'){
        lengthCheck++; 
    }
    if (lengthCheck > lengthInput) return -1; 
    
    for (i = lengthInput; i >= 0; i--){
        if (input[i] == check[x]){
            start = i; 
            while (input[i]==check[x]){
                i++; 
                x++; 
                if (x > lengthCheck || i > lengthInput) break; 
            }
            if (x == lengthCheck) return start; 
        }
        i = start; 
        x = 0; 

    }
    return -1; 
}

int indexOf(const char * input, const char *check){ // add start position argument like in java?

    int lengthInput = 0, lengthCheck = 0, i = 0, x = 0, start; 
    while (input[lengthInput] != '\0'){
        lengthInput++; 
    }
    while (check[lengthCheck] != '\0'){
        lengthCheck++; 
    }
    if (lengthCheck > lengthInput) return -1; 

    for (i = 0; i < lengthInput; i++){
        if (input[i] == check[x]){
            start = i; 
            while (input[i] == check[x]){
                i++; 
                x++; 
                if (x > lengthCheck || i > lengthInput) break; 
            }
            if (x == lengthCheck) return start; 
        }
        i = start; 
        x = 0; 
    }


    return -1; 
}

char * replace (char * input, char search, char replace){ // unlike java, this will modify the string, NOT make a new one and then modify it. 
    int i = 0, length = 0; 

    while(input[length] != '\0'){
        length++; 
    }

    for (i = 0; i < length; i++){
        if (input[i] == search) input[i] = replace; 
    }

    return input; 
}


char * replaceAll (char * input, const char * search, const char * replace){

    int i = 0, x = 0, j = 0, z = 0, start = 0, lengthInput = 0, lengthSearch = 0, lengthReplace = 0; 

    while (input[lengthInput] != '\0'){
        lengthInput++; 
    }
    while (search[lengthSearch] != '\0'){
        lengthSearch++; 
    }
    while (replace[lengthReplace] != '\0'){
        lengthReplace++; 
    }

    if (lengthReplace > lengthSearch) exit(0); 
    if (lengthSearch > lengthInput) exit(0); 
    
    for (i = 0; i < lengthInput; i++){
        start = i; 
        if (input[i] == search[x]){
            i++; 
            x++; 
            if (x == lengthSearch){
                for (j = start; j < i; j++){
                    input[i] = replace[z]; 
                    z++; 
                }
                z = 0; 
            }
        }
    }
    return input; 
}





//WATER YOUR PLANTS BOZO!