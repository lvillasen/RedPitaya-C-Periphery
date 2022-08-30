#include <stdio.h>                                                                                                                                
#include <stdlib.h>                                                                                                                               
#include <stdint.h>                                                                                                                               
                                                                                                                                                  
#include "mmio.h"  

#include<stdio.h>
#include<math.h>
#define GAIN 20.0 
//#define GAIN 1.0 
//######################################## inputs
//CHANNEL = 1 # 1 
//########################################
int v_to_counts(float voltage)
{
    unsigned int  adc_cnts ;
    if(voltage > GAIN) voltage = GAIN;
if (voltage < -GAIN) voltage = -GAIN;
    if(voltage >= 0) 
        adc_cnts = (int)round(voltage/GAIN*pow(2,13)-1);
    else
        adc_cnts = (int)round((1+voltage/GAIN)*pow(2,13)+pow(2,13));
    return adc_cnts;
} 

float counts_to_v(unsigned int counts)
{    
    float voltage;
    if(counts > pow(2,14)-1) counts = pow(2,14)-1;
    if(counts <pow(2,13)) 
        voltage = GAIN*(counts+1)/pow(2,13); 
    else 
        voltage =  GAIN*((counts-pow(2,13))/pow(2,13) -1);
    return voltage;
}
int main(int argc, char **argv) {                                                                                                                 
    int i;                                                                                                                                        
    uint32_t addr;                                                                                                                                
    uint32_t  value_r, value_w, SIZE, ptr_trig;                                                                                                                 
    float TRIGGER_TRES;                                                                                                                                         
   // for (i=0; i<argc; i++) printf ("%s\n", argv[i]);                                                                                            
    if (argc == 3) { 
        SIZE = strtol(argv[1], NULL, 0);
        TRIGGER_TRES =   atof(argv[2]);  
    }  else {
        SIZE = 1024 ; 
        TRIGGER_TRES = -0.5 ;
    }  
    //printf ("Size = %d Trigger Treshold = %3.4f \n",SIZE,TRIGGER_TRES);
                                                                                                                                      
    mmio_t *mmio;                                                                                                                                 
                                                                                                                                                  
    mmio = mmio_new();                                                                                                                            
                                                                                                                
    /* Open control module */                                                                                                                     
    if (mmio_open(mmio, 0x40100000, 0x1FFFC) < 0) {                                                                                                         
        fprintf(stderr, "mmio_open(): %s\n", mmio_errmsg(mmio));                                                                                  
        exit(1);                                                                                                                                  
    }   
  // mmio_write32(mmio, 0, 2); // reset write state machine
    mmio_write16(mmio, 0x4, 3); // 2-ch A threshold positive edge
    mmio_write32(mmio, 0x8,v_to_counts(TRIGGER_TRES)); // Ch A threshold
   mmio_write32(mmio, 0x14, 1); // decimation
   mmio_write32(mmio, 0x10, 8000); // decimation
   //printf ("Trigger treshold set at %3.4f  = %d \n",TRIGGER_TRES,v_to_counts(TRIGGER_TRES));
    mmio_write32(mmio, 0x0,1); // arm trigger
    //sleep(5);
    while(1) {    
        mmio_read32(mmio, 0, &value_r); // trigger status
    //printf("%d ",value_r);     
                if (value_r > 5)
		{	
                   // mmio_write32(mmio, 0, 2); // reset write state machine
     //             printf("Trigger status: %d\n",value_r);
                        break;
                 }  
    }
mmio_read32(mmio,0x1C, &ptr_trig);
ptr_trig -= 50; // start 50 samples before trigger pointer
                  //printf("Trigger status: %d ptr_trig: %d\n",value_r,ptr_trig);
    for (uint32_t offset_addr = 0x10000+ptr_trig*4 ; offset_addr < 0x10000+ptr_trig*4 + SIZE*4 ; offset_addr+= 4)  {
mmio_read32(mmio,offset_addr, &value_r);
printf ("%3.4f\n",counts_to_v(value_r));

       } 
    mmio_close(mmio);                                                                                                                             
    mmio_free(mmio);                                                                                                                              
    return 0;                                                                                                                                     
}              
