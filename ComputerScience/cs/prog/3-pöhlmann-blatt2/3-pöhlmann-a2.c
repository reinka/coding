/*

1. 	C Source Code ist der Quelltext des Programmierers, im unkompilierten Zustand.

2.	Beim Kompilieren wird der Qeulltext in Maschinencode übersetzt,
	wodurch das Program erst ausführbar wird.

3. 	zusätzliche Befehle/Funktionen, die der Kompiler beim Kompilieren berücksichtigt. -Werror z.b., dass jede Warnung des Kompilers als error behandelt wird, 
	das Program somit bei einer Warnung abbricht. 

4. 	siehe Kommentare im Quellcode

5.	durch die Einagbe von ./a2 im Terminal. Dabei muss man sich jedoch in dem selben Verzeichnis wie das Executable befinden


*/

#include <stdio.h> //sog header. Hier wird der standard input/output header inkludiert, in dem unter anderem die im Quellcode benutzte printf Funktion vordefiniert ist

int main(int argc, char const *argv[])  //main function. Hauptfunktion eines jeden Programms. Die Parameter könnten durc "void" ersetz weden, da hier unwichtig
{
	 //print function, die den Ausdruck zwischen den Anführungszeichen in der Konsole ausgibt.
	printf("hello world\n");  //\n ist ein sog. 'escape character' in diesem Fall führt dies zu einer neuen Zeile nach 'world'

	return 0;  //die main function muss einen integer Wert ausgeben, dies wird durch return 0 sichergestellt
}