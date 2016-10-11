package recursion;

public class Recursion {
    public static void main(String args[]) {
        
        /**
         * Recursive calculation of factorial
         */
        Factorial f = new Factorial();
        System.out.println(f.fact(5));
        
        /**
         * Recursive output of first n Elements
         */
        RecTest arr = new RecTest(10);
        arr.load(10);
        arr.printArray(10);
    }
}
