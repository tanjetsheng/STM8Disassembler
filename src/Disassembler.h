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
extern Opcode OpcodeTable72[];
extern Opcode OpcodeTable90[];
extern Opcode OpcodeTable91[];
extern Opcode OpcodeTable92[];

#endif // _DISASSEMBLER_H
