package de.mpaap.kurs1618;

public class BruchTest {

    public static void main(String[] args) {
        Bruch r1 = new Bruch();
        Bruch r2 = new Bruch(7,3);
        r1.setZaehler(4);
        r1.setNenner(3);
        
        System.out.println(r2);
        System.out.println(r1);
        System.out.printf("Nenner: %d", r1.getNenner());
    }
}
