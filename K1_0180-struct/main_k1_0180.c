/*
 * main_k1_0190.c
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


struct point_3D {   // Dies ist nur das Gerüst
	float x;		// (die "Bauanleitung")
	float y;
	float z;
	char bez10[11];
};

/*typedef struct  {   // Dies ist nur das Gerüst
	float x;		// (die "Bauanleitung")
	float y;
	float z;
	char bez10[11];
} point3D_t;
*/

int main()
{
   struct point_3D p1,p2;		// Zwei Punkte anlegen
//   point3D_t p1,p2;		// Zwei Punkte anlegen

   p1.x = 2.3;
   p1.y = 1.4;
   p1.z = 0.5;
   strcpy(p1.bez10,"P1"); // Achtung, p1.bez10="P1" funktioniert nicht!

   printf("%s(%4.2f/%4.2f/%4.2f)\r\n\n",p1.bez10, p1.x, p1.y, p1.z);

   p2 = p1;		// Zuweisung kopiert Inhalt
   strcpy(p2.bez10,"P2"); // Werte ändern
   p2.z = -0.5;

   // Zunächst P1 nochmal ausgeben, um zu prüfen, dass
   // dieser nicht geändert wurde (das wäre so, wenn
   // p2=p1 nur den Verweis auf den Speicher kopiert)
   printf("%s(%4.2f/%4.2f/%4.2f)\r\n",p1.bez10, p1.x, p1.y, p1.z);
   printf("%s(%4.2f/%4.2f/%4.2f)\r\n",p2.bez10, p2.x, p2.y, p2.z);

   return 0;
}
