/***************************************
* Lab02 *
* Author: Esfandiari, Adrina *
* EECS/Prism username: a2esfand *
* Yorku Student #: 221277835 *
* Email: a2esfand@my.yorku.ca *
****************************************/

#include <stdio.h>
#include <stdlib.h>  // for atoi

#define SIZE 14
 
int main(){
  int a, b;
    char arr[SIZE];

    printf("Enter a word of positive number or 'quit': ");
    scanf("%s", arr);

    while (!isQuit(arr))
    {
        printf("%s\n", arr);

        a = atoi(arr);
        printf("atoi:    %d (%#o, %#X)\t%d\t%d\n",
               a, a, a, a * 2, a * a);

        b = my_atoi(arr);
        printf("my_atoi: %d (%#o, %#X)\t%d\t%d\n",
               b, b, b * 2, b * b);

        scanf("%s", arr);
    }

    return 0;

}

/* converts an array of (digit) characters into a decimal value*/

/* Here you should scan from RIGHT to LEFT. See the description of question inlab document */

int my_atoi (char c[]) {
    int result = 0;
    int i;
    int power = 1;

    i = length(c) - 1;

    while (i >= 0)
    {
        result = result + (c[i] - '0') * power;
        power = power * 10;
        i--;
    }

    return result;
}
