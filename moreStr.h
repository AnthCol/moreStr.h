
#ifndef _MORESTR_H
#define _MORESTR_H

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
    This version of the library does not include error checking for the sake of efficiency. 
    If you want the version with error checking, use moreStrE.h
*/



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
    long int lengthInput = strlen(input), lengthCheck = strlen(check); 

    for (long int i = lengthInput-lengthCheck, x = 0; input[i] != '\0'; i++, x++){
        if (input[i] != check[x]) return 0; 
    }

    return 1; 
}

int is_empty(const char * input){
    return (input[0] == '\0'); 
}

int starts_with(const char * input, const char * check){

    for (long int i = 0; check[i] != '\0'; i++){
        if(input[i] != check[i]){
            return 0; 
        }
    }

    return 1; 
}


// This function is ugly and slow! use horspools!! FIXME

int last_index_of(const char * input, const char * check){

    int length_input = strlen(input); 
    long int length_check = strlen(check); 

    for (long int i = length_input, x = 0, start; i >= 0; i--){
        if (input[i] == check[x]){
            start = i; 
            while (i != length_input && input[i] == check[x]){
                i++; 
                x++; 
                if (i > length_input) break; 
            }
            if (x == length_check) return start; 
            i = start; 
            x = 0; 
        }
    }
    return -1; 
}


// ALSO NEED TO FIX THIS ONE (FIXME) - slow and ugly 
int index_of(const char * input, const char *check){ 

    int length_check = strlen(check), i = 0, x = 0, start; 

    
    for (i = 0; input[i] != '\0'; i++){
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


// USE HORSPOOLS

int contains (const char * input, const char * search){

    int i = 0, x = 0, start, lengthInput = strlen(input), lengthSearch = strlen(search);


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


int region_matches(const char * one, int twoOffset, const char * two, int starting, int ending){ 

    int lengthOne = strlen(one), lengthTwo = strlen(two); 

    for (int i = starting, x = twoOffset; i < ending; i++, x++){
        if (one[i] != two[x]) return 0; 
    }

    return 1; 
}

int equals_ignore_case(const char * one, const char * two){
    for (int i = 0; one[i] != '\0'; i++){
       if (tolower(one[i]) != tolower(two[i])) return 0; 
    }
    return 1; 
}

#endif