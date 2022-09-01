#include <stdio.h>                                                                                                                                
#include <stdlib.h>                                                                                                                               
#include <stdint.h>                                                                                                                               
                                                                                                                                                  
#include "mmio.h"                                                                                                                                 
int main(int argc, char **argv) {                                                                                                                 
    int i;                                                                                                                                        
    uint32_t addr;                                                                                                                                
uint32_t        value_r, value_w;                                                                                                                                                                                                                                                              
    //for (i=0; i<argc; i++) printf ("%s\n", argv[i]);                                                                                                                                                                                                                                        
    mmio_t *mmio;                                                                                                                                                                                                                                                                             
    mmio = mmio_new();                                                                                                                            
addr= strtol(argv[1], NULL, 0);                                                                                                                   
    /* Open control module */                                                                                                                     
    if (mmio_open(mmio, addr, 0x4) < 0) {                                                                                                         
        fprintf(stderr, "mmio_open(): %s\n", mmio_errmsg(mmio));                                                                                  
        exit(1);                                                                                                                                  
    }                                                                                                                                                                                                                                                                                                                                                                                                                                        
       if (argc == 2) {                     // read                                                                                                                                                                                                                                             
    if (mmio_read32(mmio, 0, &value_r) < 0) {                                                                                                     
        fprintf(stderr, "mmio_read32(): %s\n", mmio_errmsg(mmio));                                                                                
        exit(1);                                                                                                                                  
        }                                                                                                                                         
        printf("read 0x%04x from address 0x%08x\n", value_r,addr);                                                                                
}                                                                                                                                                 
       if (argc == 3) {                     // write                                                                                              
        value_w= strtol(argv[2], NULL, 0);                                                                                                        
                                                                                                                                                  
    if (mmio_write32(mmio, 0, value_w) < 0) {                                                                                                     
        fprintf(stderr, "mmio_write32(): %s\n", mmio_errmsg(mmio));                                                                               
        exit(1);                                                                                                                                  
    }                                                                                                                                             
        printf("wrote 0x%04x to address 0x%08x\n", value_w,addr);                                                                                 
}                                                                                                                                                 
    mmio_close(mmio);                                                                                                                                                                                                                                                          
    mmio_free(mmio);                                                                                                                              
    return 0;                                                                                                                                     
}              
