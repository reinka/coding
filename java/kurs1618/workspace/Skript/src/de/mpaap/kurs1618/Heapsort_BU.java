package de.mpaap.kurs1618;

import java.util.Arrays;

public class Heapsort_BU {
    private int[] field;
    int n;

    Heapsort_BU(int[] data){
        this.field = data;
        this.n = field.length;
        System.out.println("Retrieved following array: " + Arrays.toString(field));
    }
    public void BottomUp(int n){
        for(int i = (n/2); i > 0; i--) {
            int k = i;
            int v = field[k-1];
            boolean heap = false;
            
            while(!heap && ((2*k)<=n)) {
                int j = 2*k;
                
                /*
                 * check whether there are 2 children
                 */
                if (j < n) {
                    if(field[j-1]<field[j]) {
                        j++;
                    }
                }
                if(v >= field[j-1]) {
                    heap = true;
                } else {
                    field[k-1] = field[j-1];
                    k = j;
                }
            }
            field[k-1] = v;
        }
    }
    
    public void sort() {
        // create heap first
        this.BottomUp(n);
        int count = n-1;
        System.out.println("Sorting...");
        System.out.println(Arrays.toString(field)); 
        while(count > 0) {
            // temp variable for last element in array = last added leaf of the tree
            int temp = field[count];
            //swap root with last leaf
            field[count] = field[0];
            field[0] = temp;
            
            // update the heap ranging from 0 to n - 1 
            // repeat steps until n = 0 
            this.BottomUp(--count);
            
            // print each step
            System.out.println(Arrays.toString(field)); 
        }
    }
    
    public void print() {
        if(field==null) {
            System.out.println("No elements.");
        } else {
            System.out.println("Sorted array:" + Arrays.toString(field));
        }
    }
    
    public static void main(String[] args) {
        Heapsort_BU test = new Heapsort_BU(new int[] {60, 15, 23,16, 71, 98, 78, 72, 4});
        test.sort();
        test.print();
    }
}