package de.mpaap.kurs1618;

public class ZahlAusdenken {

    public static void main(String[] args) {
        int startzahl = 0;
        /*
         * Ueberpruefe input auf Korrektheit.
         */
        try {
            startzahl = Integer.parseInt(args[0]); //lies eine Zahl ueber die Konsole ein
        } catch (Exception e)
        {
            System.out.println("Falscher input. Nur Ganzzahlen im Intervall [-2147483648, 2147483647] erlaubt.");
            System.exit(-1);
        }
        int ergebnis = startzahl; //Setze Ergebnis = Startzahl
        
        /*Falls ergebnis > 0: addiere 2 hinzu
         *Ansonten multipliziere das ergebnis mit -1 und 
         *addiere anschliessend 2 hinzu
         */
        if(ergebnis>0) {                
            ergebnis = ergebnis + 2;
        } else {
            ergebnis = ergebnis * (-1) +2;
        }
        
        /*Solange ergebnis > 2: 
         *subtrahiere 2 
         */
        while (ergebnis > 2) {
            ergebnis -=2;
        }
        int arbeiten = 4;
        /*iteriere von 2 bis 20 in 2er Schritten 
         *und addiere startzahl zur variable arbeiten
         */
        for(int i = 2; i <= 20; i+=2) {
            arbeiten += startzahl;
        }
        
        /* ueberpruefe den wert der variable ergebnis, und 
         * gib fuer den jeweiligen fall den 
         * dazugehoerenden print befehl aus. 
         * falls nichts davon zutrifft, gib "Fehler!" aus.
         */
        switch (ergebnis) {
        case 0:
            System.out.println("Das kann nicht sein!");
            break;
        case 1:
            System.out.println("Die urspruengliche Zahl war ungerade!");
            break;
        case 2:
            System.out.println("Die urspruengliche Zahl war gerade!");
            break;
        default:
            System.out.println("Fehler!");
        }
        
        //gib schliesslich die startzahl aus
        System.out.println("startzahl = " + startzahl);
        
    }
}
