package de.mpaap.kurs1618;

public class a5 {
    
    int x, y;
    /** Simple constructor */
    public a5(int anX, int aY) {
    x = anX; y = aY;
    }
    @Override
    public String toString() {
        return "x = " +x +"\ny = "+ y;
    }
    /** Main just creates and prints an object */
    public static void main(String[] args) {
    System.out.println(new a5(42, 86));
    }
   }