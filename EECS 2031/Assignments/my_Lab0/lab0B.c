/***************************************
* Fall2026 – Lab0 *
* Author: Esfandiari, Adrina *
* EECS username: a2esfand *
* YorkuStudent#: 221277835
****************************************/

#include <stdio.h>

int main(){
    // Steps: 
    // 1. Read input int form of "%d %d %d" for mnth day year
    // 2. Print the different formats of 3 integers:
    //    Year/month/day and Year-month-day

    int month, day, year; 

    printf("Enter month, day and year separatedby spaces: "); 

    scanf("%d %d %d", &month, &day, &year); 

    printf("The input '%d %d %d' is reformatted as %d/%d/%d and %d-%d-%d", month, day, year, year, month, day, year, month, day); 




}