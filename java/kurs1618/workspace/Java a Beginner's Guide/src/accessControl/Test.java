package accessControl;

/**
 * This program demonstrates the difference between
 * public and private.
 * @author slackoverflow
 * @since 24.07.2016
 */

public class Test {
    int a;          //default access
    public int b;   //public access
    private int c;  //private access
    
    /**
     * Setter- and getter-methods to acces c
     */
    void setc(int i) {
        c = i;
    }
    int getc() {
        return c;
    }
}
