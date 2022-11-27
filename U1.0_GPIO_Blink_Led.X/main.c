#include "main.h"
#include <stdint.h>

void main(void) {
    
    TRISD = 0;
    PORTD = 0xFF;
    
    uint8_t mask = 0xFF;
    
    while(1){
        for(int i = 0; i < 8; i++){
            mask = (mask << 1);
            PORTD = mask;
            __delay_ms(200);
        }
        for(int i = 0; i < 8; i++){
            mask = (mask << 1) | 0x01;
            PORTD = mask;
            __delay_ms(200);
        }
        
        mask = 0x7F;
        for(int i = 0; i < 8; i++){
            mask = (mask >> 1);
            PORTD = mask;
            __delay_ms(200);
        }
        for(int i = 0; i < 8; i++){
            mask = (mask >> 1) | 0x80;
            PORTD = mask;
            __delay_ms(200);
        }
        
    }
    
    return;
}
