package de.mpaap.kurs1618;

public enum THW {
    
    HELFER {
        @Override
        public String toString() {
            return "Helfer";
        }
    }, TRUPPFUEHRER{
        @Override
        public String toString() {
            return "Truppfuehrer";
        }
    }, GRUPPENFUEHRER{
        @Override
        public String toString() {
            return "Gruppenfuehrer";
        }
    }, ZUGTRUPPFUEHRER{
        @Override
        public String toString() {
            return "Zugtruppfuehrer";
        }
    }, ZUGFUEHRER{
        @Override
        public String toString() {
            return "Zugfuehrer";
        }
    };
    public boolean istVorgesetzterVor(THW d) {
        return this.ordinal() > d.ordinal();
    }
    public static void printAll() {
        for(THW k : THW.values()) {
            System.out.println(k);
        }
    }
    
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        printAll();
        System.out.println(HELFER.istVorgesetzterVor(GRUPPENFUEHRER));
        System.out.println(TRUPPFUEHRER.istVorgesetzterVor(HELFER));
        System.out.println(GRUPPENFUEHRER.istVorgesetzterVor(GRUPPENFUEHRER));
    }

}
