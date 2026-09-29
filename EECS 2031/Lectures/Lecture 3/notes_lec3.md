# Lecture 3: Arrays and Number System
## One-dimensional Arrays: 

## Array subscripting: 
* Format: 
    * ``int a[10] = {0}``
* See the examples in code file. 

for (i = 0; i < N; i++){
    scanf("%d", &a[i])
}

## Array Initilization: 
* int a[10] = {1, 2, 3, 4}
* int a[10] = {0}; 
* int a[] = {1, 2, ..., 10}

## Static vs non-static arrays: 
* **STUDY ABOUT THEM SLIDE 6**
* static arrays: they keep the values that are being passed from a function to another. 
- They are only created once in the porgram. 
- There's two things about a data: lifetime and the scope. If we make another static array with the same name in another function, it will have the same memory as the one we had in the first function. 

* non-static will not preserve it and will chnage it t ogarbage values. 



## Iterating through arrays
* C don't perform bounds checking. 
* Bounds checking will produce bound time over head, which goes against the low level language of C. 
* Since C is used for being fast. 

## Multidimensional Arrays:
* **Look at the example slide 8-9**

## Strings or Chararcter array: 
* When you see a null characeter, it is the end of that string. 
* Example: char a[5] = "Hello" --> print(a): would give "Hell" --> becaus eit will take 4 data and save the last one for the null char. 
* so for length of string n, we need n+1 bytes of memory. 
* scanf("%s", a[i]) --> This would go to address of first element, but what about the ith element? (this is also a way to make a kist of string??)
* The name of array is a pointer to its first element address
* We have to explicitly maje the list, 

