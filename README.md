# RedPitaya-Hello-World-Software                                                                                
Extremely simple C programs to control the RedPitaya board with the official memory map. These programs are based on c-periphery.                                   
# Usage                                                                                                
                                                                                                       
Clone the repositiry                                                                                   
                                                                                                       
Copy the src folder to the RedPitaya                                                                   
                                                                                                       
Compile the C programs with                                                                            
                                                                                                       
```                                                                                                    
gcc xxx.c mmio.c -lm -o xxx               
```                                                                                                    
where xxx.c is the name of the C file.                                                                 
                                                                                                       
- The program leds_counter.c displays a binary incremental counter from 0 to 19 at a rate of 1Hz on the leds of the RedPitaya board.

- The program monitor16.c reads (monitor16 addr) or writes (monitor16 addr value_w) 2-byte numbers from address addr, i.e., to turn on LEDs 0-3 use:
```                                                                                                    
monitor16 0x40000030 0xf            
```

- The program monitor32.c reads (monitor32 addr) or writes (monitor32 addr value_w) 4-byte numbers from address addr, i.e., to turn on LEDs 0-3 use:
```                                                                                                    
monitor32 0x40000030 0xf            
```

- The program acquire_SINGLE.c acquires SIZE samples of a triggered signal on CH1 with trigger value TRIGGER (in volts) and GAIN = 20. 
```                                                                                                    
acquire_SINGLE SIZE TRIGGER           
```

- The program generate_BURST.c generates an arbitrary wave in burst or continuous mode. Define your arbitrary function in the program, default is Sine.
```                                                                                                    
generator_BURST amplitude(volt) frequency(MHz) n_cycles n_replicas delay(us or 0 for continuous mode) period(ms)  
```

- The program generate_STOP.c stops continuous mode.
```                                                                                                    
generator_STOP  
```

                                                                                                       
# Credits                                                                                              
                                                                                                       
These programas are straightforward applications of the c-periphery code available at                  
                                                                                                       
https://github.com/vsergeev/c-periphery                                                                
                                                                                                                                                
