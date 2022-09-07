/*
 * main_k1_0100.c
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
#include <math.h>	// fuer fabs

#define EPSILON 1e-10


int main()
{
	double a,b,x;
	a=0.9;
	b=0.8;
	x=a+b;

	// Ohne EPSILON
	if (x==1.7)
	{
		printf("x ist 1.7\r\n");
	}
	else
	{
		printf("x weicht von 1.7 um %e ab\r\n",x-1.7);
	}

	// Mit Epsilon
	if (fabs(x-1.7)<EPSILON)
	{
		printf("x ist ungefaehr 1.7\r\n");
	}

	return 0;
}
