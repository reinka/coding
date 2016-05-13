package de.mpaap.kurs1618;

/* 
 * zu d) der Programmspeicher wird in 4 Teilen unterteilt, darunter 
 * dem Heap und dem Stack. Wird jetzt eine Funktion aufgerufen, 
 * wird Speicher fuer die dafuer benoetigten Variablen vom Heap
 * 'beantragt', welcher bildlich auf den Stack gelegt wird. Bei 
 * rekursiven Funktionen wiederholt sich jetzt dieser Schritt, 
 * abhaengig von der rekursionstiefe (in unserm Fall startWert). 
 * Da der Stack eine begrenzte Ressource ist, kann es nun bei 
 * zu tiefer Rekursion dazu fueheren, dass der Stack 'voll' wird.
 * Es kommt zum sogenannten stack overflow. 
 * Von der Speicherkomplexitaet her betrachtet, sind somit rekursive 
 * Funktionen fuer diese Art von Probleme extrem ineffizient. 
 */


public class Summierer {

    public static void main(String[] args) {
        Summierer summierer = new Summierer();
        int startWert = Integer.parseInt(args[0]);
        
        System.out.println("Ergebnis mit for-Schleife: " 
                + summierer.forSumme(startWert));
        System.out.println("Ergebnis mit kleiner Gauss: " 
                + summierer.kleinerGauss(startWert));
        System.out.println("Ergebnis rekursiv: " 
                + summierer.rekursiveSumme(startWert));
    }

    int forSumme(int startWert ) {
        int sum = 0;
        for(int i = 0; i <= startWert; i++) {
            sum += i;
        }
        return sum;
    }
    int rekursiveSumme(int startWert) {
        if (startWert != 1){
            return startWert + rekursiveSumme(startWert - 1);
        }
        else {
            return 1;
        }
    }
    int kleinerGauss(int startWert) {
        return (startWert*startWert + startWert)/2;
    }
    
}
