/***************************************
* Lab04 *
* Author: Esfandiari, Adrina *
* EECS/Prism username: a2esfand *
* Yorku Student #: 221277835 *
* Email: a2esfnad@my.yorku.ca *
****************************************/
 
#include <stdio.h>
 
int main()
{
  int age = 10;
  int age2 = 100;
  int *ptr = &age;
  int *ptr2 = &age2;
 
  printf("age: %d %d\n", age, *ptr);
 
  *ptr = 14;
  printf("age: %d %d\n", age, *ptr);
 
  /* triple of age's value into age2, using only the pointers */
  *ptr2 = 3 * (*ptr);
  printf("age: %d %d\n", age2, *ptr2);
 
  /* ptr2 now points to age too, copied from ptr (no &age) */
  ptr2 = ptr;
  printf("ptr2's current pointee: %d\n", *ptr2);
  printf("age: %d %d %d\n", age, *ptr, *ptr2);
 
  /* decrease age by 1 through ptr2 */
  (*ptr2)--;
  printf("age: %d %d %d\n", age, *ptr, *ptr2);
  printf("ptr2's current pointee: %d\n", *ptr2);
 
  printf("%p %p %p\n", (void *)&age, (void *)ptr, (void *)ptr2);
 
  return 0;
}
 
