#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void substring(char * input, long int left_index, long int right_index){

    long int i = left_index, x = 0, length = strlen(input); 

    char new_string[length + 1]; 

    strcpy(new_string, input); 

    for (; i < right_index; i++, x++){
        input[x] = new_string[i]; 
    }

    input[x] = '\0'; 

    return;
}

void reverse(char * input){
    long int length = strlen(input); 
    char tempChar; 

    for (long int i = 0, x = length - 1; i < length/2; i++, x--){
        tempChar = input[i]; 
        input[i] = input[x]; 
        input[x] = tempChar; 
    }

    return; 
}
   
int is_palindrome(const char * input){
    int length = strlen(input); 

    for (int i = 0, x = length - 1; i < length/2; i++, x--){
        if (input[i] != input[x]) return 0; 
    }

    return 1; 
}


int ends_with(const char * input, const char * check){
    int lengthInput = strlen(input), lengthCheck = strlen(check); 

    if (lengthCheck > lengthInput || lengthInput == 0 || lengthCheck == 0) exit(0); 

    for (int i = lengthInput-lengthCheck, x = 0; input[i] != '\0'; i++, x++){
        if (input[i] != check[x]) return 0; 
    }
    return 1; 
}

int isEmpty(const char * input){
    return (input[0] == '\0'); 
}

int startsWith(const char * input, const char * check){
    int length_input = strlen(input), length_check = strlen(check); 

    if (length_check > length_input || length_input == 0 || length_check == 0) exit(0); 


    int i = 0; 
    while (check[i] != '\0'){
        if (input[i] != check[i]) return 0; 
        i++; 
    }

    return 1; 
}



int lastIndexOf(const char * input, const char * check){

    int lengthInput = strlen(input), lengthCheck = strlen(check), i = 0, x = 0, start; 
    if (lengthCheck > lengthInput || lengthInput == 0 || lengthCheck == 0) return -1; // maybe exit if lengthCheck > lengthInput?
    
    for (i = lengthInput; i >= 0; i--){
        if (input[i] == check[x]){
            start = i; 
            while (i != lengthInput && input[i] == check[x]){
                i++; 
                x++; 
                if (i > lengthInput) break; 
            }
            if (x == lengthCheck) return start; 
            i = start; 
            x = 0; 
        }
    }
    return -1; 
}


int indexOf(const char * input, const char *check){ // add start position argument like in Java? (maybe FIXME)

    int lengthInput = strlen(input), lengthCheck = strlen(check), i = 0, x = 0, start; 

    if (lengthCheck > lengthInput) return -1; 
    
    for (i = 0; i < lengthInput; i++){
        if (input[i] == check[x]){
            start = i; 
            while (i != lengthInput  && x != lengthCheck && input[i] == check[x]){
                i++; 
                x++; 
            }
            if (x == lengthCheck) return start; 
            i = start; 
            x = 0; 
        }
    }


    return -1; 
}


int contains (const char * input, const char * search){

    int i = 0, x = 0, start, lengthInput = strlen(input), lengthSearch = strlen(search);

    if (lengthSearch > lengthInput || lengthInput == 0 || lengthSearch == 0) exit(0); 

    for (i = 0; i < lengthInput; i++){ 
        if (input[i] == search[x]){
            start = i;
            while (i != lengthInput && input[i] == search[x]){
                i++; 
                x++; 
                if (x == lengthSearch) return 1; //true 
            }
            x = 0; 
            i = start; 
        }
    }

    return 0; 
}


void trim (char * input){   

    int length = 0, firstChar = -1, lastChar = -1; 
    while(input[length] != '\0'){
        if (firstChar == -1 && input[length] != ' ') firstChar = length; // find index of first char
        length++; 
    }

    if (length == 0) exit(0); 

    for (int i = length-1; i >= 0; i--){
        if (input[i] != ' '){
            lastChar = i;  
            break; 
        }
    }

    char tempString[length - firstChar - (length - lastChar) + 1]; 

    for (int i = firstChar, x = 0; i <= lastChar; i++, x++){
        tempString[x] = input[i]; 
    }
    
    int i; 

    for (i = 0; i < length - firstChar - (length - lastChar) + 1; i++){
        input[i] = tempString[i]; 
    }
    input[i] = '\0'; 
    return; 
}


int regionMatches(const char * one, int twoOffset, const char * two, int starting, int ending){ // FIXME maybe change the order of the arguments here to make it more intuitive. 

    int lengthOne = strlen(one), lengthTwo = strlen(two); 

    if (ending < starting || lengthOne == 0 || lengthTwo == 0 || starting < 0 || ending + twoOffset > lengthOne) exit(0); 
    if (lengthOne > lengthTwo && starting + twoOffset > lengthTwo) exit(0); 
    if (ending > lengthOne + 1 || ending + twoOffset > lengthTwo + 1) exit(0); 

    for (int i = starting, x = twoOffset; i < ending; i++, x++){
        if (one[i] != two[x]) return 0; 
    }

    return 1; 
}

int equalsIgnoreCase(const char * one, const char * two){

    int length1 = strlen(one), length2 = strlen(two); 

    if (length1 != length2) return 0; 
    if (length1 == 0 && length2 == 0) return 1; 


    for (int i = 0; i < length1; i++){
       if (tolower(one[i]) != tolower(two[i])) return 0; 
    }
   
    return 1; 
}
