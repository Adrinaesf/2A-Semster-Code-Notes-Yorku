/***************************************
*Lab01: Problem A *
* Author: Adrina Esfandiari
* EECS/Prism username: a2esfand *
* Yorku Student #: 221277835 *
* Email: a2esfand@my.yorku.ca *
****************************************/

#include <stdio.h>
/*
    This progrma reads input from Standard input and outputs the processed information in the 
    Standard output. 

    Steps: 
    We know that the correct input is of the form of "int char2" and we need to save them
        1. defining 2 chars to input the values.  
    We need ask user to input the value: 
        2. printing the message + using scanf to save result
    We now need to check what the character ch is representing: can be either: 
        * ch = digit -> output: Character '<%c: c>' represents a digit. Sum of <%d:digit> and <%c: c> is <%d: digit + vallue(c>
        * ch = alphabet (a-z or A-Z (in ascii: 65-90 Or 97-122)) -> output: Character '<%c: c>' represent a letter
        * ch = other (else) -> output: Character '<%c: c>' represents others
    
        So we need 3 functions: isDigit(), isLetter() and isOperator(); Since they all return boolean, 
        and in C, 0 = false and 1 = true, they return int, and input char. 

        3. Making functions as headers
        4. Define each function + code them
        5. We now need to have a loop, and we use our digit for the condition. 
        6. Now we check teh conditions and print the result
    

*/

// Step 3:
int isDigit(char ch); 
int isLetter(char ch); 
int isOperator(char ch); 

int main(){
    // Steps 1
    int digit; 
    char ch; 

    // Step 2
    printf("Enter an integer and a character seperated by blank: "); 
    scanf("%d %c", &digit, &ch); 

    // Step 5:
    while (digit != -10000){
        // Steps 6:
        if (isDigit(ch)) {
            printf("Character '%c' represents a digit. Sum of %d and %c is %d", ch, digit, ch, digit + (ch - '0')); 
        } else if (isLetter(ch)) {
            printf("Character '%c' represent a letter", ch); 
        } else if (isOperator(ch)) {
            printf("Character '%c' represents others", ch);
        } else {
            printf("Character '%c' represents others", ch);
        }

        printf(""); // creates a new line to continue the loop: 
        printf("Enter an integer and a character seperated by blank: "); 
        scanf("%d %c", &digit, &ch); // Asking for input until input is not satisfied
    }


    return 0; 
}

/*
    Checks whether character ch is digit or not. It returns 1 if it is, and 0 otherwise. 

    Example: isDigit('1') -> 1, isDigit('b') -> 0

    isDigit: char -> int
*/
int isDigit(char ch){
    if (ch >= '0' && ch <= '9'){
        // if it's a digit return 1. 
        return 1; 
    }

    return 0; // return 0 otherwise
}

/*
    Checks whether character ch is letter alphabet or not. It returns 1 if it is, and 0 otherwise. 

    Example: isLetter('1') -> 0, isLetter('b') -> 1, isLetter('A') -> 1

    isDigit: char -> int
*/
int isLetter(char ch){
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
        // if it's a letter
        return 1; 
    }

    return 0; // return 0 otherwise
}

/*
    Checks whether character ch is one of five specific arithmetic operations

    Example: isDigit(' ') -> 0, isDigit('+') -> 1, isDigit('/') -> 1

    isDigit: char -> int
*/
int isOperator(char ch){
    // we use the other two functions. 
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%'){
        // if it's not a digit and not a letter then it's other 
        return 1; 
    }

    return 0; // return 0 otherwise
}
