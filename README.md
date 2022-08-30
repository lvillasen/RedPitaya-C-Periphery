# RedPitaya-C-Periphery                                                                                
Extremely simple C programs to control the RedPitaya board with the official ecosystem. These programs are based on c-periphery.                                   
                                                                                                                                    
                                                                                                       
# Usage                                                                                                
                                                                                                       
Clone the repositiry                                                                                   
                                                                                                       
Copy the src folder to the RedPitaya                                                                   
                                                                                                       
Compile the C programs with                                                                            
                                                                                                       
```                                                                                                    
gcc xxx.c mmio.c -lm -o xxx               
```                                                                                                    
where xxx.c is the name of the C file.                                                                 
                                                                                                       
- The program leds_counter.c displays a binary incremental counter at a rate of 1Hz on the leds of the RedPitaya board.

- The program monitor16.c reads (monitor16 addr) or writes (monitor16 addr value_w) 2-byte numbers from address addr, i.e., to turn on LEDs 0-3 use:
```                                                                                                    
monitor16 0x40000030 0xf            
```

- The program acquire_SINGLE.c acquires SIZE samples of a triggered signal with trigger value TRIGGER where TRIGGER is in volts
```                                                                                                    
acquire_SINGLE SIZE TRIGGER           
```

                                                                                                       
# Credits                                                                                              
                                                                                                       
These programas are straightforward applications of the c-periphery code available at                  
                                                                                                       
https://github.com/vsergeev/c-periphery                                                                
                                                                                                       
therefore https://github.com/vsergeev deserves all the credit.                                         
