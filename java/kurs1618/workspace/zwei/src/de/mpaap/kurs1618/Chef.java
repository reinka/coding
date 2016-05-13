package de.mpaap.kurs1618;

class Mitarbeiter {
    public int budget;
    private Chef chef;
    /*
     * Konstruktor fuer Zugriff auf Chef.getTermin()
     */
    Mitarbeiter(Chef chef1) {
        this.chef = chef1;
    }    
    public int getBudget() {
        return budget;
    }    
    void getTermin() {
        chef.getTermin();
    }
}

public class Chef {
    private String naechsterTermin;
    private Mitarbeiter x; 
    /*
     * Konstruktor fuer Mitarbeiter.budget setter
     */
    Chef(Mitarbeiter xy){
        this.x = xy;
    }
    public void setBudget(int newBudget) {
        x.budget = newBudget;
    }
    public String getTermin() {
        return naechsterTermin;
    }
    public void setTermin(String date) {
        this.naechsterTermin = date;
    }
}

class ChefSekretaerin {
    private Mitarbeiter x;
    private Chef chef;
    /*
     * Konstruktor fuer Mitarbeiter.budget setter,
     * Chef.getTermin() und Chef.setTermin()
     */     
    ChefSekretaerin(Chef chef2, Mitarbeiter xy) {
        this.chef = chef2;
        this.x = xy;
    }
    void setBudget(int newBudget) {
        x.budget = newBudget;
    }    
    void getTermin() {
        chef.getTermin();
    }    
    void setTermin(String newDate) {
        chef.setTermin(newDate);
    } 
}