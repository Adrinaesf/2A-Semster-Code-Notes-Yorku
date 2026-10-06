/***************************************
* Lab02 *
* Author: Esfandiari, Adrina *
* EECS/Prism username: a2esfand *
* Yorku Student #: 221277835 *
* Email: a2esfand@my.yorku.ca *
****************************************/

#include <stdio.h>
#include <stdlib.h>   

#define SIZE 14

/*
    In Lab 2B, we made our own version of atoi(): my_atoi("2134")
    which converts a String containing decimal digits into the integer 2134.

*/

// function decleartions
int length(char word[]);
int isQuit(char word[]);
int my_atoi(char c[], int base);

int main()
{
    int a;
    int base;
    char arr[SIZE];

    // We read TWO things from the user:
    // 1. A string containing the number
    // 2. The base
    printf("Enter a word of positive number and base, or 'quit': ");
    scanf("%s %d", arr, &base);

    // if arr == quit -> end the loop
    while (!isQuit(arr))
    {
        printf("%s\n", arr);
        a = my_atoi(arr, base);
        
        printf("my_atoi: %d (%#o, %#X)\t%d\t%d\n",
               a, a, a, a * 2, a * a);

        printf("Enter a word of positive number and base, or 'quit': ");
        scanf("%s %d", arr, &base);
    }


    return 0;
}


/*
    my_atoi() converts a string representing a number
    in ANY BASE from 2 through 10 into its decimal integer value.

    Example: my_atoi("2134", 10) ->  2*10^3 + 1*10^2 + 3*10^1 + 4*10^0 = 2134
             my_atoi("122", 4) -> 1*4^2 + 2*4^1 + 2*4^0 = 122

    my_atoi: String (listof char), int -> int
*/
int my_atoi(char c[], int base)
{
    int result = 0;
    int i;
    int power = 1;
    int numDigit = 0; 

    i = length(c) - 1; // index starting from left most digit


    while (i >= 0) {
        numDigit = c[i] - '0'; // give the dumerical value of digit char
        result = result + numDigit * power;
        power = power * base;
        i--;
    }
    return result;
}