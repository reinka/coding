package de.mpaap.kurs1618;
import java.util.NoSuchElementException;

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
class LinkdList<ET> {
    Entry<ET> tail = new Entry<ET>(null, null, null);
    int size = 0;
    /* Constructs an empty Linked List. */
    LinkdList() {
      tail.next = tail;
      tail.previous = tail;
    }
    /* Appends the given element to the end of this List. */
    void addLast(ET e) {
      Entry<ET> newEntry = new Entry<ET>(e, tail, tail.previous);
      tail.previous.next = newEntry;
      tail.previous = newEntry;
      size++;
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
        } 
    }
    ListIterator listIterator() {
        return new ListIterator();
    } 
}
public class Morse {
    private LinkdList<String> morse = new LinkdList<String>(); 
    private LinkdList<String>.ListIterator morsealphabet;
    private String symbols[] = new String[]{"·−", "-...", "-.-.", "-..", ".", "..-.", 
                               "--.", "....", "..", ".---", "-.-", ".-..",
                               "--", "-.", "---", ".--.", "--.-", ".-.", 
                               "...", "-", "..-", "...-", ".--", "-..-", 
                               "-.--", "--.."};
    Morse(){
        for(String s: symbols) {
            morse.addLast(s);
        }
        morsealphabet = morse.listIterator();
    }
    /*
     * Da nicht explizit angegeben, dass linked list 'morsealphabet' fuer
     * die Konvertierung des Buchstaben zu Morse-Code benutzt
     * werden soll, wird hier einfach das oben definierte Array
     * dafuer verwendet. Ansonsten statt ins array indexen durch Liste iterieren,
     * dem Wert 'val' entsprechend.
     */
    public String code(char b) {
        //Numeric Value of 'a' = 'A' = 10; 'z' = 'Z' = 35;
        int val = Character.getNumericValue(b);
        if (val < 10 || val > 35) {
            return "Fehler!";
        }else {
            return symbols[val - 10];
        }
    }
    
    public static void main(String[] args) {
        Morse encoder = new Morse();
        //encoder.morsealphabet = encoder.morse.listIterator();
        for(String s: args) {
            for(int i = 0; i<s.length();i++)
            System.out.println(encoder.code(s.charAt(i)));
        }
        
    }

}
