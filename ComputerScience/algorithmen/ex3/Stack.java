/*

    COMPLEXITY

pop and top O(1). 
push, in case array has to be expanded: O(n), else: O(1).

*/

public class Stack {
 
    private int stackSize;
    private int[] stack;
    private int top;
 
    /**
     * constructor to create stack with size
     */
    public Stack(int size) {
        this.stackSize = size;
        this.stack = new int[stackSize];
        this.top = -1;
    }
 
    /**
     * Adds new entry to the top
     * of the stack
     */
    public void push(int entry){
        if(this.isFull()){
            System.out.println(("Stack is full. Increasing the capacity."));
            this.increaseStackCapacity();
        }
        System.out.println("Adding: "+entry);
        this.stack[++top] = entry;
    }
 
    /**
     * Removes an entry from the
     * top of the stack.
     */
    public int pop() throws Exception {
        if(this.isEmpty()){
            throw new Exception("Stack is empty. Can not remove element.");
        }
        int entry = this.stack[top--];
        System.out.println("Removed entry: "+entry);
        return entry;
    }
     
    /**
     * Returns top of the stack
     * without removing it.
     */
    public long top() {
        return stack[top];
    }
 	
 	/** 
 	 * Increases stack capacity
 	 */
    private void increaseStackCapacity(){
         
        int[] newStack = new int[this.stackSize*2];
        for(int i=0;i<stackSize;i++){
            newStack[i] = this.stack[i];
        }
        // Copy new stack into old one
        this.stack = newStack;
        this.stackSize = this.stackSize*2;
    }
     
    /**
     * Returns true if the stack is empty
     */
    public boolean isEmpty() {
        return (top == -1);
    }
 
    /**
     * Returns true if the stack is full
     * @return
     */
    public boolean isFull() {
        return (top == stackSize - 1);
    }

    /**
     * Returns stack size
     */
    public int size(){
    	return stackSize;
    }
 
    public static void main(String[] args) {
        Stack stack = new Stack(2);
        for(int i=1;i<10;i++){
            stack.push(i);
        }
        for(int i=1;i<4;i++){
            try {
                stack.pop();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
