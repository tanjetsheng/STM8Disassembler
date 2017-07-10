#include "Disassembler.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "CException.h"
#include "exception.h"


#define KB 1024

char code[8*KB];
char memory[20*KB];


Opcode opcodeTable72[256] = {
};
Opcode opcodeTable90[256] = {
  [0xF9] = {ADCY,2,1}
};
Opcode opcodeTable91[256] = {
};
Opcode opcodeTable92[256] = {
};
Opcode opcodeTable[256] = {
  [0xA9] = {ADCbyte,2 ,1},
  [0xB9] = {ADCshortmem,2,1},
  [0xC9] = {ADClongmem,3,1},
  [0xF9] = {ADCX,1,1},
  [0xE9] = {ADCshortoff,2,1},
  [0xD9] = {ADClongoff,3,1}
};

Opcode data;
int ditermineCode(uint8_t *code){    //seperate into several 8bit code 
  if(data.length == 2){             
  code[1] = *code&0x00FF;
  *code=*code>>8;
  code[0] = *code&0x00FF;
  }
  else if(data.length == 3){
  code[2] = *code&0x0000FF;
  *code=*code>>8;
  code[1] = *code&0x0000FF;
  *code=*code>>8;
  code[0] = *code&0x0000FF;
  }
  else if(data.length ==4){
  code[3] = *code&0x000000FF;
  *code=*code>>8;
  code[2] = *code&0x000000FF;
  *code=*code>>8;
  code[1] = *code&0x000000FF;
  *code=*code>>8;
  code[0] = *code&0x000000FF;
  }
  else
    return 0;
}

char* error(uint8_t *code){
  if(opcodeTable[code[0]].execute(code) == NULL){
  Throw(createException("invalid instruction",*code));
  }
  else{
    disassembler(code);
  }
 }
 
char* disassembler(uint8_t *code){               //check the first byte so that can
                        //determine to use which table
	if(code[0] == 72){                     
		return opcodeTable72[code[1]].execute(code);
	}
	else if(code[0] == 90){
	  return opcodeTable90[code[1]].execute(code);
	}
	else if(code[0] == 91){
	  return opcodeTable91[code[1]].execute(code);
	}
	else if(code[0] == 92){
		return opcodeTable92[code[1]].execute(code);
	}
	else {
	return opcodeTable[code[0]].execute(code);
  }
}

char* printError(uint8_t *code){
 CEXCEPTION_T ex; 
 Try{
  }
  Catch(ex){
    dumpException(ex);
  }
}



char* ADCbyte(uint8_t *code){           //length 2
  
  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,#$%x", code[1]);
  printf("ADC  A,#$%x",code[1]);
  return buffer;
}

char* ADCshortmem(uint8_t *code){
  
  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,$%x", code[1]);
  printf("ADC  A,$%x",code[1]);
  return buffer;
}

char* ADClongmem(uint8_t *code){        //length 3
  
  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,$%x%x", code[1],code[2]);
  printf("ADC  A,$%x%x",code[1],code[2]);
  return buffer;
}

char* ADCX(uint8_t *code){            //length 1
  
  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,(X)");
  printf("ADC  A,(X)");
  return buffer;
}

char* ADCshortoff(uint8_t *code){
  
  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,($%x,X)", code[1]);
  printf("ADC  A,($%x,X)",code[1]);
  return buffer;
}

char* ADClongoff(uint8_t *code){       
  
  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,($%x%x,X)", code[1],code[2]);
  printf("ADC  A,($%x%x,X)",code[1],code[2]);
  return buffer;
}

char* ADCY(uint8_t *code){          
  
  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,(Y)");
  printf("ADC  A,(Y)");
  return buffer;
}






















