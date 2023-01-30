

/**
 * main.c
 */
#include "include.h"

#define SENSOR  (*((volatile uint32_t *)0x4002400C))
#define LIGHT   (*((volatile uint32_t *)0x400050FC))
// Linked data structure

struct State {
  uint32_t Out;
  uint32_t Time;
  uint32_t Next[4];};

typedef const struct State State_t;
#define goN   0
#define waitN 1
#define goE   2
#define waitE 3

State_t FSM[4]={
 {0x21,500,{goN,waitN,goN,waitN}},
 {0x22, 250,{goE,goE,goE,goE}},
 {0x0C,500,{goE,goE,waitE,waitE}},
 {0x14, 250,{goN,goN,goN,goN}}};
uint32_t S;  // index to the current state
uint32_t Input;

void Delay(void){unsigned long volatile time;
  time = 1000000;
  while(time){
        time--;
  }
}

int main(void)
{
    SetSystemClock_80MHz(_80MHZ);
    Configurar_SysTick();
    Configurar_GPIO();

    S = goN;
     while(1){
       LIGHT = FSM[S].Out;  // set lights
      Delay();
       // SysTick_ms(FSM[S].Time/100000.0);
       Input = SENSOR;     // read sensors
       S = FSM[S].Next[Input];
     }
}
