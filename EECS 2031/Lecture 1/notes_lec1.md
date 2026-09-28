# Lecture 0: C programming Langague
## Use of C language: 
* Operating Systems
* Embeded Systems
* Real-time systems
* Communication Systems

**Note:** The reason that C is in many areas is that they have in-buil constructions that give them the functionality to deal with both software and hardware, connects to memory, and embedded systems, and more. 

## Strengths of C:
* Efficiency -> Rn fast and in limited amount of memory
* Portability 
* Power
* Flexibility 
* **Integeration with UNIX**

## C programming Environment:
* Editors: VSCode 
* Preprocessor: Process the code and see if you have the required libraries for your functions, and modifies it to send it to compiler. 
* Compilers: Create object code and stores it on disk
* Linker: Links the object code with the libraries, craets an executable file and stores it in disk
* Loaders: Puts the program in the memory
* Execute: CPU -> Takes each instruction 


## include <studio.h> 
* #include tells the preprocessor to open a particular file and “include” its contents as part of the file being
compiled.
* Example: #include <stdio.h> instructs the preprocessor to open the file named stdio.h and bring its contents into the program.

## Compiling and Executing a C program: 
- A C-program are files ending with ``.c``
- Compiler: Gnu COmpiler Collection (gcc)
- gcc do the compilation, calls other programs to assemble the program, and then link it to an executable program. 

- To compile a C program we do: 
- ``gcc file_name`` --> ``a.out``
- This will make an executable file named **a.out**
- Sometimes we might have many programs, and if we keep running them, then a.out will have the last programmed that got compiled. 
- Solution: ``gcc hello.c -o hello``
- This will create an executable program specifically for our file, and we can also name it which in here is ``hello``/ 


## Primative Data Types and Sizes
* Primative data types: int, float, char
    * Integers data: are signed, so the leftmost bit is reserved for the sign. 
    * To make it unsigned, declare it to be ``unsigned.``
    * Ex: unsigned int x; (x is non-negative value)

    * Floating data type: 
    * It can be: float, double, long double. float is used when the amount of percision isn't critical, and use double if upi think it is. long double is rarly used. 
    * Ex: 5e-2, 6e+3, 5 * 10^-2, 6 * 10^3
    
* Derived date types: array, pointers, structure, union 

## Constants: 
* Can be written in decimal (base 10), octal (base 8), hexadecimal (base 16)
    * decimal digits: 0-9
    * octal digits: 0-7 + must begin with 0
    * hexadecimal: 0-9 + a-f + always begin with 0x

## Character Sets: 
* Has to be assigned in ''
* C treats characters as numbers: range[0000000, 1111111]
* Examples: 
    *  'a' = 97
    *  'A' = 65
    *  '0' = 48
    *  '' = 32

## Variables: 
* Temporarily storage locations. 
* Variable must have a type
* Syntax: type variableName = value; 
* Variables must be declared before they are used.

## Identifiers: 
* Names for variables, functions, macros, and are called identifiers. 
* Keywords can't be used for identifiers, since they have a special meaning for the compiler.
* must begin with a letter or an underscore. We can not have - in the name, but _ is allowed: get-char (wrong) but get_char (correct)
* C is case sesitive

## Assignment Operators: 
* += 
* -= 
* *=
* /= 
* %=

## Streams: 
* Input and output are performed with sequence of bytes called **streams**
* In input operations, the bytes are flow in main memory from a device: such as the screen, keyboard, and more. 
* In output operation, the bytes are flow from main memory to a dvice like the screen, printer and more. 

* When execution happens we have access to: 
1. standard input stream like keyboard
2. std output stream like screen
3. std error stream which is connected to the screen. 

## Formatting output with printf: 
* Every printf has **format control string** that describe the format: 
* How to do it? percent sign + conversion specifiers. 
* Integers: 
    * %d or %i --> use for printing integers
    * %hd --> prints as type short
    * %ld --> prints as type long
    * %o --> Prints the octal value of num
    * %u --> Prints the unsigned version of num
    * %x --> prints the hexadecimal of num with lowercase letters
    * %X --> prints the hexadecimal of num with uppercase letters

* Floats: 
    * %e --> prints the float point
    * %f --> it prints the float num with 6 digit s to riht of decimal point, 
    * %g --> prints with lowercase e + rounding
    * %G --> prints with uppercase E + rounding

* Characters: 
    * %c --> used for characters

* String: 
    * %s --> used for strings, char arrays: char string_list[],  char pointers and more. 

## The printf Function: 
* Compilers aren’t required to check that the number of conversion specifications in a format string. 
    * Example: printf("%d\n", i, j); /*** WRONG ***/
* If the programmer uses an incorrect specification, the program will produce meaningless output. 
* Printing With Field Widths and Precision can be done as below: 
    * %(flags)(width)(.precision)specifier
        * Example: 
        * %2d -> fills at least 2 character spaces and uses empty space in case of non. Like 5 -> " 5", 120 -> "120"
        * %8.4: fills at least 8 charcter spaces including the decimal seperator, with exactly 4 digits after .  

* **READ MORE ABOUT PRINTING LITERALS AND ESCAPE SEQUENCES**

## Scanf: 
* Input formatting with scanf is genrally like: 
* ``scanf (cormat-control-string, other-arguments)``
    * **format-control-string** describes the input formats +  **other-arguments** are pointers to variables in which inputs are stored

* **Read about the scanf conversion specifiers (slide 41 & 42)** 
* In general we have: 
* Integers: 
    * %d, i, o, u, x, X, h, l, ll
* Floats: 
    * %e, E, f, g, G, l, L
* Char and String: 
    * %c, s

* **See the example in slide 43**

## Common mistake: 
* Consider the following call of scanf: 
    * ``scanf("%d, %d", &i, &j);``
    * Scanf first inpu an integer and puts it in variable i. 
    * It then take the comma and puts it into j (which is wrong)
    * If the next input character is a space, not a comma, scanf will terminate without reading a value for j.
    * (check your understnading of this part again)

## Compiling and excuting a C program:
* Read through the slides but not a lot of info in general. 






