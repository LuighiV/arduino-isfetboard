/********************************************************************
 *
 * Copyright Luighi Vitón, 2018
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * 
 ********************************************************************
*/

/**
 * \file    isfetboard.c
 * \author  Luighi Viton <luighiavz@gmail.com>
 * \date    27 November 2018
 * \brief   Driver to control ISFET board.
 *
 * \details This file contains methods for the operation of ISFET  
 * board  which serves as an interface to it.
 */

#include "isfetboard.h"
#include <SoftwareSerial.h>
#include "string.h"

IsfetBoard::IsfetBoard(uint8_t pintx, uint8_t pinrx, int baudrate=9600) :
	_serial(pintx,pinrx){
	_pintx = pintx;
	_pinrx = pinrx;
	_baudrate = baudrate;
	
	pH = NAN;
    pHcomp = NAN;
	temperature = NAN;
}

IsfetBoard::~IsfetBoard(){
	delete this;
}

void IsfetBoard::begin(void){
	_serial.begin(_baudrate);
	delay(1000);
	
}

int IsfetBoard::readData(){

	_serial.write("R 1 \n\r");
	delay(1000);
	char* temporal;
	temporal = read();
	
	//Serial.println(temporal);
	
	char* tokens;
	tokens = strtok(temporal,"\n");
	
	//Serial.println(tokens);
	
	listToData(tokens);
	
	return 0;
}

int IsfetBoard::listToData(char* tokens){
	char* str;
	int count = 0;
	
	float values[3];
	float temp;
	str = strtok(tokens,",");
	//Serial.print("token: ");
	//Serial.println(str);
	
	str2float(&temp,str);
	values[0] = temp;
	//Serial.print("converted: ");
	//Serial.println(values[count]);
	count++;
	
	while(str!=NULL && count<3){
		str= strtok(NULL,",");
		//Serial.print("token: ");
		//Serial.println(str);
		
		str2float(&temp,str);
		values[count] = temp;
 		//Serial.print("converted: ");
		//Serial.println(values[count]);
		count++;
	}
	
	if (count!=3){
		return -1;
	}
	
	if (values[0]<0 && values[0]>14){
		return -1;
	}else{
		pHcomp = values[0];
	}
	
	if (values[1]<0 && values[1]>14){
		return -1;
	}else{
		pH = values[1];
	}
	
	if (values[2]<5.6 && values[2]>70){
		return -1;
	}else{
		temperature = values[2];
	}
	
	return 0;
}

int IsfetBoard::str2float (float* num, char const *s)
{
    char *end;
    double  d;
    d = 0;
    d = strtod(s, &end);
    
    if (*s == '\0' || *end != '\0') {
        return -1;
    }
    * num = d;
    return 0;
}

char* IsfetBoard::read()
{
	int count=0;
	int character = 0;
	
	memset(_str,0,sizeof(_str));
	
	while (_serial.available()>0){
		
			character=_serial.read();		
			_str[count] =(char)character;
			count++;
	}
	return _str;
}

void IsfetBoard::sendCommand(char* str){
	
	_serial.write(str);
}

int IsfetBoard::calibrate(int mode,int pH){
	return 0;
}

