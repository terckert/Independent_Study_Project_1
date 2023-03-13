#ifndef _MAIN_H
#define _MAIN_H

#include "mbed.h"
#include "DigitalOut.h"
#include "ThisThread.h"
#include <PinNames.h>
#include <iostream>
/*
	PINS CURRENTLY IN USE
	A:
        2  - UART_CONSOLE
        3  - UART_CONSOLE
		10 - LED MATRIX COL 1
		15 - BLUETOOTH TX
	B:
		1  - LED MATRIX ROW 4
		3  - LED MATRIX COL 2
		4  - LED MATRIX COL 4
		5  - LED MATRIX COL 3
		7  - BLUETOOTH RX	
		13 - LED MATRIX ROW 1
		14 - LED MATRIX ROW 2
		15 - LED MATRIX ROW 3
	C:
*/

#define LEDM_ROW1_PIN		PB_13
#define LEDM_ROW2_PIN		PB_14
#define LEDM_ROW3_PIN		PB_15
#define LEDM_ROW4_PIN		PB_1

#define LEDM_COL1_PIN		PA_10
#define LEDM_COL2_PIN		PB_3
#define LEDM_COL3_PIN		PB_5
#define LEDM_COL4_PIN		PB_4

#define BT_TX_PIN           PA_15
#define BT_RX_PIN           PB_7
#define BT_BAUD             9600

#define DELAY_TIME          150ms
#define COL_DELAY           2ms

#endif // _MAIN_H