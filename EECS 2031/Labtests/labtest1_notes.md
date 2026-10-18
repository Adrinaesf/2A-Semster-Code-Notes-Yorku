# Important Topics to Remember (Lecture 1-2)

## `scanf`
- In scanf we might do `scanf("%d, %d", &i, &j);` but the correct way to do this is `scanf("%d %d", &i, &j);`

## Operations on characters:
* isDigit: 

    int isDigit(char c){
        return (c >= '0' && c <= '9'); 
    }

* isLower

    int isLower(char c){
        return (c >= 'a' && c <= 'z'); 
    }

## getchar(), putchar()
* `getchar()` reads a char from input each time it is called, and if there is no input and we are at the end of file, it returns EOF (which is -1)

* `putchar(int c)` puts c in the stdout. It's like `printf("%c", c)`

- Expected questions: 
1. Count the char in a inputted message


## Conditional operator: (? :)
- Syntax: `condition ? pass_res : fail_res` 

## Switch statments: 
- Syntax:
    switch(choice) {
        case 1: ...; break; 
        case 2: ...; break;
        case 3: ...; break;
        default: ...; break; 
    }
    choice can be: int, char, string

- we can have two cases or more for the same result: 
    switch(choice) {
        case 1:
        case 2: 
            ...; 
            break; 

        case 3: 
            ...; 
            break;

        case 4: 
        case 5:
            ...; 
            break;

        default: 
            ...; 
            break; 
    }

## Enumeration: 
- Constants with meaningful names: 
    `enum months {JAN=1, FEB, ..., DEC}`
- Here we need to fill in `...` section, and the default num that they get is from 0 to len-1, but we can specify it ourselves and it will increase automatically, so as an example MAR = 3. 
    `enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t', NEWLINE = '\n', VTAB = '\v', RETURN = '\r' };`


# Lecture 3:

## Array initilizations: 
1. `int a[10];`, `int a[10] = {1, 2, 3, 0, 0, 1}`
2. `int a[101] = {[25] = 1, [50] = 1, [75] = 1, [100] = 1}` the rest are 0. 

## Mult dim array:
1. `int a[2][3];` two rows and 3 cols. 
2. `int a[2][3] = {{1, 1, 1}, {2, 2, 2}};` 

- **Potential question:** ask input to fill make their own matrix, by inputing the number of the rows and cols they want, then inputting the values in each index, and then printing it out like a matrix. 

## length of array: 
**IMPORTANT: C does not have a built in function to give the length of array**. 
So we need to do: 
    int length(int a[]){
        return sizeof(a) / sizeof(a[0]); 
    }

## Strings: 
### Declaring String Variables
* Example: Suppose a string must hold up to 80 characters.

    #define STR_LEN 80
    char str[STR_LEN + 1];

* One element is reserved for the null terminator.
* **Solution: ``char str[] = "hello";``**

### Reading Strings: 
1. If it's one word: Use `scanf`: 

        char str[20]; 
        printf("Enter a string: "); 
        scanf("19%s", str); 
        printf("%s\n", str);

2. If it's a sentence: Use `fgets()`

        char str[20]; 

        printf("Enter your message: ")
        fgets(str, sizeof(str), stdin); 

        printf("%s", str)

Another way you can consider is b using `getchar()`: 
        char str[n]; 
        int ch = 0; 
        int i = 0; 

        ch = getchar()
        while (ch != '\n'){
            if (i < n){
                str[i] = ch; 
                i++; 
            }
        }

        str[i] = '\0'
        rreturn str; 
        

Now str will have teh new line into it if you don't want it, you can simply write a loop: 
    
        int i = 0; 
        while(str[i] != '\n' || str[i] != '\0'){
            i++; 
        }
        str[i] = '\0\; 

Or another way to do it is by:
- `str[strcspn(str, "\n")] = '\0';`

### Iterating through String loop: 
1. Go until we rech `s[i] == '\0'`: 

    int i = 0;
    while (str[i] != '\0') {

        printf("%c", str[i]);

        i++;
    }

2. Just use a for loop and length function. We should note taht `sizeof(s) / sizeof(s[0])` will be total number of array elements, including '\0'. 

### String functions: 
(STUDY THEM FOR TEST)
1. `strnlen` returns the number of char and NOT including '\0'. 
    - Example: `char str[100] = UNICEF` -> `strlen(str) = 6`















