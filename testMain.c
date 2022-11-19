//#include "string2.h"
#include <stdio.h>
#include "string2.h"




int main(void){
    char * tempString; //"hello this is a temporary string"; 
    tempString = malloc(sizeof(char) * 50); 
    strcpy(tempString, "hello this is a temporary string"); 


    char pali[100] = "racecar"; 
    printf("is palindrome for racecar: %d\n", isPalindrome(pali)); 


    char * empty = ""; 
    int length = 0; 
    for (int i = 0; tempString[i] != '\0'; i++){
        length++; 
    }
    
    printf("length of tempsTring is: %d\n", length);  
    printf("The tempstring is: %s\n", tempString);  

    
    
    substring(tempString, 1, 9);  
 
    printf("printing substring [index 1 to 8]: %s\n", tempString); 

    printf("now changing tempstring back to the original.\n"); 
    strcpy(tempString, "hello this is a temporary string"); 

    printf("before reverse: %s\n", tempString); 
    reverse(tempString); 

    printf("after revserse: %s\n", tempString); 

    printf("now changing tempString back to the original.\n"); 

    strcpy(tempString, "hellow this is a temporary string"); 

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
   // char * trimIt = "                   hello!                "; 
    char * trimIt = malloc(sizeof(char) * 100); 
    strcpy(trimIt, "                  hello!                    "); 
    printf("pre trim: %s\n", trimIt); 
    trim(trimIt); 
    printf("after trim: %s\n", trimIt); 

    free (trimIt); 

    char * one = "hello how are you"; 
    char * two = "yo yo yo hello how are you"; 
    printf("[should be true] regionMatches 16-24: %d\n", regionMatches(one, 9, two, 0, 6)); 
    printf("[should be false] regionMatches 2-4: %d\n", regionMatches(one, 0, two, 2, 4));   
   

    char * upper2 = "HELLO"; 
    char * lower2 = "hello"; 
    printf("does %s equal %s when ignoring case? -> %d\n", upper2, lower2, equalsIgnoreCase(upper2, lower2)); 
    

    char * intStringNeg = "-1234"; 
    char * intStringPos = "1234"; 
  
    printf("values: %s and %s, now using value of int + 1 for both: %d and %d\n", intStringNeg, intStringPos, valueOfInt(intStringNeg) + 1, valueOfInt(intStringPos) + 1);
    


    return 0; 
}