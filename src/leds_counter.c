#include <stdio.h>                                                                                     
#include <stdlib.h>                                                                                    
#include <stdint.h>                                                                                    
#include <unistd.h>                                                                                    
                                                                                                       
#include "mmio.h"                                                                                      
                                                                                                       
int main(void) {                                                                                       
    uint32_t leds_w;                                                                                   
    mmio_t *mmio;                                                                                      
    mmio = mmio_new();                                                                                 
    /* Open control module */                                                                          
    if (mmio_open(mmio, 0x40000000, 0x1000) < 0) {                                                     
        fprintf(stderr, "mmio_open(): %s\n", mmio_errmsg(mmio));                                       
        exit(1);                                                                                       
    }                                                                                                  
    for (leds_w=0; leds_w<20; leds_w++){                                                               
        mmio_write16(mmio, 0x30, leds_w);                                                              
sleep(1);                                                                                              
    }                                                                                                  
    mmio_close(mmio);                                                                                  
    mmio_free(mmio);                                                                                   
    return 0;                                                                                          
}            
