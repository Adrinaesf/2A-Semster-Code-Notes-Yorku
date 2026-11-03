/***************************************
* Lab04 *
* Author: Esfandiari, Adrina *
* EECS/Prism username: a2esfand *
* Yorku Student #: 221277835 *
* Email: a2esfnad@my.yorku.ca *
****************************************/
 
#include <stdio.h>
 
void swap(int *, int *);
void swapIncres(int *, int *, int *);
 
int main( ) {
  int a, b,c;
 
  /* Read in three integers */
  printf(" Enter three values seperated by a blank: ");
  scanf("%d %d %d", &a, &b,&c);
 
  while(a != -1) {
     printf("Original inputs:   a:%-4d  b:%-4d  c:%-4d\n", a, b,c);
     swapIncres(&a,&b,&c);
     printf("Rearranged inputs: a:%-4d  b:%-4d  c:%-4d\n\n", a, b,c);
 
     /* to read again */
     printf(" Enter three values seperated by a blank: ");
     scanf("%d %d %d", &a, &b,&c);
   }
 
}
 
// swaps the values pointed to by x and y
void swap(int *x, int *y){
   int temp = *x;
   *x = *y;
   *y = temp;
}
 
// only increments/doubles; delegates the swapping to swap()
void swapIncres(int *x, int *y, int *z){
   swap(x, z);
 
   *x += 100;
   *y *= 2;
}
 
