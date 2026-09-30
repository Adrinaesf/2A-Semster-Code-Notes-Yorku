/***************************************
*Lab01: Problem 0*
* Author: Adrina Esfandiari
* EECS/Prism username: a2esfand *
* Yorku Student #: 221277835 *
* Email: a2esfand@my.yorku.ca *
****************************************/

#include <stdio.h> // define EOF

int main(){
  int c;
  int count = 0;
  int newL_count = 0; 
  int white_space = 0; 
 
  c = getchar();
  while(c != EOF)  /* no end-of-file yet */
  { 
    if (c == '\n'){
      newL_count++; 
      c = getchar(); // we need to read the next character before continuing.
      continue; // we don't need to increment count
    } 

    if (c == ' '){
      white_space++; 
      count++; // white space is part of count
    }
    
    count++;  

    c = getchar(); /* read next */
  }

  printf("# of chars: %d (# of blanks: %d)\n", count - white_space, white_space);
  printf("# of lines: %d", newL_count); 

}

