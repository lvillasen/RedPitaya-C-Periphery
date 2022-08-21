# RedPitaya-C-Periphery                                                                                
Extremely simple C programs to control the RedPitaya board with the official ecosystem based on c-periphery .                                   
                                                                                                                                    
                                                                                                       
# Usage                                                                                                
                                                                                                       
Clone the repositiry                                                                                   
                                                                                                       
Copy the src folder to the RedPitaya                                                                   
                                                                                                       
Compile the C programs with                                                                            
                                                                                                       
```                                                                                                    
gcc xxx.c mmio.c -o xxx               
```                                                                                                    
where xxx.c is the name of the C file.                                                                 
                                                                                                       
- The program leds_counter.c displays a binary incremental counter at a rate of 1Hz on the leds of the RedPitaya board.

- The program monitor16.c reads (monitor16 addr) or writes (monitor16 addr value_w) 2-byte numbers, i.e.,
```                                                                                                    
monitor16 0x40000030 0xf            
```turns on LEDs 0-3
                                                                                                       
# Credits                                                                                              
                                                                                                       
These programas are straightforward applications of the c-periphery code available at                  
                                                                                                       
https://github.com/vsergeev/c-periphery                                                                
                                                                                                       
therefore https://github.com/vsergeev deserves all the credit.                                         
