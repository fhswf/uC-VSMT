/*
 * main_l2_1.c
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

// Auskommentieren deaktiviert die Debug-Ausgabe weiter unten...
#define DEBUG

// Die fortgeschrittene Variante,
// die auch noch Dateiname, Funktion und Zeile
// ausgibt
// (Der Backslash erlaubt, einen define über
//  mehrere Zeilen zu schreiben)
#ifdef DEBUG
    #define debug_printf(fmt, args...) \
	    printf("%s:%s:%d: "fmt, __FILE__, __FUNCTION__, __LINE__, args)
#else
    #define debug_printf(fmt, args...) {}
#endif


int main()
{
	printf("Diese Zeile wird immer ausgegeben\r\n");

	// Die "einfache" Variante
	// --> Allerdings kann hiermit mehr als eine Zeile und auch weiterer Code
	//     ausgeklammert werden
	#ifdef DEBUG
		printf("Eine Debug-Ausgabe\r\n");
	#endif
	printf("Hier wieder weiter...\r\n");

	// Die fortgeschrittene Variante
	int16_t a=25;
	debug_printf("Eine Testausgabe mit Variable %i\r\n",a);

	return 0;
}
