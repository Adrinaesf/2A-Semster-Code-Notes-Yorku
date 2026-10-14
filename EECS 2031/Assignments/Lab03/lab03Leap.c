/***************************************
* Lab03 Problem 1 *
* Author: Esfandiari, Adrina *
* EECS/Prism username: a2esfand *
* Yorku Student #: 221277835 *
* Email: a2esfand@my.yorku.ca *
****************************************/

#include <stdio.h>


int isLeap(int year); 
int countDays(int month, int day, int isLeap); 



/*
    Main program: Reads an integer from standard input: (year, month, day)
    Then determines how many days has elapsed in the year. 

*/

int main(){
    int year; 
    int month; 
    int day;  

    printf("Enter date ('YYYY MM DD'): "); 
    scanf("%d %d %d", &year, &month, &day); 

    while (year > 0){
        // we first check whethere year is leap or not, 
        // then we pass that result in to our function countDays to find the number of days. 
        // print result at the end; 

        int isleap = isLeap(year); 
        int count = countDays(month, day, isleap); 

        if (isleap){
            printf("%d days of year %d have elapsed [leap year]\n", count, year); 
        } else {
            printf("%d days of year %d have elapsed\n", count, year); 
        }

        printf("\n"); // next line 
        printf("Enter date ('YYYY MM DD'): "); 
        scanf("%d %d %d", &year, &month, &day); // read again
    }
}


/*
    This function determines whethere year is a leap year or not. 
    Returns true (1) if it is and false (0) otherwise. 

    Rule: year is leap if year % 4 == 0 && year % 100 != 0 || year % 400 == 0

    Example: 
        isLeap(4) -> 1, 
        isLeap(100) -> 0, 
        isLeap(800) -> 1

    isLeap: int -> int
*/
int isLeap(int year){
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
        return 1; 
    }
    
    return 0; 
}

/*
    This function calculates how many days we have elapsed 
    since the start of the year, including the day. 
    Month and day are the current month and day we are in. The month starts from 1-12

        There are 31 days in: 
            - Jan Mar May Jul Aug Oct Dec

        There are 30 days in: 
            - Apr Jun Sep Nov

        if year = leap: 
            - feb = 29 day
        else: 
            - feb = 28 day
    
    Example: 
        countDays(10, 05, 1) -> 
        31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day=5 = 279 -> need to go through month 1 - 9 + days
        
    isLeap: int, int, int -> int
*/
int countDays(int month, int day, int isLeap){
    // We can create a list of integers, representing the number of days in each month
    // size(list) = 13, and for index 0 we define = 0, and we set feb = 0, since it is dependant on isLeap year. 

    int daysPerMonth[13] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 

    if (isLeap){
        // leap year -> feb = 29
        daysPerMonth[2] = 29; 
    } else {
        daysPerMonth[2] = 28; 
    }

    int counter = 0; 
    for (int i = 1; i < month; i++){
        counter += daysPerMonth[i]; 
    }
    counter += day; 

    return counter; 
}

