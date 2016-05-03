#include "extern.h"

/**
 * @param sensor the sensor port to use for the averaging
 * @param total the number of samples to take
 * @return an averaged sensor value to minimise noise
 */
int get_sensor_average(int sensor, int total){
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
