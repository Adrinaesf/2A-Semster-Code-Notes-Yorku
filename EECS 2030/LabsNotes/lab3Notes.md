# Important notes for lab 3: 
## Question 1
- Completed but need review
## Question 2
- Completed but need review
## Question 3
- In here we are trying to implement the methods for the calss `BankAccount`, in another class called `SavingsAccount`. 
- So what we have to do is: 
    1. We first put all the interfaces we want for `BankAccount` in there and define it. So we have: 

        package part3_exceptions;
        public interface BankAccount {
            void withdrawATM(double ampount);
            void depositATM(double amount);
        }

    **Interface (BankAccount) = says what methods a bank account must have.**

    2. We implement them in the `SavingsAccount`: 

        class SavingsAccount implements BankAccount {
            private double balance = 0;

            public void depositATM(double amount) {
                balance += amount;
            }

            public void withdrawATM(double amount) {
                balance -= amount;
            }
        }

    **Implementation (SavingsAccount) = defines what those methods actually do.**

### Question: Why do we make interface instead of implementing the bankAccount class?
The easiest way to recognize when to use an interface is to ask yourself:

**“Do I have different types of objects that should all be able to do the same things, but might do them differently?”**

Examples:
1. Payment methods: Imagine you're building an online shopping app. 
Customers can pay using a credit card, PayPal, or a gift card.
    
    Interface: Payment
    Requires a pay(amount) method.
    - CreditCard
        Charges the customer's card.
    - PayPal
        Processes payment through PayPal.
    - GiftCard
        Deducts money from the gift card balance.

All three support pay(), but each implements it differently.

    interface Payment {
        void pay(double amount);
    }
    
    class CreditCard implements Payment {
        public void pay(double amount) {
            // Charge credit card
        }
    }
    class PayPal implements Payment {
        public void pay(double amount) {
            // Process PayPal payment
        }
    }

2. Animals that make sounds: Different animals can all make sounds, but the sounds differ.

    interface Animal {
        void makeSound();
    }

    class Dog implements Animal {
        public void makeSound() {
            System.out.println("Woof!");
        }
    }

    class Cat implements Animal {
        public void makeSound() {
            System.out.println("Meow!");
        }
    }

3. Shapes that calculate area: 
Different shapes can calculate their area, but each uses a different formula.
- An interface could require every shape to have a getArea() method.
- Circle: `pi x r^2`
- Rectangle: `w x h`
- Triangle: `1/2 x b x h`

4. Students and their degree requirements: 
Different programs have different degree requirements, but we want every program to provide a way to retrieve those requirements.

    interface StudentReq {
        String getReq();
    }
    class Science implements StudentReq {
        public String getReq() {
            return "Complete science courses and electives";
        }
    }
    class ComputerScience implements StudentReq {
        public String getReq() {
            return "Complete CS courses, math courses, and electives";
        }
    }

We could then write: 

    StudentReq s = new ComputerScience();
    System.out.println(s.getReq());
