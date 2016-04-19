#include <stdio.h>
#include <string.h>

extern "C" {
    int init(); // InitHardware()
    int read_analog(int ch_adc); // ReadAnalog(int ch_adc)
    int Sleep(int sec, int usec);
}

int main() {
    init();
    return 0;
}
