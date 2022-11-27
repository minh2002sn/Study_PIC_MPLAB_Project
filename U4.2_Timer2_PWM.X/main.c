#include "main.h"

void main(void) {
    // Port D config
    TRISD = 0x00;
    PORTD = 0xff;
    
    // Interrupt config
    PIE1bits.TMR2IE = 1;
    PIR1bits.TMR2IF = 0;
    INTCONbits.PEIE = 1;
    INTCONbits.GIE = 1;
    
    // Timer 2 config
    T2CONbits.TOUTPS3 = 1;
    T2CONbits.TOUTPS2 = 0;
    T2CONbits.TOUTPS1 = 0;
    T2CONbits.TOUTPS0 = 1;
    T2CONbits.T2CKPS1 = 0;
    T2CONbits.T2CKPS0 = 1;
    PR2 = 250;
    T2CONbits.TMR2ON = 1;
    
    while(1){}
    
    return;
}

void __interrupt() ISR(){
    if(PIR1bits.TMR2IF == 1){
        PORTDbits.RD0 = ~PORTDbits.RD0;
        
        PIR1bits.TMR2IF = 0;
    }
}