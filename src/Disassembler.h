#ifndef _DISASSEMBLER_H
#define _DISASSEMBLER_H
#include <stdint.h>

int ADCbyte(uint8_t *code);
char disassembler(uint8_t *code);
typedef struct Opcode Opcode;
struct Opcode{
  uint8_t *code;
  int length;
  int cycle;
};
extern Opcode OpcodeTable[];

#endif // _DISASSEMBLER_H
