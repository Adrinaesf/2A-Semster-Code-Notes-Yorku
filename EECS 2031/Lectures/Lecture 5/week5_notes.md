# Functions: 
The outline: 
1. Define and call functions
2. Pass-by-value and modifying variables
3. Global, local, and static variables
4. Arrays as function arguments
5. Multiple source files

# Define and call functions: 
* The syntax: 

    return_type function_name(parameters)
    {
        declarations;
        statements;
        return value;
    }

* Function prototype: returnType name(args); 
    * We use this for declaring the functions.  

* Use return value; to return a value.
* Use void when the function does not return a value.

# Communication between functions:
Two main ways for functions to communicate:
1. Through arguments and return values.
- Arguments and return values: when a function should operate on explicit inputs and return a result.
2. Through external (global) variables.
- Global variables: when several functions need to share program-wide state, although excessive use makes programs harder to maintain and debug.

# Multiple source files: `.c`, `.h`, and `extern`
The three-file structure: 
1. Header file: Contains the function prototype.

    #ifndef SUM_H
    #define SUM_H

    int sum(int a, int b);

    #endif

2. Function definition: Contains the code + `include "header_file_name"`

    #include "sum.h"

    int sum(int a, int b)
    {
        return a + b;
    }

3. Function caller: main.c — Function caller

    #include <stdio.h>
    #include "sum.h"

    int main(void)
    {
        printf("%d\n", sum(2, 3));
        return 0;
    }

* Compile the files all together: 
`gcc main.c sum.c -o program`


# Header guards
The coding structure: 
    #ifndef SUM_H
    #define SUM_H

    int sum(int a, int b);

    #endif

- `#ifndef SUM_H`: Checks whether SUM_H has not been defined.
- `#define SUM_H` Defines the macro.
- `#endif` Ends the conditional section.

* **Question:** Can you use a global variable defined in another file? How?
extern declares that a variable or function is defined elsewhere. 
* Example: if result is defined in globals.c: `int result = 0;`

Another file can access it using: `extern int result;`. This declaration does not create a second global variable. It refers to the existing definition.

But this can cause to problems if we don't use the header file. In header file you only define it for one time. And you cna also change it one time if you add a new paramter. But now imagin we have fileA.c, fileB.c and a lot more that all of them use the extern int result in each file. then if we make any changes to the result function then we have to change it in all these files which takes a lot of time. 

(Read more about it on slide 25)

# Pass-by-value versus pass-by-reference: 
* Pass-by-value: In C, ordinary function arguments are passed by value. This means the function receives a copy of the argument's value. 
(READ MORE ABOUT IT ON)


