#ifndef MAIN_H
#define MAIN_H

// include files to use in main
#include <xc.h>
#include <stdlib.h>
#include <stdbool.h>
#include "configuration.h"
#include "DEFINITIONS.h"
#include "eusart.h"

// method primatives
__interrupt() void ISR(void);
extern unsigned char heartState;
extern unsigned char y;
extern unsigned char o;
extern unsigned char b;
void INIT(void);
void getRCREG(void);
void sendData(void);
void hbTOGL1000(void);
void hbTOGL(void);
void hbTOGL_CNTR(unsigned int count);
void ledTEST(void);
void clearRxTx(void);
void incrLED(unsigned int val);

#endif


