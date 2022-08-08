//#include "string2.h"
#include <stdio.h>
#include "string2.h"




int main(void){
    char * tempString = "hello this is a temporary string"; 
    char * number = "-1234"; 
    char * empty = ""; 
    int length = 0; 
    for (int i = 0; tempString[i] != '\0'; i++){
        length++; 
    }
    printf("length of tempsTring is: %d\n", length);  // 
    printf("The tempstring is: %s\n", tempString);  
    // for some reason the program exits at substring
    
  //  char * sub = substring(tempString, 1, 8);  // segfault
   
   // printf("printing substring [index 1 to 8]: %s\n", sub); 

    // resetting temporary string after substring modification. 
    printf("Ends with z: %d\n", endsWith(tempString, "z")); // working
    printf("Ends with g: %d\n", endsWith(tempString, "g")); 

    printf("Is Empty (tempstring): %d\n", isEmpty(tempString));  // working
    printf("Is Empty (empty string): %d\n", isEmpty(empty)); 

    printf("Starts with z: %d\n", startsWith(tempString, "z"));  // working
    printf("Starts with h: %d\n", startsWith(tempString, "h")); 

    char * upperCase = "HELLO THIS IS A TEMPORARY STRING"; 
   // printf("before: %s\n", upperCase); 
    //printf("after tolowercase: %s\n", toLowerCase(upperCase)); // seg fault
    //printf("after touppercase: %s\n", toUpperCase(upperCase)); // seg fault

    //printf("Index of 't': %d\n", indexOf(tempString, "t")); ????
    //printf("lastIndex of '5': %d\n", lastIndexOf(tempString, "t")); ???

   // printf("replacing the t's with z's: %s\n", replace(tempString, 't', 'z')); // seg
    //printf("replacing them back: %s\n", replace(tempString, 'z', 't'));  // seg

   // printf("replacing all 'orary' with 'bonjour': %s\n", replaceAll(tempString, "orary", "bonjour")); SEG
   // printf("replacing it back to normal: %s\n", replaceAll(tempString, "bonjour", "orary")); SEG

    printf("contains 'this': %d\n", contains(tempString, "this")); // working
    printf("contains bonjour: %d\n", contains(tempString, "bonjour"));  // working

    char * trimIt = "            hello!            ";
    printf("pre trim: %s\n", trimIt); 
   // printf("after trim: %s\n", trim(trimIt)); // segfault

    char * tempString2 = "hello temporary"; 
    printf("[should be true] regionMatches 16-24: %d\n", regionMatches(tempString, 6, tempString2, 16, 24)); 
    printf("[should be false] regionMatches 2-4: %d\n", regionMatches(tempString, 0, tempString2, 2, 4)); 
    // working
    
    char * upper = "HELLO"; 
    char * lower = "hello"; 
    printf("does %s equal %s when ignoring case? -> %d\n", upper, lower, equalsIgnoreCase(upper, lower)); 
    // working

    char * intStringNeg = "-1234"; 
    char * intStringPos = "1234"; 
  
    printf("values: %s and %s, now using value of int + 1 for both: %d and %d\n", intStringNeg, intStringPos, valueOfInt(intStringNeg) + 1, valueOfInt(intStringPos) + 1);
    // working


    return 0; 
}