#include <stdio.h>
#include "moreStr.h"

void test_substring(); 
void test_reverse(); 
void test_is_palindrome(); 
void test_contains(); 
void test_ends_with(); 
void test_equals_ignore_case(); 
void test_index_of(); 
void test_is_empty(); 
void test_last_index_of(); 
void test_starts_with(); 
void test_trim();
void test_region_matches(); 


int main(void){
    test_substring(); 
    // test_reverse(); 
    // test_is_palindrome(); 
    // test_contains(); 
    // test_ends_with(); 
    // test_equals_ignore_case(); 
    // test_index_of(); 
    // test_is_empty(); 
    // test_last_index_of(); 
    // test_starts_with(); 
    // test_trim();
    // test_region_matches(); 

    return 0; 
}


void test_substring(){

    int left = 5, right = 10; 
    char * s = malloc(20); 
    strcpy(s, "123456789_123456789"); 

    printf("Original string: \"%s\"\n", s); 
    
    substring(s, left, right); 

    printf("Substring from indices 5 -> 10\n"); 
    printf("\"%s\"\n", s); 

    free(s); 
    return; 
}
