#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "peri.h"

int main(){
        uint8_t count = 0;

        init_peri();
        set_led_value(0);
        while(1){
                //wait until sw is pressed
                while(!SWITCH_PRESSED())
                        ;
                _delay_ms(20);
                count++;
                set_led_value(count);

                //wait until sw is released
                while(SWITCH_PRESSED())
                        ;
                _delay_ms(20);
        }
}