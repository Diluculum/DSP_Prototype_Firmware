#ifndef DEFINITIONS_H
#define DEFINITIONS_H

// A Registers

// B Registers
#define heart_TRIS      TRISBbits.TRISB4
#define heart           PORTBbits.RB4

#define pstnLSC_TRIS    TRISBbits.TRISB0
#define pstnLSC         PORTBbits.RB0

#define pstnLC_TRIS     TRISBbits.TRISB1
#define pstnLC          PORTBbits.RB1

#define pstnFR_TRIS     TRISBbits.TRISB2
#define pstnFR          PORTBbits.RB2

#define icspCLK_TRIS    TRISBbits.TRISB6
#define icspCLK         PORTBbits.RB6

#define icspDAT_TRIS    TRISBbits.TRISB7
#define icspDAT         PORTBbits.RB7

// C Registers
#define dspSEL_TRIS     TRISCbits.TRISC0
#define dspSEL          PORTCbits.RC0

#define cmxSEL_TRIS     TRISCbits.TRISC1
#define cmxSEL          PORTCbits.RC1

#define mRESET_TRIS     TRISCbits.TRISC2
#define mRESET          PORTCbits.RC2

#define rvCTRL_TRIS     TRISCbits.TRISC3
#define rvCTRL          PORTCbits.RC3

#define ampFAULT_TRIS   TRISCbits.TRISC4
#define ampFAULT        PORTCbits.RC4

#define cmxIRQn_TRIS    TRISCbits.TRISC5
#define cmxIRQn         PORTCbits.RC5

#define uCTx_TRIS       TRISCbits.TRISC6
#define uCTx            PORTCbits.RC6

#define uCRx_TRIS       TRISCbits.TRISC7
#define uCRx            PORTCbits.RC7

// D Registers
#define spiCLK_TRIS     TRISDbits.TRISD0
#define spiCLK          PORTDbits.RD0

#define spiDATI_TRIS    TRISDbits.TRISD1
#define spiDATI         PORTDbits.RD1

#define spiDATO_TRIS    TRISDbits.TRISD2
#define spiDATO         PORTDbits.RD2

#define ringSIGH_TRIS   TRISDbits.TRISD3
#define ringSIGH        PORTDbits.RD3

#define ringSIGL_TRIS   TRISDbits.TRISD4
#define ringSIGL        PORTDbits.RD4

// Test Pins
#define YLLW_TRIS       TRISAbits.TRISA5
#define YLLW            PORTAbits.RA5

#define ORNG_TRIS       TRISEbits.TRISE1
#define ORNG            PORTEbits.RE1

#define BLUE_TRIS       TRISEbits.TRISE2
#define BLUE            PORTEbits.RE2

// OTHER REGISTERS
#define OP_REG           OPTION_REG

void INIT_PIN(void);
void INIT_EUSART(void);
void INIT_INTERRUPTS(void);
void INIT_TEST(void);

#endif