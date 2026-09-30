/***************************************
*Lab01: Problem C2 *
* Author: Adrina Esfandiari
* EECS/Prism username: a2esfand *
* Yorku Student #: 221277835 *
* Email: a2esfand@my.yorku.ca *
****************************************/

#include <stdio.h>
/*
    This progrma generates array of random integers and then determines and display all even and prime number
    of the array.  

    Steps: 
    1. Define 2 arrays for even and prime numbers to save them
    2. The ideal size of them is 10, since it can be at most 10 element in each of them
    3. Loop through the array: 
        - if num is prime, add it to prime list --> need isPrime(int n)
        - if num is even, add it to even list --> is even is just n % 2 == 0
    4. Output the information: 
        - array: array [ 28 11 29 1 0 6 38 22 34 2 ]
        - even: <%d> even numbers: ... --> d = length of even_array
        - prime: <%d> prime numbers: ... --> d = length of prime_array
        
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int isPrime(int n); 

int main ()
{
  int i;
  int arr[SIZE];
  srand(time(0));
  for( i = 0; i<SIZE; i++){
    int ran = rand()%41 ;   // a random number that's in the range of [0,40] inclusive
    arr[i] = ran;
  }

  // display the array
  printf("array [ ");
  for (int i = 0; i < SIZE; i++){
    printf("%d ", arr[i]); 
  }
  printf("]\n"); 

  
  // creating two arrays for even and prime: 
  // we define them as -1, which means we have none in either of them for now
  int prime_num[SIZE] = {-1}; 
  int even_num[SIZE] = {-1}; 

  // we also need index_count for both of them so that we can change the 
  // variables based on that
  int prime_index = 0; 
  int even_index = 0;

  // Scanning the array: 
  for (int i = 0; i < 10; i++){

    if (isPrime(arr[i])){
        // if num is prime:
        prime_num[prime_index] = arr[i]; 
        prime_index++; 
    } else if (arr[i] % 2 == 0){
        // if num is even:
        even_num[even_index] = arr[i]; 
        even_index++; 
    }

  }

  // Now the number of the even numbers and primes are just simply:
  // prime_index, and even_index
  
  // output the even numbers
  printf("%d even numbers: ", even_index); 
  for (int i = 0; i < even_index; i++){
    if (i == even_index - 1) {
        // we have to go to the next line instead of blank after num
        printf("%d\n", even_num[i]); 
    } else {
        printf("%d ", even_num[i]); 
    }
  }

  // output the prime numbers
  printf("%d prime numbers: ", prime_index); 
  for (int i = 0; i < prime_index; i++){
    printf("%d ", prime_num[i]); 
  }

  
}

/*
    Checks whether integer n is prime or not. Return 1 if it's true, and 0 otherwise. 
    Example: isPrime(-2) -> 0, isPrime(1) -> 0, isPrime(43) -> 1
    isPrime: int -> int
*/
int isPrime(int n){
    // check n >= 2:
    if (n <= 1){
        return 0; 
    }

    for (int i = 1; i <= n; i++){
        if (i == 1 || i == n){
            continue; 
        } else {
            if (n % i == 0){
                // if num n is divisible by some other value other than 1 and the number
                // then it's not prime. 
                return 0; 
            }
        }
    }

    return 1; 
}


