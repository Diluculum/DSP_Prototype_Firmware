#ifndef EUSUART_H
#define	EUSUART_H

#define KHz *1000UL
#define MHz *1000000UL
#define _XTAL_FREQ 11059200

#define baud 115200// 9600
#define spbrg_val 5 // 71 //(_XTAL_FREQ - baud*16)/(baud*16) 

//void enaTx(void);
//void enaRx(void);

//void usartRCV(void);
unsigned char getChar(void);
unsigned int getData(unsigned char *data);
void clearRCREG(void);
void sendChar(unsigned char txDat);
void write2Reg(unsigned char *dat_st, int dat_end);

#endif	/* XC_HEADER_TEMPLATE_H */