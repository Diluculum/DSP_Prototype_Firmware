/* 
 * File:   main.c
 * Author: smcch
 *
 * Created on May 2, 2023, 3:54 PM
 */

#include "main.h"

unsigned char heartState = 1;
    unsigned char y = 1;
    unsigned char o = 1;
    unsigned char b = 1;
    unsigned int counter = 0;
unsigned int datTrans = 0;
enum {buf_size = 16};
unsigned char buf_rx[buf_size];  // 16 byte buffer
unsigned char *dat_end = &buf_rx[0];
unsigned int  i = 0;
unsigned char buf[5] = {0x02,0x13,0x08,0x05,0x03};
unsigned int rts = 0;


void INIT(void){
    INIT_PIN();
    clearRCREG();
    INIT_EUSART();
    INIT_INTERRUPTS();
    INIT_TEST();
    heartState = heart;
    y = YLLW;
    o = ORNG;
    b = BLUE;
    counter = 0;
    __delay_ms(10);
    clearRCREG();
}

__interrupt() void ISR(void){
    //hbTOGL();
    if(RCIF == 1){
        
    }
}

/*
 * MAIN --------------------------------------------------
 */
void main(void) {
    INIT();
    while(true){
        //hbTOGL1000();
        if(RCIF == 1){
            getRCREG();
        }
    }
    heart = 1;
}
/*
 * MAIN --------------------------------------------------
 */

void getRCREG(void){
    buf_rx[i] = getChar();
    //clearRCREG();
    if(buf_rx[i] == 0x00){
    }else if(i >= 2){
        buf[1] = buf_rx[0];
        buf[2] = buf_rx[1];
        buf[3] = buf_rx[2];
        clearRCREG();
        sendData();
        incrLED(++i);
        rts = 1;
        i=0;
        dat_end = &buf_rx[0];
    }else{
        ++dat_end;
//        i++;
        incrLED(++i);
    }
    return;
}

void sendData(void){
    rts = 0;
    write2Reg(&buf[0], 5);
    buf[1] = 'a';
    buf[2] = 0x08;
    buf[3] = 0x05;
    return;
}

void hbTOGL1000(void){
    __delay_ms(1000);
    heartState = !heartState;
    heart = heartState;
    //ledTEST();
}

void hbTOGL(void){
    int count = 0;
    while(count < 10){
        __delay_ms(50);
        heartState = !heartState;
        heart = heartState;
        count++;
    }
    return;
}

void hbTOGL_CNTR(unsigned int count){
    for(unsigned int i=0;i<count;i++){
        heartState = heart;
        __delay_ms(300);
        heartState = !heartState;
        heart = heartState;
        __delay_ms(100);
        heartState = !heartState;
        heart = heartState;
    }
    return;
}

void ledTEST(void){
    switch(counter){
        case 0:
            y = !y;
            YLLW = y;
            break;
        case 1:
            o = !o;
            ORNG = o;
            break;
        case 2:
            b = !b;
            BLUE = b;
            break;
    }
    counter++;
    if(counter > 2){
        counter = 0;
    }
    return;
}

void clearRxTx(void){
    i=0;
    dat_end=&buf_rx[0];
    return;
}

void incrLED(unsigned int val){
    switch(val){
        case 1:
            ORNG = 0;
            YLLW = 1;
            BLUE = 1;
            break;
        case 2:
            ORNG = 1;
            YLLW = 0;
            BLUE = 1;
            break;
        case 3:
            ORNG = 0;
            YLLW = 0;
            BLUE = 1;
            break;
        case 4:
            ORNG = 1;
            YLLW = 1;
            BLUE = 0;
            break;
        default:
            ORNG = 1;
            YLLW = 1;
            BLUE = 1;
            break;
    }
}

