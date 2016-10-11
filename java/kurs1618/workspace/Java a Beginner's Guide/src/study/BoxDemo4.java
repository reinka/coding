package study;

public class BoxDemo4 extends BoxDemo {
    public static void main(String args[]) {
        Box myBox1 = new Box();
        Box myBox2 = new Box();
        
        System.out.println("Volume of box 1 is " + myBox1.volume());
        System.out.println("Volume of box 2 is " + myBox2.volume());
    }
}
