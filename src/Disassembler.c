#include "Disassembler.h"
#include <stdint.h>
#include <stdio.h>

#define KB 1024

char code[8*KB];
char memory[20*KB];



Opcode data;
char disassembler(uint8_t *code){
  if(data.length == 2){             //seperate into several 8bit code 
  code[1] = *code&&0x00FF;
  *code=*code>>8;
  code[0] = *code&&0x00FF;
  }
  else if(data.length == 3){
  code[2] = *code&&0x0000FF;
  *code=*code>>8;
  code[1] = *code&&0x0000FF;
  *code=*code>>8;
  code[0] = *code&&0x0000FF;
  }
  else if(data.length ==4){
  code[3] = *code&&0x000000FF;
  *code=*code>>8;
  code[2] = *code&&0x000000FF;
  *code=*code>>8;
  code[1] = *code&&0x000000FF;
  *code=*code>>8;
  code[0] = *code&&0x000000FF;
  }
  else
    return 0;
}
int ADCbyte(uint8_t *code){
  printf("ADC  A, #$%x\n", code[1]);
  return 0;
}

Opcode OpcodeTable[256] = {
  [0xA9] = {ADCbyte,2 ,1}
};
