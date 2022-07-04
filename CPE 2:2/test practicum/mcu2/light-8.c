#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "peri.h"

int main(){
        uint16_t light;
        init_peri();
        while(1){ 
                light = read_adc(PC4);
                if(light < 700){ 
                        set_led_value(0b000);
                }else if(light < 730){ 
                        set_led_value(0b001);
                }else if(light < 760){ 
                        set_led_value(0b010);
                }else if(light < 790){ 
                        set_led_value(0b011);
                }else if(light < 820){ 
                        set_led_value(0b100);
                }else if(light < 850){ 
                        set_led_value(0b101);
                }else if(light < 880){ 
                        set_led_value(0b110);
                }else{
                        set_led_value(7);
                }
        }
}