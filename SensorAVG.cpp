#include "extern.h"

/**
 * Returns an averaged sensor value to deal with noise 
 */
int getSensorAVG(int sensor, int total){  
	init();  
	int adc_reading;  
	int count = 0; 
	while (count < total) {   
		adc_reading += read_analog(sensor);   
		count++;  
	}  
	adc_reading /= total;  
	return adc_reading;
} 
