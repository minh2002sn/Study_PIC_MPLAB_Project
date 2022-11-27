#include "main.h"

void main(void) {
    OPTION_REG = 0x01;
    TMR0 = 5;
    INTCONbits.T0IE = 1;
    INTCONbits.T0IF = 0;
    INTCONbits.GIE = 1;
    
    TRISD = 0x00;
    PORTD = 0xFF;
    
    while(1){}
    
    return;
}

void __interrupt() ISR(){
    static unsigned int counter = 0;
    if(INTCONbits.T0IF == 1){
        TMR0 = 5;
        counter++;
        if(counter == 100){
            PORTDbits.RD0 = ~PORTDbits.RD0;
            counter = 0;
        }
        INTCONbits.T0IF = 0;
    }
}