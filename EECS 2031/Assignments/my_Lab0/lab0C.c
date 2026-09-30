/***************************************
* Fall2026 – Lab0 *
* Author: Esfandiari, Adrina *
* EECS username: a2esfand *
* YorkuStudent#: 221277835
****************************************/

#include <stdio.h>

void greet(int i){
  printf("Hello %d!\n", i);
}

/* function definition */
float sum (float i, float j){
   return i + j;             
}

// The problem is that they have to be defined before
// our main function since the program starts from the top to bottom when reading and compiling it. 

int main()
{  
   int a = 2011 + 20;
   greet(a);
   int b = 1015 - 3;
   greet(b);
   float x =2.2, y=3.3;
   float su= sum(x,y);
   printf( "%f + %f = %f\n", x,y, su);

   return 0;

}


