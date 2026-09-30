import java.util.Arrays;

public class code_notes {

    public static int sum_leper(int[] a, int index) {
        if (index >= a.length) {
            return 0;
        } else {
            return a[index] + sum_leper(a, index + 1);
        }
    }

    public static int sum(int[] a) {
        return sum_leper(a, 0);
    }
    // Similar problems: how many even/odd, how many num of values
    public static int countThrees(int[] a) {
    if (a.length == 0) {
        return 0;
    } else {
        int[] subA = Arrays.copyOfRange(a, 1, a.length);

        if (a[0] == 3) {
            return 1 + countThrees(subA);
        } else {
            return 0 + countThrees(subA);
        }
    }
}

    public static void printIt(String s, int n){
        if (n == 0){
            return; 
        } else {
            System.out.println(s); 
            printIt(s, n-1); 
        }
    }


    public static void main(String[] args) {
        int[] a = {2, 4, 6, 8};
        int result = sum(a);
        System.out.println("Sum: " + result);
    }
}