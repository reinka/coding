package de.mpaap.kurs1618;
import java.util.NoSuchElementException;
import java.util.Scanner;

class Entry<ET> {
        ET element;
        Entry<ET> next;
        Entry<ET> previous;
        Entry(ET element, Entry<ET> next, Entry<ET> previous) {
            this.element = element;
            this.next = next;
            this.previous = previous;
        } 
    }
public class Ringpuffer<ET>{
    Entry<ET> queue = new Entry<ET>(null, null, null);
    int counter = 0; //Number of used Nodes
    int size = 0; //Number of Nodes within the buffer
    
    /* Constructs an empty Queue. */
    Ringpuffer(int n) {
      queue.next = queue;
      queue.previous = queue;
      this.size = n;
    }
    /* Returns the last Element in this List. */
    ET getLast()  {
      if( counter == 0 ) throw new NoSuchElementException();
      return queue.previous.element;
    }/* Removes the last Element from this List. */
    void removeLast() {
      Entry lastentry = queue.previous;
      if(lastentry==queue) throw new NoSuchElementException();
      lastentry.previous.next = lastentry.next;
      lastentry.next.previous = lastentry.previous;
      counter--;
    } 
    /* Prepends a new Node to the beginning of the buffer. */
    void addFirst(ET data) {
      Entry<ET> newEntry = new Entry<ET>(data, queue.next, queue);
      queue.next.previous = newEntry;
      queue.next = newEntry;
      counter++;
    }
    void insert(ET data){
        //Create temporary Entry object that keeps track of current node
        //We want the FIFO mechanism, so we start at queue.previous = last element
        Entry<ET> last = queue.previous;
        int iterator = 0;
        boolean found = false;          
        //Loop through the buffer until empty Entry is found
        while(iterator < counter){
            if(last.element == null){
                last.element = data;
                found = true;
                break;
            }
            last = last.previous;
            iterator++;
        }
        //If no empty entry was found, the buffer is already full
        //So we have to delete the oldest item and insert the new one
        //at the beginning of the buffer - FIFO, remember
        if(!found){
            removeLast();
            addFirst(data);
        }
    }
    void print(){
        //Create temporary Entry object that keeps track of current node.
        //We want the FIFO mechanism, so this time we start 
        //at queue.next = first element in buffer = last inserted element
        Entry<ET> current = queue.next;
        int iterator = 0;
        while(iterator < counter){
            if(current.element != null){
                 System.out.print(String.valueOf(current.element) + ' ');
                 current = current.next;
            } 
            else{
                current = current.next;
            } 
            iterator++; 
        } System.out.print('\n');
    }
    public static void main(String[] args) {
        
        /* Get size of buffer from user input */
        Scanner keyboard = new Scanner(System.in);
        System.out.print("Please enter size of buffer: ");
        while(!keyboard.hasNextInt()){ 
            System.out.println("Wrong input. Integer only. Try again.");
            keyboard.next();
        }
        int number = keyboard.nextInt();  // Save it in a local variable
        keyboard.nextLine();  // Handle the end of line characters
        keyboard.close();

        /* Test Code */
        Ringpuffer ring = new Ringpuffer(number);
        for(int i = 0; i < ring.size; i++){
            ring.addFirst(null);
        }
        /* Add elements while displaying current 
         * buffer content. This way you can see how
         * the buffer keeps kicking out elements, once
         * its capacity is full.
         */
        System.out.println("Loading data [25, 16, 9, 4, 1] into buffer...");
        for(int i = 1; i <= 5; i++){
            ring.insert(i*i);
            ring.print();
        }

        System.out.println("Final buffer content:");
        ring.print();
        System.out.println("Last element:");
        System.out.println(ring.getLast());
    }
}