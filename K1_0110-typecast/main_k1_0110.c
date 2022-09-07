/*
 * main_k1_0110.c
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
#include <math.h>	// fuer sin

#define PI 3.141592653589

int main()
{
	double deg;
	double x;

	deg = 27.5;		// Winkel in Grad

	x = sin(2/360*PI*deg);		// falsch, liefert 0 als Ergebnis
	printf("%5.3lf\r\n",x);

	x = sin(2./360.*PI*deg);		// richtig
	printf("%5.3lf\r\n",x);

	return 0;
}
