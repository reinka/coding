package recursion;

public class RecTest {
    int arr[];
    int size;
    
    RecTest(int i){
        arr = new int[i];
        size = i;
    }
    
    /**
     * Load array
     * @param   n   Range [n, 0[ of integers being loaded into array
     * @return      Loaded array
     */
    void load(int n) {
        if (n > size) {
            System.out.println("Warning: n is bigger than the initial size of the array."
                    + "\nArray has been expanded to size " + n + '.');
            arr = new int[n];
        }
        if(n == 0) {
            return;
        }
        load(n-1);
        arr[n-1] = n;
        
    }
    
    /**
     * Display array
     * @param   n Number of index up to which elements should be displayed 
     * @return    first n array elements 
     */
    void printArray(int n) {
        if(n == 0) return;
        printArray(n-1);
        System.out.println("[" + (n-1) + "] " + arr[n-1]);
    }
}
