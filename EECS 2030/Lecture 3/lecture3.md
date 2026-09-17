# Lecture 3:
**Summerize the materials in slides 52-72**
* Java is strictly pass-by-value!
* ava uses pass-by-value for all types (primitive and reference)
* The precise effect differs between whether a primitive type or a reference type is passed (i.e., aliasing?)
* Primative type:
    * for an argument of primitive type, value is passed (copied)
    * cannot be changed by a method
    * In C we can use pointer/address explicitly twice(&a)
* Reference Type:
    * for an argument of reference type (array, list, student etc,) reference/address is passed by value (copied). 
    * due to aliasing, can have its state changed by a method
    * effectively pass-by-reference

## Wrapper CLass: 
* A wrapper class in Java is a predefined class that encapsulates, or "wraps," a primitive data type into a standard Java object
* Because Java is not completely object-oriented (it relies on standard primitives like int and char for raw performance), wrapper classes provide a bridge to treat these fundamental values as objects when object-oriented features are required.
* Examples: 
    * boolean -> Boolean
    * byte -> Byte
    * char -> Character
    * float-> Float
    * int -> Integer

## JavaDoc:
* Deasign by contract: we need pre/post conditions and API documentations. 
    * Pre-conditions: a condition that the client must ensure is true immediately before a method is invoked. It's about the arguments. 

    * postcondition: a condition that the method must ensure is true immediately after the method is invoked. It's about the return value. 

    * Example: 
        * double div(double num, double denom): 
        - num be a double
        - denom be a double != 0

    