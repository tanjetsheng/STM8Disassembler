#include "Disassembler.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "CException.h"
#include "exception.h"


#define KB 1024

char code[8*KB];
char memory[20*KB];

//char* _disassembler(uint8_t *code);		// used internally

Opcode opcodeTable72[256] = {
  [0xC9] = {ADClongptr,4,4},
  [0xD9] = {ADClongptrX,4,4},
  [0xCB] = {ADDlongptr,4,4},
  [0xDB] = {ADDlongptrX,4,4},
  [0xC4] = {ANDlongptr,4,4},
  [0xD4] = {ANDlongptrX,4,4},
  [0x5C] = {INClongmem,4,1},
  [0x4C] = {INClongoffX,4,1},
  [0x3C] = {INClongptr,4,4},
  [0x6C] = {INClongptrX,4,4}
  
};
Opcode opcodeTable90[256] = {
  [0xF9] = {ADCY,2,1},
  [0xE9] = {ADCshortoffY,3,1},
  [0xD9] = {ADClongoffY,4,1},
  [0xFB] = {ADDY,2,1},
  [0xEB] = {ADDshortoffY,3,1},
  [0xDB] = {ADDlongoffY,4,1},
  [0xF4] = {ANDY,2,1},
  [0xE4] = {ANDshortoffY,3,1},
  [0xD4] = {ANDlongoffY,4,1},
  [0x7C] = {INCY,2,1},
  [0x6C] = {INCshortoffY,3,1},
  [0x4C] = {INClongoffY,4,1}
};

Opcode opcodeTable91[256] = {
  [0xD9] = {ADCshortptrY,3,4},
  [0xDB] = {ADDshortptrY,3,4},
  [0xD4] = {ANDshortptrY,3,4},
  [0x6C] = {INCshortptrY,3,4}
};

Opcode opcodeTable92[256] = {
  [0xC9] = {ADCshortptr,3,4},
  [0xD9] = {ADCshortptrX,3,4},
  [0xCB] = {ADDshortptr,3,4},
  [0xDB] = {ADDshortptrX,3,4},
  [0xC4] = {ANDshortptr,3,4},
  [0xD4] = {ANDshortptrX,3,4},
  [0x3C] = {INCshortptr,3,4},
  [0x6C] = {INCshortptrX,3,4}
};

Opcode opcodeTable[256] = {
  [0xA9] = {ADCbyte,2 ,1},
  [0xB9] = {ADCshortmem,2,1},
  [0xC9] = {ADClongmem,3,1},
  [0xF9] = {ADCX,1,1},
  [0xE9] = {ADCshortoffX,2,1},
  [0xD9] = {ADClongoffX,3,1},
  [0x19] = {ADCshortoffSP,2,1},
  [0xAB] = {ADDbyte,2,1},
  [0xBB] = {ADDshortmem,2,1},
  [0xCB] = {ADDlongmem,3,1},
  [0xFB] = {ADDX,1,1},
  [0xEB] = {ADDshortoffX,2,1},
  [0xDB] = {ADDlongoffX,3,1},
  [0x1B] = {ADDshortoffSP,2,1},
  [0xA4] = {ANDbyte,2,1},
  [0xB4] = {ANDshortmem,2,1},
  [0xC4] = {ANDlongmem,3,1},
  [0xF4] = {ANDX,1,1},
  [0xE4] = {ANDshortoffX,2,1},
  [0xD4] = {ANDlongoffX,3,1},
  [0x14] = {ANDshortoffSP,2,1},
  [0x4C] = {INCA,1,1},
  [0X3C] = {INCshortmem,2,1},
  [0x7C] = {INCX,1,1},
  [0x6C] = {INCshortoffX,2,1},
  [0x0C] = {INCshortoffSP,2,1}
  
};




char* disassembler(uint8_t *code){               //check the first byte so that can
                        //determine to use which table
	if(code[0] == 0x72){   
		if(opcodeTable72[code[1]].execute == NULL){
      Throw(createException("invalid instruction",*code));
	}
		else{                  
		return opcodeTable72[code[1]].execute(code);
	}
	}
	else if(code[0] == 0x90){
		if(opcodeTable90[code[1]].execute == NULL){
      Throw(createException("invalid instruction",*code));
	}
		else{ 
	    return opcodeTable90[code[1]].execute(code);
	}
	}
	else if(code[0] == 0x91){
		if(opcodeTable91[code[1]].execute == NULL){
	Throw(createException("invalid instruction",*code));
	}
		else{ 
		return opcodeTable91[code[1]].execute(code);
	}
	}
	else if(code[0] == 0x92){
		if(opcodeTable92[code[1]].execute == NULL){
	Throw(createException("invalid instruction",*code));
	}
		else{ 
		return opcodeTable92[code[1]].execute(code);
	}
	}
	else {
		if(opcodeTable[code[0]].execute == NULL){
	Throw(createException("invalid instruction",*code));
	}
		else{ 
	return opcodeTable[code[0]].execute(code);
	}
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

               /*ADC*/
                
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

char* ADCshortoffX(uint8_t *code){
  
  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,($%x,X)", code[1]);
  printf("ADC  A,($%x,X)",code[1]);
  return buffer;
}

char* ADClongoffX(uint8_t *code){       
  
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

char* ADCshortoffY(uint8_t *code){       
  
  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,($%x,Y)",code[2]);
  printf("ADC  A,($%x,Y)",code[2]);
  return buffer;
}

char* ADClongoffY(uint8_t *code){        //length 4
  
  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,($%x%x,Y)", code[2],code[3]);
  printf("ADC  A,($%x%x,Y)", code[2],code[3]);
  return buffer;
}

char* ADCshortoffSP(uint8_t *code){           
  
  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,($%x,SP)", code[1]);
  printf("ADC  A,($%x,SP)", code[1]);
  return buffer;
}

char* ADCshortptr(uint8_t *code){        
  
  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,[$%x.w]", code[2]);
  printf("ADC  A,[$%x.w]",code[2]);
  return buffer;
}

char* ADClongptr(uint8_t *code){        
  
  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,[$%x%x.w]", code[2],code[3]);
  printf("ADC  A,[$%x%x.w]",code[2],code[3]);
  return buffer;
}

char* ADCshortptrX(uint8_t *code){        
  
  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,[$%x.w],X",code[2]);
  printf("ADC  A,[$%x.w],X",code[2]);
  return buffer;
}

char* ADClongptrX(uint8_t *code){        
  
  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,[$%x%x.w],X",code[2],code[3]);
  printf("ADC  A,[$%x%x.w],X",code[2],code[3]);
  return buffer;
}

char* ADCshortptrY(uint8_t *code){        
  
  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,[$%x.w],Y",code[2]);
  printf("ADC  A,[$%x.w],Y",code[2]);
  return buffer;
}


                    /*ADD*/
                    
char* ADDbyte(uint8_t *code){           //length 2
  
  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,#$%x", code[1]);
  printf("ADD  A,#$%x",code[1]);
  return buffer;
}

char* ADDshortmem(uint8_t *code){
  
  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,$%x", code[1]);
  printf("ADD  A,$%x",code[1]);
  return buffer;
}

char* ADDlongmem(uint8_t *code){        //length 3
  
  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,$%x%x", code[1],code[2]);
  printf("ADD  A,$%x%x",code[1],code[2]);
  return buffer;
}

char* ADDX(uint8_t *code){            //length 1
  
  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,(X)");
  printf("ADD  A,(X)");
  return buffer;
}

char* ADDshortoffX(uint8_t *code){
  
  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,($%x,X)", code[1]);
  printf("ADD  A,($%x,X)",code[1]);
  return buffer;
}

char* ADDlongoffX(uint8_t *code){       
  
  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,($%x%x,X)", code[1],code[2]);
  printf("ADD  A,($%x%x,X)",code[1],code[2]);
  return buffer;
}

char* ADDY(uint8_t *code){          
  
  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,(Y)");
  printf("ADD  A,(Y)");
  return buffer;
}

char* ADDshortoffY(uint8_t *code){       
  
  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,($%x,Y)",code[2]);
  printf("ADD  A,($%x,Y)",code[2]);
  return buffer;
}

char* ADDlongoffY(uint8_t *code){        //length 4
  
  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,($%x%x,Y)", code[2],code[3]);
  printf("ADD  A,($%x%x,Y)", code[2],code[3]);
  return buffer;
}

char* ADDshortoffSP(uint8_t *code){           
  
  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,($%x,SP)", code[1]);
  printf("ADD  A,($%x,SP)", code[1]);
  return buffer;
}

char* ADDshortptr(uint8_t *code){        
  
  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,[$%x.w]", code[2]);
  printf("ADD  A,[$%x.w]",code[2]);
  return buffer;
}

char* ADDlongptr(uint8_t *code){        
  
  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,[$%x%x.w]", code[2],code[3]);
  printf("ADD  A,[$%x%x.w]",code[2],code[3]);
  return buffer;
}

char* ADDshortptrX(uint8_t *code){        
  
  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,[$%x.w],X",code[2]);
  printf("ADD  A,[$%x.w],X",code[2]);
  return buffer;
}

char* ADDlongptrX(uint8_t *code){        
  
  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,[$%x%x.w],X",code[2],code[3]);
  printf("ADD  A,[$%x%x.w],X",code[2],code[3]);
  return buffer;
}

char* ADDshortptrY(uint8_t *code){  

  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,[$%x.w],Y",code[2]);
  printf("ADD  A,[$%x.w],Y",code[2]);
  return buffer;
}

                    /*AND*/
                    
char* ANDbyte(uint8_t *code){           //length 2
  
  buffer = malloc(1024);
  sprintf(buffer,"AND  A,#$%x", code[1]);
  printf("AND  A,#$%x",code[1]);
  return buffer;
}

char* ANDshortmem(uint8_t *code){
  
  buffer = malloc(1024);
  sprintf(buffer,"AND  A,$%x", code[1]);
  printf("AND  A,$%x",code[1]);
  return buffer;
}

char* ANDlongmem(uint8_t *code){        //length 3
  
  buffer = malloc(1024);
  sprintf(buffer,"AND  A,$%x%x", code[1],code[2]);
  printf("AND  A,$%x%x",code[1],code[2]);
  return buffer;
}

char* ANDX(uint8_t *code){            //length 1
  
  buffer = malloc(1024);
  sprintf(buffer,"AND  A,(X)");
  printf("AND  A,(X)");
  return buffer;
}

char* ANDshortoffX(uint8_t *code){
  
  buffer = malloc(1024);
  sprintf(buffer,"AND  A,($%x,X)", code[1]);
  printf("AND  A,($%x,X)",code[1]);
  return buffer;
}

char* ANDlongoffX(uint8_t *code){       
  
  buffer = malloc(1024);
  sprintf(buffer,"AND  A,($%x%x,X)", code[1],code[2]);
  printf("AND  A,($%x%x,X)",code[1],code[2]);
  return buffer;
}

char* ANDY(uint8_t *code){          
  
  buffer = malloc(1024);
  sprintf(buffer,"AND  A,(Y)");
  printf("AND  A,(Y)");
  return buffer;
}

char* ANDshortoffY(uint8_t *code){       
  
  buffer = malloc(1024);
  sprintf(buffer,"AND  A,($%x,Y)",code[2]);
  printf("AND  A,($%x,Y)",code[2]);
  return buffer;
}

char* ANDlongoffY(uint8_t *code){        //length 4
  
  buffer = malloc(1024);
  sprintf(buffer,"AND  A,($%x%x,Y)", code[2],code[3]);
  printf("AND  A,($%x%x,Y)", code[2],code[3]);
  return buffer;
}

char* ANDshortoffSP(uint8_t *code){           
  
  buffer = malloc(1024);
  sprintf(buffer,"AND  A,($%x,SP)", code[1]);
  printf("AND  A,($%x,SP)", code[1]);
  return buffer;
}

char* ANDshortptr(uint8_t *code){        
  
  buffer = malloc(1024);
  sprintf(buffer,"AND  A,[$%x.w]", code[2]);
  printf("AND  A,[$%x.w]",code[2]);
  return buffer;
}

char* ANDlongptr(uint8_t *code){        
  
  buffer = malloc(1024);
  sprintf(buffer,"AND  A,[$%x%x.w]", code[2],code[3]);
  printf("AND  A,[$%x%x.w]",code[2],code[3]);
  return buffer;
}

char* ANDshortptrX(uint8_t *code){        
  
  buffer = malloc(1024);
  sprintf(buffer,"AND  A,[$%x.w],X",code[2]);
  printf("AND  A,[$%x.w],X",code[2]);
  return buffer;
}

char* ANDlongptrX(uint8_t *code){        
  
  buffer = malloc(1024);
  sprintf(buffer,"AND  A,[$%x%x.w],X",code[2],code[3]);
  printf("AND  A,[$%x%x.w],X",code[2],code[3]);
  return buffer;
}

char* ANDshortptrY(uint8_t *code){  

  buffer = malloc(1024);
  sprintf(buffer,"AND  A,[$%x.w],Y",code[2]);
  printf("AND  A,[$%x.w],Y",code[2]);
  return buffer;
}

                   /*INC*/
                    
char* INCA(uint8_t *code){           //length 2
  
  buffer = malloc(1024);
  sprintf(buffer,"INC A");
  printf("INC A");
  return buffer;
}

char* INCshortmem(uint8_t *code){
  
  buffer = malloc(1024);
  sprintf(buffer,"INC$%x", code[1]);
  printf("INC$%x",code[1]);
  return buffer;
}

char* INClongmem(uint8_t *code){        //length 4
  
  buffer = malloc(1024);
  sprintf(buffer,"INC$%x%x",code[2],code[3]);
  printf("INC$%x%x",code[2],code[3]);
  return buffer;
}

char* INCX(uint8_t *code){            //length 1
  
  buffer = malloc(1024);
  sprintf(buffer,"INC(X)");
  printf("INC(X)");
  return buffer;
}

char* INCshortoffX(uint8_t *code){
  
  buffer = malloc(1024);
  sprintf(buffer,"INC($%x,X)", code[1]);
  printf("INC($%x,X)",code[1]);
  return buffer;
}

char* INClongoffX(uint8_t *code){       
  
  buffer = malloc(1024);
  sprintf(buffer,"INC($%x%x,X)", code[2],code[3]);
  printf("INC($%x%x,X)",code[2],code[3]);
  return buffer;
}

char* INCY(uint8_t *code){          
  
  buffer = malloc(1024);
  sprintf(buffer,"INC(Y)");
  printf("INC(Y)");
  return buffer;
}

char* INCshortoffY(uint8_t *code){       
  
  buffer = malloc(1024);
  sprintf(buffer,"INC($%x,Y)",code[2]);
  printf("INC($%x,Y)",code[2]);
  return buffer;
}

char* INClongoffY(uint8_t *code){        //length 4
  
  buffer = malloc(1024);
  sprintf(buffer,"INC($%x%x,Y)", code[2],code[3]);
  printf("INC($%x%x,Y)", code[2],code[3]);
  return buffer;
}

char* INCshortoffSP(uint8_t *code){           
  
  buffer = malloc(1024);
  sprintf(buffer,"INC($%x,SP)", code[1]);
  printf("INC($%x,SP)", code[1]);
  return buffer;
}

char* INCshortptr(uint8_t *code){        
  
  buffer = malloc(1024);
  sprintf(buffer,"INC[$%x.w]", code[2]);
  printf("INC[$%x.w]",code[2]);
  return buffer;
}

char* INClongptr(uint8_t *code){        
  
  buffer = malloc(1024);
  sprintf(buffer,"INC[$%x%x.w]", code[2],code[3]);
  printf("INC[$%x%x.w]",code[2],code[3]);
  return buffer;
}

char* INCshortptrX(uint8_t *code){        
  
  buffer = malloc(1024);
  sprintf(buffer,"INC[$%x.w],X",code[2]);
  printf("INC[$%x.w],X",code[2]);
  return buffer;
}

char* INClongptrX(uint8_t *code){        
  
  buffer = malloc(1024);
  sprintf(buffer,"INC[$%x%x.w],X",code[2],code[3]);
  printf("INC[$%x%x.w],X",code[2],code[3]);
  return buffer;
}

char* INCshortptrY(uint8_t *code){  

  buffer = malloc(1024);
  sprintf(buffer,"INC[$%x.w],Y",code[2]);
  printf("INC[$%x.w],Y",code[2]);
  return buffer;
}








