package de.mpaap.kurs1618;

/**
 * Implementiert die Klasse Fahrzeug
 * @author slackoverflow
 * @since 13.05.2016
 */

public class Fahrzeug {
    private int kilometerzaehler;
    private int tank;
    private String marke;
    private String farbe;
    
    Fahrzeug(int kilometerzaehler, int tank, String marke, String farbe){
        this.kilometerzaehler = kilometerzaehler;
        this.tank = tank;
        this.marke = marke;
        this.farbe = farbe;
    }
    public int kilometerAnzeige() {
        return kilometerzaehler;
    }
    public int tankAnzeige() {
        return tank;
    }
    public String getMarke() {
        return marke;
    }
    public String getFarbe() {
        return farbe;
    }
}
