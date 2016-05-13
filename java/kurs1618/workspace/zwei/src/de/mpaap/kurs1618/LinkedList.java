package de.mpaap.kurs1618;
import java.util.NoSuchElementException;

class LinkedList<ET> {
  Entry<ET> tail = new Entry<ET>(null, null, null);
  int size = 0;
  /* Constructs an empty Linked List. */
  LinkedList() {
    tail.next = tail;
    tail.previous = tail;
  }
  /* Returns the last Element in this List. */
  ET getLast()  {
    if( size == 0 ) throw new NoSuchElementException();
    return tail.previous.element;
  }
  /* Removes and returns the last Element from this List. */
  ET removeLast() {
    Entry<ET> lastentry = tail.previous;
    if(lastentry == tail) throw new NoSuchElementException();
    lastentry.previous.next = lastentry.next;
    lastentry.next.previous = lastentry.previous;
    size--;
    return lastentry.element;
  }
  /* Appends the given element to the end of this List. */
  void addLast(ET e) {
    Entry<ET> newEntry = new Entry<ET>(e, tail, tail.previous);
    tail.previous.next = newEntry;
    tail.previous = newEntry;
    size++;
  }
  ET removeFirst() {
      Entry<ET>first = tail.next;
      if(first == tail) throw new NoSuchElementException();
      first.next.previous = tail;
      tail.next = first.next;
      size--;
      return first.element;
  }
  void print() {
      Entry<ET> current = tail.next;
      System.out.println(current.element);
  }
  /* Returns the number of elements in this List. */
  int size() {
    return size;
  }
  class ListIterator {
      private int nextIndex = 0;
      private Entry<ET> next = tail.next;
      boolean hasNext() {
        return nextIndex != size;
  }
  ET next() {
        if (nextIndex == size)
           throw new NoSuchElementException();
        ET elem = next.element;
        next = next.next;
        nextIndex++;
        return elem;
  } }
    ListIterator listIterator() {
      return new ListIterator();
  } 
  
}