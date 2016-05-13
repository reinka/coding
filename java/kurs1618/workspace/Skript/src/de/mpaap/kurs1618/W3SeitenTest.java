package de.mpaap.kurs1618;

public class W3SeitenTest {

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        W3Seite meineSeite;
        meineSeite = new W3Seite("Abstraktion",
                "Abstraktion bedeutet ...");
        (System.out).println( meineSeite.getInhalt() );;
    
        W3Seite meinAlias;
        meinAlias = meineSeite;
        meinAlias.inhalt = "Keine Angabe";
        System.out.println(meineSeite.getInhalt());
        
    }

}
