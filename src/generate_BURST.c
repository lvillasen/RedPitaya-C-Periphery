#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include<unistd.h>
#include "mmio.h"
#include<stdio.h>
#include<math.h>
double PI = 3.14159265358979323846;
unsigned int  BUFFER_SIZE = 16384;
//######################################## inputs
//CHANNEL = 1 # 1
//########################################
float fun(unsigned int x)         // function definition
{
    double f;
    f = sin(2*PI*x/BUFFER_SIZE);
    return f;
}
int v_to_counts(float voltage)
{
    unsigned int  adc_cnts ;
    if(voltage > 1.0) voltage = 1.0;
if (voltage < -1.0) voltage = -1.0;
    if(voltage >= 0)
        adc_cnts = (int)round(voltage*pow(2,13)-1);
    else
        adc_cnts = (int)round((1+voltage)*pow(2,13)+pow(2,13));
    return adc_cnts;
}
int main(int argc, char **argv) {
    float AMPLITUDE =1.0;
    float  FREQUENCY = 1.0;
    unsigned int N_CYCLES = 2;
    unsigned int N_REPLICAS = 2;
    unsigned int DELAY = 10;
    unsigned int  PERIOD = 1000; // in ms
//    for (int i=0; i<argc; i++) printf ("%s\n", argv[i]);
if (argc == 7) {
        AMPLITUDE =   atof(argv[1]);
        FREQUENCY = atof(argv[2]) ; // MHz
        N_CYCLES = strtol(argv[3], NULL, 0);
        N_REPLICAS = strtol(argv[4], NULL, 0);
        DELAY = strtol(argv[5], NULL, 0);
        PERIOD = strtol(argv[6],NULL, 0);
    } else {
printf("Usage: generate_BURST amplitude(volt) frequency(MHz) n_cycles n_replicas delay(us or 0 for continuous mode) period(ms)  \n");
printf("Define your arbitrary function in the program, default is Sine  \n");
return -1;}
    mmio_t *mmio;
    mmio = mmio_new();
    if (mmio_open(mmio, 0x40200000, 0x1FFFC) < 0) {
        fprintf(stderr, "mmio_open(): %s\n", mmio_errmsg(mmio));
        exit(1);
    }

    mmio_write32(mmio, 0, 0x80); // stop DAC1
    unsigned int step = (int) (pow(2,16) * FREQUENCY /125 * BUFFER_SIZE);
    mmio_write32(mmio, 0x10,step); // write step
    mmio_write32(mmio, 0x18, N_CYCLES); // number of read cycles in one burst
    mmio_write32(mmio, 0x1C, N_REPLICAS); // number of burst repetitions
    mmio_write32(mmio, 0x20, DELAY); // delay between burst repetitions in us
    for (unsigned int offset_addr = 0x10000; offset_addr < 0x10000 + (int)BUFFER_SIZE*4 ; offset_addr+= 4)
    {
    mmio_write32(mmio, offset_addr,v_to_counts(AMPLITUDE*fun((int)offset_addr/4))); // copy wave to memory register
    }
    mmio_write32(mmio, 0,1); // start DAC1 in 1-trig immediately configuration
    int n = 0;
    while(DELAY >0) {
    n += 1 ;
    mmio_write32(mmio, 0,1); // start DAC1 in 1-trig immediately configuration
    usleep(PERIOD*1000);
    mmio_write32(mmio, 0,0); //
    }
    mmio_close(mmio);
    mmio_free(mmio);
    return 0;
}
