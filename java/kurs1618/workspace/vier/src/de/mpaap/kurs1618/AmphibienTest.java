package de.mpaap.kurs1618;

public class AmphibienTest {

    public static void main(String[] args) {
        Amphibienfahrzeug bla = new Amphibienfahrzeug(245.6f, 68.56f, "Yamaha", "schwarz", true);
        Auto car = new Auto(5233, 23, "VW", "silber", false);
        
        System.out.println(bla.getKilometerzaehler() + " km bisher gefahren.");
        System.out.println(bla.getFarbe());
        System.out.println(bla.getMarke());
        System.out.println(bla.getTank() + " Liter im Tank.");
        bla.Fahren(232.5f);
        System.out.println("Anschliessend:" + bla.getKilometerzaehler() + " bisher zurueckgelegt.");
        bla.Schwimmen(35.8f);
        System.out.println("Eigenschaften");
        bla.getEigenschaften();
        System.out.println("\nAuto Eigenschaften: \n");
        car.getEigenschaften();
        car.Fahren(5.5f);
        System.out.println("Neue Kilometeranzeige: " + car.getKilometerzaehler());
    }

}
