/*  _______ _______        _______ ________ _______             ______        ______
 * |    ___|   |   |______|     __|  |  |  |    ___|    .--.--.|      |______|   __ \.----.-----.-----.
 * |    ___|       |______|__     |  |  |  |    ___|    |  |  ||   ---|______|    __/|   _|  _  |  _  |
 * |___|   |___|___|      |_______|________|___|        |_____||______|      |___|   |__| |_____|___  |
 *                                                                                              |_____|
 *  K7_0100_handle / main.c
 *
 *  Code-Samples Lehrbrief "Mikrocontroller-Programmierung"
 *
 *  (c) Prof. Tobias Ellermeyer
 *      Fachhochschule Suedwestfalen
 *
 *  Last Update: SoSe 2023
 */


#include <stdio.h>
#include <stdlib.h>         // File processing
#include <string.h>

int main()
{
    char *filename="text.txt";
    short int i;

    FILE* filehandle = NULL;

    printf("Opening File %s for read/append\r\n",filename);

    filehandle=fopen(filename, "w+");		// w+ -> Write append

    if (filehandle == NULL)
    {
    	printf("Opening %s failed!\r\n",filename);
    	return 1;
    }

    for (i=1;i<=4;i++)
    {
    	fprintf(filehandle,"%i squares is %i\r\n",i,i*i);
    }

    fclose(filehandle);
	return 0;
}
