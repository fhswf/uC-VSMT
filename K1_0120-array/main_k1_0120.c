/*
 * main_k1_0120.c
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
	uint8_t c[2][3] = { {11,12,13}, {21,22,23}};
	uint16_t i;

	for (i=0;i<6;i++)
	{
		printf("%i  ", *(((uint8_t*)c)+i));
		// vgl. Kapitel Pointer
		// c enthaelt die Startadresse des Feldes
		// ueber (uint8_t*)c  wird daraus ein einfacher Zeiger auf eine einzelne uint8_t Zahl
		// anschliessend wird auf die Adresse von c der Wert von i addiert
		// zuletzt über *(...) auf den Inhalt der sich ergebenden Speicheradresse zugegriffen
	}

	return 0;
}
