# Lecture 2: 
## PAckages:
* Question: How can you access a class from a package?
    * You have to do: Java.packageName.File
    * Ex: Java.util.ArrayList
    * However Strings are fine, and its becoause String is very funcemental and it is in **java.lang** and so there is no need to import this. 
    * The classes inside java.lang are essential for the Java Virtual Machine (JVM) to run any code.

* Two ways to import classes from packages:
    * ``import packagename.*; \\ for all classes in package``
    * ``import packagename.name; \\ for that class only``

* Question: We want to use File class defined in java.io. Which of the following are the valid ways to declare a reference of type File without confusing Java?
A. File f;
B. java.io.File f;
C. import java.io.*;
 File f;
D. import java.io.File;
 File f;
* Answer: B, C, D

## Types: 
* Set of values and valid operations can be performed in them
* int: + - * / % == != > < 
* String: ==, equal(), charAt(), indexOf()

* We have Primative and reference types. 
* Primative types: 
    * In Java the primitive types are the built-in numeric types and the type boolean. 

* Reference Types: 
    * Reference types include everything that is not primitive. 
    * Examples: Strings, Arrays, ArrayLists, User Defined (Book, Point, ...)
    * Classes: An implementation of the **Reference Types**, which provides a template for a set of values and operations
    * Objects: (instance of a class) – class blueprint used to make
        * Objects are the actual variables that each may take on a unique value and thus be operated on independently of other objects


## Java Operators and Precedence
* Postfix: i++ i--, and Prefix: ++i, --i
* Take note of the timing of the operations. 


## Memory:
* Primitive types (fixed allocation in memory) variable stores a value directly
* Reference types (dynamic allocation in memory)
    * memory allocated at runtime usually
    * reference stores a memory address initially (the location at which a newly instantiated object will reside in memory when allocated)

* Practice the Momry alicing with the lists. 

# Object aliasing and pass-by-value
## Static Methods:
* a method that is static is a per-class member
    * client does not need an object reference to invoke the method
    * client uses the class name to access the method
    * static methods are also called class methods

* Studied till slide 58. 


