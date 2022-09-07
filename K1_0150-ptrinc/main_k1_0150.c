/*
 * main_k1_0150.c
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

int main()
{
	char text[10]="Hallo";
	char *textz;

	textz=text;			// Den Zeiger textz auf die Anfangsadresse
	                    // des Textes zeigen lassen
	while( (*textz) != '\0')	// Das String-Ende wird durch \0 gekennzeichnet (Nullbyte)
	{
		printf("textz=0x%p  Zeichen %c ASCII %i\n",
		   (void*)textz, *textz, *textz);
		textz++;		// Den Zeiger um eins erhöhen
	}

	return 0;
}
