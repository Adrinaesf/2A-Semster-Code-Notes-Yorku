# Lab 4 Materials
Outline: 
1. 2D Array
2. Structures
3. Pointers
4. Passing Addresses to Functions

# Part A: 2D Array
* Declaration: 
    * `int numbers[row][col]; `

* String 2D array: 
    * A string in C is an array of characters ending with `\0`.
    
    char names[3][10] = {
        "Sarah",
        "John",
        "Alex"
    };

    int arr[3][2] = {
        {1, 2},
        {3, 4},
        {5, 6}
    };

* Size of array:
    * sizeof(arr) = MAXLINES * MAXCOLS * data_byte
    * Printing it: `printf("sizeof inputs: %lu\n", sizeof(inputs));`

* Reading strings to a 2D array: 
    * we use: `fgets()`
    * Input: "Hello World"
    * fgets(inputs[0], MAXCOLS, stdin);
    * fgets(): also saves the newline character


* Reading multiple rows: 

    char inputs[MAXLINES][MAXCOLS];
    int count = 0;
    while (count < MAXLINES) {
        printf("Enter string: ");
        fgets(inputs[count], MAXCOLS, stdin);
        /* Check whether the user entered xxx */
        count++;
    }


    if (strcmp(inputs[count], "xxx\n") == 0) {
        break;
    }



* Passing a 2D array to a function: 
`void print2D(char inputs[][50], int n);`
Why do we need to specify 50?

* Let's say we want to do: 
- `names[0] = names[1]`

- This is what we do: 
    char temp[20];
    strcpy(temp, names[0]);
    strcpy(names[0], names[1]);
    strcpy(names[1], temp);


# PartB: Structures
* Defenition: 
    * User-defined data-type that allows you to group multiple varaibles together. 
    * They can be different data types. 
    

* Decleration: 

        struct Student {
            int studentID;
            char name[30];
            double GPA;
        };

* Initilization of the objects: 

        struct Student s1;
        struct Student s2;

* Access the informations: 

        struct Student s1;
        s1.studentID = 12345;
        s1.GPA = 3.9;
        strcpy(s1.name, "Adrina");

**IMPORTANT:Structures can be assigned to each other**

        struct Student s1 = {12345, "Adrina", 3.9};
        struct Student s2;
        s2 = s1;

Now all the members of s1 are copied into s2.
**Changing a member of s2 does not change s1.**

* Structures and functions: 
    * You can pass a structure to a function just like you pass an integer or a double.

            void printStudent(struct Student s) {
                printf("%d\n", s.studentID);
                printf("%s\n", s.name);
                printf("%.2f\n", s.GPA);
            }

    * Structures are passed by **values** and not references. Example:
    ```c
        void changeStudent(struct Student s) {
            s.GPA = 2.0;
        }

        int main() {
            struct Student s1 = {12345, "Adrina", 3.9};

            changeStudent(s1);

            printf("%f", s1.GPA);

            return 0;
        }
    ```
    
    * This will print 3.9 since s1 is passed by value and not reference. 





