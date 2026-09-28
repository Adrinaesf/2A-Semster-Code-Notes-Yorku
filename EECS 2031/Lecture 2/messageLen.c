/**
 * This script will determine the length of the inputted message
 */
#include <stdio.h>

int main(){
    int len = 0; 
    printf("Enter ur message: "); 
    while(getchar() != '/n'){
        len++; 
    }
    printf("Your message was %d character(s) long. \n", len); 
}