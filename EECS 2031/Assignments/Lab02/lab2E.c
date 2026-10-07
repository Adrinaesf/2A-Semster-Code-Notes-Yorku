/***************************************
* Lab02 *
* Author: Esfandiari, Adrina *
* EECS/Prism username: a2esfand *
* Yorku Student #: 221277835 *
* Email: a2esfand@my.yorku.ca *
****************************************/

#include <stdio.h>
#include <string.h> // for strcmp()

#define SIZE 36

// Function declaration for our version of strcmp
int my_strcmp(char x[], char y[]);

int main(){
   char a[SIZE];
   char b[SIZE];
   
   printf("Enter the first string(with no spaces) stored in array 'a': ");
   scanf("%s",a);

   printf("Enter the first string(with no spaces) stored in array 'b': ");
   scanf("%s",b);
    
   // Keep reading until both strings are "xxx"
   while (!(strcmp(a, "xxx") == 0 && strcmp(b, "xxx") == 0)){
      
      // First compare the strings using the library strcmp()
      int result = strcmp(a,b); 

      // Negative means a comes before b
      if (result < 0) 
         printf("strcmp:   \"%s\" appears earlier in dictionary than \"%s\"\n", a,b);
      
      // Positive means a comes after b
      else if (result > 0) 
         printf("strcmp:   \"%s\" appears later in dictionary than \"%s\"\n", a,b);
      
      // Zero means both strings have the same content
      else 
         printf("\"%s\" and \"%s\" are same\n", a, b);
      
      
      // Now compare the same strings using our own function
      int result2 = my_strcmp(a,b);

      if (result2 < 0) 
         printf("mystrcmp: \"%s\" appears earlier in dictionary than \"%s\"\n\n", a,b);
      
      else if (result2 > 0) 
         printf("mystrcmp: \"%s\" appears later in dictionary than \"%s\"\n\n", a,b);
      
      else 
         printf("\"%s\" and \"%s\" are same \n", a,b);

      printf("\n"); 
      // Ask for the next two strings
      printf("Enter the first string(with no spaces) stored in array 'a': ");
      scanf("%s",a);

      printf("Enter the first string(with no spaces) stored in array 'b': ");
      scanf("%s",b);
   }

   return 0;
}


// Our version of strcmp()
int my_strcmp(char x[], char y[]){
   int i = 0;

   // Compare the strings character by character
   while (x[i] != '\0' && y[i] != '\0'){
      
      // The first different character determines the result
      if (x[i] != y[i]){
         return x[i] - y[i];
      }

      i++;
   }

   // If all compared characters were equal, this handles
   // equal strings or the case where one string is shorter
   return x[i] - y[i];
}