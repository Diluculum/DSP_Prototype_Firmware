#include "DEFINITIONS.h"
#include <xc.h>
#include "eusart.h"

void INIT_PIN(void){
    
    TRISB  = 0b00000110;
    TRISC  = 0b01101100;
    TRISD  = 0b00000010;
    ANSEL  = 0b00000000;
    ANSELH = 0b00000000;
    heart  = 0;
}

void INIT_EUSART(void){
    PIR1    = 0b00000000; // - | adif | rcif | txif | sspif | ccp1if | tmr2if | tmr1if
    PIR2    = 0b00000000; // osfif | c2if | c1if | eeif | bclif | ulpwuif | - | ccp2if
    RCSTA   = 0b00000000;
    TXSTA   = 0b00000000;
    SPBRG   = spbrg_val;
    BAUDCTL = 0b01000000; // abdovf | rcidl | - | sckp | brg16 | - | wue | abden 
    RCSTA   = 0b10010000; // spen | rx9 | sren | cren | adden | ferr | oerr | rx9d
    TXSTA   = 0b00100100; // csrc | tx9 | txen | sync | sendb | brgh | trmt | tx9d
}
void INIT_INTERRUPTS(void){
    OP_REG = 0b00000000;
    PIE1   = 0b00000000;
    INTCON = 0b00000000;
    
    OP_REG = 0b01000000; // rabpu | intedg | t0cs | t0se | psa | ps2 | ps1 | ps0
    PIE1   = 0b00000000; // - | adie | rcie | txie | sspie | ccp1ie | tmr2ie | tmr1ie
    INTCON = 0b00000000; // gie | peie | t0ie | inte | rbie | t0if | intf | rbif
}

void INIT_TEST(void){
    YLLW_TRIS = 0;
    ORNG_TRIS = 0;
    BLUE_TRIS = 0;
    
    YLLW = 1;
    ORNG = 1;
    BLUE = 1;
}