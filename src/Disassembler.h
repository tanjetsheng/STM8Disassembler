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
char *str;
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
char* INCWord_X(uint8_t *code);
char* INCWord_Y(uint8_t *code);

		//ADDW
char* ADDWword(uint8_t *code);
char* ADDWlongmem(uint8_t *code);
char* ADDWshortoffSP(uint8_t *code);
char* ADDWwordY(uint8_t *code);
char* ADDWlongmemY(uint8_t *code);
char* ADDWshortoffSPY(uint8_t *code);
char* ADDWSP(uint8_t *code);

    //BCP
char* BCPbyte(uint8_t *code);
char* BCPshortmem(uint8_t *code);
char* BCPlongmem(uint8_t *code);
char* BCPX(uint8_t *code);
char* BCPshortoffX(uint8_t *code);
char* BCPlongoffX(uint8_t *code);
char* BCPY(uint8_t *code);
char* BCPshortoffY(uint8_t *code);
char* BCPlongoffY(uint8_t *code);
char* BCPshortoffSP(uint8_t *code);
char* BCPshortptr(uint8_t *code);
char* BCPlongptr(uint8_t *code);
char* BCPshortptrX(uint8_t *code);
char* BCPlongptrX(uint8_t *code);
char* BCPshortptrY(uint8_t *code);

      //CALL
char* CALLlongmem(uint8_t *code);
char* CALLX(uint8_t *code);
char* CALLshortoffX(uint8_t *code);
char* CALLlongoffX(uint8_t *code);
char* CALLY(uint8_t *code);
char* CALLshortoffY(uint8_t *code);
char* CALLlongoffY(uint8_t *code);
char* CALLshortptr(uint8_t *code);
char* CALLlongptr(uint8_t *code);
char* CALLshortptrX(uint8_t *code);
char* CALLlongptrX(uint8_t *code);
char* CALLshortptrY(uint8_t *code);
char* CALLFextmem(uint8_t *code);
char* CALLFlongptr(uint8_t *code);
char* CALLR(uint8_t *code);
char* CCF(uint8_t *code);

      //clear
char* CLRA(uint8_t *code);
char* CLRshortmem(uint8_t *code);
char* CLRlongmem(uint8_t *code);
char* CLRX(uint8_t *code);
char* CLRshortoffX(uint8_t *code);
char* CLRlongoffX(uint8_t *code);
char* CLRY(uint8_t *code);
char* CLRshortoffY(uint8_t *code);
char* CLRlongoffY(uint8_t *code);
char* CLRshortoffSP(uint8_t *code);
char* CLRshortptr(uint8_t *code);
char* CLRlongptr(uint8_t *code);
char* CLRshortptrX(uint8_t *code);
char* CLRlongptrX(uint8_t *code);
char* CLRshortptrY(uint8_t *code);
char* CLRWX(uint8_t *code);
char* CLRWY(uint8_t *code);

      //compare
char* CPbyte(uint8_t *code);
char* CPshortmem(uint8_t *code);
char* CPlongmem(uint8_t *code);
char* CPX(uint8_t *code);
char* CPshortoffX(uint8_t *code);
char* CPlongoffX(uint8_t *code);
char* CPY(uint8_t *code);
char* CPshortoffY(uint8_t *code);
char* CPlongoffY(uint8_t *code);
char* CPshortoffSP(uint8_t *code);
char* CPshortptr(uint8_t *code);
char* CPlongptr(uint8_t *code);
char* CPshortptrX(uint8_t *code);
char* CPlongptrX(uint8_t *code);
char* CPshortptrY(uint8_t *code);
char* CPwordX(uint8_t *code);
char* CPWshortmemX(uint8_t *code);
char* CPWlongmemX(uint8_t *code);
char* CPWY(uint8_t *code);
char* CPWshortoffY_X(uint8_t *code);
char* CPWlongoffY_X(uint8_t *code);
char* CPWshortoffSP_X(uint8_t *code);
char* CPWshortptr_X(uint8_t *code);
char* CPWlongptr_X(uint8_t *code);
char* CPWshortptrY_X(uint8_t *code);
char* CPwordY(uint8_t *code);
char* CPWshortmem_Y(uint8_t *code);
char* CPWlongmem_Y(uint8_t *code);
char* CPWX(uint8_t *code);
char* CPWshortoffX_Y(uint8_t *code);
char* CPWlongoffX_Y(uint8_t *code);
char* CPWshortptr_Y(uint8_t *code);
char* CPWshortptrX_Y(uint8_t *code);
char* CPWlongptrX_Y(uint8_t *code);

        //logic 1's complement

char* CPLA(uint8_t *code);
char* CPLshortmem(uint8_t *code);
char* CPLlongmem(uint8_t *code);
char* CPLX(uint8_t *code);
char* CPLshortoffX(uint8_t *code);
char* CPLlongoffX(uint8_t *code);
char* CPLY(uint8_t *code);
char* CPLshortoffY(uint8_t *code);
char* CPLlongoffY(uint8_t *code);
char* CPLshortoffSP(uint8_t *code);
char* CPLshortptr(uint8_t *code);
char* CPLlongptr(uint8_t *code);
char* CPLshortptrX(uint8_t *code);
char* CPLlongptrX(uint8_t *code);
char* CPLshortptrY(uint8_t *code);
char* CPLWX(uint8_t *code);
char* CPLWY(uint8_t *code);

      //DECREMENT
char* DECA(uint8_t *code);
char* DECshortmem(uint8_t *code);
char* DEClongmem(uint8_t *code);
char* DECX(uint8_t *code);
char* DECshortoffX(uint8_t *code);
char* DEClongoffX(uint8_t *code);
char* DECY(uint8_t *code);
char* DECshortoffY(uint8_t *code);
char* DEClongoffY(uint8_t *code);
char* DECshortoffSP(uint8_t *code);
char* DECshortptr(uint8_t *code);
char* DEClongptr(uint8_t *code);
char* DECshortptrX(uint8_t *code);
char* DEClongptrX(uint8_t *code);
char* DECshortptrY(uint8_t *code);
char* DECWX(uint8_t *code);
char* DECWY(uint8_t *code);

          //JP
char* JPlongmem(uint8_t *code);
char* JPX(uint8_t *code);
char* JPshortoffX(uint8_t *code);
char* JPlongoffX(uint8_t *code);
char* JPY(uint8_t *code);
char* JPshortoffY(uint8_t *code);
char* JPlongoffY(uint8_t *code);
char* JPshortptr(uint8_t *code);
char* JPlongptr(uint8_t *code);
char* JPshortptrX(uint8_t *code);
char* JPlongptrX(uint8_t *code);
char* JPshortptrY(uint8_t *code);
char* JPFextmem(uint8_t *code);
char* JPFlongptr(uint8_t *code);
char* JumpRelativeAlways(uint8_t *code);

        //JUMP CONDITION
char* Carry(uint8_t *code);
char* Equal(uint8_t *code);
char* False(uint8_t *code);
char* HalfCarry(uint8_t *code);
char* InterruptHigh(uint8_t *code);
char* InterurptLow(uint8_t *code);
char* InterruptMask(uint8_t *code);
char* Minus(uint8_t *code);
char* NotCarry(uint8_t *code);
char* NotEqual(uint8_t *code);
char* NotHalfCarry(uint8_t *code);
char* NotInterruptMask(uint8_t *code);
char* NotOverflow(uint8_t *code);
char* Plus(uint8_t *code);
char* SignGreaterOrEqual(uint8_t *code);
char* SignGreaterThan(uint8_t *code);
char* SignLowerOrEqual(uint8_t *code);
char* SignLowerThan(uint8_t *code);
char* True(uint8_t *code);
char* UnsignGreaterOrEqual(uint8_t *code);
char* UnsignGreaterThan(uint8_t *code);
char* UsignLowerOrEqual(uint8_t *code);
char* UnsignLowerThan(uint8_t *code);
char* carry(uint8_t *code);
char* Overflow(uint8_t *code);



char* BREAK(uint8_t *code);
char* BitComplement(uint8_t *code);
char* BCCM(uint8_t *code);
char* BitReset(uint8_t *code);
char* Bitset(uint8_t *code);
char* BitTestJumpFalse(uint8_t *code);
char* BitTestJumpTrue(uint8_t *code);
char* DivideUnsignedX(uint8_t *code);
char* DivideUnsignedY(uint8_t *code);
char* DivideSigned(uint8_t *code);
char* EXG_X(uint8_t *code);
char* EXG_Y(uint8_t *code);
char* EXG_longmem(uint8_t *code);
char* EXGW(uint8_t *code);
char* HALT(uint8_t *code);
char* Interrupt(uint8_t *code);
char* InterruptReturn(uint8_t *code);

      //load
char* LDbyte(uint8_t *code);
char* LDshortmem(uint8_t *code);
char* LDlongmem(uint8_t *code);
char* LDX(uint8_t *code);
char* LDshortoffX(uint8_t *code);
char* LDlongoffX(uint8_t *code);
char* LDY(uint8_t *code);
char* LDshortoffY(uint8_t *code);
char* LDlongoffY(uint8_t *code);
char* LDshortoffSP(uint8_t *code);
char* LDshortptr(uint8_t *code);
char* LDlongptr(uint8_t *code);
char* LDshortptrX(uint8_t *code);
char* LDlongptrX(uint8_t *code);
char* LDshortptrY(uint8_t *code);

char* disassembler(uint8_t **ptrptrcode);
char* disassembleNCodes(uint8_t **ptrptrcode, int numCode);

extern Opcode opcodeTable[];
extern Opcode opcodeTable72[];
extern Opcode opcodeTable90[];
extern Opcode opcodeTable91[];
extern Opcode opcodeTable92[];
#endif // _DISASSEMBLER_H
