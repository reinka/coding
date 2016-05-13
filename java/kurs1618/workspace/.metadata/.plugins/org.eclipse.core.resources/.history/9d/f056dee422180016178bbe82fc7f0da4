package de.mpaap.kurs1618;

public class Figure {
    double dim1;
    double dim2;
    
    Figure(double a, double b){
        dim1=a;
        dim2=b;
    }
    double area() {
        System.out.printf("Area for Figure is undefined.");
        return 0;
    }
    
    public static void main(String args[]) {
        Rectangle test = new Rectangle(2,4);
        test.area();
    }
}
class Rectangle extends Figure{
    Rectangle(double a, double b){
        super(a, b);
    }
    /**
     * Override superclass method
     * @param takes none
     * @return product of 
     */
    @Override
    double area() {
        super.area();
        return dim1*dim2;
    }
}