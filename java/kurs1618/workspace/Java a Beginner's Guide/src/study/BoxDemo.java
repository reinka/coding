package study;

class Box {
    double width;
    double height;
    double depth;
    
    /**
     * Constructor
     * @param Dimensions width, height and depth of the box being constructed
     */
    Box(double width, double height, double depth) {
        this.depth = depth;
        this.width = width;
        this.height = height;
    }
    
    /**
     * Overload constructor: in case dimensions are not specified
     * just use the 'default' constructor
     */
    Box(){
    }
    
    /**
     * Constructor used when cube is created
     * @param Single Dimension used for all 3 dimensions
     */
    Box(double len){
        this.depth = this.width = this.height = len;
    }
    
    /**
     * Display the volume of the box
     * @return Prints the volume of the box
     */
    void printVol() {
        System.out.println("Volume is " + this.volume());
    }
    
    /**
     * calculate volume of box
     * @param none
     * @return double which represents the value
     */
    double volume() {
        return width*height*depth;
    }
    
    /**
     *set parameters of box
     *@param Dimensions of box
     */
    void setDim(double width, double height, double depth) {
        this.depth = depth;
        this.width = width;
        this.height = height;
    }
}


public class BoxDemo {
    public static void main(String args[]) {
        Box myBox1 = new Box();
        Box myBox2 = new Box();
        Box myCube = new Box(3.5);
        
        myBox1.width = 10;
        myBox1.height = 20;
        myBox1.depth = 15;
        
        myBox2.width = 6;
        myBox2.height = 3;
        myBox2.depth = 0.875;
        
        //print value
        myBox1.printVol();
        myBox2.printVol();
        myCube.printVol();
        
    }
}