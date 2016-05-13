import java.util.NoSuchElementException;

class Entry<ET> {
  ET element;
  Entry<ET> next;
  Entry<ET> previous;
  Entry(ET element, Entry<ET> next, Entry<ET> previous) {
    this.element = element;
    this.next = next;
    this.previous = previous;
} }
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
  void addFirst(ET e) {
    Entry<ET> newEntry = new Entry<ET>(e, tail.next, tail);
    tail.next = newEntry;
    tail.next.previous = newEntry;
    size++;
  }
  /* Returns the number of elements in this List. */
  int size() {
    return size;
  }
}