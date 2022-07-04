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
                        set_led_value(0);
                }else if(light < 730){ 
                        set_led_value(1);
                }else if(light < 760){ 
                        set_led_value(2);
                }else if(light < 790){ 
                        set_led_value(3);
                }else if(light < 820){ 
                        set_led_value(4);
                }else if(light < 850){ 
                        set_led_value(5);
                }else if(light < 880){ 
                        set_led_value(6);
                }else{
                        set_led_value(7);
                }
        }
}