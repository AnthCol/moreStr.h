//#include "string2.h"
#include <stdio.h>
#include "string2.h"




int main(void){
    char * tempString = "hello this is a temporary string"; 
    char * empty = ""; 
    int length = 0; 
    for (int i = 0; tempString[i] != '\0'; i++){
        length++; 
    }
    
    printf("length of tempsTring is: %d\n", length);  
    printf("The tempstring is: %s\n", tempString);  
    
    
    char * sub = substring(tempString, 1, 9);  
 
    printf("printing substring [index 1 to 8]: %s\n", sub); 

    free (sub); 

    printf("Ends with z: %d\n", endsWith(tempString, "z")); 
    printf("Ends with g: %d\n", endsWith(tempString, "g")); 

    printf("Is Empty (tempstring): %d\n", isEmpty(tempString));  
    printf("Is Empty (empty string): %d\n", isEmpty(empty)); 

    printf("Starts with z: %d\n", startsWith(tempString, "z"));  
    printf("Starts with h: %d\n", startsWith(tempString, "h")); 

    printf("Index of 'this': %d\n", indexOf(tempString, "this")); 
    printf("lastIndex of 't': %d\n", lastIndexOf(tempString, "t")); 

    printf("contains 'this': %d\n", contains(tempString, "this")); 
    printf("contains bonjour: %d\n", contains(tempString, "bonjour")); 

  //  char * trimIt = "            hello!            ";
    char * trimIt = "hello!"; 
    printf("pre trim: %s\n", trimIt); 
    char * trimAfter = trim(trimIt); 
    printf("after trim: %s\n", trimAfter); 
    free(trimAfter); 

    char * tempString2 = "hello temporary"; 
    printf("[should be true] regionMatches 16-24: %d\n", regionMatches(tempString, 6, tempString2, 16, 24)); 
    printf("[should be false] regionMatches 2-4: %d\n", regionMatches(tempString, 0, tempString2, 2, 4));   
   

    char * upper2 = "HELLO"; 
    char * lower2 = "hello"; 
    printf("does %s equal %s when ignoring case? -> %d\n", upper2, lower2, equalsIgnoreCase(upper2, lower2)); 
    

    char * intStringNeg = "-1234"; 
    char * intStringPos = "1234"; 
  
    printf("values: %s and %s, now using value of int + 1 for both: %d and %d\n", intStringNeg, intStringPos, valueOfInt(intStringNeg) + 1, valueOfInt(intStringPos) + 1);
    


    return 0; 
}