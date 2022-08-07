#include "string2.h"
#include <stdio.h>

int main(void){
    char * tempString = "hello this is a temporary string"; 
    char * number = "-1234"; 
    char * empty = ""; 
    
    printf("The tempstring is: %s\n", tempString); 
    // for some reason the program exits at substring
    char * sub = substring(tempString, 1, 8); 
    printf("printing substring [index 1 to 8]: %s\n", tempString); 

    // resetting temporary string after substring modification. 
    printf("Ends with z: %d\n", endsWith(tempString, "z")); 
    printf("Ends with g: %d\n", endsWith(tempString, "g")); 

    printf("Is Empty (tempstring): %d\n", isEmpty(tempString)); 
    printf("Is Empty (empty string): %d\n", isEmpty(empty)); 

    printf("Starts with z: %d\n", startsWith(tempString, "z")); 
    printf("Starts with h: %d\n", startsWith(tempString, "h")); 

    char * upperCase = "HELLO THIS IS A TEMPORARY STRING"; 
    printf("before: %s\n", upperCase); 
    printf("after tolowercase: %s\n", upperCase); 
    printf("after touppercase: %s\n", upperCase); 

    printf("Index of 't': %d\n", indexOf(tempString, "t")); 
    printf("lastIndex of '5': %d\n", lastIndexOf(tempString, "t")); 

    printf("replacing the t's with z's: %s\n", replace(tempString, 't', 'z')); 
    printf("replacing them back: %s\n", replace(tempString, 'z', 't')); 

    printf("replacing all 'orary' with 'bonjour': %s\n", replaceAll(tempString, "orary", "bonjour")); 
    printf("replacing it back to normal: %s\n", replaceAll(tempString, "bonjour", "orary")); 

    printf("contains 'this': %d\n", contains(tempString, "this")); 
    printf("contains bonjour: %d\n", contains(tempString, "bonjour")); 

    char * trimIt = "            hello!            ";
    printf("pre trim: %s\n", trimIt); 
    printf("after trim: %s\n", trim(trimIt)); 

    char * tempString2 = "hello temporary"; 
    printf("[should be true] regionMatches 16-24: %d\n", regionMatches(tempString, 6, tempString2, 16, 24)); 
    printf("[should be false] regionMatches 2-4: %d\n", regionMatches(tempString, 0, tempString2, 2, 4)); 

    char * upper = "HELLO"; 
    char * lower = "hello"; 
    printf("does %s equal %s when ignoring case? -> %d\n", upper, lower, equalsIgnoreCase(upper, lower)); 



    char * intStringNeg = "-1234"; 
    char * intStringPos = "1234"; 

    printf("values: %s and %s, now using value of int + 1 for both: %d and %d\n", intStringNeg, intStringPos, valueOfInt(intStringNeg) + 1, valueOfInt(intStringPos) + 1);



    return 0; 
}