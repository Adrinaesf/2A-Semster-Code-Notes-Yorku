// ===================================
// ===================================
// Adrina Esfandiari
// Lab 0
// 221277835
// ===================================
// ===================================


/*
    C version of Hello program which asks for a number and then outputs the double 
    and triple of the number. Name the program hello.c

    Example: 
    Please enter an integer number: 23
    Output: Hi, you entered 23. Double and triple of 23 is 46 and 69, respectively.
    
    hello.c: void -> void

*/

#include <stdio.h>

int main(void){
    int num; 

    printf("Please enter an integer number: ");
    scanf("%d", &num); 

    int num_double = num * 2; 
    int num_triple = num * 3; 

    printf("Hi, you entered %d. Double and triple of %d is %d and %d, respectively.", num, num, num_double, num_triple); 


}