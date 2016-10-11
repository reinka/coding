package study;


public class BoxDemo2 {
    public static void main(String args[]) {
        Box myBox1 = new Box();
        Box myBox2 = new Box();
        double vol;
        
        myBox1.width = 10;
        myBox1.height = 20;
        myBox1.depth = 15;
        
        myBox2.width = 6;
        myBox2.height = 3;
        myBox2.depth = 0.5;
        
        //print value
        System.out.println("Volume of Box 1 is: " + myBox1.volume());
        System.out.println("Volume of Box 2 is: " + myBox2.volume());
    }
}
