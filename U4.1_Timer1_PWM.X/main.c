#include "main.h"

void main(void) {
    // Timer 1 config
    T1CONbits.T1CKPS1 = 0;
    T1CONbits.T1CKPS0 = 0;
    T1CONbits.TMR1CS = 0;
    TMR1H = (uint8_t)((0xffff - 9999) >> 8);
    TMR1L = (uint8_t)(0xffff - 9999);
    T1CONbits.TMR1ON = 1;
    
    // Timer 1 interrupt config
    PIE1bits.TMR1IE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.GIE = 1;
    
    // Port D config
    TRISD = 0x00;
    PORTD = 0xff;
    
    while(1){}
    
}

void __interrupt() ISR(){
    if(PIR1bits.TMR1IF == 1){
        PORTDbits.RD0 = ~PORTDbits.RD0;
        
        TMR1H = (uint8_t)((0xffff - 9999) >> 8);
        TMR1L = (uint8_t)(0xffff - 9999);
        PIR1bits.TMR1IF = 0;
    }
}
