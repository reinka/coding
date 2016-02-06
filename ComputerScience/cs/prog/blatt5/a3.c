#include <stdio.h>

int main(void) {
	float a = 1.2;
	double x = sizeof(a) * 2 && 23 / printf("abc\n") ^ 4 + 1;
	double y = ((int)a / 2 + (7 | 8) << 4);
	double z = a * 6;
	double u = 0xBADCAB1E ? 1 << 1 : 0xDEADC0DE;
	double v = (u + z * 10) / 8;
	double w = (int)(u + z * 10) / 8;

	printf("x=%lf\n", x);
	printf("y=%lf\n", y);
	printf("z=%lf\n", z);
	printf("u=%lf\n", u);
	printf("v=%lf\n", v);
	printf("w=%lf\n", w);

	return 0;
}

100

/*Erklärungen:

zu x: 	da &&-Operator in der Deklartaion, wird die Auswertung
		dieser Und-Bedingung in x gespeichert. 23 / printf("abc\n") ^ 4 + 1 ergibt 
		0 (beide Seiten des XOR Ausdrucks sind gleich (5 bzw 101). Somit
		ist der XOR Ausdruck 0 (000)), damit false. Daher ist der gesamte Ausdruck false, also 0.
		Anschließend implizites typcast zu double, daher 0.000000.

zu y: 	7 | 8 = 0111 | 1000 = 1111. 
		(int) a / 2 = 1 / 2 = 0. (wegen int-Konvertierung)
		also 0 + 1111 = 1111.
		1111 << 4 = 1111 0000 = 240 in Dezmal.
		Anschließend implizites typcast zu double, daher 240.000000.

zu z:	Gleitkommamultiplikation 1.2 * 6 = 7.2. Selbsterklärend.
		Anschließend implizites typcast zu double. 

zu u: 	Übersetzt: if condition 0xBADCAB1E true, then value 1 << 1 : otherwise value 0xDEADC0DE
		0xBADCAB1E ist true, da ungleich 0. Somit wird 1 << 1 = 10 = 2 (Dezimal) zugeteilt. Anschließend
		implizites typecast zu double. Daher 2.000000.

zu v: 	(2 + 7.2 * 10) / 8 = (2 + 72.0) / 8 = 74.00 / 8 = 9.25

zu w: 	9.25 wird zu type integer konvertiert, daher fällt die Kommastelle 0.25 weg, sodass das Ergebnis
		9 ist. Anschließend wird implizit zu double konvertiert, daher 9.000000.


Zusatzfragen: 

- boolsche-Werte:	als Zahlen (integers).

- true: 			jede Zahl ungleich 0.

- false: 			0

- typecast: 		int typecast 2x, in y und w. In y wird float zu integer, in w 
					double zu integer konvertiert. In x führt dies dazu, dass 0 statt 0.6 
					das Ergebnis der Division ist, in w, dass (u + z * 10) = 74 type integer, statt
					74.0 type double. Somit die Division mit 8 an einem integer ausgeführt wird.

- implizite:		Ja, bei jeder Variablen findet ein implizites Typecast des Ergebnisses statt, da jede 
					Variable als type double abgespeichert wird, jedoch keine explizite double-Variable
					zuvor deklariert wurde. Des Weiteren in den Rechnungen, wo mit unterschiedlichen Variabletypen
					gerechnet wird, wie z.B. in z. C Operatoren wirken immer auf die selben Variablentypen, 
					daher wird, sobald eine Variable vom Typ der anderen abweicht, diese implizit angepasst. Dabei wird 
					immer an den "größeren" der beiden Variabletypen angepasst. Damit ist die Anzahl an Bytes gemeint, die 
					für die jeweiligen Typen zu Verfügung stehen (Bsp: typeof(x) > typeof(y) -> Konversion von y zum Variablentypen von x).  