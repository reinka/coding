package de.mpaap.kurs1618;

public class SimpleLocation {

    public double latitude;
    public double longitude;
    
    public SimpleLocation() { //Default constructor
        this.latitude = 32.9;
        this.longitude = -117.2;
    }
    
    public SimpleLocation (double lat, double lon){
        this.latitude = lat;
        this.longitude = lon;
    }
    public double distance(SimpleLocation other) {
        
    }
    public double distance(double otherLat, double otherLon) {
        
    }

}
