#include "Disassembler.h"
#include <stdint.h>
#include <stdio.h>

#define KB 1024

char code[8*KB];
char memory[20*KB];



Opcode data;
char ditermineCode(uint8_t *code){
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
int UseTable(uint8_t *code){
	if(code[0] == 72){
		Opcode OpcodeTable72[256];
	}
	else if(code[0] == 90){
		Opcode OpCodeTable90[256];
	}
	else if(code[0] == 91){
		Opcode OpCodeTable91[256];
	}
	else if(code[0] == 92){
		Opcode OpCodeTable92[256];
	}
	else 
		Opcode OpcodeTable[256];
}	
	

int ADCbyte(uint8_t *code){
  printf("ADC  A, #$%x\n", code[1]);
  return 0;
}
Opcode OpcodeTable72[256] = {
};
Opcode OpcodeTable90[256] = {
};
Opcode OpcodeTable91[256] = {
};
Opcode OpcodeTable92[256] = {
};
Opcode OpcodeTable[256] = {
  [0xA9] = {ADCbyte,2 ,1}
};
