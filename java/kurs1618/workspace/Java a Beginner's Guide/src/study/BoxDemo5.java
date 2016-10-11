package study;

public class BoxDemo5 {
    public static void main(String args[]) {
        Box myBox1 = new Box(10,20,30);
        Box myBox2 = new Box(3, 5, 0.75);
        
        System.out.println("Volum box 1 is " + myBox1.volume());
        System.out.println("Volum box 2 is " + myBox2.volume());
    }
}
