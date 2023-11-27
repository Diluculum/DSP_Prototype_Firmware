#include "eusart.h"
#include <xc.h>

#define RxBufSize 8
#define TxBufSize 8

unsigned char rxBuf[RxBufSize];
unsigned char rxHead = 0;
unsigned char rxTail = 0;
volatile char eusartRxCnt;

//void usartRCV(void){
//    unsigned char c;
//    if(OERR == 1){
//        CREN = 0;
//        CREN = 1;
//    } 
//    rxBuf[rxHead++] = RCREG;
//    if (sizeof rxBuf <= rxHead){
//        rxHead = 0;
//    }
//    eusartRxCnt++;
//}
//
//unsigned char readRx(void){
//    unsigned char c = 0;
//    while (eusartRxCnt == 0);
//    RCIE = 0;
//    c = rxBuf[rxTail++];
//    if(sizeof rxBuf <= rxTail){
//        rxTail = 0;
//    }
//    RCIE = 1;
//    return c;
//}

unsigned char getChar(void){
    unsigned char c;
    if(OERR){
        CREN = 0;
        CREN = 1;
    } 
    if(FERR){
        c = RCREG;
    }
    c = RCREG;
    return c;
}

unsigned int getData(unsigned char *data){
    unsigned int i = 0;
    unsigned char brkpnt = 0x04;
    for(i=0; i < 10; i++){
        *data = getChar();
        if(*data == brkpnt){
            clearRCREG();
            return i;
        }
        ++data;
    }
    clearRCREG();
    return i;
}

void clearRCREG(void){
    if(OERR){
        CREN = 0;
        CREN = 1;
    }
    if(FERR){
        
    }
    char c;
    c = RCREG;
    c = RCREG;
    c = RCREG;
    return;
}

void sendChar(unsigned char data){
    TXREG = data; 
    while(!TRMT);
}

void write2Reg(unsigned char *dat_st, int dat_end){
    //sendChar(0x02);
    for(int i=0; i<dat_end;i++){
        sendChar(*dat_st);
        dat_st++;
    }
    //sendChar(0x03);
}
