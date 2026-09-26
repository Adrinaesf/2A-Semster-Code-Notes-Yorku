# Lecture 4: Recursion
Last time we did: 
* MEmory and addresses in Java
* Java doc
* Junit
* Intro to recursion

## Recursion: 
* We have to think recursively. 
* Def: Recursion is the process of defining a problem in terms of itself. 
    * Num of char in string is: 1 + f(n-1) where f gives the number of character and n = size of string
    * Ex: length("ABCD") = length("ABC") + 1
* In recursion we have to progress towards the base case. 
* Usually recursion on smaller version of itself. 

* Ex: 
    * a x b = a + a x (b-1)
    * a^b = a x a^(b-1)
    * sum of n = n + f(n-1)
    * (Read more from the slides.)


* Why Recursion?
    * Solves problems more naturally than iteration
    * Tower of hi

* Steps in Recursion:
1. Base case
2. Recursive calls/cases

* Template:
if (Condition for base case){
    do something with no recursion, usually terminate
}


