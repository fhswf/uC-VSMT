/*
 * main_u1_6.c
 *
 *  Code-Beispiele zum Lehrbrief
 *  "Mikrocontroller-Programmierung"
 *
 *  (c) Prof. Tobias Ellermeyer
 *      Fachhochschule Suedwestfalen
 *
 *  Stand: WS 2022/23
 *
 *
 */


#include <stdio.h>
#include <stdint.h>

int main()
{
	   char buf[6];	// Denken Sie an das Null-Byte am String-Ende; d.h. es koennen 5 Zeichen gespeichert werden
	   int32_t  i;

	   i = 10;
	   printf("Anleitung: Fuerhen Sie das Progamm 5-mal nacheinander aus, mit folgenden Aenderungen\n"
			  " 1) geben Si als Text nur 'Hallo' (ohne die Anfuehrungszeichen) ein\n"
			  "    und schauen sich die Ausgabe an\n"
			  " 2) starten Sie das Programm neu und geben 'A B C' ein\n"
			  "    -> Sie sollten jetzt sehen, dass scanf nach dem ersten Leerzeichen abbricht\n"
			  " 3) starten Sie das Programm wieder und geben jetzt 'Mechatronik' ein -> Was aendert sich?\n"
			  " 4) kommentieren Sie nun die scanf-Zeile aus und aktivieren stattdessen die fgets-Zeile\n"
			  "    Compilieren Sie neu und geben Sie wieder 'Mechatronik' ein\n"
			  " 5) auf ein letztes: Geben Sie wieder 'A B C' ein\n\n");
	   printf("Text fuer buf[6]=");
	   fflush(stdout); // Nur fuer Eclipse-Console -> Text sofort ausgeben, auch wenm keine neue Zeile gestartet

	   scanf("%s",buf);		// in Schritt 4 diese Zeile auskommentieren
	   //fgets(buf,6,stdin);      // .. und diese aktivieren

	   printf("\n");
	   printf("buf = %s\n",buf);
	   printf("i   = %i\n",i);


	   return 0;}
