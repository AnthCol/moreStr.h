#include <stdlib.h>
#include <string.h>


// To-do list:
// Make sure all of the functions are safe (or at least as safe as they can be)
// maybe include exiting messages so that the user knows?

char * substring(char * tempString, int leftIndex, int rightIndex){

    if (leftIndex > rightIndex || leftIndex < 0 || tempString == NULL) exit(0); 
   
    int i, x = 0, length = 0; 

    for (i = 0; tempString[i] != '\0'; i++){ // I'm sure strlen(tempString) could be fine here, but I wanted to make it myself. 
        length++; 
    }
    
    if (rightIndex > length || leftIndex > length || rightIndex - leftIndex == 0) exit(0); 

    char * newString = (char*)malloc(sizeof(char) * (rightIndex-leftIndex+1)); 
    
    for (i = leftIndex; i < rightIndex; i++){
        newString[x] = tempString[i]; 
        x++; 
    }
    newString[x] = '\0';  

    return newString; 
}

int endsWith(const char * input, const char * check){
    int lengthInput = 0, lengthCheck = 0, x = 0; 
    for (int i = 0; input[i] != '\0'; i++){
        lengthInput++;
    }
    for (int i = 0; check[i] != '\0'; i++){
        lengthCheck++; 
    }
    if (lengthCheck > lengthInput) exit(0); 

    for (int i = lengthInput-lengthCheck; input[i] != '\0'; i++, x++){
        if (input[i] != check[x]) return 0; 
    }
    return 1; 
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
            while (i != lengthInput && input[i] == check[x]){
                i++; 
                x++; 
                if (x > lengthCheck || i > lengthInput) break; 
            }
            if (x == lengthCheck) return start; 
            i = start - 1; 
        }
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
            while (i != lengthInput  && x != lengthCheck && input[i] == check[x]){
                i++; 
                x++; 
            }
            if (x == lengthCheck) return start; 
            i = start + 1; 
        }
        x = 0; 
    }


    return -1; 
}

int contains (const char * input, const char * search){

    int i = 0, x = 0, lengthInput = 0, lengthSearch = 0;

    while (input[lengthInput] != '\0'){
        lengthInput++; 
    }
    while (search[lengthSearch] != '\0'){
        lengthSearch++; 
    }
    if (lengthSearch > lengthInput) exit(0); 

    for (i = 0; i < lengthInput; i++){
        if (input[i] == search[x]){
            while (i != lengthInput && input[i] == search[x]){
                i++; 
                x++; 
                if (x == lengthSearch) return 1; //true 
            }
        }
    }

    return 0; 
}


char * trim (char * input){   // while this is O(n), it is kind of slow

    int length = 0, left = 0, right = 0, x = 0, countSpace = 0; 
    for (int i = 0; input[i] != 0; i++){
        length++; 
        if (input[i] == ' ') countSpace++; 
    }
    if (countSpace == length){
        input[0] = '\0'; 
        return input; 
    }
    for (int i = 0; input[i] == ' '; i++){
        left++; 
    }
    right = length; 
    for (int i = length; input[i] == ' '; i--){
        right--; 
    }

    char * temp = (char*)malloc(sizeof(char) * (length - left + right)); 

    for (int i = left; i <= right; i++){
        temp[x] = input[i]; 
        x++; 
    }

    temp[x] = '\0'; 
    return temp; 
}

int regionMatches(const char * one, int twoOffset, const char * two, int starting, int ending){ // this might be awfully implemented

    // need to check safety for lengths (cant have ending past one length, cant have offSet greater than two length etc)


    if (ending < starting) exit(0); 
    for (int i = starting, x = twoOffset; i < ending; i++, x++){
        if (one[i] != two[x]) return 0; 
    }

    return 1; 
}

int equalsIgnoreCase(const char * one, const char * two){


    int length1 = 0, length2 = 0; 
    for (int i = 0; one[i] != '\0'; i++){
        length1++; 
    }
    for (int i = 0; two[i] != '\0'; i++){
        length2++; 
    }
    if (length1 != length2) return 0; 

    char temp1[length1]; 
    char temp2[length2]; 

    temp1[0] = '\0'; 
    temp2[0] = '\0'; 
    

    for (int i = 0; i < length1; i++){
        if (isupper(one[i])) temp1[i] = tolower(one[i]); 
        else temp1[i] = one[i]; 
        if (isupper(two[i])) temp2[i] = tolower(two[i]); 
        else temp2[i] = two[i]; 
        if (temp1[i] != temp2[i]) return 0; 
    }
   
    return 1; 
}

// replaceFirst
// subsequence

int valueOfInt (const char * input){
    int val = 0, length = 0, multiplier = 1, temp; 
    
    for (int i = 0; input[i] != '\0'; i++){
        length++; 
    }
    length--; 
    if (input[0] == '-'){
        for (int i = length; i > 0; i--){
            temp = input[i]; 
            switch(temp){
                case 49: val -= 1*multiplier; break; 
                case 50: val -= 2*multiplier; break; 
                case 51: val -= 3*multiplier; break; 
                case 52: val -= 4*multiplier; break; 
                case 53: val -= 5*multiplier; break; 
                case 54: val -= 6*multiplier; break; 
                case 55: val -= 7*multiplier; break; 
                case 56: val -= 8*multiplier; break; 
                case 57: val -= 9*multiplier; break; 
            }

            multiplier*= 10; 
        }

    }
    else{
        for (int i = length; i >= 0; i--){
            temp = input[i]; 
            switch(temp){
                case 49: val += 1*multiplier; break; 
                case 50: val += 2*multiplier; break; 
                case 51: val += 3*multiplier; break; 
                case 52: val += 4*multiplier; break; 
                case 53: val += 5*multiplier; break; 
                case 54: val += 6*multiplier; break; 
                case 55: val += 7*multiplier; break; 
                case 56: val += 8*multiplier; break; 
                case 57: val += 9*multiplier; break; 
            }
            multiplier *= 10; 
        }
    }

    return val; 
}