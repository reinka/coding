package de.mpaap.kurs1618;

/**
 * Klasse Auto erbt von Fahrzeug
 * und besitzt zusaetzlich die Attribute:
 * @param landfahrzeug gibt an ob es auf dem Land fahren kann 
 * @param reifenAnzahl gibt die Anzahl der Raeder an
 * und den Methoden 
 * {@link #getReifenAnzahl()}
 * #
 * @author slackoverflow
 */

public class Auto extends Fahrzeug {
    final boolean landfahrzeug = true;
    final int reifenAnzahl = 4;
    
    Auto(int kilometerzaehler, int tank, String marke, String farbe){
        super(kilometerzaehler, tank, marke, farbe);
    }
    public int getReifenAnzahl() {
        return reifenAnzahl;
    }
    /**
     * @param km gibt an wie viele Kilometer 
     * das Auto fahren soll
     */
    public void Fahren(float km) {
        System.out.printf("%.2f km gefahren", km);
    }
}
