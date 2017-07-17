#ifndef _DISASSEMBLER_H
#define _DISASSEMBLER_H
#include <stdint.h>



typedef struct Opcode Opcode;
struct Opcode{
  char* (*execute)(uint8_t *code);
  int length;
  int cycle;
};
char* buffer;

        //ADC
char* ADCbyte(uint8_t *code);
char* ADCshortmem(uint8_t *code);
char* ADClongmem(uint8_t *code);
char* ADCX(uint8_t *code);
char* ADCshortoffX(uint8_t *code);
char* ADClongoffX(uint8_t *code);
char* ADCY(uint8_t *code);
char* ADCshortoffY(uint8_t *code);
char* ADClongoffY(uint8_t *code);
char* ADCshortoffSP(uint8_t *code);
char* ADCshortptr(uint8_t *code);
char* ADClongptr(uint8_t *code);
char* ADCshortptrX(uint8_t *code);
char* ADClongptrX(uint8_t *code);
char* ADCshortptrY(uint8_t *code);

      //ADD
char* ADDbyte(uint8_t *code);
char* ADDshortmem(uint8_t *code);
char* ADDlongmem(uint8_t *code);
char* ADDX(uint8_t *code);
char* ADDshortoffX(uint8_t *code);
char* ADDlongoffX(uint8_t *code);
char* ADDY(uint8_t *code);
char* ADDshortoffY(uint8_t *code);
char* ADDlongoffY(uint8_t *code);
char* ADDshortoffSP(uint8_t *code);
char* ADDshortptr(uint8_t *code);
char* ADDlongptr(uint8_t *code);
char* ADDshortptrX(uint8_t *code);
char* ADDlongptrX(uint8_t *code);
char* ADDshortptrY(uint8_t *code);

      //AND
char* ANDbyte(uint8_t *code);
char* ANDshortmem(uint8_t *code);
char* ANDlongmem(uint8_t *code);
char* ANDX(uint8_t *code);
char* ANDshortoffX(uint8_t *code);
char* ANDlongoffX(uint8_t *code);
char* ANDY(uint8_t *code);
char* ANDshortoffY(uint8_t *code);
char* ANDlongoffY(uint8_t *code);
char* ANDshortoffSP(uint8_t *code);
char* ANDshortptr(uint8_t *code);
char* ANDlongptr(uint8_t *code);
char* ANDshortptrX(uint8_t *code);
char* ANDlongptrX(uint8_t *code);
char* ANDshortptrY(uint8_t *code);

      //INC
char* INCA(uint8_t *code);
char* INCshortmem(uint8_t *code);
char* INClongmem(uint8_t *code);
char* INCX(uint8_t *code);
char* INCshortoffX(uint8_t *code);
char* INClongoffX(uint8_t *code);
char* INCY(uint8_t *code);
char* INCshortoffY(uint8_t *code);
char* INClongoffY(uint8_t *code);
char* INCshortoffSP(uint8_t *code);
char* INCshortptr(uint8_t *code);
char* INClongptr(uint8_t *code);
char* INCshortptrX(uint8_t *code);
char* INClongptrX(uint8_t *code);
char* INCshortptrY(uint8_t *code);


char* disassembler(uint8_t *code);
char* error(uint8_t *code);
char* printError(uint8_t *code);

extern Opcode opcodeTable[];
extern Opcode opcodeTable72[];
extern Opcode opcodeTable90[];
extern Opcode opcodeTable91[];
extern Opcode opcodeTable92[];

#endif // _DISASSEMBLER_H
