/********************************************************************
 *
 * Copyright Luighi Vitón, 2018
 * All Rights Reserved
 * Licensed under MIT license
 * 
 ********************************************************************
*/

/**
 * \file    isfetboard.h
 * \author  Luighi Viton <luighiavz@gmail.com>
 * \date    27 November 2018
 * \brief   Driver to control ISFET board.
 *
 * \details This file is the header to control the operation of ISFET  
 * board  which serves as an interface to it.
 */

#ifndef _ISFETBOARD_H_
#define _ISFETBOARD_H_

#include <SoftwareSerial.h>

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

/*! A class to read info from ISFET board */
class IsfetBoard{
	
	public:
		IsfetBoard(uint8_t pintx, uint8_t pinrx, int baudrate=9600);
		~IsfetBoard();
		float pH;
		float pHcomp;
		float temperature;
		void begin(void);
		char* read();
		void sendCommand(char* str);
		int readData();
		int calibrate(int mode,int pH);
	
	private:
		int listToData(char* tokens);
		int str2float (float* num, char const *s);
		uint8_t _pintx;
		uint8_t _pinrx;
		SoftwareSerial _serial;
		int _baudrate;
		char _str[50];
		char _infochar;
};

#endif /*_ISFETBOARD_H_ */
