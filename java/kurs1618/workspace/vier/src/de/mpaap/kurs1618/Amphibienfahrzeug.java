package de.mpaap.kurs1618;



public class Amphibienfahrzeug extends Auto {   
    
    Amphibienfahrzeug(float kilometerzaehler, float tank, String marke, String farbe, boolean wasserfahrzeug){
        super(kilometerzaehler, tank, marke, farbe, wasserfahrzeug);
    }
    
    @Override
    public void getEigenschaften() {
        super.getEigenschaften();
    }
    /**
     * @param km gibt an wie viele Kilometer 
     * das Auto fahren soll und updatet gleichzeitig
     * @param kilometerzaehler
     */
    public void Schwimmen(float km) {
        System.out.printf("***%.2f km geschwommen***\n", km);
        this.updateKilometer(km);
    }
}
