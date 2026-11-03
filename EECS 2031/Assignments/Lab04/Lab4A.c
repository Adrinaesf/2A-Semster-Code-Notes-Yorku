/***************************************
* Lab04 *
* Author: Esfandiari, Adrina *
* EECS/Prism username: a2esfand *
* Yorku Student #: 221277835 *
* Email: a2esfnad@my.yorku.ca *
****************************************/
 
/* Reads in a list of strings from the keyboard, then re-organize them */
/* and then displays them on the screen. */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
#define MAX_LINES 34
#define MAX_COLS  54

 
void exchange2D(char p[][MAX_COLS], int n);
void print2D(char p[][MAX_COLS], int n);
 
int main()
{
    char inputs[MAX_LINES][MAX_COLS];
    char temp[MAX_COLS];
    int count = 0;
 
    printf("sizeof inputs: %d\n\n", (int) sizeof inputs);
 
    /* Read in the lines from the stdin (keyboard) now, using function fgets() */
    printf("Enter string: ");
    while (count < MAX_LINES && fgets(inputs[count], MAX_COLS, stdin) != NULL &&
           strcmp(inputs[count], "xxx\n") != 0 &&
           strcmp(inputs[count], "xxx") != 0)
    {
        count++;
        printf("Enter string: ");
    }
    printf("\n");
 
    printf("After while loop Count: %d\n", count);
 
    // displays the array by calling sub-function print2D(...)
    print2D(inputs, count);
 
    // swaps the first and second row here
    strcpy(temp, inputs[0]);
    strcpy(inputs[0], inputs[1]);
    strcpy(inputs[1], temp);
 
    // calls sub-function exchange2D() to swap some other rows
    exchange2D(inputs, count);
 
    printf("\n== After swapping ==\n");
 
    // displays the (exchanged array) by calling sub-function print2D()
    print2D(inputs, count);
 
    return 0;
}
 
 
// Exchange of rows. need to involve data movement
// Swaps row 2<->3, 4<->5, ... (first two rows are skipped); n = number of rows
void exchange2D(char p[][MAX_COLS], int n)
{
    char temp[MAX_COLS];
    int i;
 
    for (i = 2; i + 1 < n; i += 2)
    {
        strcpy(temp, p[i]);
        strcpy(p[i], p[i + 1]);
        strcpy(p[i + 1], temp);
    }
}
 
// output the 2D array, row by row
void print2D(char p[][MAX_COLS], int n)
{
    int i;
 
    for (i = 0; i < n; i++)
        printf("[%d]: %s", i, p[i]);
}
 
