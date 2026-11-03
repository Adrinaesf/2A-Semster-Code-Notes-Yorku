/***************************************
* Lab04 *
* Author: Esfandiari, Adrina *
* EECS/Prism username: a2esfand *
* Yorku Student #: 221277835 *
* Email: a2esfnad@my.yorku.ca *
****************************************/
 
#include <stdio.h>
#include <stdlib.h>
 
struct ints
{
   int data1;
   int data2;
};
 
 
void processStruc (struct ints);
struct ints getSumDiff(int, int);
void printStruc(struct ints);
 
 
int main()
{
  struct ints a = {100,4};
  struct ints result;
  int i = 1;
  printf("Struct a before process: %d %d\n", a.data1, a.data2);
  processStruc(a);  // pass by value
  // display a's members again, no change
  printf("Struct a after  process: %d %d\n\n", a.data1, a.data2);
 
  // functions that return a struct, thus encapsulating multiple values
  /**********************************  */
  int num1, num2;
  printf("Enter two integers: ");
  scanf("%d %d", &num1, &num2); //Use scanf to enter two values
 
  // The conditions for the while loop were never specified so I assumed two
  // loop rotations given that there were only two in the sample output
  while ( i <= 2 ){
   // call getSumDiff() to calculate returns the sum and difference of the two argument integers, as struct results
   result = getSumDiff(num1, num2);
   // call printStruc () to output sum and diff;
   printStruc(result);
 
 
      if (i == 2) {
        return 0;
      }
   // prompt and read again
   i++;
   printf("\nEnter two integers: ");
   scanf("%d %d", &num1, &num2);
 
 }
return 0;
}
 
/* call/pass by value  */
void processStruc(struct ints x){
 
  x.data1 ++;
  x.data2 +=100;
}
 
struct ints getSumDiff(int a, int b){
  struct ints r;
  r.data1 = a + b;
  r.data2 = a - b;
  return r;
}
 
void printStruc (struct ints x){
  printf("Sum is: %d, Diff is %d\n", x.data1, x.data2);
}
