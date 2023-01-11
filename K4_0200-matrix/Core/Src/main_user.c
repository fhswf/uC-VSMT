/*
 * main_user.c
 *
 *  Created on: Jan 11, 2023
 *      Author: Tobias Ellermeyer
 */


#include "main.h"
#include <stdio.h>

/******************************************************************
 * This example uses a 4x4 Key-Pad connected
 * to D5 ... D12 on the nucleo board
 *
 * D5 ... D8  are the receiving lines (PB4, PB10, PA8, PA9)
 * D9 ... D12 are the driving lines (PC7, PB6, PA7, PA6)
 *
 * NOTE: This order is due to the Nucleo-Pin-header and is far
 *       from optimal with respect to fast code
 ******************************************************************/

/*********************************************
 * Set Outputs of driving key lines
 * according to bit pattern
 * -> Bit x set in col means low on KEY_Tx
 *********************************************/
static void set_column(uint8_t col)
{
	HAL_GPIO_WritePin(KEY_T0_GPIO_Port, KEY_T0_Pin, (col & 0x01)==0);
	HAL_GPIO_WritePin(KEY_T1_GPIO_Port, KEY_T1_Pin, (col & 0x02)==0);
	HAL_GPIO_WritePin(KEY_T2_GPIO_Port, KEY_T2_Pin, (col & 0x04)==0);
	HAL_GPIO_WritePin(KEY_T3_GPIO_Port, KEY_T3_Pin, (col & 0x08)==0);
}

/*********************************************
 * Read in the four receiving lines and
 * return bit pattern
 * If Key is pressed, the line reads a 0
 *********************************************/
static uint8_t read_row()
{
	uint8_t key = 0;

	key |= HAL_GPIO_ReadPin(KEY_R0_GPIO_Port, KEY_R0_Pin);
	key |= HAL_GPIO_ReadPin(KEY_R1_GPIO_Port, KEY_R1_Pin)<<1;
	key |= HAL_GPIO_ReadPin(KEY_R2_GPIO_Port, KEY_R2_Pin)<<2;
	key |= HAL_GPIO_ReadPin(KEY_R3_GPIO_Port, KEY_R3_Pin)<<3;
	return key;
}

void main_user()
{
	char keys[]={
			'x',				// Dummy entry for idx 0, as idx=0 is used for "no key"
			'1','4','7','A',
			'2','5','8','0',
			'3','6','9','B',
			'C','D','E','F'};
	uint8_t k;					// the result of read_row()
	uint8_t i;

	uint8_t idx;				// index of currently pressed key (idx=0->no key)
	uint8_t idx_old=0;			// old value of last loop

	printf("*** HERE WE GO ***\r\n");
	printf("-> Press any key on the Matrix\r\n\n");

	while(1)
	{
		idx = 0;				// reset idx
		for (i=0;i<4;i++)		// loop throu columns 0...3
		{
			set_column(1<<i);	// set column line to high
			HAL_Delay(1);		// wait to settle
			k = read_row();		// read result
			switch(k)			// evaluate and set k
			{
				case 0b1110: k=1; break;		// Key pressed -> 0
				case 0b1101: k=2; break;
				case 0b1011: k=3; break;
				case 0b0111: k=4; break;
				default: k=0; break;
			}
			if (k!=0)			// only update idx if we have a key press
			{
				idx=i*4+k;
			}
		}
		if (idx!=idx_old)		// Chech if same result as last run
		{
			if (idx != 0)		// idx!=0 -> Key was pressed
			{
				printf("Pressed %c\r\n",keys[idx]);
			}
			else				// Key was released
			{
				printf("Released %c\r\n",keys[idx_old]);
			}
			idx_old=idx;		// store state for next run
		}

		HAL_Delay(10);
	}
}

