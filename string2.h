#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// To-do list:
// Remove dependence on ctype.h?
// More testing to make sure the functions are as safe as they can be. 
// maybe include exiting messages so that the user knows?
// need to rerun through valgrind after changes *****FIXME*****






/*

*Documentation for substring()*

The substring function takes in an existing string, and two indices. 
A starting and ending index. 
It will allocate memory for a new string and copy the information from the original string (from the left index up to (but not including)
the right index). 

The function performs multiple checks to make sure there are no invalid lengths, or invalid index requests. 
If there are, the program will exit. 

It returns the freshly allocated string to the function that called it. 
It must be freed by the user. 

*/

char * substring(char * tempString, int leftIndex, int rightIndex){

    if (leftIndex > rightIndex || leftIndex < 0 || tempString[0] == '\0') exit(0); 
   
    int i, x = 0, length = 0; 

    for (i = 0; tempString[i] != '\0'; i++){ 
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


/*

*Documentation for endsWith()*

This function takes two strings for input. 

It checks the lengths of those strings to make sure that the string the user
wants to find within the larger one can actually be found. 
The program will exit if it cannot be done. 

Otherwise, it will iterate through the strings and if it can do so successfully will return true. 
Otherwise it will return false. 

*/



int endsWith(const char * input, const char * check){
    int lengthInput = 0, lengthCheck = 0, x = 0; 
   
    for (int i = 0; input[i] != '\0'; i++){
        lengthInput++;
    }
    for (int i = 0; check[i] != '\0'; i++){
        lengthCheck++; 
    }
    if (lengthCheck > lengthInput || lengthInput == 0 || lengthCheck == 0) exit(0); 

    for (int i = lengthInput-lengthCheck; input[i] != '\0'; i++, x++){
        if (input[i] != check[x]) return 0; 
    }
    return 1; 
}

/*
*Documentation for isEmpty()*

This function checks to see if the first character in a string is the null character. 
If it is, it returns true. Otherwise false.

*/

int isEmpty(const char * input){
    if (input[0] == '\0') return 1;
    return 0; 
}

/*
*Documentation for startsWith()*

This function takes two strings as input and performs checks on their lengths to make sure that there is not a
situation that would cause issues (the substring you are looking for being longer than the other string). 

After performing these checks, it iterates through the substring and if it successfully does so returns true. 
Otherwise it returns false. 

*/

int startsWith(const char * input, const char * check){
    int i = 0, x = 0; 
    while (input[i] != '\0'){
        i++; 
    }
    while (check[x] != '\0'){
        x++; 
    }
    if (x > i || i == 0 || x == 0) exit(0); 

    i = 0; 

    while (check[i] != '\0'){
        if (input[i] != check[i]) return 0; 
        i++; 
    }

    return 1; 
}

/*

    *Documentation for lastIndexOf()*

    This function takes two strings as input. 
    After performing safety checks it runs through the input string backwards to find a character that matches
    the first character of check. 

    Then, it loops through the string and if "x" reaches the length of check, the last index will be returned. 

    If it is not found, the function will return -1. 

*/

int lastIndexOf(const char * input, const char * check){

    int lengthInput = 0, lengthCheck = 0, i = 0, x = 0, start; 
    while (input[lengthInput] != '\0'){
        lengthInput++; 
    }
    while (check[lengthCheck] != '\0'){
        lengthCheck++; 
    }
    if (lengthCheck > lengthInput || lengthInput == 0 || lengthCheck == 0) return -1; // maybe exit if lengthCheck > lengthInput?
    
    /*
        FIXME
        See design proposal change for contains(). A similar idea could apply here and work well.
    */

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



/*
    *Documentation of indexOf()*
    This function loops through the input string and will check through at every index of the 
    string to see if the substring (or character in the form of a string) is in there. 

    If it is not while doing a check, a start variable is declared to allow us to set the location of 
    i back to where it was when we started checking for the string. 

    This does have the potential to be quite slow with the nested loop - worth looking into a better 
    implementation of this in the future. 

*/
int indexOf(const char * input, const char *check){ // add start position argument like in Java? (maybe FIXME)

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
            i = start; 
            x = 0; 
        }
    }


    return -1; 
}
/*
    *Documentation of contains()*
    This function is effectively the same as indexOf() except it returns a boolean value 
    rather than an index at which the substring begins. 

    Copy of documentation from indexOf() function:
    This function loops through the input string and will check through at every index of the 
    string to see if the substring (or character in the form of a string) is in there. 

    If it is not while doing a check, a start variable is declared to allow us to set the location of 
    i back to where it was when we started checking for the string. 

    This does have the potential to be quite slow with the nested loop - worth looking into a better 
    implementation of this in the future. 
*/
int contains (const char * input, const char * search){

    int i = 0, x = 0, start, lengthInput = 0, lengthSearch = 0;

    while (input[lengthInput] != '\0'){
        lengthInput++; 
    }
    while (search[lengthSearch] != '\0'){
        lengthSearch++; 
    }
    if (lengthSearch > lengthInput || lengthInput == 0 || lengthSearch == 0) exit(0); 

    /*
        FIXME

        The following loop has the potential to be very slow. 
        Maybe a better implementation would be to find all of the indices where input has the first character of search. 

        From there you could run through those indices and store them in an array or something and just fast track to those indices. 

    */

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
/*
    *Documentation for trim() function*

    This function takes a string as input and allocates memory for a new string (that it returns). 
    That new string is identical to the input string except the whitespace from both the beginning and end of
    the string would be removed. 
    For example:

    input = "    Hi!    "
    output = "Hi!"

*/

char * trim (const char * input){   

    int length = 0, left = 0, right = 0, x = 0, countSpace = 0; 
    for (int i = 0; input[i] != 0; i++){
        length++; 
        if (input[i] == ' ') countSpace++; 
    }

    if (length == 0) exit(0); 

    if (countSpace == 0){
        // allocating memory here for consistency in main. 
        // Don't want to have issues with the user freeing a string that was not malloc'd
        char * temp = (char*)malloc(sizeof(char) * length + 1); 
        strcpy(temp, input); 
        return temp; 
    }
    else if (countSpace == length){
        char * temp = (char*)malloc(sizeof(char) * 2); 
        temp[0] = '\0';
        return temp; 
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
/*
    *Documentation for regionMatches()*

    This function takes two strings, a starting and ending index, and an optional offset (it can be passed as zero) 
    for the second string. 

    The offset is applied and a loop goes through the two strings to determine if they match between the indices
    (starting included, ending excluded). If they do not match at any point it will return false, otherwise true. 

*/
int regionMatches(const char * one, int twoOffset, const char * two, int starting, int ending){ // FIXME maybe change the order of the arguments here to make it more intuitive. 

    int lengthOne = 0, lengthTwo = 0; 

    while (one[lengthOne] != '\0'){
        lengthOne++; 
    }
    while (two[lengthTwo] != '\0'){
        lengthTwo++; 
    }
    
    if (ending < starting || lengthOne == 0 || lengthTwo == 0 || starting < 0 || ending + twoOffset > lengthOne) exit(0); 
    if (lengthOne > lengthTwo && starting + twoOffset > lengthTwo) exit(0); 
    if (ending > lengthOne + 1 || ending + twoOffset > lengthTwo + 1) exit(0); 

    for (int i = starting, x = twoOffset; i < ending; i++, x++){
        if (one[i] != two[x]) return 0; 
    }

    return 1; 
}

/*
    *Documentation for equalsIgnoreCase()*

    This function takes two strings as input and iterates through them, comparing
    at every step if the characters are the exact same when converted to lowercase. 
*/

int equalsIgnoreCase(const char * one, const char * two){


    int length1 = 0, length2 = 0; 
    for (int i = 0; one[i] != '\0'; i++){
        length1++; 
    }
    for (int i = 0; two[i] != '\0'; i++){
        length2++; 
    }
    if (length1 != length2) return 0; 
    if (length1 == 0 && length2 == 0) return 1; 


    for (int i = 0; i < length1; i++){
       if (tolower(one[i]) != tolower(two[i])) return 0; 
    }
   
    return 1; 
}


int valueOfInt (const char * input){
    int val = 0, length = 0, multiplier = 1, temp; 

    //FIXME maybe add some functionality to remove whitespace preceding characters in case there is any?
    
    for (int i = 0; input[i] != '\0'; i++){
        switch(input[i]){
            case '-': 
                if (i != 0) exit(0); 
                length++; 
                break; 
            case '1': length++; break; // FIXME maybe turn this into a character array and loop through it. 
            case '2': length++; break; // Probably won't do much for speed and will be worse for memory, but will look cleaner (maybe not worth?)
            case '3': length++; break; 
            case '4': length++; break; 
            case '5': length++; break; 
            case '6': length++; break; 
            case '7': length++; break; 
            case '8': length++; break; 
            case '9': length++; break; 
            case '0': length++; break; 
            default: exit(0); 
        }
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