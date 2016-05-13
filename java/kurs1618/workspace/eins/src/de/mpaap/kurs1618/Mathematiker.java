package de.mpaap.kurs1618;

public class Mathematiker {

    public static void main(String[] args) {
        try {
            try {
                int i = 7 % 5;
                if (i/(i % 2)==1) {
                    throw new Exception();
                }
                System.out.println("Ich mag");
            }
            catch (Exception e) {
                System.out.println("Ich liebe");
                try {
                    if ((7 % 6 / (7 % 6 % 2)) == 1) {
                        throw new Exception();
                    }
                    System.out.println("nichts mehr, als");
                } catch (Exception u) {
                    System.out.println("es,");
                }
            }
            System.out.println("wenn");
            try {
                int i = true & false ? 0 : 1;
                switch(i) {
                case 0:
                    System.out.println("eine Formel");
                case 1:
                    System.out.println("ein Programm");
                default:
                    throw new Exception();
                }
            } catch (ArithmeticException e) {
                    System.out.println("abbricht.");
                } catch (Exception e) {
                    System.out.println("funktioniert.");
                }
                finally {
                    int i = false && true ? 0 : 2;
                    switch (i) {
                    case 1:
                        System.out.println(";)");
                    default:
                        throw new Exception();
                    }
                }
            } catch (ArithmeticException e) {
                System.out.println(":(");
            } catch (Exception e) {
                System.out.println(" ");
        }
    }
}
