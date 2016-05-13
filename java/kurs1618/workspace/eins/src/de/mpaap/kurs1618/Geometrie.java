package de.mpaap.kurs1618;

import java.util.stream.Stream;

public class Geometrie {
    
    public static void main(String[] args) {
        
        String figur = args[0];
        
        if (figur.equals("Quadrat")) {
            System.out.println("Vier Ecken\nVier Symmetrieachsen\nIst punktsymmetrisch\nIst geschlossen");
        } else if (figur.equals("Dreieck")) { 
            System.out.println("Drei Ecken\nDrei Seiten\nHat drei Innenwinkel\nHat einen Innkreis");
        } else if (figur.equals("RechtwinkligesDreieck")) { 
            System.out.println("Drei Ecken\nDrei Seiten\nHat drei Innenwinkel\nHat einen 90 Grad Winkel");
        } else if (figur.equals("UnregelmässigesDreieck")) { 
            System.out.println("Drei Ecken\nDrei unterschiedlich lange Seiten\nDrei unterschiedliche grosse Innenwinkel\nHat einen Innkreis");
        } else if (figur.equals("GleichseitigesDreieck")) { 
            System.out.println("Drei Ecken\nDrei gleich lange Seiten\nDrei gleich grosse Innenwinkel\nHat einen Innkreis");
        } else if (figur.equals("SphärischesDreieck")) { 
            System.out.println("Drei Ecken\nDrei Seiten\nDrei Innenwinkel\nSeitensumme kleiner 6\u03c0");
        } else if (figur.equals("Fünfeck")) {
            System.out.println("Fünf Ecken\nFünf Innenwinkel\nFünf Seiten\nIst geschlossen");
        } else if (figur.equals("KonkavesFünfeck")) {
            System.out.println("Fünf Ecken\nFünf Innenwinkel\nFünf Seiten\nIst geschlossen");
        } else if (figur.equals("KonvexesFünfeck")) {
            System.out.println("Fünf Ecken\nFünf Innenwinkel\nFünf Seiten\nIst geschlossen");
        } else if (figur.equals("SehnenFünfeck")) {
            System.out.println("Fünf Ecken\nFünf Innenwinkel\nFünf Seiten\nIst geschlossen");
        }
    }
}
