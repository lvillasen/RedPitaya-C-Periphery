# RedPitaya-C-Periphery                                                                                
Simple programs to control the RedPitaya board based on c-periphery.                                   
                                                                                                       
                                                                                                       
                                                                                                       
                                                                                                       
# Usage                                                                                                
                                                                                                       
Clone the repositiry                                                                                   
                                                                                                       
Copy the src folder to the RedPitaya                                                                   
                                                                                                       
Compile the C programs with                                                                            
                                                                                                       
```                                                                                                    
gcc xxx.c mmio.c -o xxx                                                                                
```                                                                                                    
where xxx.c is the name of the C file.                                                                 
                                                                                                       
The program leds_counter.c will display a binary incremental counter at a rate of 1Hz on the leds of the RedPitaya board.
                                                                                                       
# Credits                                                                                              
                                                                                                       
These programas are straigthforward applications of the c-periphery code available at                  
                                                                                                       
https://github.com/vsergeev/c-periphery                                                                
                                                                                                       
therefore https://github.com/vsergeev deserves all the credit.                                         
