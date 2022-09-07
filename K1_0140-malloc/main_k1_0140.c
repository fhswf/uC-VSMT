/*
 * main_k1_0140.c
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
#include <stdlib.h>		// Hier ist malloc enthalten

#define ARRAY_SIZE 10

int main()
{
	int32_t *array;		// Zeiger auf ein Array
					// identisch mit: int array[];

	printf("%i Eintraege int32_t benoetigen %i Bytes ...\n",
			ARRAY_SIZE, ARRAY_SIZE*sizeof(int));

	// Hier ist noch kein Speicher zugewiesen, array zeigt
	// auf zufälligen Wert -> Compiler Warning
	printf("Zeiger auf Array vor malloc:  0x%p\n",
			(void *)array);

	// Speicher anfordern
	array=(int32_t*)malloc(ARRAY_SIZE*sizeof(int32_t));

	// Prüfen, ob Anforderung erfolgreich
	if (array == NULL)
	{
		printf("FEHLER: Nicht genug Speicherplatz\n");
		exit(EXIT_FAILURE);
	}

	printf("Zeiger auf Array nach malloc: 0x%p\n",
			(void *)array);

	return 0;
}
