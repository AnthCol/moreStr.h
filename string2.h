#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// To-do list:
// Remove dependence on ctype.h (probably not necessary)
// maybe include exiting messages so that the user knows?






/*

    *Documentation for substring()*

    The substring function takes in an existing string, and two indices. 
    A starting and ending index. 
    It makes a temporary string to copy from and then fills the users original string with 

    The function performs multiple checks to make sure there are no invalid lengths, or invalid index requests. 
    If there are, the program will exit. 



*/

void substring(char * input, int leftIndex, int rightIndex){

    if (leftIndex > rightIndex || leftIndex < 0 || input[0] == '\0') exit(0); 
   
    int i, x = 0, length = strlen(input); 
    
    if (rightIndex > length || leftIndex > length || rightIndex - leftIndex == 0) exit(0); 

    char * newString = (char*)malloc(sizeof(char) * (rightIndex-leftIndex+1)); 
    
    for (i = leftIndex; i < rightIndex; i++){
        newString[x] = input[i]; 
        x++; 
    }
    newString[x] = '\0'; 
    for (i = 0; i < rightIndex - leftIndex; i++){
        input[i] = newString[i]; 
    }
    free(newString); 
    input[i] = '\0';  

    return;
}

/*
    *Documentation for reverse()*

    This function takes a string as input (malloc'd in main) and reverses it. 
    Then it returns back to main after modifying the string. 

*/
void reverse(char * input){
    int length = strlen(input); 
    char tempChar; 

    for (int i = 0, x = length - 1; i < length/2; i++, x--){
        tempChar = input[i]; 
        input[i] = input[x]; 
        input[x] = tempChar; 
    }

    return; 
}



/*
    *Documentation for isPalindrome()*

    A palindrome is a string that reads the same forwards as it does backwards. 
    This function considers ALL types of characters in the string (including 
    commas, colons, periods, etc.)

    It returns true or false. 


*/

int isPalindrome(const char * input){
    int length = strlen(input); 

    for (int i = 0, x = length - 1; i < length/2; i++, x--){
        if (input[i] != input[x]) return 0; 
    }

    return 1; 
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
    int lengthInput = strlen(input), lengthCheck = strlen(check); 

    if (lengthCheck > lengthInput || lengthInput == 0 || lengthCheck == 0) exit(0); 

    for (int i = lengthInput-lengthCheck, x = 0; input[i] != '\0'; i++, x++){
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
    return (input[0] == '\0'); 
}

/*
    *Documentation for startsWith()*

    This function takes two strings as input and performs checks on their lengths to make sure that there is not a
    situation that would cause issues (the substring you are looking for being longer than the other string). 

    After performing these checks, it iterates through the substring and if it successfully does so returns true. 
    Otherwise it returns false. 

*/

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

/*

    *Documentation for lastIndexOf()*

    This function takes two strings as input. 
    After performing safety checks it runs through the input string backwards to find a character that matches
    the first character of check. 

    Then, it loops through the string and if "x" reaches the length of check, the last index will be returned. 

    If it is not found, the function will return -1. 

*/

int lastIndexOf(const char * input, const char * check){

    int lengthInput = strlen(input), lengthCheck = strlen(check), i = 0, x = 0, start; 
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

    int i = 0, x = 0, start, lengthInput = strlen(input), lengthSearch = strlen(search);

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

    char * tempString = (char*)malloc(sizeof(char) * length - firstChar - (length - lastChar) + 1); 

    for (int i = firstChar, x = 0; i <= lastChar; i++, x++){
        tempString[x] = input[i]; 
    }
    int i; 
    for (i = 0; i < length - firstChar - (length - lastChar) + 1; i++){
        input[i] = tempString[i]; 
    }
    input[i] = '\0'; 
    free(tempString); 
    
    return; 
}


/*
    *Documentation for regionMatches()*

    This function takes two strings, a starting and ending index, and an optional offset (it can be passed as zero) 
    for the second string. 

    The offset is applied and a loop goes through the two strings to determine if they match between the indices
    (starting included, ending excluded). If they do not match at any point it will return false, otherwise true. 

*/
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

/*
    *Documentation for equalsIgnoreCase()*

    This function takes two strings as input and iterates through them, comparing
    at every step if the characters are the exact same when converted to lowercase. 

    If they do not equal eachother at any point after being changed to lowercase, 
    the function will return 0 (false). 

    If it makes it through the whole string, it will return 1 (true). 
*/

int equalsIgnoreCase(const char * one, const char * two){

    int length1 = strlen(one), length2 = strlen(two); 

    if (length1 != length2) return 0; 
    if (length1 == 0 && length2 == 0) return 1; 


    for (int i = 0; i < length1; i++){
       if (tolower(one[i]) != tolower(two[i])) return 0; 
    }
   
    return 1; 
}


/*
    *Documentation for valueOfInt()*

    This function will take in a string and calculate an integer value with it. 
    It first checks if there is a negative (and makes sure it is the first character in the string). 
    After that it uses a switch case and a multiplier to calculate the number as it iterates 
    through the string backwards. 


    Notes:
    It currenlty only works if the string is just a number. 
    It will not remove whitespace or anything else. 
*/

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

            multiplier *= 10; 
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