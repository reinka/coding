package de.mpaap.kurs1618;

public class Geometrieobjektverwaltung {
    public static void main(String args[]) {
        Kreis circle = new Kreis();
        Bogenstueck curve = new Bogenstueck();
        Rechteck rectangle = new Rechteck();
        
        /**
         * Es kann zwar kein Objekt einer abstrakten Klasse 
         * kreiert werden, jedoch eine Referenzvariable vom 
         * Typen abstrakte Klasse:
         */
        GeometrischesObjekt referenz = rectangle;
        referenz.druckeEigenschaften();
        
        circle.druckeEigenschaft();
        curve.druckeEigenschaft();
        rectangle.druckeEigenschaft();
        
    }
}
class Kreis extends GeometrischesObjekt{    
    public void druckeEigenschaft() {
        System.out.println("Ist punktsymmetrisch. Ist geschlossen.");
    }
}
class Bogenstueck extends GeometrischesObjekt{
    public void druckeEigenschaft() {
        System.out.println("Ist nicht punktsymmetrisch. Ist nicht geschlossen.");
    }
}
class Rechteck extends GeometrischesObjekt{
    public void druckeEigenschaft() {
        System.out.println("Ist punktsymmetrisch. Ist geschlossen.");
    }
}
abstract class GeometrischesObjekt{    
    void druckeEigenschaften() {};
}
