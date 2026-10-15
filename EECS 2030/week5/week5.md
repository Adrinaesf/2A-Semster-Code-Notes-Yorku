# Outline: 
1. Information hiding and encapsulation
Explain private fields, public methods, accessors, mutators, and why an internal representation can change without changing the API.

2. Constructors
Understand default, parameterized, and copy constructors, plus constructor chaining using this(...).


3. Immutability
Know the five rules, why String is immutable, how StringBuilder differs, and what final does and does not guarantee.


5. Class invariants
Define an invariant, identify valid and invalid states, and enforce the invariant in constructors and mutator methods.


6. Exceptions and preconditions
Recognize common exceptions, check arguments, and understand the difference between printing an error and throwing an exception.


7. throw and throws
Distinguish throwing an exception object from declaring that a method may pass an exception to its caller.


8. Call stack and propagation
Trace how Java searches for a handler from the method where an exception occurs back through its callers.


9. try-catch
Determine which statements execute, which are skipped, and how execution resumes after a handler.


10. Multiple catch blocks
Match exceptions to handlers, put specific types before general types, and identify unhandled exceptions.

11. Input loops and custom exceptions
Understand repeated prompting, boolean loop conditions, and defining a checked exception with extends Exception.


12. Checked and unchecked exceptions
Know which exceptions must be caught or declared.


13. finally
Trace execution when no exception occurs, an exception is caught, or an exception remains unhandled.

# Part 1: Information hiding and encapsulation
## 1. Encapsulation
Definition: Encapsulation means grouping data (fields) and the methods that operate on that data into one class, while controlling how other code accesses it.

Example: 

    public class Point2D {
        public double x;
        public double y;
    }

We can create and use a point:

    Point2D p = new Point2D();
    p.x = 3.0;
    p.y = 4.0;

* However, the fields are public, so any code can change them—even in ways we might not want.
* Ex: `p.x = -1000;`

Encapsulation allows us to improve the class by adding:
- Access modifiers to control access to fields.
- Constructors to initialize objects.
- Methods to perform calculations, such as calculating distance, rotating a point, or translating it.
- Standard methods such as toString() and equals() to represent and compare objects meaningfully.


## 2. Information hiding
Definition: Information hiding means hiding a class's internal implementation details behind a stable interface (API).

The two important terms are:
- Implementation: How the class actually stores and processes its data.
- Interface/API: The public methods that other code uses to interact with the class.

Example: Methods client can use:
    public double getX() {
        return x;
    }

    public void setY(double newY) {
        y = newY;
    }

    public void set(double newX, double newY) {
        x = newX;
        y = newY;
    }

    // Later client do: 
    p.set(3.0, 4.0);
    System.out.println(p.getX());   

The client interacts with the public interface, not the internal representation.

**Question: Why should fields be private?**
Consider: 
    private double x;
    private double y;

We can change the implementation of our methods, without changing their product. 

Example: 
    public float getX(){
        return this.x; 
    }

    public void setX(float newX){
        this.x = newX; 
    }

    // now we decide to use arraylist to save the coordinates. 
    ArrayList coord_x = new ArrayList<1>(); 

    public float getX(){
        return coord_x.get(0); 
    }

    public void setX(float newX){
        coord_x.set(0, newX); 
    }

**If the fields were public, clients might directly access p.x or p.y. Changing those fields into an array could break that client code. Information hiding avoids this dependency.**

## 3. Constructors and constructor chaining
    // default
    public Point2D() {
        this(0.0f, 0.0f);
    }

    // custom
    public Point2D(float newX, float newY) {
        this.x = newX;
        this.y = newY;
    }

`this(0.0f, 0.0f);` is called constructor chaining. It calls another constructor in the same class.

A copy constructor can be: 
    public Point2D(Point2D other) {
        this(other.x, other.y);
    }

# Part 2: Immutability
## 1. What is an immutable object?
Definition: An immutable object is an object whose state cannot be changed after it has been created.

Compare mutable and immutable objects:
    - Mutable: 
        - Its state can change after creation.
        - Mutator methods can modify its state.
        - Example: `StringBuilder`

    Immutable object:
        - Its state cannot change after creation.
        - Its public API does not allow its state to be modified.
        - Example: `String, Integer, Double, other wrapper...`

Advantages: 
1. Easier to design, implement, and use. Once an object has been created, you do not need to worry about its state changing unexpectedly.

2. Prevents inconsistent states after creation. Its state cannot later be changed into an invalid state through a mutator method.

3. References can be safely shared. If multiple parts of a program refer to the same immutable object, one cannot change that object's state and unexpectedly affect the others.

Coding example: 
    String myName = "EECS2030 section_C";

    myName.replace('o', 'x');
    myName.toLowerCase();

    System.out.println(myName);

Neither method changes the original string. The original value remains "EECS2030 section_C". This is becuase `String` is immutable, and it returns a new string. 
So we need to do `String newName = myName.toLowerCase();`

## 2. Recipe for immutability in Java
1. Do not provide methods that alter the object's state. Avoid mutators such as `SetX()`

2. Prevent the class from being extended. Declare the class `final`, so subclasses cannot add behavior that breaks the intended immutability.

3. Make all fields `final`. A field must be assigned its value during initialization and cannot subsequently be reassigned.

4. Make all fields `private`. Clients cannot directly access and change the fields.

5. Do not let clients obtain references to mutable internal fields. Returning a mutable internal object could allow clients to change its contents even if the field itself is final.

## 3. Making Point2D immutable
    public final class IPoint2D {
        private final float x;
        private final float y;

        public IPoint2D() {
            this(0.0f, 0.0f);
        }

        public IPoint2D(float newX, float newY) {
            this.x = newX;
            this.y = newY;
        }

        public IPoint2D(IPoint2D other) {
            this(other.x, other.y);
        }

        public float getX() {
            return this.x;
        }

        public float getY() {
            return this.y;
        }
    }

Important notes: 
* `final class` prevents inheritance.
* `private final fields` prevent direct access and reassignment.
* There are no setter methods.
* The constructors assign the initial coordinates.
* The getters allow clients to read the coordinates.

## 4. Two important cases for immutability:
*Case 1:* 
**`final` does not automatically make an object immutable.**
For example: 
    final StringBuilder text = new StringBuilder("Hello");

    text.append(" World");  // Allowed
    // text = new StringBuilder("Bye");  // Not allowed

Two things will happen: 
1. The variable text cannot be reassigned to another StringBuilder. BUT
2. The contents of its current object can still change.

That is why the fifth rule matters: an immutable class must protect any mutable objects stored inside it.

*Case 2:* 
Imagine in the IPoint2D we have:
    public void moveX() {
        this.x++;
    }

* This **cannot compile** because x is final. Once the constructor assigns x, the method cannot reassign it.
* To create a point with a different x-coordinate, you would create a new IPoint2D rather than modify the existing point.

# Part 3: Class invariants
Definition: A class invariant is a condition about an object's state that must always be true. (Sort of like the pre-conditions we have for functions and their variables, now for classes we call them as *class invariant*)

**Important:**
1. The invariant must be established when the object is created.
2. Every public method must preserve the invariant.
3. The invariant should be true both when a public method begins and when it finishes. Otherwise it crashes. 

Example: Suppose a Point2D object must always satisfy: `x >= 0, y >= 0`
    - Valid point: (3, 4)
    - Invalid point: (-2, 1)

## 1. Enforcing the invariant in constructors
Consider the constructor: 
    public Point2D(float newX, float newY) {
        if (newX < 0.0f) {
            throw new IllegalArgumentException(
                "x coordinate is negative");
        }

        if (newY < 0.0f) {
            throw new IllegalArgumentException(
                "y coordinate is negative");
        }

        this.x = newX;
        this.y = newY;
    }

Other constructors: 
* The lecture also shows a default constructor and a copy constructor. The default constructor creates (0,0), which satisfies the invariant. 
* A copy constructor can copy the coordinates of an already-valid point.

## 2. Enforcing the invariant in mutators
Suppose we have a setter:
    public void setX(float newX) {
        if (newX < 0.0f) {
            throw new IllegalArgumentException(
                "x coordinate is negative");
        }

        this.x = newX;
    }

    public void set(float newX, float newY) {
        if (newX < 0.0f || newY < 0.0f) {
            throw new IllegalArgumentException(
                "Coordinates must be non-negative");
        }

        this.x = newX;
        this.y = newY;
    }

The check happens **before** the assignment.
Example: 
    Point2D p = new Point2D(3, 4);
    p.setX(5);   // Allowed
    p.setX(-2);  // Exception

After the second call, assuming the exception is handled and execution continues, the x-coordinate remains 5.

## 3. The relationship between invariants and immutability
* A class invariant defines what must always be true.
* Immutability prevents the object's state from changing after construction.

For example:
- A point class with non-negative coordinates has the invariant `x >= 0, y >= 0`. 
- An immutable point class has the additional property that its coordinates cannot change after construction.
An immutable point with non-negative coordinates satisfies both properties.

# Part 4: Exceptions and testing
Definition: An exception is an event that occurs during program execution and disrupts the normal flow of instructions.

Exceptions can result from errors in our program or from external circumstances. Java uses exceptions to signal these abnormal conditions, and programs can catch and handle many of them.

Why do we need them? We cannot predict everything a user might do. So we need to take care of different cases. 

* Examples: 
    * Integer division by zero: `ArithmeticException`
    * Invalid array index: `ArrayIndexOutOfBoundsException`
    * Passing an invalid argument to a method: `IllegalArgumentException`
    * Parsing an invalid number string: `NumberFormatException`
    * Calling a method through a null reference: `NullPointerException`

Two approaches to handling invalid input:
1. Print an error and continue:
    class Circle {
        double radius;

        void setRadius(double r) {
            if (r < 0) {
                System.out.println("Invalid radius.");
            } else {
                radius = r;
            }
        }

        double getArea() {
            return radius * radius * Math.PI;
        }
    }

    // suppose we run: 
    Circle c = new Circle();
    c.setRadius(-10);

    double area = c.getArea();
    System.out.println("Area: " + area);

    // output:
    Invalid radius.
    Area: 0.0

This approach prevents the invalid assignment, but our function is not notified through the method's return value or an exception that the operation failed. 

2. Throw an exception:
    void setRadius(double r) {
        if (r < 0) {
            throw new IllegalArgumentException("Invalid radius");
        } else {
            radius = r;
        }
    }

    // So now if we do:
    Circle c = new Circle();
    c.setRadius(-10);

    double area = c.getArea();
    System.out.println("Area: " + area);

The setRadius(-10) call throws an exception. If nothing catches it, execution does not proceed to calculate and print the area. The exception propagates, and the program terminates if no suitable handler is found.

**Main difference: Printing an error is just displaying a message. Throwing an exception signals failure to the caller and allows the caller to handle it or pass it along.**

## 1. Caller, callee, and call stack
These terms explain where an exception goes.
- Caller: The method that calls another method.
- Callee: The method being called.
- Call stack: The chain of active method calls.

Example:
    class CircleCalculator {
        public static void main(String[] args) {
            Circle c = new Circle();
            c.setRadius(-10);
        }
    }

Here:
- main() is the caller.
- setRadius() is the callee.

If `setRadius()` throws an exception, Java first looks for a suitable handler in the method where the exception occurred. 
If there is none, the exception can go back to the caller, then to its caller, and so on.
    - Example: `BankApplication.main() → Bank.withdrawFrom() → Account.withdraw()`

## 2. How Java processes a thrown exception?
Steps: 
1. An error occurs: For example, an invalid radius is passed to a method.
2. An exception object is created and thrown: It contains information about the type of error and its message.
3. Java searches for a handler: The search starts where the exception occurred, then moves up the call stack.
    - Handler found: The matching catch block handles the exception, and execution continues after the try-catch structure.
    - No handler found: The exception remains unhandled, and the program terminates.

The `throw` keyword:
* Definition: throw is used to explicitly throw an exception object.
* Syntax: 
    * `throw new IllegalArgumentException("Invalid radius");`
    * throwing an object:
        IllegalArgumentException ex = new IllegalArgumentException("Invalid radius");

        throw ex;

Both approaches throw an exception of the same type.

Examples: 
- Division by zero: 

    - `int result = 100 / 0;` 
    - throws an `ArithmeticException`

- Invalid array index:

    `int[] data = {7, 3, 5, 6, 8, 9};`
    `System.out.println(data[-10]);`

    - This throws an `ArrayIndexOutOfBoundsException`

- Invalid integer parsing:

    `int n = Integer.parseInt("3.56");`

    - This throws a `NumberFormatException` because "3.56" is not a valid representation of an integer for parseInt().

- Uninitialized reference: 

    Point2D p = null;
    p.getX();

    - This throws a `NullPointerException`, because p does not refer to an actual Point2D object.

## 3. `throws`: passing responsibility to the caller:
Rule: “Catch or Specify.”

When a method may throw an exception, responsibility for dealing with it can be handled in two main ways:
1. Catch and handle the exception.
2. Specify the exception with throws, allowing responsibility to be passed to the caller.

Example: 
    void withdrawFrom(int id, double amount)
            throws IllegalArgumentException {
        // Method body
    }

Compare the keywords:
* `throw`: Actually thowing an exception
* `throws`: Declares exceptions that a method may pass to its caller.

Example: 
    void setRadius(double r) {
        if (r < 0) {
            throw new IllegalArgumentException("Invalid radius");
        }
    }

Or we have: 
    void readData() throws IOException {
        // Code that might throw IOException
    }

**Checked versus unchecked exceptions**
* Checked exceptions: Java requires them to be caught or declared with throws in the applicable method context. `IOException` is an example.
    * For a checked exception, the compiler requires the method to catch it or declare it appropriately.

* Unchecked exceptions: Java does not require them to be caught or declared. Examples include `IllegalArgumentException, NullPointerException, and ArithmeticException.`
    * For an unchecked exception, a programmer can choose to let it propagate to the JVM.

## 4. Catching exceptions with `try-catch`
Definition: A `try-catch` statement lets a program detect a thrown exception and execute code to handle it.

General structure: 
    try {
        // Statements that might throw an exception
    }
    catch (ExceptionType ex) {
        // Code that handles the exception
    }

The variable ex refers to the exception object.

Example: 
    class CircleCalculator {
        public static void main(String[] args) {
            Circle c = new Circle();

            try {
                c.setRadius(-10);
                double area = c.getArea();
                System.out.println("Area: " + area);
                c.expand(3.0);
            }
            catch (IllegalArgumentException e) {
                System.out.println(e);
                System.out.println("Please try again");
            }

            System.out.println("After try-catch");
        }
    }

How the program runs: 
    try {
        statement1;
        statement2;
        statement3;
    }
    catch (ExceptionType ex) {
        handleException();
    }

    statement4;

If none of the statements in the try block throws a matching exception:
- statement1, statement2, and statement3 execute.
- The catch block is skipped.
- statement4 executes.

If statement2 throws an exception of ExceptionType:
- statement1 executes.
- statement2 throws the exception.
- statement3 is skipped.
- The matching catch block executes.
- statement4 executes afterward.


## 5. Multiple catch blocks
A single `try block` can have multiple `catch blocks` to handle different kinds of exceptions.

    try {
        // Code that might throw exceptions
    }
    catch (FileNotFoundException e) {
        // Handle missing file
    }
    catch (IOException e) {
        // Handle other I/O errors
    }
    catch (Exception e) {
        // Handle other exceptions
    }

How does Java choose the correct one?
* Java checks the catch clauses in order and executes the first matching handler.
    * Suppose the code throws a FileNotFoundException. The first handler matches, so it executes.
    * If the code throws another kind of IOException, the first handler does not match, but the second one does.
    * If it throws an exception that matches none of the specific handlers but is covered by Exception, the last handler can catch it.

**Important: order matters**
A subclass of an exception is also an instance of its superclass.

For example, `FileNotFoundException` is a subclass of `IOException`. Therefore, this ordering is correct:

    catch (FileNotFoundException e) {
        // Handle specific exception
    }
    catch (IOException e) {
        // Handle general I/O exception
    }

But reversing them causes a compilation error. 

What if the exception matches none of the handlers?
If neither handler matches, neither catch block executes. The exception propagates to the caller, unless another suitable handler is found higher up the call stack.

Example: **Catching an array-index exception**
    
    int[] data = {7, 3, 5, 6, 8, 9};
    try {
        System.out.println(data[-10]);
    }
    catch (ArrayIndexOutOfBoundsException e) {
        System.out.println(e);
        System.out.println("Please try again");
    }

## 6. Using try-catch to keep prompting the user: 
One of the final examples combines exception handling with a loop. The goal is to keep asking the user for a radius until a valid one is provided.

    Scanner input = new Scanner(System.in);
    boolean validRadius = false;
    while (!validRadius) {
        System.out.println("Enter a radius:");
        double r = input.nextDouble();
        Circle c = new Circle();

        try {
            c.setRadius(r);
            validRadius = true; 

            System.out.println("Circle with radius " + r);
            System.out.println("has area: " + c.getArea());
        }
        catch (IllegalArgumentException e) {
            System.out.println("Try again!");
            
        }
    }
    System.out.println("Bye!");

## 7. Writing your own exception class
Sometimes the standard Java exception classes do not express the exact problem you want to represent.

Example: `NegativeRadiusException`

    public class NegativeRadiusException extends Exception {
        public NegativeRadiusException(String message) {
            super(message);
        }
    }

We can use it as: 

    void setRadius(double r) throws NegativeRadiusException {
        if (r < 0) {
            throw new NegativeRadiusException("Invalid radius");
        } else {
            radius = r;
        }
    }

# Part 5: Checked exceptions and finally: 
* Checked exceptions: 
    * Must be caught or declared with throws under Java's exception rules.
    * Usually represent conditions a program may need to recover from.
    * Example: `IOException`, `FileNotFoundException`, `SocketException`

* Unchecked: 
    * Do not have to be caught or declared.
    * Often represent programming errors or invalid operations.
    * Example: `IllegalArgumentException`, `NullPointerException`, `IllegalStateException`

For example: 
The following method does not have to declare `IllegalArgumentException` with `throws`:

    void setRadius(double r) {
        if (r < 0) {
            throw new IllegalArgumentException("Invalid radius");
        }
    }

**Even though the method explicitly throws an exception, it is not required to declare it because IllegalArgumentException is unchecked.**

## 1. The finally clause
Definition: A finally block contains code that normally runs after a try block and any applicable catch block, whether or not an exception occurred.

General structure:

    try {
        statement1;
        statement2;
    }
    catch (Exception e) {
        handleException();
    }
    finally {
        statement3;
    }
    statement4;

Three different cases that can happen: 
- Case A: No exception occurs
    Execution proceeds in this order:
    1. statement1
    2. statement2
    3. Skip the catch block.
    4. Execute statement3 in finally.
    5. Execute statement4.

- Case B: A matching exception is caught
    Suppose statement2 throws an exception that matches the catch block.
    1. statement1 executes.
    2. statement2 throws the exception.
    3. Remaining statements in the try block are skipped.
    4. The matching catch block executes.
    5. statement3 executes in finally.
    6. Execution continues to statement4.

- Case C: An exception is not caught
    Suppose statement2 throws an exception that does not match any catch block.
    1. statement1 executes.
    2. statement2 throws the exception.
    3. Remaining statements in the try block are skipped.
    4. No catch block handles the exception.
    5. The finally block normally executes.
    6. The exception continues propagating, so statement4 is not reached if the exception remains unhandled.

Why is finally useful?
It is commonly used for cleanup operations that should happen regardless of whether the main operation succeeds or fails.