# EECS2030 Lab 4 — Java Study Notes

# Part A: Static Math Methods and Static Factory Methods

## 1. Static Methods

### Definition

A `static` method belongs to the **class itself**, rather than to an individual object.

You can call a static method using the class name without creating an object first.

### Example: Instance Method

```java
public class Circle {
    private double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    public double getRadius() {
        return this.radius;
    }
}
```

Calling the instance method requires an object:

```java
Circle c = new Circle(5.0);
double r = c.getRadius();
```

The method accesses the radius belonging to the particular `Circle` object.

### Example: Static Method

```java
public class Calculator {
    public static int square(int n) {
        return n * n;
    }
}
```

Call it using the class name:

```java
int result = Calculator.square(5);
```

Output:

```text
25
```

No `Calculator` object is needed.

### Instance Methods vs. Static Methods

| Instance Method | Static Method |
|---|---|
| Belongs to an individual object | Belongs to the class |
| Usually called using `object.method()` | Usually called using `Class.method()` |
| Can directly access instance fields | Cannot directly access instance fields without an object reference |
| Useful for operations involving an object's state | Useful for operations that do not depend on a particular object's state |

**When should you use `static`?**

Use `static` when an operation does not need the state of a particular object. Mathematical calculations are a common example.

A static method can still receive an object as a parameter and operate on it. It simply does not automatically have an instance of its own class.

---

## 2. Static Math Methods in Java

Java provides a built-in class called `Math`, which contains static methods for mathematical calculations.

You do not need to import `Math` or create a `Math` object.

### Important Math Methods

| Method or Constant | Meaning | Example | Result |
|---|---|---|---|
| `Math.sqrt(x)` | Square root | `Math.sqrt(25)` | `5.0` |
| `Math.pow(x, y)` | x raised to the power y | `Math.pow(2, 3)` | `8.0` |
| `Math.abs(x)` | Absolute value | `Math.abs(-7)` | `7` |
| `Math.max(a, b)` | Larger value | `Math.max(4, 9)` | `9` |
| `Math.min(a, b)` | Smaller value | `Math.min(4, 9)` | `4` |
| `Math.sin(x)` | Sine of an angle in radians | `Math.sin(0)` | `0.0` |
| `Math.cos(x)` | Cosine of an angle in radians | `Math.cos(0)` | `1.0` |
| `Math.PI` | Constant representing π | `Math.PI` | Approximately `3.14159` |

### Example 1: Pythagorean Theorem

The hypotenuse of a right triangle is:

\[
c = \sqrt{a^2 + b^2}
\]

Java:

```java
double c = Math.sqrt(
    Math.pow(3, 2) + Math.pow(4, 2)
);

System.out.println(c);
```

Output:

```text
5.0
```

You can also use multiplication instead of `Math.pow()`:

```java
double c = Math.sqrt(3 * 3 + 4 * 4);
```

Both versions work.

### Example 2: Create Your Own Static Math Method

```java
public class MathHelper {

    public static double distance(
            double x1, double y1,
            double x2, double y2) {

        double dx = x2 - x1;
        double dy = y2 - y1;

        return Math.sqrt(dx * dx + dy * dy);
    }
}
```

Calling it:

```java
double d = MathHelper.distance(1, 2, 4, 6);
```

Calculation:

- `dx = 4 - 1 = 3`
- `dy = 6 - 2 = 4`
- `distance = sqrt(3² + 4²) = 5`

The result is `5.0`.

The method is static because it calculates a distance from its arguments without needing the fields of a `MathHelper` object.

---

## 3. Degrees and Radians

This concept is useful when working with angles, directions, and graphics.

Java's `Math.sin()` and `Math.cos()` expect angles in **radians**, not degrees.

### Conversion Formula

\[
\text{radians} = \text{degrees} \times \frac{\pi}{180}
\]

Java provides a method for converting degrees to radians:

```java
double radians = Math.toRadians(90);
```

This gives approximately:

\[
\frac{\pi}{2} \approx 1.5708
\]

Then:

```java
double x = Math.cos(radians);
double y = Math.sin(radians);
```

The results are approximately:

```text
x = 0.0
y = 1.0
```

These values represent a direction pointing upward under the usual mathematical coordinate convention.

### Common Angles

| Angle | Direction |
|---|---|
| `0°` | Right |
| `90°` | Up |
| `180°` | Left |
| `270°` | Down |
| `360°` | Same direction as `0°` |

### Connection to the Firework Lab

The provided method:

```java
Vector2.dirVector(angle);
```

creates a direction vector from an angle expressed in degrees.

For example:

```java
Vector2 v = Vector2.dirVector(90);
```

The method is called using the class name, so it is a static method.

The supplied method handles the direction-vector calculation, so you do not need to manually convert the angle when using it.

---

## 4. Static Factory Methods

### Definition

A **static factory method** is a static method that creates or obtains an object and returns it to the caller.

The key difference from a typical static math method is the return value.

### Example: Static Math Method

```java
public static int square(int n) {
    return n * n;
}
```

This returns an integer.

### Example: Static Factory Method

```java
public static Circle createCircle(double radius) {
    return new Circle(radius);
}
```

This returns a `Circle` object.

### Example with a Private Constructor

```java
public class Circle {
    private double radius;

    private Circle(double radius) {
        this.radius = radius;
    }

    public static Circle createCircle(double radius) {
        Circle c = new Circle(radius);
        return c;
    }

    public double getRadius() {
        return this.radius;
    }
}
```

Calling the factory method:

```java
Circle c = Circle.createCircle(5.0);
```

### What Happens Step by Step?

1. Java calls `createCircle(5.0)` using the class name.
2. The method executes `new Circle(5.0)`.
3. A new `Circle` object is created and initialized.
4. The method returns a reference to that object.
5. The caller stores the returned reference in `c`.

You can then use the object:

```java
System.out.println(c.getRadius());
```

Output:

```text
5.0
```

### Why Make a Constructor Private?

A private constructor prevents code outside the class from directly calling that constructor.

For example, outside the `Circle` class, this is not allowed:

```java
Circle c = new Circle(5.0);
```

Instead, callers use the public factory method:

```java
Circle c = Circle.createCircle(5.0);
```

This allows the class to control how objects are created.

**Important:** A factory method does not always require a private constructor. A factory method can also exist alongside public constructors.

### Factory Methods vs. Constructors

| Constructor | Static Factory Method |
|---|---|
| Initializes a new object | Provides an object to the caller |
| Name must match the class name | Can have a descriptive name |
| Has no return type | Declares a return type |
| Called using `new` | Called using the class name |
| Cannot be declared `static` | Is declared `static` in this pattern |

A constructor has no return type, not even `void`.

A factory method explicitly declares its return type:

```java
public static Circle createCircle(double radius)
```

### Connection to the Firework Lab

Your starter code includes static factory methods such as:

```java
Firework.pearl(position, speed);
Firework.ring(position, speed);
```

For example:

```java
Firework f = Firework.pearl(position, 50.0);
```

The factory method creates the firework, initializes its particle list, creates the required particle or particles, and returns the `Firework` object.

Different factory methods create different types of fireworks.

- `pearl()` creates one particle.
- `ring()` creates 36 particles.

The caller does not need to construct and configure every particle manually.

### Important Distinction

A static factory method is not the same as a static object.

For example:

```java
public static Circle createCircle(double radius) {
    return new Circle(radius);
}
```

The method is static, but the `Circle` returned by it is an ordinary object.

---

# Part B: Aggregation and Composition

## 5. Object Relationships

Objects can contain references to other objects. This is often called a **has-a relationship**.

Example:

```java
public class Owner {
    private String name;
}
```

```java
public class OwnedPiggyBank {
    private Owner owner;
}
```

An `OwnedPiggyBank` has an `Owner`.

Compare this with inheritance:

```java
public class OwnedPiggyBank extends Owner {
}
```

This means an `OwnedPiggyBank` is an `Owner`, which is conceptually incorrect.

A piggy bank is not an owner. It has an owner.

### Three Important Relationships

| Relationship | Meaning | Example |
|---|---|---|
| Inheritance | IS-A | A dog is an animal |
| Aggregation | HAS-A, with an independently existing object | A bank has an owner |
| Composition | HAS-A, with strong ownership of a part | A bank owns its collection |

Aggregation and composition both involve objects referring to other objects. The main difference is the nature of the ownership relationship.

---

## 6. Aggregation

### Definition

**Aggregation** is a relationship where one object refers to another object, but the referred-to object can exist independently of it.

### Example: Owner and Piggy Bank

```java
Owner alice = new Owner("Alice");

OwnedPiggyBank bank = new OwnedPiggyBank(alice);
```

The `Owner` is created separately and passed to the bank's constructor.

A simplified constructor could be:

```java
public OwnedPiggyBank(Owner owner) {
    this.owner = owner;
}
```

The field:

```java
private Owner owner;
```

stores a reference to the supplied `Owner` object.

### Why Is This Aggregation?

The owner exists independently of the bank.

The same owner can be associated with multiple banks:

```java
Owner alice = new Owner("Alice");

OwnedPiggyBank bank1 = new OwnedPiggyBank(alice);
OwnedPiggyBank bank2 = new OwnedPiggyBank(alice);
```

Conceptually:

```text
           Owner: Alice
              /   \
             /     \
          bank1    bank2
```

Both banks can refer to the same owner object.

If one bank becomes unreachable, the other can still refer to Alice.

### Important Point: Reference Assignment

Consider:

```java
this.owner = owner;
```

This does not create a new `Owner`.

It assigns the supplied object reference to the field.

Both the caller's variable and the bank's field can refer to the same object.

Compare this with:

```java
this.owner = new Owner(owner.getName());
```

This would create a separate `Owner` object, assuming the shown method is available. It would not preserve the original owner reference.

**Rule to remember:** Assigning an object reference to a field does not create a copy of the object.

---

## 7. Composition

### Definition

**Composition** is a strong whole-part relationship. A whole owns a part, and the part is conceptually tied to the whole's lifecycle.

In the piggy bank example, the bank owns its collection of coins.

The field is:

```java
private ArrayList<Coin> coins;
```

This is a reference to an `ArrayList` object.

The constructor initializes the collection:

```java
this.coins = new ArrayList<Coin>();
```

The bank creates its own collection rather than receiving an existing collection from an external caller.

### Why Create a New Collection for Each Bank?

Consider:

```java
OwnedPiggyBank bank1 = new OwnedPiggyBank(alice);
OwnedPiggyBank bank2 = new OwnedPiggyBank(alice);
```

Each bank should have a separate collection.

Conceptually:

```text
bank1 ---> list1
            |-- coin references
            |-- coin references

bank2 ---> list2
            |-- coin references
            |-- coin references
```

If both banks accidentally shared the same list, changes to one bank's collection would also affect the collection seen by the other bank.

### Aggregation vs. Composition in the Lab

The documentation makes an important distinction:

- The bank has an **aggregation relationship** with its owner.
- The bank has a **composition relationship** with its collection.
- The individual coin objects are not owned by the bank in the same way as its collection.

The bank stores references to coin objects, but those coin objects can exist independently.

**Important:** The ownership relationship must be identified from the class's specification, not merely from the fact that one object refers to another.

---

## 8. Collection Objects vs. Elements

Consider the declaration:

```java
private ArrayList<Coin> coins;
```

There are two levels of objects:

1. The `ArrayList` object.
2. The individual `Coin` objects referenced by elements of the list.

The bank owns its collection, but the individual coins can exist independently.

For example:

```java
Coin penny = Coin.PENNY;

OwnedPiggyBank bank = new OwnedPiggyBank(alice);

List<Coin> coinsToAdd = new ArrayList<>();
coinsToAdd.add(penny);

bank.add(coinsToAdd);
```

The exact method call depends on the supplied API, but the important idea is that the same `Coin` object can be referenced from multiple places.

Conceptually:

```text
External variable: penny
          |
          v
      Coin object
          ^
          |
Bank's collection
```

Both the external variable and the bank's list may refer to the same coin object.

Java collections store object references, not independent copies of each object.

### Relationships in This Lab

| Relationship | Objects Involved | Reason |
|---|---|---|
| Aggregation | `OwnedPiggyBank` and `Owner` | The owner exists independently and is provided to the bank |
| Composition | `OwnedPiggyBank` and its `ArrayList<Coin>` | The bank creates and owns its collection |
| Independent coin objects | The individual `Coin` objects | The bank stores references but does not own the coin objects themselves |

---

# 9. Copy Constructors

### Definition

A **copy constructor** receives another object of the same class and initializes a new object based on it.

Your starter code includes a constructor with this signature:

```java
public OwnedPiggyBank(OwnedPiggyBank other)
```

According to its specification, the new bank should have the same owner and the same number and types of coins as the original bank.

If the original bank contains three coins, the copy should also contain three coins of the same types.

However, different copying approaches create different relationships between the original and the copy.

---

## 10. Shallow Copying

A shallow copy creates a new collection but reuses the existing element references.

Example:

```java
this.coins = new ArrayList<Coin>(other.coins);
```

This creates a new `ArrayList`, but the coin objects are not copied.

Conceptually:

```text
Original bank ---> List A ----+
                              |
                              +----> Coin 1
                              |
                              +----> Coin 2

Copied bank ----> List B ----+
```

The lists are different objects, but their elements refer to the same coins.

### What Happens?

If you add a coin to List A, List B does not automatically gain a new element because the lists are separate.

However, if a coin object has mutable state and you modify that shared object, both lists still reference the same changed object.

This is called a **shallow copy** of the collection.

---

## 11. Deep Copying

A deep copy creates a new collection and new copies of the contained objects, to the depth required by the specification.

Your `Coin` class provides a copy constructor:

```java
public Coin(Coin c) {
    this.value = c.value;
}
```

This creates a new `Coin` with the same value as the supplied coin.

Example:

```java
Coin original = Coin.DIME;
Coin copy = new Coin(original);
```

The objects `original` and `copy` are different objects, but both have a value of 10 cents.

### Creating a Deep Copy of a Collection

A conceptual implementation is:

```java
List<Coin> copy = new ArrayList<Coin>();

for (Coin c : this.coins) {
    copy.add(new Coin(c));
}
```

Step by step:

1. Create a new empty list.
2. Visit every coin in the original list.
3. Create a new coin object using its copy constructor.
4. Add the new coin to the new list.

The result contains a new collection and new coin objects.

### What About the Owner?

The copy-constructor specification says that the copied bank should have the **same owner**.

Therefore, it should retain the reference to the original owner rather than create another owner object.

The coins are copied, but the owner reference is shared.

### Shallow Copy vs. Deep Copy

| Feature | Shallow Copy | Deep Copy |
|---|---|---|
| New list? | Yes, if a new list is constructed | Yes |
| New coin objects? | No | Yes |
| Are the lists independent? | Yes | Yes |
| Are coin references shared? | Yes | No |
| Relevant to the lab? | Useful for understanding references | Required by the `deepCopy()` specification |

**Important:** The lab's `deepCopy()` method also requires the returned collection to contain coins in sorted order. Copying the coins is only one part of the requirement; sorting is another.

---

# 12. Summary: How to Recognize Each Concept

| Code Pattern | Concept | Explanation |
|---|---|---|
| `Math.sqrt(25)` | Static math method | Performs a calculation using the class |
| `Firework.pearl(position, 50)` | Static factory method | Returns a constructed `Firework` object |
| `private Owner owner;` | Aggregation in this lab | Refers to an independently existing owner |
| `private ArrayList<Coin> coins;` | Composition with the collection | The bank owns its collection object |
| `this.owner = owner;` | Reference assignment | The field refers to the supplied owner |
| `new ArrayList<Coin>()` | Collection creation | Creates a new list |
| `new ArrayList<Coin>(other.coins)` | Shallow copy | Creates a new list but reuses coin references |
| `new Coin(c)` | Copy constructor | Creates a new coin with the same value |
| Creating a new list and copying every coin | Deep copy | Creates a new list with new coin objects |

Remember that `static`, aggregation, and composition describe different concepts:

- **Static** describes a class member.
- **Aggregation** describes a relationship between objects that can exist independently.
- **Composition** describes a stronger whole-part ownership relationship.

A static method can create an object that participates in aggregation, composition, or neither.

---

# 13. Practice Questions

## Question 1: Static Methods

Given:

```java
public class Calculator {
    public static int doubleValue(int n) {
        return n * 2;
    }
}
```

Which expression is correct?

A. `Calculator.doubleValue(4)`

B. `new Calculator().doubleValue(4)`

C. `Calculator.doubleValue()`

**Answer:** A. A static method can be called through the class name and requires the argument `4`.

## Question 2: Factory Methods

Given:

```java
public static Circle create(double r) {
    return new Circle(r);
}
```

Why is `create()` a factory method?

A. Because it is named `create`.

B. Because it is static and returns a `Circle` object it constructs.

C. Because every static method creates an object.

**Answer:** B. A factory method provides an object to the caller. Not every static method creates an object.

## Question 3: Aggregation

Given:

```java
Owner alice = new Owner("Alice");
OwnedPiggyBank bank = new OwnedPiggyBank(alice);
```

Why is this aggregation?

**Answer:** The owner is created independently and passed into the bank. The bank holds a reference to the owner, who can exist independently of that bank.

## Question 4: Composition

Why should each bank create its own `ArrayList<Coin>` rather than use one shared static list?

**Answer:** Each bank should have its own collection. Otherwise, adding or removing coins through one bank could change the shared list seen by another bank.

## Question 5: Shallow Copying

Given:

```java
List<Coin> copy = new ArrayList<Coin>(original);
```

Is this a shallow copy or a deep copy?

**Answer:** A shallow copy. A new list is created, but the elements refer to the same coin objects.

## Question 6: Identify the Concept

Match each expression to its concept.

| Expression | Answer |
|---|---|
| `Math.sqrt(64)` | Static math method |
| `Firework.ring(position, 50)` | Static factory method |
| `this.owner = owner` | Reference assignment used for aggregation |
| `new ArrayList<Coin>()` | Creation of a collection owned by the bank |
| `new Coin(existingCoin)` | Coin copy constructor |

---

# Final Review

Before the lab, make sure you can explain these four ideas without looking at the notes:

1. **Static math methods:** Called using a class name, such as `Math.sqrt(25)`.
2. **Static factory methods:** Static methods that return objects, such as `Firework.pearl(position, speed)`.
3. **Aggregation:** One object holds a reference to another independently existing object, such as a piggy bank referring to its owner.
4. **Composition:** A strong whole-part relationship, such as a piggy bank owning its own collection.

Also understand the difference between a shallow copy and a deep copy. A shallow copy creates a new collection but shares element references. A deep copy creates new copies of the elements as well.

These concepts help you decide when to use a class method, when to create an object, when to retain an existing reference, and when to make independent copies.
