/*
 * main_k1_0160.c
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
	int16_t werte[5]={2,3,5,7,11};
	int16_t *wertez;
	int16_t i;

	wertez=werte;

	for (i=0;i<5;i++)
	{
	   printf("wertez=0x%p; werte[i]=%2i; *wertez=%2i\n",
		  (void*)wertez, werte[i], *wertez);
	   wertez++;
	   //wertez = (int*)( (char*)wertez +1);	// Mit dieser Zeile statt der davor
	   	   	   	   	   	   	   	   	   	   	   	// würde man byteweise durch das Feld gehen
	}

	return 0;
}
