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


* Documenting: 
    1. Start with the commenting. `` \** *\ ``. The first sentence of the documentation should be short summary of the method; this sentence appears in the constructor/method summary section. 
    2. Add your block tags: ``@param, @return, @throws, @author`` and more. 
    3. Post-condition: Add your `` @return `` tag and say what the function will return. 
    4. Pre-condition: Add your `` @pre `` to add your pre-condition of that method. 

**Read the slides 60-91 for java doc in Eclipse**

## JUnit: 
*  JUnit is a unit test framework in Java unittest module in Python. 
**Read the slides for testing + implement some test cases yourself**

**Studied up untill lecture slide 110, (done with the 17-Sep Slides)**