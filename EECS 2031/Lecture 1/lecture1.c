/*
    This is the first lecture and let's check if everything is good in our VSCode with 
    c programming language. 
*/ 
// ===================================
// ===================================
// Lecture 1: Intro to C programming language
// ===================================
// ===================================

/* Adds two fractions */
#include <stdio.h>


void user_addition_integer(void){
    // ok we have to save the two numbers and then add them adn print them: 

    int num1, num2; 

    printf("Enter the first number:"); 
    scanf("%d", &num1); 

    printf("Enter the first number:"); 
    scanf("%d", &num2); 

    int sum ; // variable in which sum will be stored
    sum = num1 + num2; // assign total to sum

    printf("Sum is %d\n", sum); // print sum

}

void user_addition_float(void){
    // Now these will have an address in the memory
	int num1, denom1, num2, denom2, result_num, result_denom; 
	
	printf("Enter first fraction: ");

    // &.... gets the memory address.  And %.... prints the value in that memory address. 
	scanf("%d/%d", &num1, &denom1);
	
	printf("Enter second fraction: ");
	scanf("%d/%d", &num2, &denom2);
	
	result_num = num1 * denom2 + num2 *denom1;
	result_denom = denom1 * denom2;
	printf("The sum is %d/%d\n",result_num, result_denom);

}

int main(void){
    // Now these will have an address in the memory
	user_addition_float();

}

// ---------------------------------------------------------------------


