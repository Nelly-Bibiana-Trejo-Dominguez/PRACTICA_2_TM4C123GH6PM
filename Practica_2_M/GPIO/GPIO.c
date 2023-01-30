/*
 * GPIO.c
 */
#include "../include.h"

extern void Configurar_GPIO(void){

        SYSCTL->RCGCGPIO |= (1<<1) | (1<<4);      // B E
        GPIOE->DIR &= ~0x03;   // inputs on PE1-0
        GPIOE->DEN |= (1<<0) | (1<<1);    // enable digital on PE1-0
        GPIOE->DIR |= (0<<0) | (0<<1); //El pin PB6 es salida

        GPIOB->DIR |= 0x3F;    // outputs on PB5-0
        GPIOB->DEN |= 0x3F;    // enable digital on PB5-0

}

extern void habilitar_IntGPIO(void){

}

extern void GPIOF_INT_ISR(void){

}




