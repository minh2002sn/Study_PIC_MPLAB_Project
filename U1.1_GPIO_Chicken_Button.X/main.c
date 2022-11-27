#include <pic16f877a.h>

#include "main.h"

int main(void){
    OPTION_REG = 0x00;
    TRISB = 1;
    TRISD = 0x00;
    PORTD = 0xFF;
    
    uint8_t mask = 0;
    uint8_t btn_state = 0;
    uint8_t btn_last_state = 0;

    while(1){
        btn_state = PORTBbits.RB0;
        if(btn_state != btn_last_state){
            if(btn_state == 0){
                mask++;
            }
            __delay_ms(100);
            btn_last_state = btn_state;
        }
        PORTD = ~mask;
    }
}
