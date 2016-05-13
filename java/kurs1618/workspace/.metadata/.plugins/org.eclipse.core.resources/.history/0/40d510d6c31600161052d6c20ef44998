package de.mpaap.kurs1618;

import java.util.Arrays;

public class Heapsort_BU {
    private int[] field;
    
    Heapsort_BU(int[] data){
        this.field = data;
        System.out.println("Retrieved following array: " + Arrays.toString(field));
    }
    public void BottomUp(){
        int n = field.length;
        
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
    public void print() {
        if(field==null) {
            System.out.println("No elements.");
        } else {
            System.out.println("Sorting...\nSorted array:" + Arrays.toString(field));
        }
    }
    
    public static void main(String[] args) {
        Heapsort_BU test = new Heapsort_BU(new int[] {9, 23, 3, 14, 10, 20, 5, 13, 15, 11, 18, 17, 7, 24, 2});
        test.BottomUp();
        test.print();
    }
}