/*
 * public static ReturnType methodName(parameters) {

    // 1. BASE CASE
    // Stop the recursion
    if (baseCondition) {
        return baseValue;
    }

    // 2. RECURSIVE CASE
    // Make the problem smaller
    return something + methodName(smallerInput);
}
    ------------------------------------------------
    1. Template for Recursion That RETURNS a Value
    public static ReturnType method(parameters) {

        // BASE CASE
        if (baseCondition) {
            return baseValue;
        }

        // RECURSIVE CALL
        ReturnType recursiveResult = method(smallerProblem);

        // USE THE RECURSIVE RESULT
        return answerUsing(recursiveResult);
    }

    ------------------------------------------------
    2. Template for Recursion That DOESN'T Return Anything
    Sometimes you just want the recursive method to do something, like print.
    
    public static void recursiveMethod(int n) {
        // Base case
        if (n == 0) {
            return;
        }

        // Do something
        System.out.println(n);

        // Recursive call
        recursiveMethod(n - 1);
    }
    ------------------------------------------------
    3. Recursive Array Template
    With arrays, recursion often uses an index to keep track of where you are.
    public static ReturnType method(int[] arr, int index) {
        // Base case:
        // We reached the end of the array
        if (index == arr.length) {
            return BASE_VALUE;
        }

        // Recursive case:
        return SOMETHING_WITH(arr[index])
                + method(arr, index + 1);
    }
    ------------------------------------------------
    4. Array Recursion With a Helper Method
    This is a very common Java pattern because you usually don't want the person 
    calling your method to have to provide index = 0.

    public static ReturnType method(DataType input) {
        return helper(input, INITIAL_VALUE);
    }

    private static ReturnType helper(DataType input, int position) {

        // Base case
        if (BASE_CONDITION) {
            return BASE_VALUE;
        }

        // Recursive case
        return COMBINATION_OF_CURRENT_VALUE
                + helper(input, NEXT_POSITION);
    }
    ------------------------------------------------
    5. Recursive String Template
    Strings work similarly to arrays. (we use indexing)
    public static ReturnType method(String s, int index) {

        if (index == s.length()) {
            return BASE_VALUE;
        }

        char current = s.charAt(index);

        return SOMETHING + method(s, index + 1);
    }
    ------------------------------------------------
    6. Recursive Search Template
    A very common recursion question is:
        Does this array/string contain X?
    public static boolean search(int[] arr, int index, int target) {

        // Nothing left to search
        if (index == arr.length) {
            return false;
        }

        // Found it
        if (arr[index] == target) {
            return true;
        }

        // Search the rest
        return search(arr, index + 1, target);
    }
    ------------------------------------------------
    7. Recursive Linked-Structure Template
    Later, when you work with linked lists or trees, recursion becomes especially natural.
    For something like a linked node:

        public static int sum(Node node) {

        if (node == null) {
            return 0;
        }

        return node.value + sum(node.next);
    }
*/


// Type 1: General recursion
public static int sum(int n) {

    if (n == 0) {
        return 0;
    }

    return n + sum(n - 1);
}

//-------------------------------------------------
// Type 2: recursion with no return value
public static void countdown(int n) {

    if (n == 0) {
        System.out.println("Done!");
        return;
    }

    System.out.println(n);

    countdown(n - 1);
}
// ------------------------------------------------
// Type 3: recursion on lists
public static int sumArray(int[] arr, int index) {

    if (index == arr.length) {
        return 0;
    }

    return arr[index] + sumArray(arr, index + 1);
}
//-------------------------------------------------
// Type 4: Recursion on lists with helper functions
public static int sumArray(int[] arr) {
    return sumArrayHelper(arr, 0);
}

private static int sumArrayHelper(int[] arr, int index) {

    if (index == arr.length) {
        return 0;
    }

    return arr[index] + sumArrayHelper(arr, index + 1);
}
//-------------------------------------------------
// Type 5: Recursion on strings: 
public static int countA(String s, int index) {

    if (index == s.length()) {
        return 0;
    }

    if (s.charAt(index) == 'a') {
        return 1 + countA(s, index + 1);
    }

    return countA(s, index + 1);
}
//-------------------------------------------------
// Type 6: General ones. 
/* Our Template: 
    public static ReturnType method(parameters) {

    // 1. BASE CASE
    if (baseCondition) {
        return baseValue;
    }

    // 2. RECURSIVE CALL
    ReturnType recursiveResult = method(smallerProblem);

    // 3. USE THE RESULT
    return answerUsing(recursiveResult);
}
*/
// Find the second-largest element
public static int secondLargest(int[] arr, int index, int largest, int second) {

    // BASE CASE
    if (index == arr.length) {
        return second;
    }

    // Process current element
    if (arr[index] > largest) {
        second = largest;
        largest = arr[index];
    }
    else if (arr[index] > second && arr[index] != largest) {
        second = arr[index];
    }

    // RECURSIVE CALL
    return secondLargest(arr, index + 1, largest, second);
}
// *******************************************************
// Check whether an array is sorted











public static void main(String[] args) {
    // Entry point required for running this implicitly declared class.
    int[] arr = {7, 2, 15, 4, 11, 9};
    int answer = secondLargest(
        arr,
        0,
        Integer.MIN_VALUE,
        Integer.MIN_VALUE
    );

    System.out.println(answer); // 11
}