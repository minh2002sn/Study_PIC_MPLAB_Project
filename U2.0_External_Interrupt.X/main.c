#include "main.h"

void main(void) {
    TRISB = 0x11;
    TRISD = 0x00;
    PORTD = 0xFF;
    OPTION_REGbits.nRBPU = 0;
    INTCONbits.GIE = 1;
    OPTION_REGbits.INTEDG = 1;
    INTCONbits.INTE = 1;
    INTCONbits.INTF = 0;
    INTCONbits.RBIE = 1;
    INTCONbits.RBIF = 0;
    
    while(1){

    }
    
    return;
}

void __interrupt() ISR(){
    if(INTCONbits.INTF == 1){
        PORTDbits.RD0 = !PORTDbits.RD0;
        INTCONbits.INTF = 0;
    }
    if(INTCONbits.RBIF == 1){
        PORTDbits.RD1 = !PORTDbits.RD1;
        INTCONbits.RBIF = 0;
    }
}
