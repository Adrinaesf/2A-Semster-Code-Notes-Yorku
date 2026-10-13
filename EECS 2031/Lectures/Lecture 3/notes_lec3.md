# Lecture 3: Arrays and Number System
# 1. One-dimensional Arrays: 

## Array Initilization: 
* int a[10] = {1, 2, 3, 4}
* int a[10] = {0}; 
* int a[] = {1, 2, ..., 10}
* int a[10];


## Going through a loop: 

#define N 5

int a[N];
int i;

for (i = 0; i < N; i++) {

    a[i] = 0;

}

Reading values from input to fill the array: 

    for (i = 0; i < N; i++){

        scanf("%d", &a[i]); 

    }

* The & is needed because scanf needs the address of the integer where the input should be stored.

## Determining the Array Length: 

for (i = 0; i < sizeof(a) / sizeof(a[0]); i++) {

    a[i] = 0;

}

Here: 
* `sizeof(a)` is the total number of bytes occupied by the array.
* `sizeof(a[0])` is the number of bytes occupied by one element.
* Dividing them gives the number of elements.

# 2. Array initialization: 
* Initializing an array with values: `int a[5] = {10, 20, 30, 40, 50};`
* Initilizing with shorter length: `int a[5] = {10, 20};` 
    * Which is: `a = {10, 20, 0, 0, 0}`
* Initializing all elements to zero: `int a[10] = {0};`
* Initilizing longer than length: `int a[2] = {10, 20, 30};  // ERROR`
* You can let the compiler determine the length from the initializer. That is: 
    * `int a[] = {10, 20, 30, 40};`
* Designated initializers (C99): specifying particular indices 
    * `int a[10] = {[2] = 29, [5] = 7};`
    * which is: `{0, 0, 29, 0, 0, 7, 0, 0, 0, 0}`

**Question: What happens if you do not initialize an array?**
* Declaration Initial contents int a[5]; as an ordinary local variable --> 	garbage values (intermidiate values)
* static int a[5];	--> All zeros
* Global int a[5];	--> All zeros
* int a[5] = {0};  --> All zeros

**Common logical error:  accessing out of range array element --> C does not catch/detect this error.** We need a debugger. It results in **undefined behavior.** 

# 3. Multi-dimensional Arrays: 
* An array may have any number of dimensions.
* A two-dimensional array: 
    * `int m[5][9]; \\ 5 rows, 9 cols`
* Accessing values:  
    * `m[0][0] = 10;  // First row, first column`
    * `m[2][1] = 25;  // Third row, second column`

* Initiliing 2d arrays: 

        int m[2][3] = {

        {22, 44, 66},

        {97, 98, 99}

    };

* Traversing a 2D array: 

    int i, j;


    for (i = 0; i < 2; i++) {

        for (j = 0; j < 3; j++) {

            printf("%d ", m[i][j]);

        }

        printf("\n");

    }

**Exam reminder: For int m[R][C], the valid ranges are 0 through R-1 for rows and 0 through C-1 for columns.**



# 4. Strings in C
* A C string is a character array terminated by the null character `'\0'`.
* Consider: 
    * `char str[] = "abc";`
    * It contains four characters in memory:
    * `a + b + c + \0 = 4`
* Null marks the end of a C string.
* The empty string `""` consists of just `'\0'`.

## Declaring string variables
* Example: Suppose a string must hold up to 80 characters.

    #define STR_LEN 80

    char str[STR_LEN + 1];

* One element is reserved for the null terminator.
* If the array is larger than the initialized string:
    * `char date2[9] = "June 14";`
    * The string terminator is added, and the remaining array elements are also zero-initialized with `\0`.


**Solution: ``char str[] = "hello";``**

* Key difference of initilizing and inputting: 
* **The key: scanf("%s", userStr) replaces the beginning of the array but does not clear the rest of the array.** So if the value is smaller than length, when initilizing, the string will fill the rest with `\0` but `scanf` fill it with garbage. 

### Common mistake: 
* `char str[5] = "hello";`
* In here we have not putten enough space for null char. Failing to do may cause unpredictable results when the program is executed.

## Reading strings using `scanf`

    char str[20];

    scanf("%s", str);

* Notice that there is no `&` before str. For a character array, the array name is used directly here.
* Now consider the following code: 

    char str[20];

    scanf("%19s", str);

* `%s` reads a sequence of non-whitespace characters. 
* `19` limits the input to at most 19 characters.
* The remaining position is reserved for the terminating `\0`. 
    * So if we do `input = hello world`, the `scanf("%19s", str)` reads only `"hello"`. 
    * It stops when it encounters the space.

* `scanf` does not keep '\n' in the string. 

**Question: How do we read the whole thing?**
* Use fgets() instead.

    int main(void) {

        char str[20];

        fgets(str, sizeof(str), stdin);

        printf("%s", str);

        return 0;

    }

## Reading strings using `getchar()`
The important idea is to:
1. Read characters one at a time.
2. Stop when a newline is encountered.
3. Store only the characters that fit.
4. Append '\0' so the stored characters form a valid C string.

That is: 

    int ch; 
    int i = 0; 
    char str[11]; 

    while (s.getchar() != '\n'){
        if (i < 10){
            str[i++] = ch; 
        }
    }
    str[i] = '\0';

* The lecture uses an int variable for ch because getchar() returns an int, including the special value EOF.

## Iterating through a String Array with a Loop: 
* Go until we rech `s[i] == '\0'`: 

    int i = 0;

    while (str[i] != '\0') {

        printf("%c", str[i]);

        i++;

    }

* This is an important pattern because the actual string length may be shorter than the capacity of its character array.
* For example, char str[100] = "hello"; has capacity for 100 characters, but its string length is only five.
* Don't blindly print every array position as a character when your intention is to process the string. **Stop at the null terminator.**

# 5. String library functions
* Include the library: `#include <string.h>`

## `strlen`: find the string length: 
* strlen counts the characters before the first '\0'. It does not count the terminating null character.
* What happens when a char array doesn't have the null terminator? If a character array does not contain a null terminator, using strlen on it can read beyond the intended array.

## `strcpy`: copy a string

    char source[] = "hello";

    char dest[10];

    strcpy(dest, source);

* After the operation, dest contains "hello", including the terminating null character.
* Two mistakes: 
    1. Having the length of source more that dest
    * This can result in undefined behavoiur

    2. Copy one array to another using the assignment operator: `dest = source;`

## `strncpy`: copy a limited number of characters
* Syntax: `strncpy(dest, source, n);`
    * If the source is shorter than n, the destination is padded with null characters.
    * If the source has at least n characters, the function may fill all n positions without appending a terminating null character.

    * Example: 

        char message[10];

        strncpy(message, "ok", 4);

        The first three char is copied and rest with a null: so result is `o, k, \0, \0`


    * Example: 

        strncpy(message, "hello world", 5);

        **copies five characters, hello, without adding a null terminator. Do not assume strncpy always creates a valid C string.**

## `strcat`: append a string
    char message[20] = "hello";

    strcat(message, " world");

* The result is "hello world". 
* strcat starts at the destination's existing '\0', appends the source string, and copies the new terminating null character.
* The destination needs at least: `strlen(src) + strlen(dest) + 1`
    * Example: "hello" requires 5 characters, " world" requires 6, and the terminator requires 1 more. Therefore, 12 elements are needed.

## `strncat`: append a limited number of characters
    char message[20] = "abc";

    strncat(message, "123456789", 3);

* The resulting string is "abc123".
* strncat appends at most three characters from the source, then writes a terminating null character. 
* Ensure that the destination has room for the original string, the characters appended, and the terminator.

## `strcmp`: compare two strings
The function compares the strings character by character until it finds a difference or reaches the end.
* Results: 
    * 0 = The string are equal
        * Ex: `strcmp("abc", "abc") == 0 // Equal`
    * Positive value = str1 is lexicographically greater than str2
        * Ex: `strcmp("abe", "abd") > 0 // e > d`
    * Negative value = str1 is lexicographically smaller than str2
        * Ex: `strcmp("abc", "abd") < 0 // c < d`

* Checking equality: 

    if (strcmp(str1, str2) == 0) {

        printf("Equal\n");

    }

**Common mistake: str1 == str2 is not the standard way to compare the contents of two strings. It compares pointer values rather than performing a character-by-character string comparison.**

## `strchr`: find a character in a string
strchr looks for the first occurrence of the requested character.
* Syntax: `char *p = strchr(str, 'a');`

* If the character is found, it returns a pointer to that position.
* If the character is not found, it returns NULL.
* Matching is case-sensitive: 'A' and 'a' are different characters.

# 6. The `<math.h>` library
* Function: Purpose
* sin(x), cos(x), tan(x) --> Trigonometric functions
* asin(x), acos(x), atan(x) --> Inverse trigonometric functions
* exp(x) --> Computes \(e^x\)
* log(x) --> Natural logarithm
* log10(x) --> Base-10 logarithm
* pow(x, y) --> Computes \(x^y\)
* sqrt(x) --> Square root
* ceil(x) --> Rounds upward to an integer-valued result
* floor(x) --> Rounds downward to an integer-valued result

* some Unix environments require linking the math library using -lm
    * Ex: `gcc program.c -o program -lm`

# 7. The `assert` macro
The header: `#include <assert.h>`

    int x = 5;

    assert(x > 0);

    assert(x == 5);

* Both assertions pass.
* But `assert(x < 0);` fails and normally terminates the program, displaying information about the failed assertion.
* Use assert to check assumptions during development and debugging. It is not a replacement for validating user input.

# 8. Number systems
In any base, each digit represents a multiple of a power of that base.
* Decimal (Base 10): 
    * Base = 10
    * Valid digit = 0 to 9
    * Ex: `1479=1(10^3)+4(10^2)+7(10^1)+9(10^0)`

* Binary (Base 2): 
    * Base = 2 
    * Valid digit = 0, 1
    * Ex: `(1011)_2=1(2^3)+0(2^2)+1(2^1)+1(2^0)=11`

* Octal (Base 8): 
    * Base = 8
    * Valid digit: 0 to 7
    * Ex: `(675)_8 = 6 * (8^2) + 7 * (8^1) + 5 * (8^0)

* Hexadecimal	
    * Base = 16	
    * Valid digit = 0 through 9, A through F
    * The final slide warns that binary integer literals such as 0b1011 are not supported by every version of standard C. Some compilers support them as an extension, but you should not assume they are portable C syntax. Follow the C standard and compiler version used in your course.