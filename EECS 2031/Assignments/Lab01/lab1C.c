/***************************************
*Lab01: Problem C *
* Author: Adrina Esfandiari
* EECS/Prism username: a2esfand *
* Yorku Student #: 221277835 *
* Email: a2esfand@my.yorku.ca *
****************************************/

#include <stdio.h>
/*
    This progrma reads input from Standard input and outputs teh occurence count of digit 0-9 in the inputs. 

    Steps: 
    - we have to use getchar()
    - we have to have a loop and continue untill EOF
    - we have to keep track of other (non-digit char) which includes chars + blanks + \n
    - we have to also keep track of digit count. Define an array here if allowed. 
    - Use switch to add the values. 
    - we ahev to check if it's a digit (IsDIgit function) and we also need to save 
    the actual value of the digit in a value to use it for switch statments. 

    We are using getchar() and a loop to read characters:
        1. define int c for saving the char + saving the character + looping through it untill it's EOF
   
    We now need to check what the character ch is representing: can be either: 
        * ch =  

        3. Making functions as headers
        4. Define each function + code them
        5. Now we check the conditions and print the result at the end using a for loop

*/

// Step 3:
int isDigit(char ch); 

int main(){
    // Steps 1
    int c; 
    int other_count = 0; 
    int digit_count[10] = {0}; // making an array [0, 0, ..., 0]

    c = getchar(); 

    while (c != EOF){ // no end of file yet
        if (isDigit(c)){
            int char_value = c - '0'; 
            switch(char_value){
                case 0: 
                    digit_count[0]++; 
                    break; 
                case 1: 
                    digit_count[1]++; 
                    break;  
                case 2: 
                    digit_count[2]++; 
                    break;  
                case 3: 
                    digit_count[3]++; 
                    break; 
                case 4: 
                    digit_count[4]++; 
                    break; 
                case 5: 
                    digit_count[5]++; 
                    break; 
                case 6: 
                    digit_count[6]++; 
                    break;  
                case 7: 
                    digit_count[7]++; 
                    break; 
                case 8: 
                    digit_count[8]++; 
                    break; 
                case 9: 
                    digit_count[9]++; 
                    break;
            }

        } else {
            other_count++; 
        }
        c = getchar(); 
    }

    // Now we have to print out the result: 
    for (int i = 0; i < 10; i++){
        printf("%d: %d\n", i, digit_count[i]); 
    }
    printf("X: %d\n", other_count); 
    
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
