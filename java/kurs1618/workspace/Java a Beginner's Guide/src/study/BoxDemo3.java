package study;

public class BoxDemo3 {
    public static void main(String args[]) {
        Box myBox1 = new Box();
        Box myBox2 = new Box();
        
        //set Dimensions
        myBox1.setDim(10, 15, 20);
        myBox2.setDim(3, 7, 0.875);
        
        System.out.println("Volume of box 1 is " + myBox1.volume());
        System.out.println("Volume of box 2 is " + myBox2.volume());
    }
}
