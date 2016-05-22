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
    private boolean landfahrzeug = true;
    private boolean wasserfahrzeug = false;
    private final int reifenAnzahl = 4;
    
    Auto(float kilometerzaehler, float tank, String marke, String farbe, boolean wasserfahrzeug){
        super(kilometerzaehler, tank, marke, farbe);
        this.wasserfahrzeug = wasserfahrzeug;
    }
    public void getEigenschaften() {
        System.out.printf("Reifenanzahl: %d\nKilometeranzahl: %.2f km\nTank: %.2f l\nMarke: %s\nFarbe: %s\nLandfahrzeug: %s\nWasserfahrzeug: %s\n", 
                reifenAnzahl,getKilometerzaehler(),getTank(),getMarke(),getFarbe(),landfahrzeug ? "wahr" : "falsch", wasserfahrzeug ? "wahr" : "falsch");
    }
    /**
     * @param km gibt an wie viele Kilometer 
     * das Auto fahren soll und update gleichzeitig
     * @param kilometerzaehler
     */
    public void Fahren(float km) {
        System.out.printf("***%.2f km gefahren***\n", km);
        this.updateKilometer(km);
    }
    
    
}
