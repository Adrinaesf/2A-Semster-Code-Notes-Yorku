/***************************************
* Lab03 Problem 2 *
* Author: Esfandiari, Adrina *
* EECS/Prism username: a2esfand *
* Yorku Student #: 221277835 *
* Email: a2esfand@my.yorku.ca *
****************************************/

#include <stdio.h>

#define SIZE 16
void printBinary(short int);

/*counting digits*/

int main () {
    int c; 
    short flags = 0;
    printf("flags: ");
    printBinary(flags); 
    printf("\nEnter your input: ");

    while ((c = getchar()) != EOF){
        if (c >= '0' && c <= '9'){  // if c is a digit with numerical value n, turn on bit-n in flags
            
            // we can turn it on using bitwise or operation. 
            // we can do it using n | 2^(digit) 
            // example: n = 00000000 00000000
            // we want to turn the digit 4
            // so we do 00000000 00000000 | 000000000 00010000 
            // which is n | 2^4

            // another way is to make a mask and then do the | operation,
            // we can make the mask by doing 1 << 4 --> 0000 0001 will change to 0001 0000
            // and we can do flags | mask. 
            int digit = c - '0';
            int mask = 1 << digit;
            flags = flags | mask;

        } 
    }


    printf("\n\nflags: ");
    printBinary(flags); 
    printf("\n");

    // output occurences by checking the lower 10 bits one by one
    // hint: at least two approaches
    // you can use one of the idioms mentioned in pdf lab manual, or get hint 
    // from the function printBinary() listed below.

    for (int i = 0; i <= 9; i++) {
        // we have to check if the rightmost digit in flags is 1 or not. 

        // if it is 1 then we print yes, 
        // if it is 0 then we print no. 

        // we do bitwise & with flags
        // flags & 1 → checks the rightmost bit of n and gives us either 0 or 1.
        // example: n = 0010 1101  &  0000 0001  -> 0000 0001 = 1
        // now we have to shift n 1 to the right, so we do n >>= 1

        if (flags & 1){
            printf("%d: %s\n", i, "Yes");
        } else {
            printf("%d: %s\n", i, "No");
        }

        flags >>= 1; 
    }

    return 0;
} 


/*
    This function is used to outputs the binary representation of n. 
*/
void printBinary(short int n){
    //printf("binary: ");

    // it is counter for 15-0
    int cou = SIZE-1;

    // listof (16 zeros) that we need to update based on n, and print later. 
    int k[SIZE]={0}; 

    while (n && cou >=0) { 
        // check if n has 1 in its binary representation: 
        // if so change k[cou] = 1, and k[cou] = 0 otherwise. 

        // we do bitwise & with n
        // n & 1 → checks the rightmost bit of n and gives us either 0 or 1.
        // example: n = 0010 1101  &  0000 0001  -> 0000 0001 = 1
        // now we have to shift n 1 to the right, so we do n >>= 1

        if (n & 1){
            // check the rightmost digit
            k[cou] = 1; 
        } else {
            k[cou] = 0; 
        }

        n >>= 1; // shift
        cou--; // we need to fill the rest. 
    }
    
    for (int i=0; i< SIZE; i++) {
        // printing the result: 
        printf("%d", k[i]);

        if ((i+1) % 8 == 0) {
            // styling
            printf(" ");
        }
    }
}
