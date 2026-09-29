# Lecture 1-2
Outline: 
1. Arithmetic in C
2. #define
3. Operations on Characters
4. Control Structures(if-else, for loop, do-while, while)

# Arithmetic in C: 
* ``+, -, *, /, %``
* Example: z = pr mod q + w/x - y
* In C: z = ((p*r) % q) + ((w / x) - y)

# define directive: 
* Directive such as **#define and #include** are handeled by the **preprocessor**. A piece of software that edits C program prior to compilation. 
* Preprocessor makes C(or C++) unique among other programmin lang. 
* How it works? 
    * Preprocessor looks for **preprocessing directives**, which begins with a # char. 
    * Example: 
        * **#define directive**: It defines a *macro*, which is a name that represents something else such as constants, or small functions. 
        * The preprocessor responds to a #define directive by storing the name of the macro along with its definition.
        * When the macro is used later, the preprocessor “expands” the macro, replacing it by its defined value.

        * **#include directive**: Causes the contents of a specified file to be included in a program. 

## Example of #define directive
* Space and horizontal tabs between chars are allowed. 
* We use capital letters for the name of constants: 
* Directives can appear anywhere in a program, but #define and #include are at the beginning of a file. 
    * Example: 
    * `` #define LENGTH 10 ``
    * `` #define NEWLINE '\n'``
    * `` #define SQUARE(x) ((x) * (x))`` and we can use it by calling it. Example: ``SQUARE(5)``

* Common mistakes with define directives: 
1. Putting the = symbol in a macro definition: 
    * `` #define N = 100 /*** WRONG ***/ ``
2. Ending a macro definition with a semicolon: 
    * `` #define N 100; /*** WRONG ***/ ``

## Advantage of using #define: 
1. It makes programs easier to read. 
2. It makes programs easier to modify. 
3. It helps avoid inconsistencies and typographical errors. 

# Operation on Characters: 
* A char is represented by integers in C
* Example: 
* ``i = 'a'; /* i is now 97 */ ch = 65; /* ch is now 'A' */ ch = ch + 1; /* ch is now 'B' */ ch++; /* ch is now 'C' */ ‘E' -'B' //expression with value 69-66 = 3``
* Characters can be compared, just as numbers can. 
* An if statement that converts a lower-case letter to upper case: if ('a' <= ch && ch <= 'z') --> ch = ch - 'a' + 'A’;

* Advantages of having characters as numbers has advantages: 
1. Having a for loop going through the upper-case letters: ``for (ch='A'; ch <= 'Z'; ch++)

## getchar, putchar: 
Advantages: 
1. Using getchar and putchar (rather than
scanf and printf) saves execution time.
2. getchar and putchar are much simpler
than scanf and printf, which are
designed to read and write many kinds
of data in a variety of formats.
3. They have high speed because they are implemented as macros. 
4. getchar() has another advantage. Because it
returns the character that it reads, getchar
lends itself to various C idioms. 

* int getchar(void): 
    * To read one character at a time from the standard input. 
    * Returns the next input char each time it is called. 
    * Returns EOF when it encounters end of file. EOF: an int constant defined in <stdio.h>, value is -1.

* int putchar(int c):
    * Puts the character c on the standard output. 
    * It's like **printf("%c", c)**

## Operations on Characters: 
* isalpha(c) --> true if c = a-Z
* isdigit(c)
* isspace(c) --> true if white space or \n
* toupper(c) --> change to uppercase char
* tolower(c) --> change to lowercase char

## Difference of getchar and scanf: 
* scanf("%d", &i) reads the integer but leaves the newline from pressing Enter in the input buffer.
* If you immediately call getchar(), it may read that leftover newline instead of waiting for your intended character.
* This is why we need to be careful when mixing scanf() and getchar().

# Control Structures(if-else, for loop, do-while, while): 
Types of statments: 
1. Selection statments: if and switch
2. Iteration statments: while, do, for
3. Jump statments: break, continue, goto

## Decision Making: Equality and Relational Operators: 
* Relational: 
    * `` >, <, >=, <= ``
* Equality: 
    * `` ==, != ``

## Logical Operators: 
* Not: ``!``
* And: ``&&``
* Or: ``||``

* Bool data type
    * Keyword: ``Bool`` stores 0 or 1
    * 0 is false, and 1 is ture. 
    * Any non-zero value for bool is equevelant to 1. 
    * The <stdbool.h> header defines bool as a shorthand for the type _Bool, and true and false as named representations of 1 and 0. 
    * During preprocessing, the identifiers bool, true and false are replaced with _Bool, 1 and 0
    * **Look at example + Order of evaluation at page 29, 42**

## Selection Statments in C:
* **The conditional operator (? :) is C’s only ternary operator (3 operands)**
* Format: ``expr1? expr2 : expr3 ``
    * First operand is condition. 
    * expr2 happens if condition == true
    * expr3 happens as the else case.  

## If and switch statments: 
* we know if :)
* switch statments: 
    * switch(choice) {
        case 1: ...; break; 
        case 2: ...; break;
        case 3: ...; break;
        default: ...; break; 
    }
    choice can be: int, char, string

* Default is there if non of the cases happen. 

## break and continue: 
* ``break``: In a loop causes an immediate exit of the loop. 
* ``continue``: In a loop causes an immediate jump to the loop condition check. 
* break and continue can **sometimes** improve the readability of a loop.
* **See example page 36-37**

## Loops: 
1. ``while (x in condition) {...; change in x}``
2. ``do {...; change in x} while(x in condition);``
3. ``for(int i = 0; i <5 ; i++)``
* Infinite loop: ``for(;;) {...; break;}`` break is needed to avoid infinite loop: 

## Increment and Decrement: 
* prefix: 
    * ``++a``: increment by 1 for a --> then assign to new value. 
    * ``--a``: decrement by 1 of a --> then assign to new value. 

* Postfix: 
    * ``a++``: first assign value of a to new value --> then increment a by 1. 
    * ``a--``: first assign the value of a to new value --> then decrement by 1. 

* **See the example in page 41**

## Enumeration - User defined data type: 
* Enumerations are related constants that can be represented by meaningful names --> making the code more readable and maintainable.
* Examples: 
    * enum boolean ``{ NO, YES };``
    * enum colours ``{ black, white, red, blue, green };``
    * enum escapes ``{BELL = '\a', BACKSPACE = '\b', TAB = '\t', NEWLINE = '\n', VTAB = '\v', RETURN = '\r' };``
    * enum months ``{ JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };``
    * enum TvChannels ``{TC_CBS = 2, TC_NBC = 5, TC_ABC = 7}``

## Functions: 
* def: Series of statements that have been grouped together and given a name. Each function is essentially a small program, with its own declarations and statements.
* Advantages: 
    1. A program can be divided into small pieces that are easier to understand and modify.
    2. Avoid duplicating code
    3. A function that was originally part of one program can be reused in other programs

* Structure: 
    * ``return_type functionName(parameter type name, ……) {body block} ``

* **See the examples in page 45-49**














