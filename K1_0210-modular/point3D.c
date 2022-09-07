/*
 * point3D.c
 *
 *  Created on: 06.09.2022
 *      Author: Tobias Ellermeyer
 */


#include <stdio.h>
#include <math.h>
#include "point3D.h"	// Wir brauchen auch hier die Deklarationen

float dist3D(point3D_t* p)
{
	float d;

	d = sqrt(p->x * p->x + p->y*p->y + p->z*p->z);
	return d;
}

void print3D(point3D_t* p)
{
	printf("%s(%4.2f/%4.2f/%4.2f)\r\n\n",p->bez10, p->x, p->y, p->z);
}
