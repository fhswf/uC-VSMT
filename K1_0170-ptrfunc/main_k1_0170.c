/*
 * main_k1_0170.c
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
#include <math.h>		// Je nach Zielsystem auch für Linker -lm angeben!

#define PI 3.1415926535897932384
#define DEG2RAD  PI/180.0

void rotate(float*, float*,float);  // Prototype

int main()
{
	float x1,y1;

	x1= 20.;
	y1= 30.;

	printf("Vor Rotation:  (%5.1f / %5.1f)\r\n",x1,y1);
	rotate(&x1,&y1,45.0);
	printf("Nach Rotation: (%5.1f / %5.1f)\r\n",x1,y1);

	return 0;
}

void rotate(float *x, float *y,float deg)
{
	float xt,yt;
	float sinv, cosv;

	xt=(*x);	// Werte merken
	yt=(*y);

	deg *= DEG2RAD;		// Winkel in Bogenmaß umrechnen
	sinv = sin(deg);	// Winkel jetzt in Bogenmaß!
	cosv = cos(deg);

	(*x) = xt*cosv - yt*sinv;
	(*y) = xt*sinv + yt*cosv;
}
