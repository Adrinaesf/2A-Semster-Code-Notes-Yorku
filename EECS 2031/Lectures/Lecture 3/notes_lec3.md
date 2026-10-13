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