package accessControl;

public class AccessTest {
    public static void main(String args[]) {
        Test ob = new Test();

    //These are OK, a and b may be accessed directly
    ob.a = 10;
    ob.b = 20;
    
    /*
     * This is not OK and will cause an error
     * ob.c = 30;
     */
    
    /*
     * Private members must be accesed through its methods
     */
    ob.setc(30);
    System.out.println("a, b, and c: " + ob.a + " " + ob.b + " " + ob.getc());
    }
}