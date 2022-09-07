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

typedef struct {
   char a;
   short int b;
} __attribute__ ((__packed__)) padded_t;


int main()
{

   printf("Sizeof padded_t: %i Bytes\r\n",sizeof(padded_t));
   return 0;
}
