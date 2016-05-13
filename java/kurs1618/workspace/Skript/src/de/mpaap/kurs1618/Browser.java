package de.mpaap.kurs1618;

class Browser {
    TextFenster oberfl;
    W3Seite aktSeite; //aktuelle Seite
    static W3Server    meinServer;
    static final int    MAX_ANZAHL = 4;
    static Browser[]    gestarteteBrowser = new Browser[MAX_ANZAHL];
    static int          naechsterFreierIndex = 0;
    static int          aktBrowserIndex;
    static W3Seite      startseite = 
            new W3Seite("Startseite", "NetzSurfer: Keiner ist kleiner");
    
    //Konstruktor zum Starten des ersten Browsers
    
    Browser( W3Server server ){
        if( naechsterFreierIndex != 0) {
            System.out.println("Es sind bereits Browser gestartet");
        } else {
            meinServer = server;
            initialisieren();
            } 
        }
        // Konstruktor zum Starten weiterer Browser
        Browser() {
          if( naechsterFreierIndex == MAX_ANZAHL ) {
            System.out.println("Maximale Anzahl Browser erreicht");
          } else {
            initialisieren();
        } }
        static void start( W3Server server ) {
          new Browser(server);
          Browser.interaktiveSteuerung();
        }
        void initialisieren() {
          oberfl     =  new TextFenster();
          gestarteteBrowser[ naechsterFreierIndex ] = this;
          aktBrowserIndex = naechsterFreierIndex;
          naechsterFreierIndex++ ;
          laden( startseite );
        }
        void laden( W3Seite s ){
        aktSeite = s;
          oberfl.anzeigen(aktSeite.getTitel(),aktSeite.getInhalt());
        }
        static void interaktiveSteuerung() {
            char steuerzeichen = ’0’;
            do {
              Konsole.writeString("Steuerzeichen eingeben [lnwe]: ");
              try {
                String eingabe =  Konsole.readString();
                if( eingabe.equals("") )
                  steuerzeichen = ’0’;
                else
                  steuerzeichen =  eingabe.charAt(0);
              } catch( Exception e ) {
                System.exit( 0 );
              }
              switch( steuerzeichen ){
              case ’l’:
                String seitenadr;
                Konsole.writeString("Seitenadresse eingeben: ");
                seitenadr = Konsole.readString();
                gestarteteBrowser[aktBrowserIndex] .
                  laden( meinServer.holenSeite( seitenadr ) );
                break;
              case ’n’:
                new Browser();
                break;
              case ’w’:
               aktBrowserIndex =
                 (aktBrowserIndex+1) % naechsterFreierIndex;
                break;
              case ’e’:
                System.exit( 0 );
              default:
                Konsole.writeString("undefiniertes Steuerzeichen\n");
              }
            } while( true );
          }
        Browser.start(testServer);
}
