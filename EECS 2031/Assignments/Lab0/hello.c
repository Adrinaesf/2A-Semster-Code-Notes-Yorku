/***************************************
* Fall2026 – Lab0 *
* Author: Esfandiari, Adrina *
* EECS username: a2esfand *
* YorkuStudent#: 221277835
****************************************/

#include <stdio.h>

int main(){
    // Steps: 
    // 1. Saving a local variable for saving the num, double and triple. 
    // 2. Asking for a number + saving it
    // 3. Calculating the result and printing the answer. 

    int num; 

    printf("Please enter an integer number: "); 
    scanf("%d", &num); 

    int num_double = num * 2; 
    int num_triple = num * 3; 

    printf("Hi, you entered %d. Double and triple of %d is %d and %d, respectively.", num, num, num_double, num_triple); 
}