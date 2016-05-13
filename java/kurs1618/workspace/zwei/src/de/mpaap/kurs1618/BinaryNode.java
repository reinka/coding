package de.mpaap.kurs1618;

public class BinaryNode {
    
    private BinaryNode leftSon, rightSon;
    private int value;
    
    //Constructor
    public BinaryNode(int i) {
        leftSon = rightSon = null;
        value = i;
    }
    /**
     * Inserts a new element into the tree.
     * If that element already exists, it will 
     * be ignored. 
     */
    public void insert(int e) {
        if (e < this.value) {
            if(this.leftSon != null) {
                this.leftSon.insert(e);
            } else {
                this.leftSon = new BinaryNode(e);
            }
        }else {
            if(this.rightSon != null) {
                this.rightSon.insert(e);
            }else {
                this.rightSon = new BinaryNode(e);
            }
        }
    }
    
    /**
     * Prints the content of the tree in 
     * order from smallest to largest element.
     */
    public void inorder() {
        if(this.leftSon != null) {
            this.leftSon.inorder();
        } System.out.println(this.value);
        if(this.rightSon != null)
            this.rightSon.inorder();            
    }
    /*
     * Checks whether a given element is 
     * already part of the tree
     */
    public boolean contains(int e) {
        boolean compare = value == e ? true : false;
        if(compare)
            return true;
        if(!compare && e < value && leftSon != null && leftSon.contains(e))
            return true;
        if(!compare && e > value && rightSon != null && rightSon.contains(e))
            return true;
       return false;
         
                
    }
    /*
     * Main function with some test nodes.
     */
    public static void main(String[] args) {
        BinaryNode myTree = new BinaryNode(6);
        myTree.insert(5);
        myTree.insert(4);
        myTree.insert(12);
        System.out.println("Does it already contain 10? " + myTree.contains(10));
        myTree.insert(11);
        myTree.insert(10);
        System.out.println("Does it contain 10 now? " + myTree.contains(10));
        System.out.println("Does it contain 4? " + myTree.contains(4));
        System.out.println("Does it contain 6? " + myTree.contains(6));
        System.out.println("Does it contain 666? " + myTree.contains(666));
        System.out.println("Tree content ordered from smallest to largest element: ");
        myTree.inorder();
    }

}
