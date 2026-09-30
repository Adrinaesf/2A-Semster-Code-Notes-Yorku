/***************************************
*Lab01: Problem B *
* Author: Adrina Esfandiari
* EECS/Prism username: a2esfand *
* Yorku Student #: 221277835 *
* Email: a2esfand@my.yorku.ca *
****************************************/

#include <stdio.h>
/*
    This progrma reads input from Standard input and outputs duplicates of characters to the standard output 

    Steps: 
    We are using getchar() and a loop to read characters:
        1. define int c for saving the char + saving the character + looping through it untill it's EOF
   
    We now need to check what the character ch is representing: can be either: 
        * ch = lowercase letter (lower case function) -> Conver to upper case --> my_toupper()
        * ch = uppercase letter --> No change
        * ch = digit --> convert to - if digit < 5. convert to + if digit > 5, if digit == 5: no change. 
            * we need isDigit function + checing the value of ch by using ch - '0'  
            
        3. Making functions as headers
        4. Define each function + code them
        5. Now we check the conditions and print the result

*/

// Step 3:
int isDigit(char ch); 
int my_toupper(char ch); 
int my_islower(char ch); 

int main(){
    // Steps 1
    int c; 
    c = getchar(); 

    while (c != EOF){ // no end of file yet
        if (my_islower(c)){
            // converts it to upper case and display: 
            c = my_toupper(c);
            putchar(c); 

        } else if (isDigit(c)) {
            // no change if c == 5
            if ((c - '0') > 5){
                c = '+'; 
                putchar(c); 
            } else if ((c - '0') < 5){
                c = '-'; 
                putchar(c); 
            } else {
                putchar(c); 
            }
        } else {
            putchar(c);
        }

        c = getchar(); 
    }
    // Step 2
    
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
    It takes a lowercase letter ch, and change it to upper case; 

    Example: my_toupper('a') -> 'A' 

    isDigit: char -> int
*/
int my_toupper(char ch){
    return 'A' + ch - 'a'; 
}

/*
    Checks whether character ch is lower case letter or not. It returns 1 if it is, and 0 otherwise. 

    Example: islower('1') -> 0, islower('b') -> 1, islower('a') -> 1

    islower: char -> int
*/
int my_islower(char ch){
    if (ch >= 'a' && ch <= 'z'){
        // if it's a letter
        return 1; 
    }

    return 0; // return 0 otherwise
}
