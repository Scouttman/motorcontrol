/*
 * structs.h
 *
 *  Created on: Mar 5, 2020
 *      Author: Ben
 */

#ifndef STRUCTS_H
#define STRUCTS_H




#include <stdint.h>
//#include <stdbool.h>
#include "gpio.h"
#include "adc.h"
#include "tim.h"
#include "position_sensor.h"
#include "preference_writer.h"
#include "fdcan.h"
#include "fsm.h"
#include "foc.h"
#include "calibration.h"

typedef struct{
    } GPIOStruct;

typedef struct{
    }COMStruct;


/* Global Structs */
extern ControllerStruct controller;
extern ObserverStruct observer;
extern COMStruct com;
extern FSMStruct state;
extern EncoderStruct comm_encoder;
extern PreferenceWriter prefs;
extern CalStruct comm_encoder_cal;
extern CANTxMessage can_tx;
extern CANRxMessage can_rx;

#endif
