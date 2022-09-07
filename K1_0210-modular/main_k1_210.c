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
#include "point3D.h"

int main()
{
   float d;
   point3D_t pa={2.3, 1.4, 0.5, "PA"};   // Strukturen können auch direkt
                                        // initialisiert werden

   d = dist3D(&pa);
   printf("Abstand vom Nullpunkt: %6.2f\r\n",d);

   print3D(&pa);

   return 0;
}

