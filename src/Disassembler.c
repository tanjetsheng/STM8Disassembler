#include "Disassembler.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "CException.h"
#include "exception.h"
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "error.h"
#include "Token.h"
#include <ctype.h>


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
  [0x6C] = {INClongptrX,4,4},
  [0xBB] = {ADDWlongmem,4,2},
  [0xFB] = {ADDWshortoffSP,3,2},
  [0xA9] = {ADDWwordY,4,2},
  [0xB9] = {ADDWlongmemY,4,2},
  [0xF9] = {ADDWshortoffSPY,3,2},
  [0xC5] = {BCPlongptr,4,4},
  [0xD5] = {BCPlongptrX,4,4},
  [0x11] = {BitReset,4,1},
  [0x13] = {BitReset,4,1},
  [0x15] = {BitReset,4,1},
  [0x17] = {BitReset,4,1},
  [0x19] = {BitReset,4,1},
  [0x1B] = {BitReset,4,1},
  [0x1D] = {BitReset,4,1},
  [0x1F] = {BitReset,4,1},
  [0x10] = {Bitset,4,1},
  [0x12] = {Bitset,4,1},
  [0x14] = {Bitset,4,1},
  [0x16] = {Bitset,4,1},
  [0x18] = {Bitset,4,1},
  [0x1A] = {Bitset,4,1},
  [0x1C] = {Bitset,4,1},
  [0x1E] = {Bitset,4,1},
  [0x01] = {BitTestJumpFalse,5,3/2},
  [0x03] = {BitTestJumpFalse,5,3/2},
  [0x05] = {BitTestJumpFalse,5,3/2},
  [0x07] = {BitTestJumpFalse,5,3/2},
  [0x09] = {BitTestJumpFalse,5,3/2},
  [0x0B] = {BitTestJumpFalse,5,3/2},
  [0x0D] = {BitTestJumpFalse,5,3/2},
  [0x0F] = {BitTestJumpFalse,5,3/2},
  [0x00] = {BitTestJumpTrue,4,1},
  [0x02] = {BitTestJumpTrue,4,1},
  [0x04] = {BitTestJumpTrue,4,1},
  [0x06] = {BitTestJumpTrue,4,1},
  [0x08] = {BitTestJumpTrue,4,1},
  [0x0A] = {BitTestJumpTrue,4,1},
  [0x0C] = {BitTestJumpTrue,4,1},
  [0x0E] = {BitTestJumpTrue,4,1},
  [0xCD] = {CALLlongptr,4,6},
  [0xDD] = {CALLlongptrX,4,6},
  [0x5F] = {CLRlongmem,4,1},
  [0x4F] = {CLRlongoffX,4,1},
  [0x3F] = {CLRlongptr,4,4},
  [0x6F] = {CLRlongptrX,4,4},
  [0xC1] = {CPlongptr,4,4},
  [0xD1] = {CPlongptrX,4,4},
  [0xC3] = {CPWlongptr_X,4,5},
  [0xD3] = {CPWlongptrX_Y,4,5},
  [0x53] = {CPLlongmem,4,1},
  [0x43] = {CPLlongoffX,4,1},
  [0x33] = {CPLlongptr,4,4},
  [0x63] = {CPLlongptrX,4,4},
  [0x5A] = {DEClongmem,4,1},
  [0x4A] = {DEClongoffX,4,1},
  [0x3A] = {DEClongptr,4,4},
  [0x6A] = {DEClongptrX,4,4},
  [0xCC] = {JPlongptr,4,5},
  [0xDC] = {JPlongptrX,4,5}


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
  [0x4C] = {INClongoffY,4,1},
  [0x5C] = {INCWord_Y,2,1},
  [0xF5] = {BCPY,2,1},
  [0xE5] = {BCPshortoffY,3,1},
  [0xD5] = {BCPlongoffY,4,1},
  [0x10] = {BitComplement,4,1},
  [0x12] = {BitComplement,4,1},
  [0x14] = {BitComplement,4,1},
  [0x16] = {BitComplement,4,1},
  [0x18] = {BitComplement,4,1},
  [0x1A] = {BitComplement,4,1},
  [0x1C] = {BitComplement,4,1},
  [0x1E] = {BitComplement,4,1},
  [0x11] = {BCCM,4,1},
  [0x13] = {BCCM,4,1},
  [0x15] = {BCCM,4,1},
  [0x17] = {BCCM,4,1},
  [0x19] = {BCCM,4,1},
  [0x1B] = {BCCM,4,1},
  [0x1D] = {BCCM,4,1},
  [0x1F] = {BCCM,4,1},
  [0XFD] = {CALLY,2,4},
  [0xED] = {CALLshortoffY,3,4},
  [0XDD] = {CALLlongoffY,4,4},
  [0x7F] = {CLRY,2,1},
  [0x6F] = {CLRshortoffY,3,1},
  [0x4F] = {CLRlongoffY,4,1},
  [0X5F] = {CLRWY,2,1},
  [0xF1] = {CPY,2,1},
  [0xE1] = {CPshortoffY,3,1},
  [0xD1] = {CPlongoffY,4,1},
  [0xF3] = {CPWY,2,2},
  [0xE3] = {CPWshortoffY_X,3,2},
  [0xD3] = {CPWlongoffY_X,4,2},
  [0xA3] = {CPwordY,4,2},
  [0xB3] = {CPWshortmem_Y,3,2},
  [0xC3] = {CPWlongmem_Y,4,2},
  [0x73] = {CPLY,2,1},
  [0x63] = {CPLshortoffY,3,1},
  [0x43] = {CPLlongoffY,4,1},
  [0x53] = {CPLWY,2,2},
  [0x7A] = {DECY,2,1},
  [0x6A] = {DECshortoffY,3,1},
  [0x4A] = {DEClongoffY,4,1},
  [0x5A] = {DECWY,2,2},
  [0x62] = {DivideUnsignedY,2,2},
  [0xFC] = {JPY,2,1},
  [0xEC] = {JPshortoffY,3,2},
  [0xDC] = {JPlongoffY,4,2},
  [0x29] = {HalfCarry,3,1/2},
  [0x2F] = {InterruptHigh,3,1/2},
  [0x2E] = {InterurptLow,3,1/2},
  [0x2D] = {InterruptMask,3,1/2},
  [0x28] = {NotHalfCarry,3,1/2},
  [0x2C] = {NotInterruptMask,3,1/2}

};

Opcode opcodeTable91[256] = {
  [0xD9] = {ADCshortptrY,3,4},
  [0xDB] = {ADDshortptrY,3,4},
  [0xD4] = {ANDshortptrY,3,4},
  [0x6C] = {INCshortptrY,3,4},
  [0xD5] = {BCPshortptrY,3,4},
  [0xDD] = {CALLshortptrY,3,6},
  [0x6F] = {CLRshortptrY,3,4},
  [0xD1] = {CPshortptrY,3,4},
  [0xD3] = {CPWshortptrY_X,3,5},
  [0xC3] = {CPWshortptr_Y,3,5},
  [0x63] = {CPLshortptrY,3,4},
  [0x6A] = {DECshortptrY,3,4},
  [0xDC] = {JPshortptrY,3,5}
};

Opcode opcodeTable92[256] = {
  [0xC9] = {ADCshortptr,3,4},
  [0xD9] = {ADCshortptrX,3,4},
  [0xCB] = {ADDshortptr,3,4},
  [0xDB] = {ADDshortptrX,3,4},
  [0xC4] = {ANDshortptr,3,4},
  [0xD4] = {ANDshortptrX,3,4},
  [0x3C] = {INCshortptr,3,4},
  [0x6C] = {INCshortptrX,3,4},
  [0xC5] = {BCPshortptr,3,4},
  [0xD5] = {BCPshortptrX,3,4},
  [0xCD] = {CALLshortptr,3,6},
  [0xDD] = {CALLshortptrX,3,6},
  [0x8D] = {CALLFlongptr,4,8},
  [0x3F] = {CLRshortptr,3,4},
  [0x6F] = {CLRshortptrX,3,4},
  [0xC1] = {CPshortptr,3,4},
  [0xD1] = {CPshortptrX,3,4},
  [0xC3] = {CPWshortptr_X,3,5},
  [0xD3] = {CPWshortptrX_Y,3,5},
  [0x33] = {CPLshortptr,3,4},
  [0x63] = {CPLshortptrX,3,4},
  [0x3A] = {DECshortptr,3,4},
  [0x6A] = {DECshortptrX,3,4},
  [0xCC] = {JPshortptr,3,5},
  [0xDC] = {JPshortptrX,3,5},
  [0xAC] = {JPFlongptr,4,6}
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
  [0x0C] = {INCshortoffSP,2,1},
  [0x5C] = {INCWord_X,1,1},
  [0x1C] = {ADDWword,3,2},
  [0x5B] = {ADDWSP,2,2},
  [0xA5] = {BCPbyte,2 ,1},
  [0xB5] = {BCPshortmem,2,1},
  [0xC5] = {BCPlongmem,3,1},
  [0xF5] = {BCPX,1,1},
  [0xE5] = {BCPshortoffX,2,1},
  [0xD5] = {BCPlongoffX,3,1},
  [0x15] = {BCPshortoffSP,2,1},
  [0X8B] = {BREAK,1,1},
  [0XCD] = {CALLlongmem,4,3},
  [0XFD] = {CALLX,1,4},
  [0XED] = {CALLshortoffX,2,4},
  [0xDD] = {CALLlongoffX,3,4},
  [0xAD] = {CALLR,2,4},
  [0x8D] = {CALLFextmem,4,5},
  [0x8C] = {CCF,1,1},
  [0x4F] = {CLRA,1,1},
  [0X3F] = {CLRshortmem,2,1},
  [0x7F] = {CLRX,1,1},
  [0x6F] = {CLRshortoffX,2,1},
  [0x0F] = {CLRshortoffSP,2,1},
  [0X5F] = {CLRWX,1,1},
  [0xA1] = {CPbyte,2,1},
  [0xB1] = {CPshortmem,2,1},
  [0xC1] = {CPlongmem,3,1},
  [0xF1] = {CPX,1,1},
  [0xE1] = {CPshortoffX,2,1},
  [0xD1] = {CPlongoffX,3,1},
  [0x11] = {CPshortoffSP,2,1},
  [0xA3] = {CPwordX,3,2},
  [0xB3] = {CPWshortmemX,2,2},
  [0xC3] = {CPWlongmemX,3,2},
  [0x13] = {CPWshortoffSP_X,2,2},
  [0xF3] = {CPWX,1,2},
  [0xE3] = {CPWshortoffX_Y,2,2},
  [0xD3] = {CPWlongoffX_Y,3,2},
  [0x43] = {CPLA,1,1},
  [0X33] = {CPLshortmem,2,1},
  [0x73] = {CPLX,1,1},
  [0x63] = {CPLshortoffX,2,1},
  [0x03] = {CPLshortoffSP,2,1},
  [0x53] = {CPLWX,1,2},
  [0x4A] = {DECA,1,1},
  [0X3A] = {DECshortmem,2,1},
  [0x7A] = {DECX,1,1},
  [0x6A] = {DECshortoffX,2,1},
  [0x0A] = {DECshortoffSP,2,1},
  [0x5A] = {DECWX,1,2},
  [0x62] = {DivideUnsignedX,1,2},
  [0x65] = {DivideSigned,1,2},
  [0x41] = {EXG_X,1,1},
  [0x61] = {EXG_Y,1,1},
  [0x31] = {EXG_longmem,3,3},
  [0x51] = {EXGW,1,1},
  [0x8E] = {HALT,1,10},
  [0x82] = {Interrupt,4,2},
  [0x80] = {InterruptReturn,1,11},
  [0xCC] = {JPlongmem,3,1},
  [0xFC] = {JPX,1,1},
  [0xEC] = {JPshortoffX,2,1},
  [0xDC] = {JPlongoffX,3,1},
  [0xAC] = {JPFextmem,4,2},
  [0x20] = {JumpRelativeAlways,2,2},
  [0x25] = {Carry,2,1/2},
  [0x27] = {Equal,2,1/2},
  [0x21] = {False,2,1/2},
  [0x2B] = {Minus,2,1/2},
  [0x24] = {NotCarry,2,1/2},
  [0x26] = {NotEqual,2,1/2},
  [0x28] = {NotOverflow,2,1/2},
  [0x2A] = {Plus,2,1/2},
  [0x2E] = {SignGreaterOrEqual,2,1/2},
  [0x2C] = {SignGreaterThan,2,1/2},
  [0x2D] = {SignLowerOrEqual,2,1/2},
  [0x2F] = {SignLowerThan,2,1/2},
  [0x22] = {UnsignGreaterThan,2,1/2},
  [0x23] = {UsignLowerOrEqual,2,1/2},
  [0x29] = {Overflow,2,1/2},
  [0x25] = {carry,2,1}


};

//disassemble multiple function
char* disassembleNCodes(uint8_t **ptrptrcode, int numCode)
{
  char *str;
  int i;
  char* buff = malloc(1028);
  str = malloc(1028);
  for( i = 0 ; i < numCode ; i++)           //used for loop to loop how many code did it have
  {
    str = disassembler(ptrptrcode);
    if(i==0)
      strcpy(buff,str);
                         //copy the value into buff so that it can combine all the value
    else                                  //that every time the loop output
      strcat(buff,str);
   }
   return buff;
}

char* disassembler(uint8_t **ptrptrcode){       //check the first byte so that can
    uint8_t *code = *ptrptrcode;              //determine to use which table
    if(code[0] == 0x72){
      if(opcodeTable72[code[1]].execute == NULL){               //when cant find the code in opcode table,it throw
                                                                //the code and invalid instruction
        throwException(ERR_INVALID_OPERAND,(void *)code,    \
                      "invalid instruction 0x%x,", 			\
                       code[1]);
      }
      else{
          *ptrptrcode += opcodeTable72[code[1]].length;           //it determine the length of the code so the pointer
          return opcodeTable72[code[1]].execute(code);            //can know need to move how many pointer
      }
    }
    else if(code[0] == 0x90){
      if(opcodeTable90[code[1]].execute == NULL){
        throwException(ERR_INVALID_OPERAND,(void *)code,    \
                     " invalid instruction 0x%x,", 			\
                       code[1]);
        }
      else{
        *ptrptrcode += opcodeTable90[code[1]].length;
        return opcodeTable90[code[1]].execute(code);
        }
      }
    else if(code[0] == 0x91){
      if(opcodeTable91[code[1]].execute == NULL){
        throwException(ERR_INVALID_OPERAND,(void *)code,   \
                      "invalid instruction 0x%x,", 			\
                       code[1]);
        }
      else{
        *ptrptrcode += opcodeTable91[code[1]].length;
        return opcodeTable91[code[1]].execute(code);
      }
    }
    else if(code[0] == 0x92){
      if(opcodeTable92[code[1]].execute == NULL){
        throwException(ERR_INVALID_OPERAND,(void *)code,    \
                      "invalid instruction 0x%x,", 			\
                       code[1]);
        }
      else{
        *ptrptrcode += opcodeTable92[code[1]].length;
        return opcodeTable92[code[1]].execute(code);
      }
    }
    else {
      if(opcodeTable[code[0]].execute == NULL){
        throwException(ERR_INVALID_OPERAND,(void *)code,    \
                      "invalid instruction 0x%x,", 			\
                       *code);
        }
      else{
        *ptrptrcode += opcodeTable[code[0]].length;
        return opcodeTable[code[0]].execute(code);
      }
    }
}



               /*ADC*/

char* ADCbyte(uint8_t *code){           //length 2

  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,#$%x", code[1]);
  printf("ADC  A,#$%x\n",code[1]);
  return buffer;
}

char* ADCshortmem(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,$%x", code[1]);
  printf("ADC  A,$%x\n",code[1]);
  return buffer;
}

char* ADClongmem(uint8_t *code){        //length 3

  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,$%x%x", code[1],code[2]);
  printf("ADC  A,$%x%x\n",code[1],code[2]);
  return buffer;
}

char* ADCX(uint8_t *code){            //length 1

  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,(X)");
  printf("ADC  A,(X)\n");
  return buffer;
}

char* ADCshortoffX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,($%x,X)", code[1]);
  printf("ADC  A,($%x,X)\n",code[1]);
  return buffer;
}

char* ADClongoffX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,($%x%x,X)", code[1],code[2]);
  printf("ADC  A,($%x%x,X)\n",code[1],code[2]);
  return buffer;
}

char* ADCY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,(Y)");
  printf("ADC  A,(Y)\n");
  return buffer;
}

char* ADCshortoffY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,($%x,Y)",code[2]);
  printf("ADC  A,($%x,Y)\n",code[2]);
  return buffer;
}

char* ADClongoffY(uint8_t *code){        //length 4

  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,($%x%x,Y)", code[2],code[3]);
  printf("ADC  A,($%x%x,Y)\n", code[2],code[3]);
  return buffer;
}

char* ADCshortoffSP(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,($%x,SP)", code[1]);
  printf("ADC  A,($%x,SP)\n", code[1]);
  return buffer;
}

char* ADCshortptr(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,[$%x.w]", code[2]);
  printf("ADC  A,[$%x.w]\n",code[2]);
  return buffer;
}

char* ADClongptr(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,[$%x%x.w]", code[2],code[3]);
  printf("ADC  A,[$%x%x.w]\n",code[2],code[3]);
  return buffer;
}

char* ADCshortptrX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,[$%x.w],X",code[2]);
  printf("ADC  A,[$%x.w],X\n",code[2]);
  return buffer;
}

char* ADClongptrX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,[$%x%x.w],X",code[2],code[3]);
  printf("ADC  A,[$%x%x.w],X\n",code[2],code[3]);
  return buffer;
}

char* ADCshortptrY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADC  A,[$%x.w],Y",code[2]);
  printf("ADC  A,[$%x.w],Y\n",code[2]);
  return buffer;
}


                    /*ADD*/

char* ADDbyte(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,#$%x", code[1]);
  printf("ADD  A,#$%x\n",code[1]);
  return buffer;
}

char* ADDshortmem(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,$%x", code[1]);
  printf("ADD  A,$%x\n",code[1]);
  return buffer;
}

char* ADDlongmem(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,$%x%x", code[1],code[2]);
  printf("ADD  A,$%x%x\n",code[1],code[2]);
  return buffer;
}

char* ADDX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,(X)");
  printf("ADD  A,(X)\n");
  return buffer;
}

char* ADDshortoffX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,($%x,X)", code[1]);
  printf("ADD  A,($%x,X)\n",code[1]);
  return buffer;
}

char* ADDlongoffX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,($%x%x,X)", code[1],code[2]);
  printf("ADD  A,($%x%x,X)\n",code[1],code[2]);
  return buffer;
}

char* ADDY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,(Y)");
  printf("ADD  A,(Y)\n");
  return buffer;
}

char* ADDshortoffY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,($%x,Y)",code[2]);
  printf("ADD  A,($%x,Y)\n",code[2]);
  return buffer;
}

char* ADDlongoffY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,($%x%x,Y)", code[2],code[3]);
  printf("ADD  A,($%x%x,Y)\n", code[2],code[3]);
  return buffer;
}

char* ADDshortoffSP(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,($%x,SP)", code[1]);
  printf("ADD  A,($%x,SP)\n", code[1]);
  return buffer;
}

char* ADDshortptr(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,[$%x.w]", code[2]);
  printf("ADD  A,[$%x.w]\n",code[2]);
  return buffer;
}

char* ADDlongptr(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,[$%x%x.w]", code[2],code[3]);
  printf("ADD  A,[$%x%x.w]\n",code[2],code[3]);
  return buffer;
}

char* ADDshortptrX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,[$%x.w],X",code[2]);
  printf("ADD  A,[$%x.w],X\n",code[2]);
  return buffer;
}

char* ADDlongptrX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,[$%x%x.w],X",code[2],code[3]);
  printf("ADD  A,[$%x%x.w],X\n",code[2],code[3]);
  return buffer;
}

char* ADDshortptrY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADD  A,[$%x.w],Y",code[2]);
  printf("ADD  A,[$%x.w],Y\n",code[2]);
  return buffer;
}

                    /*AND*/

char* ANDbyte(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"AND  A,#$%x", code[1]);
  printf("AND  A,#$%x\n",code[1]);
  return buffer;
}

char* ANDshortmem(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"AND  A,$%x", code[1]);
  printf("AND  A,$%x\n",code[1]);
  return buffer;
}

char* ANDlongmem(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"AND  A,$%x%x", code[1],code[2]);
  printf("AND  A,$%x%x\n",code[1],code[2]);
  return buffer;
}

char* ANDX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"AND  A,(X)");
  printf("AND  A,(X)\n");
  return buffer;
}

char* ANDshortoffX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"AND  A,($%x,X)", code[1]);
  printf("AND  A,($%x,X)\n",code[1]);
  return buffer;
}

char* ANDlongoffX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"AND  A,($%x%x,X)", code[1],code[2]);
  printf("AND  A,($%x%x,X)\n",code[1],code[2]);
  return buffer;
}

char* ANDY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"AND  A,(Y)");
  printf("AND  A,(Y)\n");
  return buffer;
}

char* ANDshortoffY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"AND  A,($%x,Y)",code[2]);
  printf("AND  A,($%x,Y)\n",code[2]);
  return buffer;
}

char* ANDlongoffY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"AND  A,($%x%x,Y)", code[2],code[3]);
  printf("AND  A,($%x%x,Y)\n", code[2],code[3]);
  return buffer;
}

char* ANDshortoffSP(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"AND  A,($%x,SP)", code[1]);
  printf("AND  A,($%x,SP)\n", code[1]);
  return buffer;
}

char* ANDshortptr(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"AND  A,[$%x.w]", code[2]);
  printf("AND  A,[$%x.w]\n",code[2]);
  return buffer;
}

char* ANDlongptr(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"AND  A,[$%x%x.w]", code[2],code[3]);
  printf("AND  A,[$%x%x.w]\n",code[2],code[3]);
  return buffer;
}

char* ANDshortptrX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"AND  A,[$%x.w],X",code[2]);
  printf("AND  A,[$%x.w],X\n",code[2]);
  return buffer;
}

char* ANDlongptrX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"AND  A,[$%x%x.w],X",code[2],code[3]);
  printf("AND  A,[$%x%x.w],X\n",code[2],code[3]);
  return buffer;
}

char* ANDshortptrY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"AND  A,[$%x.w],Y",code[2]);
  printf("AND  A,[$%x.w],Y\n",code[2]);
  return buffer;
}

                   /*INC*/

char* INCA(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"INC A");
  printf("INC A\n");
  return buffer;
}

char* INCshortmem(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"INC$%x", code[1]);
  printf("INC$%x\n",code[1]);
  return buffer;
}

char* INClongmem(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"INC$%x%x",code[2],code[3]);
  printf("INC$%x%x\n",code[2],code[3]);
  return buffer;
}

char* INCX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"INC(X)");
  printf("INC(X)\n");
  return buffer;
}

char* INCshortoffX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"INC($%x,X)", code[1]);
  printf("INC($%x,X)\n",code[1]);
  return buffer;
}

char* INClongoffX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"INC($%x%x,X)", code[2],code[3]);
  printf("INC($%x%x,X)\n",code[2],code[3]);
  return buffer;
}

char* INCY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"INC(Y)");
  printf("INC(Y)\n");
  return buffer;
}

char* INCshortoffY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"INC($%x,Y)",code[2]);
  printf("INC($%x,Y)\n",code[2]);
  return buffer;
}

char* INClongoffY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"INC($%x%x,Y)", code[2],code[3]);
  printf("INC($%x%x,Y)\n", code[2],code[3]);
  return buffer;
}

char* INCshortoffSP(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"INC($%x,SP)", code[1]);
  printf("INC($%x,SP)\n", code[1]);
  return buffer;
}

char* INCshortptr(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"INC[$%x.w]", code[2]);
  printf("INC[$%x.w]\n",code[2]);
  return buffer;
}

char* INClongptr(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"INC[$%x%x.w]", code[2],code[3]);
  printf("INC[$%x%x.w]\n",code[2],code[3]);
  return buffer;
}

char* INCshortptrX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"INC[$%x.w],X",code[2]);
  printf("INC[$%x.w],X\n",code[2]);
  return buffer;
}

char* INClongptrX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"INC[$%x%x.w],X",code[2],code[3]);
  printf("INC[$%x%x.w],X\n",code[2],code[3]);
  return buffer;
}

char* INCshortptrY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"INC[$%x.w],Y",code[2]);
  printf("INC[$%x.w],Y\n",code[2]);
  return buffer;
}

char* INCWord_X(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"INCW X");
  printf("INCW X\n");
  return buffer;
}

char* INCWord_Y(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"INCW Y");
  printf("INCW Y\n");
  return buffer;
}
  /*ADDW*/
char* ADDWword(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADDW X,#$%x%x",code[1],code[2]);
  printf("ADDW X,#$%x%x\n",code[1],code[2]);
  return buffer;
}

char* ADDWlongmem(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADDW X,$%x%x",code[2],code[3]);
  printf("ADDW X,$%x%x\n",code[1],code[2]);
  return buffer;
}

char* ADDWshortoffSP(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADDW X,($%x,SP)",code[2]);
  printf("ADDW X,($%x,SP)\n",code[2]);
  return buffer;
}

char* ADDWwordY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADDW Y,#$%x%x",code[2],code[3]);
  printf("ADDW Y,#$%x%x\n",code[2],code[3]);
  return buffer;
}

char* ADDWlongmemY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADDW Y,$%x%x",code[2],code[3]);
  printf("ADDW Y,$%x%x\n",code[2],code[3]);
  return buffer;
}

char* ADDWshortoffSPY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADDW Y,($%x,SP)",code[2]);
  printf("ADDW Y,($%x,SP)\n",code[2]);
  return buffer;
}

char* ADDWSP(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"ADDW SP,#$%x",code[1]);
  printf("ADDW SP,#$%x\n",code[1]);
  return buffer;
}

        //BCP
char* BCPbyte(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"BCP  A,#$%x", code[1]);
  printf("BCP  A,#$%x\n",code[1]);
  return buffer;
}

char* BCPshortmem(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"BCP  A,$%x", code[1]);
  printf("BCP  A,$%x\n",code[1]);
  return buffer;
}

char* BCPlongmem(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"BCP  A,$%x%x", code[1],code[2]);
  printf("BCP  A,$%x%x\n",code[1],code[2]);
  return buffer;
}

char* BCPX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"BCP  A,(X)");
  printf("BCP  A,(X)\n");
  return buffer;
}

char* BCPshortoffX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"BCP  A,($%x,X)", code[1]);
  printf("BCP  A,($%x,X)\n",code[1]);
  return buffer;
}

char* BCPlongoffX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"BCP  A,($%x%x,X)", code[1],code[2]);
  printf("BCP  A,($%x%x,X)\n",code[1],code[2]);
  return buffer;
}

char* BCPY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"BCP  A,(Y)");
  printf("BCP  A,(Y)\n");
  return buffer;
}

char* BCPshortoffY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"BCP  A,($%x,Y)",code[2]);
  printf("BCP  A,($%x,Y)\n",code[2]);
  return buffer;
}

char* BCPlongoffY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"BCP  A,($%x%x,Y)", code[2],code[3]);
  printf("BCP  A,($%x%x,Y)\n", code[2],code[3]);
  return buffer;
}

char* BCPshortoffSP(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"BCP  A,($%x,SP)", code[1]);
  printf("BCP  A,($%x,SP)\n", code[1]);
  return buffer;
}

char* BCPshortptr(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"BCP  A,[$%x.w]", code[2]);
  printf("BCP  A,[$%x.w]\n",code[2]);
  return buffer;
}

char* BCPlongptr(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"BCP  A,[$%x%x.w]", code[2],code[3]);
  printf("BCP  A,[$%x%x.w]\n",code[2],code[3]);
  return buffer;
}

char* BCPshortptrX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"BCP  A,[$%x.w],X",code[2]);
  printf("BCP  A,[$%x.w],X\n",code[2]);
  return buffer;
}

char* BCPlongptrX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"BCP  A,[$%x%x.w],X",code[2],code[3]);
  printf("BCP  A,[$%x%x.w],X\n",code[2],code[3]);
  return buffer;
}

char* BCPshortptrY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"BCP  A,[$%x.w],Y",code[2]);
  printf("BCP  A,[$%x.w],Y\n",code[2]);
  return buffer;
}

char* BREAK(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"BREAK");
  printf("BREAK\n");
  return buffer;
}

char* BitComplement(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"BCPL $%x%x,#2", code[2],code[3]);
  printf("BCPL $%x%x,#2\n", code[2],code[3]);
  return buffer;
}

char* BCCM(uint8_t *code){        //copy carry bit to memory

  buffer = malloc(1024);
  sprintf(buffer,"BCCM $%x%x,#2", code[2],code[3]);
  printf("BCCM $%x%x,#2\n", code[2],code[3]);
  return buffer;
}

char* BitReset(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"BRES $%x%x,#7", code[2],code[3]);
  printf("BRES $%x%x,#7\n", code[2],code[3]);
  return buffer;
}

char* Bitset(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"BSET $%x%x,#1", code[2],code[3]);
  printf("BSET $%x%x,#1\n", code[2],code[3]);
  return buffer;
}

char* BitTestJumpFalse(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"BTJF $%x%x,#1,%x", code[2],code[3],code[4]);
  printf("BTJF $%x%x,#1,%x\n", code[2],code[3],code[4]);
  return buffer;
}

char* BitTestJumpTrue(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"BTJT $%x%x,#1,%x", code[2],code[3],code[4]);
  printf("BTJT $%x%x,#1,%x\n", code[2],code[3],code[4]);
  return buffer;
}

      //CALL
char* CALLlongmem(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CALL$%x%x",code[1],code[2]);
  printf("CALL$%x%x\n",code[2],code[3]);
  return buffer;
}

char* CALLX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CALL(X)");
  printf("CALL(X)\n");
  return buffer;
}

char* CALLshortoffX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CALL($%x,X)", code[1]);
  printf("CALL($%x,X)\n",code[1]);
  return buffer;
}

char* CALLlongoffX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CALL($%x%x,X)", code[1],code[2]);
  printf("CALL($%x%x,X)\n",code[1],code[2]);
  return buffer;
}

char* CALLY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CALL(Y)");
  printf("CALL(Y)\n");
  return buffer;
}

char* CALLshortoffY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CALL($%x,Y)",code[2]);
  printf("CALL($%x,Y)\n",code[2]);
  return buffer;
}

char* CALLlongoffY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CALL($%x%x,Y)", code[2],code[3]);
  printf("CALL($%x%x,Y)\n", code[2],code[3]);
  return buffer;
}

char* CALLshortptr(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CALL[$%x.w]", code[2]);
  printf("CALL[$%x.w]\n",code[2]);
  return buffer;
}

char* CALLlongptr(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CALL[$%x%x.w]", code[2],code[3]);
  printf("CALL[$%x%x.w]\n",code[2],code[3]);
  return buffer;
}

char* CALLshortptrX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CALL[$%x.w],X",code[2]);
  printf("CALL[$%x.w],X\n",code[2]);
  return buffer;
}

char* CALLlongptrX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CALL[$%x%x.w],X",code[2],code[3]);
  printf("CALL[$%x%x.w],X\n",code[2],code[3]);
  return buffer;
}

char* CALLshortptrY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CALL[$%x.w],Y",code[2]);
  printf("CALL[$%x.w],Y\n",code[2]);
  return buffer;
}

char* CALLR(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CALLR$%x",code[1]);
  printf("CALLR$%x\n",code[1]);
  return buffer;
}

char* CALLFextmem(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CALLF $%x%x%x",code[1],code[2],code[3]);
  printf("CALLF $%x%x%x\n",code[1],code[2],code[3]);
  return buffer;
}

char* CALLFlongptr(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CALLF [$%x%x.e]",code[2],code[3]);
  printf("CALLF [$%x%x.e]\n",code[2],code[3]);
  return buffer;
}

char* CCF(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CCF");
  printf("CCF\n");
  return buffer;
}

      //clear

char* CLRA(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CLR A");
  printf("CLR A\n");
  return buffer;
}

char* CLRshortmem(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CLR$%x", code[1]);
  printf("CLR$%x\n",code[1]);
  return buffer;
}

char* CLRlongmem(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CLR$%x%x",code[2],code[3]);
  printf("CLR$%x%x\n",code[2],code[3]);
  return buffer;
}

char* CLRX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CLR(X)");
  printf("CLR(X)\n");
  return buffer;
}

char* CLRshortoffX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CLR($%x,X)", code[1]);
  printf("CLR($%x,X)\n",code[1]);
  return buffer;
}

char* CLRlongoffX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CLR($%x%x,X)", code[2],code[3]);
  printf("CLR($%x%x,X)\n",code[2],code[3]);
  return buffer;
}

char* CLRY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CLR(Y)");
  printf("CLR(Y)\n");
  return buffer;
}

char* CLRshortoffY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CLR($%x,Y)",code[2]);
  printf("CLR($%x,Y)\n",code[2]);
  return buffer;
}

char* CLRlongoffY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CLR($%x%x,Y)", code[2],code[3]);
  printf("CLR($%x%x,Y)\n", code[2],code[3]);
  return buffer;
}

char* CLRshortoffSP(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CLR($%x,SP)", code[1]);
  printf("CLR($%x,SP)\n", code[1]);
  return buffer;
}

char* CLRshortptr(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CLR[$%x.w]", code[2]);
  printf("CLR[$%x.w]\n",code[2]);
  return buffer;
}

char* CLRlongptr(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CLR[$%x%x.w]", code[2],code[3]);
  printf("CLR[$%x%x.w]\n",code[2],code[3]);
  return buffer;
}

char* CLRshortptrX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CLR[$%x.w],X",code[2]);
  printf("CLR[$%x.w],X\n",code[2]);
  return buffer;
}

char* CLRlongptrX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CLR[$%x%x.w],X",code[2],code[3]);
  printf("CLR[$%x%x.w],X\n",code[2],code[3]);
  return buffer;
}

char* CLRshortptrY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CLR[$%x.w],Y",code[2]);
  printf("CLR[$%x.w],Y\n",code[2]);
  return buffer;
}

char* CLRWX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CLRW X");
  printf("CLRW X\n");
  return buffer;
}

char* CLRWY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CLRW Y");
  printf("CLRW Y\n");
  return buffer;
}

      //compare
char* CPbyte(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CP  A,#$%x", code[1]);
  printf("CP  A,#$%x\n",code[1]);
  return buffer;
}

char* CPshortmem(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CP  A,$%x", code[1]);
  printf("CP  A,$%x\n",code[1]);
  return buffer;
}

char* CPlongmem(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CP  A,$%x%x", code[1],code[2]);
  printf("CP  A,$%x%x\n",code[1],code[2]);
  return buffer;
}

char* CPX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CP  A,(X)");
  printf("CP  A,(X)\n");
  return buffer;
}

char* CPshortoffX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CP  A,($%x,X)", code[1]);
  printf("CP  A,($%x,X)\n",code[1]);
  return buffer;
}

char* CPlongoffX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CP  A,($%x%x,X)", code[1],code[2]);
  printf("CP  A,($%x%x,X)\n",code[1],code[2]);
  return buffer;
}

char* CPY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CP  A,(Y)");
  printf("CP  A,(Y)\n");
  return buffer;
}

char* CPshortoffY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CP  A,($%x,Y)",code[2]);
  printf("CP  A,($%x,Y)\n",code[2]);
  return buffer;
}

char* CPlongoffY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CP  A,($%x%x,Y)", code[2],code[3]);
  printf("CP  A,($%x%x,Y)\n", code[2],code[3]);
  return buffer;
}

char* CPshortoffSP(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CP  A,($%x,SP)", code[1]);
  printf("CP  A,($%x,SP)\n", code[1]);
  return buffer;
}

char* CPshortptr(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CP  A,[$%x.w]", code[2]);
  printf("CP  A,[$%x.w]\n",code[2]);
  return buffer;
}

char* CPlongptr(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CP  A,[$%x%x.w]", code[2],code[3]);
  printf("CP  A,[$%x%x.w]\n",code[2],code[3]);
  return buffer;
}

char* CPshortptrX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CP  A,[$%x.w],X",code[2]);
  printf("CP  A,[$%x.w],X\n",code[2]);
  return buffer;
}

char* CPlongptrX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CP  A,[$%x%x.w],X",code[2],code[3]);
  printf("CP  A,[$%x%x.w],X\n",code[2],code[3]);
  return buffer;
}

char* CPshortptrY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CP  A,[$%x.w],Y",code[2]);
  printf("CP  A,[$%x.w],Y\n",code[2]);
  return buffer;
}

char* CPwordX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPW X,#$%x%x", code[1],code[2]);
  printf("CPW X,#$%x%x\n", code[1],code[2]);
  return buffer;
}

char* CPWshortmemX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPW X,$%x", code[1]);
  printf("CPW X,$%x\n",code[1]);
  return buffer;
}

char* CPWlongmemX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPW X,$%x%x", code[1],code[2]);
  printf("CPW X,$%x%x\n",code[1],code[2]);
  return buffer;
}

char* CPWY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPW X,(Y)");
  printf("CPW X,(Y)\n");
  return buffer;
}

char* CPWshortoffY_X(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPW X,($%x,Y)",code[2]);
  printf("CPW X,($%x,Y)\n",code[2]);
  return buffer;
}

char* CPWlongoffY_X(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPW X,($%x%x,Y)", code[2],code[3]);
  printf("CPW X,($%x%x,Y)\n", code[2],code[3]);
  return buffer;
}

char* CPWshortoffSP_X(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPW X,($%x,SP)", code[1]);
  printf("CPW X,($%x,SP)\n", code[1]);
  return buffer;
}

char* CPWshortptr_X(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPW X,[$%x.w]", code[2]);
  printf("CPW X,[$%x.w]\n",code[2]);
  return buffer;
}

char* CPWlongptr_X(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPW X,[$%x%x.w]", code[2],code[3]);
  printf("CPW X,[$%x%x.w]\n",code[2],code[3]);
  return buffer;
}

char* CPWshortptrY_X(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPW X,[$%x.w],Y",code[2]);
  printf("CPW X,[$%x.w],Y\n",code[2]);
  return buffer;
}

char* CPwordY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPW Y,#$%x%x", code[2],code[3]);
  printf("CPW Y,#$%x%x\n", code[2],code[3]);
  return buffer;
}

char* CPWshortmem_Y(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPW Y,$%x", code[2]);
  printf("CPW Y,$%x\n",code[2]);
  return buffer;
}

char* CPWlongmem_Y(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPW Y,$%x%x", code[2],code[3]);
  printf("CPW Y,$%x%x\n",code[2],code[3]);
  return buffer;
}

char* CPWX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPW Y,(X)");
  printf("CPW Y,(X)\n");
  return buffer;
}

char* CPWshortoffX_Y(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPW Y,($%x,X)",code[1]);
  printf("CPW Y,($%x,X)\n",code[1]);
  return buffer;
}

char* CPWlongoffX_Y(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPW Y,($%x%x,X)", code[1],code[2]);
  printf("CPW Y,($%x%x,X)\n", code[1],code[2]);
  return buffer;
}

char* CPWshortptr_Y(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPW Y,[$%x.w]", code[2]);
  printf("CPW Y,[$%x.w]\n",code[2]);
  return buffer;
}

char* CPWshortptrX_Y(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPW Y,([$%x.w],X)", code[2]);
  printf("CPW Y,([$%x.w],X)\n",code[2]);
  return buffer;
}

char* CPWlongptrX_Y(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPW Y,([$%x%x.w],X)",code[2],code[3]);
  printf("CPW Y,([$%x%x.w],X)\n",code[2],code[3]);
  return buffer;
}

      //CPL
char* CPLA(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPL A");
  printf("CPL A\n");
  return buffer;
}

char* CPLshortmem(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPL$%x", code[1]);
  printf("CPL$%x\n",code[1]);
  return buffer;
}

char* CPLlongmem(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPL$%x%x",code[2],code[3]);
  printf("CPL$%x%x\n",code[2],code[3]);
  return buffer;
}

char* CPLX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPL(X)");
  printf("CPL(X)\n");
  return buffer;
}

char* CPLshortoffX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPL($%x,X)", code[1]);
  printf("CPL($%x,X)\n",code[1]);
  return buffer;
}

char* CPLlongoffX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPL($%x%x,X)", code[2],code[3]);
  printf("CPL($%x%x,X)\n",code[2],code[3]);
  return buffer;
}

char* CPLY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPL(Y)");
  printf("CPL(Y)\n");
  return buffer;
}

char* CPLshortoffY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPL($%x,Y)",code[2]);
  printf("CPL($%x,Y)\n",code[2]);
  return buffer;
}

char* CPLlongoffY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPL($%x%x,Y)", code[2],code[3]);
  printf("CPL($%x%x,Y)\n", code[2],code[3]);
  return buffer;
}

char* CPLshortoffSP(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPL($%x,SP)", code[1]);
  printf("CPL($%x,SP)\n", code[1]);
  return buffer;
}

char* CPLshortptr(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPL[$%x.w]", code[2]);
  printf("CPL[$%x.w]\n",code[2]);
  return buffer;
}

char* CPLlongptr(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPL[$%x%x.w]", code[2],code[3]);
  printf("CPL[$%x%x.w]\n",code[2],code[3]);
  return buffer;
}

char* CPLshortptrX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPL[$%x.w],X",code[2]);
  printf("CPL[$%x.w],X\n",code[2]);
  return buffer;
}

char* CPLlongptrX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPL[$%x%x.w],X",code[2],code[3]);
  printf("CPL[$%x%x.w],X\n",code[2],code[3]);
  return buffer;
}

char* CPLshortptrY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPL[$%x],Y",code[2]);
  printf("CPL[$%x],Y\n",code[2]);
  return buffer;
}

char* CPLWX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPLW X");
  printf("CPLW X\n");
  return buffer;
}

char* CPLWY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"CPLW Y");
  printf("CPLW Y\n");
  return buffer;
}

      //DECREMENT
char* DECA(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"DEC A");
  printf("DEC A\n");
  return buffer;
}

char* DECshortmem(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"DEC$%x", code[1]);
  printf("DEC$%x\n",code[1]);
  return buffer;
}

char* DEClongmem(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"DEC$%x%x",code[2],code[3]);
  printf("DEC$%x%x\n",code[2],code[3]);
  return buffer;
}

char* DECX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"DEC(X)");
  printf("DEC(X)\n");
  return buffer;
}

char* DECshortoffX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"DEC($%x,X)", code[1]);
  printf("DEC($%x,X)\n",code[1]);
  return buffer;
}

char* DEClongoffX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"DEC($%x%x,X)", code[2],code[3]);
  printf("DEC($%x%x,X)\n",code[2],code[3]);
  return buffer;
}

char* DECY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"DEC(Y)");
  printf("DEC(Y)\n");
  return buffer;
}

char* DECshortoffY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"DEC($%x,Y)",code[2]);
  printf("DEC($%x,Y)\n",code[2]);
  return buffer;
}

char* DEClongoffY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"DEC($%x%x,Y)", code[2],code[3]);
  printf("DEC($%x%x,Y)\n", code[2],code[3]);
  return buffer;
}

char* DECshortoffSP(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"DEC($%x,SP)", code[1]);
  printf("DEC($%x,SP)\n", code[1]);
  return buffer;
}

char* DECshortptr(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"DEC[$%x.w]", code[2]);
  printf("DEC[$%x.w]\n",code[2]);
  return buffer;
}

char* DEClongptr(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"DEC[$%x%x.w]", code[2],code[3]);
  printf("DEC[$%x%x.w]\n",code[2],code[3]);
  return buffer;
}

char* DECshortptrX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"DEC[$%x.w],X",code[2]);
  printf("DEC[$%x.w],X\n",code[2]);
  return buffer;
}

char* DEClongptrX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"DEC[$%x%x.w],X",code[2],code[3]);
  printf("DEC[$%x%x.w],X\n",code[2],code[3]);
  return buffer;
}

char* DECshortptrY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"DEC[$%x],Y",code[2]);
  printf("DEC[$%x],Y\n",code[2]);
  return buffer;
}

char* DECWX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"DECW X");
  printf("DECW X\n");
  return buffer;
}

char* DECWY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"DECW Y");
  printf("DECW Y\n");
  return buffer;
}

char* DivideUnsignedX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"DIV X,A");
  printf("DIV X,A\n");
  return buffer;
}

char* DivideUnsignedY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"DIV Y,A");
  printf("DIV Y,A\n");
  return buffer;
}

char* DivideSigned(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"DIV X,Y");
  printf("DIV X,Y\n");
  return buffer;
}

char* EXG_X(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"EXG A,XL");
  printf("EXG A,XL\n");
  return buffer;
}

char* EXG_Y(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"EXG A,YL");
  printf("EXG A,YL\n");
  return buffer;
}

char* EXG_longmem(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"EXG A,$%x%x",code[1],code[2]);
  printf("EXG A,$%x%x\n",code[1],code[2]);
  return buffer;
}

char* EXGW(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"EXGW X,Y");
  printf("EXGW X,Y\n");
  return buffer;
}

char* HALT(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"HALT");
  printf("HALT\n");
  return buffer;
}

char* Interrupt(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"INT $%x%x%x",code[1],code[2],code[3]);
  printf("INT $%x%x%x\n",code[1],code[2],code[3]);
  return buffer;
}

char* InterruptReturn(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"IRET");
  printf("IRET\n");
  return buffer;
}

          //JUMP
char* JPlongmem(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JP$%x%x",code[1],code[2]);
  printf("JP$%x%x\n",code[2],code[3]);
  return buffer;
}

char* JPX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JP(X)");
  printf("JP(X)\n");
  return buffer;
}

char* JPshortoffX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JP($%x,X)", code[1]);
  printf("JP($%x,X)\n",code[1]);
  return buffer;
}

char* JPlongoffX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JP($%x%x,X)", code[1],code[2]);
  printf("JP($%x%x,X)\n",code[1],code[2]);
  return buffer;
}

char* JPY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JP(Y)");
  printf("JP(Y)\n");
  return buffer;
}

char* JPshortoffY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JP($%x,Y)",code[2]);
  printf("JP($%x,Y)\n",code[2]);
  return buffer;
}

char* JPlongoffY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JP($%x%x,Y)", code[2],code[3]);
  printf("JP($%x%x,Y)\n", code[2],code[3]);
  return buffer;
}

char* JPshortptr(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JP[$%x.w]", code[2]);
  printf("JP[$%x.w]\n",code[2]);
  return buffer;
}

char* JPlongptr(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JP[$%x%x.w]", code[2],code[3]);
  printf("JP[$%x%x.w]\n",code[2],code[3]);
  return buffer;
}

char* JPshortptrX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JP[$%x.w],X",code[2]);
  printf("JP[$%x.w],X\n",code[2]);
  return buffer;
}

char* JPlongptrX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JP[$%x%x.w],X",code[2],code[3]);
  printf("JP[$%x%x.w],X\n",code[2],code[3]);
  return buffer;
}

char* JPshortptrY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JP[$%x.w],Y",code[2]);
  printf("JP[$%x.w],Y\n",code[2]);
  return buffer;
}

char* JPFextmem(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JPF $%x%x%x",code[1],code[2],code[3]);
  printf("JPF $%x%x%x\n",code[1],code[2],code[3]);
  return buffer;
}

char* JPFlongptr(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JPF [$%x%x.e]",code[2],code[3]);
  printf("JPF [$%x%x.e]\n",code[2],code[3]);
  return buffer;
}

char* JumpRelativeAlways(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JRA $%x",code[1]);
  printf("JRA $%x\n",code[1]);
  return buffer;
}

      //CONDITION JUMP
char* Carry(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JRC $%x",code[1]);
  printf("JRC $%x\n",code[1]);
  return buffer;
}

char* Equal(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JREQ $%x",code[1]);
  printf("JREQ $%x\n",code[1]);
  return buffer;
}

char* False(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JRF $%x",code[1]);
  printf("JRF $%x\n",code[1]);
  return buffer;
}

char* HalfCarry(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JRH $%x",code[2]);
  printf("JRH $%x\n",code[1]);
  return buffer;
}

char* InterruptHigh(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JRIH $%x",code[2]);
  printf("JRIH $%x\n",code[1]);
  return buffer;
}

char* InterurptLow(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JRIL $%x",code[2]);
  printf("JRIL $%x\n",code[1]);
  return buffer;
}

char* InterruptMask(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JRM $%x",code[2]);
  printf("JRM $%x\n",code[1]);
  return buffer;
}

char* Minus(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JRMI $%x",code[1]);
  printf("JRMI $%x\n",code[1]);
  return buffer;
}

char* NotCarry(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JRNC $%x",code[1]);
  printf("JRNC $%x\n",code[1]);
  return buffer;
}

char* NotEqual(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JRNE $%x",code[1]);
  printf("JRNE $%x\n",code[1]);
  return buffer;
}

char* NotHalfCarry(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JRNH $%x",code[2]);
  printf("JRNH $%x\n",code[2]);
  return buffer;
}

char* NotInterruptMask(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JRNM $%x",code[2]);
  printf("JRNM $%x\n",code[2]);
  return buffer;
}

char* NotOverflow(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JRNV $%x",code[1]);
  printf("JRNV $%x\n",code[1]);
  return buffer;
}

char* Plus(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JRPL $%x",code[1]);
  printf("JRPL $%x\n",code[1]);
  return buffer;
}

char* SignGreaterOrEqual(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JRSGE $%x",code[1]);
  printf("JRSGE $%x\n",code[1]);
  return buffer;
}

char* SignGreaterThan(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JRSGT $%x",code[1]);
  printf("JRSGT $%x\n",code[1]);
  return buffer;
}

char* SignLowerOrEqual(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JRSLE $%x",code[1]);
  printf("JRSLE $%x\n",code[1]);
  return buffer;
}

char* SignLowerThan(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JRSLT $%x",code[1]);
  printf("JRSLT $%x\n",code[1]);
  return buffer;
}

char* True(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JRT $%x",code[1]);
  printf("JRT $%x\n",code[1]);
  return buffer;
}

char* UnsignGreaterOrEqual(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JRUGE $%x",code[1]);
  printf("JRUGE $%x\n",code[1]);
  return buffer;
}

char* UnsignGreaterThan(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JRUGT $%x",code[1]);
  printf("JRUGT $%x\n",code[1]);
  return buffer;
}


char* UsignLowerOrEqual(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JRULE $%x",code[1]);
  printf("JRULE $%x\n",code[1]);
  return buffer;
}

char* UnsignLowerThan(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JRULT $%x",code[1]);
  printf("JRULT $%x\n",code[1]);
  return buffer;
}

char* Overflow(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JRV $%x",code[1]);
  printf("JRV $%x\n",code[1]);
  return buffer;
}

char* carry(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"JRC $%x",code[1]);
  printf("JRC $%x\n",code[1]);
  return buffer;
}

char* LDbyte(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"LD  A,#$%x", code[1]);
  printf("LD  A,#$%x\n",code[1]);
  return buffer;
}

char* LDshortmem(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"LD  A,$%x", code[1]);
  printf("LD  A,$%x\n",code[1]);
  return buffer;
}

char* LDlongmem(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"LD  A,$%x%x", code[1],code[2]);
  printf("LD  A,$%x%x\n",code[1],code[2]);
  return buffer;
}

char* LDX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"LD  A,(X)");
  printf("LD  A,(X)\n");
  return buffer;
}

char* LDshortoffX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"LD  A,($%x,X)", code[1]);
  printf("LD  A,($%x,X)\n",code[1]);
  return buffer;
}

char* LDlongoffX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"LD  A,($%x%x,X)", code[1],code[2]);
  printf("LD  A,($%x%x,X)\n",code[1],code[2]);
  return buffer;
}

char* LDY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"LD  A,(Y)");
  printf("LD  A,(Y)\n");
  return buffer;
}

char* LDshortoffY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"LD  A,($%x,Y)",code[2]);
  printf("LD  A,($%x,Y)\n",code[2]);
  return buffer;
}

char* LDlongoffY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"LD  A,($%x%x,Y)", code[2],code[3]);
  printf("LD  A,($%x%x,Y)\n", code[2],code[3]);
  return buffer;
}

char* LDshortoffSP(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"LD  A,($%x,SP)", code[1]);
  printf("LD  A,($%x,SP)\n", code[1]);
  return buffer;
}

char* LDshortptr(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"LD  A,[$%x.w]", code[2]);
  printf("LD  A,[$%x.w]\n",code[2]);
  return buffer;
}

char* LDlongptr(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"LD  A,[$%x%x.w]", code[2],code[3]);
  printf("LD  A,[$%x%x.w]\n",code[2],code[3]);
  return buffer;
}

char* LDshortptrX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"LD  A,[$%x.w],X",code[2]);
  printf("LD  A,[$%x.w],X\n",code[2]);
  return buffer;
}

char* LDlongptrX(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"LD  A,[$%x%x.w],X",code[2],code[3]);
  printf("LD  A,[$%x%x.w],X\n",code[2],code[3]);
  return buffer;
}

char* LDshortptrY(uint8_t *code){

  buffer = malloc(1024);
  sprintf(buffer,"LD  A,[$%x.w],Y",code[2]);
  printf("LD  A,[$%x.w],Y\n",code[2]);
  return buffer;
}
