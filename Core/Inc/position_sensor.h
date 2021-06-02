/*
 * position_sensor.h
 *
 *  Created on: Jul 26, 2020
 *      Author: Ben
 */

#ifndef INC_POSITION_SENSOR_H_
#define INC_POSITION_SENSOR_H_


//#include "structs.h"
//#include "spi.h"
#include <stdint.h>
#include <stdbool.h>

#define N_POS_SAMPLES 20		// Number of position samples to store.  should put this somewhere else...
#define N_LUT 10 //128

typedef struct{
	float angle_singleturn, old_angle, angle_multiturn[N_POS_SAMPLES], elec_angle, velocity, elec_velocity, ppairs, vel2;
	float output_angle_multiturn;
	int raw, count, old_count, turns;
	int m_zero, e_zero;
	int offset_lut[N_LUT];
	uint8_t first_sample;
	int pos;
	bool homed;
} EncoderStruct;


void ps_sample(EncoderStruct * encoder, float dt);
void ps_print(EncoderStruct * encoder, int dt_ms);
void ps_increment(EncoderStruct * encoder, bool dir);
void ps_home(EncoderStruct * encoder);


#endif /* INC_POSITION_SENSOR_H_ */
