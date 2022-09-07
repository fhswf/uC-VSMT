/*
 * point3D.h
 *
 *  Created on: 06.09.2022
 *      Author: Tobias Ellermeyer
 */

#ifndef POINT3D_H_
#define POINT3D_H_


typedef struct  {   // Dies ist nur das Gerüst
	float x;		// (die "Bauanleitung")
	float y;
	float z;
	char bez10[11];
} point3D_t;

float dist3D(point3D_t*);   	// Distance to (0,0,0)
void  print3D(point3D_t *);		// Print Point data

#endif /* POINT3D_H_ */
