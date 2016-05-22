package de.mpaap.kurs1618;

/**
 * Implementiert die Klasse Fahrzeug
 * @author slackoverflow
 * @since 13.05.2016
 */

public class Fahrzeug {
    private float kilometerzaehler;
    private float tank;
    private String marke;
    private String farbe;
    
    Fahrzeug(float kilometerzaehler, float tank, String marke, String farbe){
        this.kilometerzaehler = kilometerzaehler;
        this.tank = tank;
        this.marke = marke;
        this.farbe = farbe;
    }
    public void updateKilometer(float km) {
        kilometerzaehler += km;
    }
    public float getKilometerzaehler() {
        return kilometerzaehler;
    }
    public float getTank() {
        return tank;
    }
    public String getMarke() {
        return marke;
    }
    public String getFarbe() {
        return farbe;
    }
}
