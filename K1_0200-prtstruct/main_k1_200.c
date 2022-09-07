/*
 * main_k1_0200.c
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
#include <string.h>  // für strcpy
#include <math.h>		// Je nach Zielsystem auch für Linker -lm angeben!


typedef struct  {   // Dies ist nur das Gerüst
	float x;		// (die "Bauanleitung")
	float y;
	float z;
	char bez10[11];
} point3D_t;

float dist3D(point3D_t*);   // Prototyp

int main()
{
   float d;
   point3D_t pa={2.3, 1.4, 0.5, "PA"};   // Strukturen können auch direkt
                                        // initialisiert werden

   d = dist3D(&pa);

   printf("Abstand vom Nullpunkt: %6.2f\r\n",d);

   return 0;
}

float dist3D(point3D_t* p)
{
	float d;

	d = sqrt(p->x * p->x + p->y*p->y + p->z*p->z);
	return d;
}
