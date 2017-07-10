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

char* ADCbyte(uint8_t *code);
char* ADCshortmem(uint8_t *code);
char* ADClongmem(uint8_t *code);
char* ADCX(uint8_t *code);
char* ADCshortoff(uint8_t *code);
char* ADClongoff(uint8_t *code);
char* ADCY(uint8_t *code);

char* disassembler(uint8_t *code);
int ditermineCode(uint8_t *code);
char* error(uint8_t *code);
char* printError(uint8_t *code);

extern Opcode opcodeTable[];
extern Opcode opcodeTable72[];
extern Opcode opcodeTable90[];
extern Opcode opcodeTable91[];
extern Opcode opcodeTable92[];

#endif // _DISASSEMBLER_H
