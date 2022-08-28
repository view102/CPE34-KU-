#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/io.h>
#include <util/delay.h>

#define SWITCH_PRESSSED()  ((PINC & (1<<PC3)) == 0)

uint16_t read_adc(uint8_t channel)
{
    ADMUX = (0<<REFS1)|(1<<REFS0) // ระบุให้ใช้ VCC เป็นแรงดันอ้างอิง (Vref) และ
          | (0<<ADLAR)            // บันทึกผลลัพธ์ชิดขวาในคู่รีจีสเตอร์ ADCH/ADCL
          | (channel & 0b1111);   // ตั้งค่า MUX เป็นค่า channel
 
    ADCSRA = (1<<ADEN)            // เปิดวงจร ADC
           | (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0) // ใช้ความเร็ว 1/128 ของคล็อกระบบ
           | (1<<ADSC);           // สั่งวงจร ADC ให้เริ่มต้นการแปลง
 
    while ((ADCSRA & (1<<ADSC)))  // รอจนบิต ADSC กลายเป็น 0 ซึ่งหมายถึงการแปลงเสร็จสิ้น
       ;
 
    return ADCL + ADCH*256;  // ผลลัพธ์ถูกเก็บอยู่ในรีจีสเตอร์ ADCL และ ADCH
    // สามารถใช้ return ADC ได้เช่นกัน
}

int main(void)
{
    uint16_t light;
    uint8_t led = 0;

    DDRC  = 0b00000111; // PC0..PC2 => output, PC3..PC5 => input
    PORTC |= (1<<PC3);  // เปิดใช้ตัวต้านทานพูลอัพที่ขา PC3

    DDRD  |= (1<<PD3);  // PD3 => output
    PORTD |= (1<<PD3);  // PD3 -> 1 (LED ดับ)
    while (1)
    {
        // อ่านระดับแรงดันจากขา PC4 (อยู่ในช่วง 0-1023)
        light = read_adc(4);

        // ตีความแสง 3 ระดับ และแสดงผลบน LED สามสี
        if (light > 800)
            led = 0b100;  // เขียว
        else if (light > 600)
            led = 0b010;  // เหลือง
        else if (light > 400)
            led = 0b001;  // แดง
        PORTC &= ~(0b111);
        PORTC |= led;

        // ตรวจสอบสวิตช์
        if (SWITCH_PRESSSED())
        {
            _delay_ms(10);
            while (SWITCH_PRESSSED())
                ;
            _delay_ms(10);
            PORTD ^= (1<<PD3);  // กลับลอจิกขา PD3 โดยใช้ xor
        }
    }
}
