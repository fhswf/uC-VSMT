/*
 * main_l1_5.c
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
	uint16_t feld[10][10];
	uint16_t i,j;

	// Feld belegen
	for (i=0;i<10;i++)  // Achtung: Der Index des Feldes geht von 0....9
	{
		for (j=0;j<10;j++)
		{
			feld[i][j] = (i+1) * (j+1);		// +1, da Feldindex bei 0 beginnt...
		}
	}

	// Feld ausgeben:
	for (i=0;i<10;i++)  // Achtung: Der Index des Feldes geht von 0....9
	{
		// Tabellenlinien in schön
		if (i==0) {
			printf(".-----.-----.-----.-----.-----.-----.-----.-----.-----.-----.\n|");
		}
		else {
			printf("\n|-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|\n|");
		}
		for (j=0;j<10;j++)
		{
			printf(" %3i |",feld[i][j]);		// +1, da Feldindex bei 0 beginnt...
		}
	}
	printf("\n'-----'-----'-----'-----'-----'-----'-----'-----'-----'-----'\n");
}
