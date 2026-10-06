/***************************************
* Lab02 *
* Author: Esfandiari, Adrina *
* EECS/Prism username: a2esfand *
* Yorku Student #: 221277835 *
* Email: a2esfand@my.yorku.ca *
****************************************/

#include <stdio.h>
#include <string.h> // for strcpy, strcat, and strcmp

#define SIZE 35

// Function declaration for our version of strcat
void my_strcat(char des[], char src[]);

int main(){
   char a[SIZE];
   char b[SIZE];
   char c[SIZE];
   char d[SIZE];

   printf("Enter the first string(with no spaces) stored in array 'a': ");
   scanf("%s",a);

   printf("Enter the first string(with no spaces) stored in array 'b': ");
   scanf("%s",b);
   
   // Keep reading strings until both a and b are "xxx"
   while (!(strcmp(a, "xxx") == 0 && strcmp(b, "xxx") == 0)){
    
      // Make copies because strcat() and my_strcat() both modify the destination
      strcpy(c,a); 
      strcpy(d,b);

      // Compare the library strcat() with our own my_strcat()
      strcat(a,b);
      my_strcat(c,d);
      
      printf("Original function strcat(a,b) results:   %s\n", a); 
      printf("My function my_strcat(c,d) results: %s\n\n", c);

      // Take the next two inputs
      printf("Enter the first string(with no spaces) stored in array 'a': ");
      scanf("%s",a);

      printf("Enter the first string(with no spaces) stored in array 'b': ");
      scanf("%s",b);
   }

   return 0;
}

/*
    The library function: strcat(a, b) takes the string in b and 
    adds it to the END of a. We implement my_strcat(char a[], char b[])
    
    Example: a = "Hello", b = "World" --> strcat(a, b): "HelloWorld"     
    
    my_strcat: String (listof char), String (listof char) -> void
*/
void my_strcat(char des[], char src[]){
   int i = 0;
   int j = 0;

   // Find the end of the destination string
   // We stop when we reach its '\0'
   while (des[i] != '\0'){
      i++;
   }

   // Copy each character from src to the end of des
   while (src[j] != '\0'){
      des[i] = src[j];
      i++;
      j++;
   }

   // Add '\0' at the end so des remains a valid C string
   // and we add it ourselves because calling it from src might result in error
   des[i] = '\0';
}
