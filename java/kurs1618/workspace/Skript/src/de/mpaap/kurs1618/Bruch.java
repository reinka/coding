package de.mpaap.kurs1618;

public class Bruch {
    private int nenner;
    private int zaehler;
    
    public Bruch(int zaehler, int nenner) {
        setZaehler(zaehler);
        setNenner(nenner);
    }
    public Bruch() {
        nenner = 1;
        zaehler = 1;
    }
    //copy constructor
    public Bruch(Bruch r) {
        this.zaehler = r.zaehler;
        this.nenner = r.nenner;
    }
    
    @Override
    public String toString() {
        return this.zaehler + "/" + this.nenner;
    }
    
    public void setZaehler(int zaehler) {
        this.zaehler = zaehler;
    }
    public int getZaehler() {
        return this.zaehler;
    }
    public void setNenner(int nenner) {
        if(nenner == 0) {
            throw new ArithmeticException("Nenner darf nicht 0 sein.");
        }else {
            this.nenner = nenner;
         }
    }
    public int getNenner() {
        return this.nenner;
    }
    private void normalisiere() {
        if(nenner < 0) {
            nenner*=(-1);
            zaehler*=(-1);
        }
        //Bruch kuerzen
        int a = zaehler;
        if(a<0) {
            a = -a;
        }
        
        
    }
}
