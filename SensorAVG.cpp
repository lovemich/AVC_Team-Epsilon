/**
 * Returns an averaged sensor value to deal with noise 
 */

extern "C" int InitHardware(); 
extern "C" int ReadAnalog(int ch_adc); 
int getSensorAVG(int sensor, int total){  
	InitHardware();  
	int adc_reading;  
	int count = 0; 
	while (count < total) {   
		adc_reading += ReadAnalog(sensor);   
		count++;  
	}  
	adc_reading /= total;  
	return adc_reading;
} 
