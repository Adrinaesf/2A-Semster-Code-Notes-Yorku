/***************************************
* Lab02 *
* Author: Esfandiari, Adrina *
* EECS/Prism username: a2esfand *
* Yorku Student #: 221277835 *
* Email: a2esfand@my.yorku.ca *
****************************************/

#include <stdio.h>
//What should be the MAX_SIZE here?
#define MAX_SIZE 21

int main() {

   char word[MAX_SIZE];
   char ch;

   char helloArr[]  = "helloWorld";
   printf("\"%s\" contains %d characters, but the size is %lu (bytes)\n", helloArr, length(helloArr), sizeof(helloArr));
   helloArr[5] = '\0'; helloArr[3]='X'; helloArr[7] ='Y';
   printf("\"%s\" contains %d characters, but the size is %lu (bytes)\n\n", helloArr, length(helloArr), sizeof(helloArr));


   /********** Fill in your code below **********/
   printf("Enter a word and a character separated by blank: ");
   scanf("%s %c", word, &ch);

   while (!isQuit(word)) {  
     // don't change these first two lines
      printf("Input word is \"");
      displayStr(word);
      
      printf("\"\n");
      printf("Length is %d\n", length(word));
      printf("Index of '%c' is %d\n", ch, indexOf(word, ch));
      printf("Occurrence of '%c' is %d\n", ch, occurrence(word, ch));

      printf("Enter a word and a character separated by blank: ");
      scanf("%s %c", word, &ch);

   }
   return 0;
}

//functions to implement
// Function to calculate the length of the string
int length(char word[]) {
   int i = 0; 
   while (word[i] != '\0'){
      i++; 
   }
   return i; 
}

// Function to find the index of the first occurrence of a character in a string
int indexOf(char word[], char c) {
   int i = 0;

   while (word[i] != '\0') {
      if (word[i] == c) {
         return i;
      }
      i++;
   }

   return -1;
}

// Function to count the number of occurrences of a character in a string
int occurrence(char word[], char c) {
   // count the number of occurences until the end of word: 
   int i = 0; 
   int count = 0; 

   while (word[i] != '\0'){
      if (word[i] == c){
         count++; 
      }
      i++; 
   }
   return count; 
}

// Function to cdisplay the string character by character
void displayStr(char word[]) {
   // we make a loop untill the char is \0 we execcute:
   int i = 0; 
   while (word[i] != '\0'){
      putchar(word[i]); 
      i++; 
   }

}

// Function to check if the input word is "quit"
// There is a flaw in this code. Find it and correct it . Submit the updated function in your submission
// The bug is that code before change would say "quite" is "quit" because it only checks the first four characters.
// so we also need to check the last char. 
int isQuit (char word[]) {
   int i;
   if (word[0]=='q' && word[1]=='u' && word[2]=='i' && word[3]=='t' && word[4] == '\0'){
      return 1; 
   }
   return 0;
}
