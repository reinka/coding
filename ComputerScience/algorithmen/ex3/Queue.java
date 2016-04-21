/* Queue is a First-In-First-Out (FIFO) data structure. In a FIFO data structure, 
the first element added to the queue will be the first one to be removed.

Stack serves as a collection of elements, with two principal operations: push, 
which adds an element to the collection, and pop, which removes the most recently 
added element that was not yet removed. The order in which elements come off a stack 
gives rise to its alternative name, LIFO (for last in, first out)
*/

/*

Implement a queue of integers (using a dynamic array) and it’s associated functions
(enqueue, dequeue, first, size, empty).

*/


/*
	COMPLEXITY

dequeue, size = O(1)

'enqueue' in case Queue has to be expanded: O(n), else: O(1)
*/

public class Queue{
	private int capacity = 2;
	int queue[];
	int front = 0;
	int rear = -1;
	int currentSize = 0;

	public Queue(){
		queue = new int[this.capacity];
	}

	/**
     * adds element at the end of the queue
     */
	public void enqueue(int item){
		if (isFull()){
			System.out.println("Queue is full, increasing capacity first...");
			increaseCapacity();
		}
		rear++;
		if(rear >= queue.length && currentSize != queue.length){
			rear = 0;
		}
		queue[rear] = item;
		currentSize++;
		System.out.println("Adding " + item);
	}
	/**
	 * Remove element from top of queue
	 */
	public void dequeue(){
		if (isEmpty()){
			System.out.println("Underflow. Unable to remove element.");
		} else {
			front++;
			if(front > queue.length-1){
				System.out.println("Removed: " + queue[front-1]);
				front = 0;
			} else {
				System.out.println("Removed: " + queue[front-1]);
			}
		}
		currentSize--;
	}

	/**
	 * Checks if Queue is empty
	 */
	public boolean isEmpty(){
		boolean empty = false;
		if(currentSize == 0)
			empty = true;
		return empty;
	}
	/**
	 * Checks if Queue is full
	 */
	public boolean isFull(){
		boolean full = false;
		if(currentSize == queue.length){
			full = true;
		}
		return full;
	}

	/* 
	 * Returns first element in Queue
	 */
	public void top() {
		System.out.println("First element in queue: " + queue[front]);
    }
	/**
	 * Increase capacity
	 */
	private void increaseCapacity(){
		int newCapacity = this.queue.length * 2;
		int[] newQueue = new int[newCapacity];
		//copy elemtns to new array
		int temp = front;
		int index = -1;
		while(true){
			newQueue[++index] = this.queue[temp];
			temp++;
			if(temp == this.queue.length){
				temp = 0;
			}
			if(currentSize == index+1){
				break;
			}
		}
		this.queue = newQueue;
		System.out.println("Size of dynamic array increased to " + this.queue.length);
		// Reset front
		this.front = 0;
		this.rear = index;
	}

	public static void main(String a[]){
         
        Queue queue = new Queue();
        queue.enqueue(4);
        queue.dequeue();
        queue.enqueue(56);
        queue.enqueue(2);
        queue.enqueue(67);
        queue.dequeue();
        queue.enqueue(24);
        queue.enqueue(98);
        queue.top();
        queue.dequeue();
        queue.dequeue();
        queue.dequeue();
        queue.top();
        queue.enqueue(435);
        queue.dequeue();
        queue.dequeue();

    }
}	