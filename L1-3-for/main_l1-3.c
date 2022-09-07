/*
 * main_l1_3.c
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
	// Zunaechst mit double-Zahlen um das Problem zu zeigen
	double x;		// Zaehlvariable
	double fstep;	// Schrittweite
	double fstart;	// Start
	double fstop;	// Stop
	uint8_t col=0;	// Zaehler fuer Spalten

	// Double-Werte vorgeben
	fstep  =  0.1;
	fstart =  0.0;	// Denken Sie daran, bei "glatten" Gleitkommazahlen immer den Dezimalpunkt mit anzugeben
	fstop  =  2.0;

	// Der folgende Abschnitt verdeutlicht das Problem mit den Rundungsfehlern
	printf("Zaehlen von 0.0 ... 2.0 mit Double-Schleifenvariablen\n");
	for (x=fstart; x<=fstop; x+=fstep)
	{
		printf("%20.16lf  ", x);
		col=(col+1)%5;
		if (col==0) printf("\n");	// nach 5 Zahlen neue Zeile

	}
	printf("\n"
		   "--> wie zu sehen sind die Zahlen aufgrund von Darstellungsfehlern mal zu klein und mal zu gross\n"
		   "    und schlimmer: der Schritt 2.0 wird nicht mehr ausgefuehrt, da dieser mit 2.000000000000xx\n"
		   "    bereits >2.0 ist und die for-Schleife somit abbricht.\n\n");

	printf("Zaehlen von 0.0 ... 2.0 mit integer-Schleife\n");

	int32_t	i;
	int32_t istart;
	int32_t istop;

	istart = fstart/fstep+0.5;	// Startwert als Integer berechnen; +0.5 zum Runden, da Typumwandlung Nachkomma abschneidet
	istop  = fstop/fstep+0.5;
	col = 0;	// Spaltenzaehler zuruecksetzen

	for (i=istart; i<=istop; i++)
	{
		x = i*fstep;	// double-Wert berechnen
		printf("%20.16lf  ", x);
		col=(col+1)%5;
		if (col==0) printf("\n");	// nach 5 Zahlen neue Zeile
	}
	printf("\n"
		   "--> es gib zwar immer noch vereinzelte  Darstellungsfehler, aber diese summieren sich nicht\n"
		   "    auf (keine Fehlerfortpflanzung).\n"
		   "    Die Schleife zaehlt auch 'sauber' bis 2.0 .\n\n");

	return 0;
}
