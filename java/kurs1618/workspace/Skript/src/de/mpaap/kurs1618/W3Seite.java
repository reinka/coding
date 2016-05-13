package de.mpaap.kurs1618;

public class W3Seite {
    String titel;
    String inhalt;
    
    W3Seite ( String t, String i){
        this.titel = t;
        this.inhalt = i;
    }
    
    String getTitel() {
        return this.titel;
    }
    
    String getInhalt() {
        return this.inhalt;
    }
}
