#include "unity.h"
#include "Disassembler.h"
#include <stdlib.h>
#include "exception.h"
#include "CException.h"
#include "CExceptionConfig.h"

void setUp(void)
{}

void tearDown(void)
{}
          /*ADC*/
/*
void test_ADCbyte_(void)
{
	char* buffer;
	uint8_t memory[]= {0xA9,0x23};
	TEST_ASSERT_EQUAL_STRING("ADC  A,#$23",buffer = disassembler(memory));
	free(buffer);
}

void test_ADCshortmem_(void)
{
	char* buffer;
	uint8_t memory[]= {0xB9,0x24};
	TEST_ASSERT_EQUAL_STRING("ADC  A,$24",buffer = disassembler(memory));
	free(buffer);
}

void test_ADClongmem_(void)
{
	char* buffer;
	uint8_t memory[]= {0xC9,0x23,0x24};
	TEST_ASSERT_EQUAL_STRING("ADC  A,$2324",buffer = disassembler(memory));
	free(buffer);
}

void test_ADCX_(void)
{
	char* buffer;
	uint8_t memory[]= {0xF9};
	TEST_ASSERT_EQUAL_STRING("ADC  A,(X)",buffer = disassembler(memory));
	free(buffer);
}

void test_ADCshortoffX_(void)
{
	char* buffer;
	uint8_t memory[]= {0xE9,0x33};
	TEST_ASSERT_EQUAL_STRING("ADC  A,($33,X)",buffer = disassembler(memory));
	free(buffer);
}

void test_ADClongoffX_(void)
{
	char* buffer;
	uint8_t memory[]= {0xD9,0x33,0X44};
	TEST_ASSERT_EQUAL_STRING("ADC  A,($3344,X)",buffer = disassembler(memory));
	free(buffer);
}

void test_ADCY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0xF9};
	TEST_ASSERT_EQUAL_STRING("ADC  A,(Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_ADCshortoffY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0xE9,0x23};
	TEST_ASSERT_EQUAL_STRING("ADC  A,($23,Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_ADClongoffY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0xD9,0x23,0x33};
	TEST_ASSERT_EQUAL_STRING("ADC  A,($2333,Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_ADCshortoffSP_(void)
{
	char* buffer;
	uint8_t memory[]= {0x19,0x23};
	TEST_ASSERT_EQUAL_STRING("ADC  A,($23,SP)",buffer = disassembler(memory));
	free(buffer);
}

void test_ADCshortptr_(void)
{
	char* buffer;
	uint8_t memory[]= {0x92,0xC9,0x22};
	TEST_ASSERT_EQUAL_STRING("ADC  A,[$22.w]",buffer = disassembler(memory));
	free(buffer);
}

void test_ADClongptr_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0xC9,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("ADC  A,[$2233.w]",buffer = disassembler(memory));
	free(buffer);
}

void test_ADCshortptrX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x92,0xD9,0x22};
	TEST_ASSERT_EQUAL_STRING("ADC  A,[$22.w],X",buffer = disassembler(memory));
	free(buffer);
}

void test_ADClongptrX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0xD9,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("ADC  A,[$2233.w],X",buffer = disassembler(memory));
	free(buffer);
}

void test_ADCshortptrY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x91,0xD9,0x22};
	TEST_ASSERT_EQUAL_STRING("ADC  A,[$22.w],Y",buffer = disassembler(memory));
	free(buffer);
}


              //ADD
void test_ADDbyte_(void)
{
	char* buffer;
	uint8_t memory[]= {0xAB,0x23};
	TEST_ASSERT_EQUAL_STRING("ADD  A,#$23",buffer = disassembler(memory));
	free(buffer);
}

void test_ADDshortmem_(void)
{
	char* buffer;
	uint8_t memory[]= {0xBB,0x24};
	TEST_ASSERT_EQUAL_STRING("ADD  A,$24",buffer = disassembler(memory));
	free(buffer);
}

void test_ADDlongmem_(void)
{
	char* buffer;
	uint8_t memory[]= {0xCB,0x23,0x24};
	TEST_ASSERT_EQUAL_STRING("ADD  A,$2324",buffer = disassembler(memory));
	free(buffer);
}

void test_ADDX_(void)
{
	char* buffer;
	uint8_t memory[]= {0xFB};
	TEST_ASSERT_EQUAL_STRING("ADD  A,(X)",buffer = disassembler(memory));
	free(buffer);
}

void test_ADDshortoffX_(void)
{
	char* buffer;
	uint8_t memory[]= {0xEB,0x33};
	TEST_ASSERT_EQUAL_STRING("ADD  A,($33,X)",buffer = disassembler(memory));
	free(buffer);
}

void test_ADDlongoffX_(void)
{
	char* buffer;
	uint8_t memory[]= {0xDB,0x33,0X44};
	TEST_ASSERT_EQUAL_STRING("ADD  A,($3344,X)",buffer = disassembler(memory));
	free(buffer);
}

void test_ADDY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0xFB};
	TEST_ASSERT_EQUAL_STRING("ADD  A,(Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_ADDshortoffY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0xEB,0x23};
	TEST_ASSERT_EQUAL_STRING("ADD  A,($23,Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_ADDlongoffY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0xDB,0x23,0x33};
	TEST_ASSERT_EQUAL_STRING("ADD  A,($2333,Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_ADDshortoffSP_(void)
{
	char* buffer;
	uint8_t memory[]= {0x1B,0x23};
	TEST_ASSERT_EQUAL_STRING("ADD  A,($23,SP)",buffer = disassembler(memory));
	free(buffer);
}

void test_ADDshortptr_(void)
{
	char* buffer;
	uint8_t memory[]= {0x92,0xCB,0x22};
	TEST_ASSERT_EQUAL_STRING("ADD  A,[$22.w]",buffer = disassembler(memory));
	free(buffer);
}

void test_ADDlongptr_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0xCB,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("ADD  A,[$2233.w]",buffer = disassembler(memory));
	free(buffer);
}

void test_ADDshortptrX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x92,0xDB,0x22};
	TEST_ASSERT_EQUAL_STRING("ADD  A,[$22.w],X",buffer = disassembler(memory));
	free(buffer);
}

void test_ADDlongptrX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0xDB,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("ADD  A,[$2233.w],X",buffer = disassembler(memory));
	free(buffer);
}

void test_ADDshortptrY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x91,0xDB,0x22};
	TEST_ASSERT_EQUAL_STRING("ADD  A,[$22.w],Y",buffer = disassembler(memory));
	free(buffer);
}

              //AND
void test_ANDbyte_(void)
{
	char* buffer;
	uint8_t memory[]= {0xA4,0x23};
	TEST_ASSERT_EQUAL_STRING("AND  A,#$23",buffer = disassembler(memory));
	free(buffer);
}

void test_ANDshortmem_(void)
{
	char* buffer;
	uint8_t memory[]= {0xB4,0x24};
	TEST_ASSERT_EQUAL_STRING("AND  A,$24",buffer = disassembler(memory));
	free(buffer);
}

void test_ANDlongmem_(void)
{
	char* buffer;
	uint8_t memory[]= {0xC4,0x23,0x24};
	TEST_ASSERT_EQUAL_STRING("AND  A,$2324",buffer = disassembler(memory));
	free(buffer);
}

void test_ANDX_(void)
{
	char* buffer;
	uint8_t memory[]= {0xF4};
	TEST_ASSERT_EQUAL_STRING("AND  A,(X)",buffer = disassembler(memory));
	free(buffer);
}

void test_ANDshortoffX_(void)
{
	char* buffer;
	uint8_t memory[]= {0xE4,0x33};
	TEST_ASSERT_EQUAL_STRING("AND  A,($33,X)",buffer = disassembler(memory));
	free(buffer);
}

void test_ANDlongoffX_(void)
{
	char* buffer;
	uint8_t memory[]= {0xD4,0x33,0X44};
	TEST_ASSERT_EQUAL_STRING("AND  A,($3344,X)",buffer = disassembler(memory));
	free(buffer);
}

void test_ANDY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0xF4};
	TEST_ASSERT_EQUAL_STRING("AND  A,(Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_ANDshortoffY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0xE4,0x23};
	TEST_ASSERT_EQUAL_STRING("AND  A,($23,Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_ANDlongoffY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0xD4,0x23,0x33};
	TEST_ASSERT_EQUAL_STRING("AND  A,($2333,Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_ANDshortoffSP_(void)
{
	char* buffer;
	uint8_t memory[]= {0x14,0x23};
	TEST_ASSERT_EQUAL_STRING("AND  A,($23,SP)",buffer = disassembler(memory));
	free(buffer);
}

void test_ANDshortptr_(void)
{
	char* buffer;
	uint8_t memory[]= {0x92,0xC4,0x22};
	TEST_ASSERT_EQUAL_STRING("AND  A,[$22.w]",buffer = disassembler(memory));
	free(buffer);
}

void test_ANDlongptr_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0xC4,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("AND  A,[$2233.w]",buffer = disassembler(memory));
	free(buffer);
}

void test_ANDshortptrX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x92,0xD4,0x22};
	TEST_ASSERT_EQUAL_STRING("AND  A,[$22.w],X",buffer = disassembler(memory));
	free(buffer);
}

void test_ANDlongptrX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0xD4,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("AND  A,[$2233.w],X",buffer = disassembler(memory));
	free(buffer);
}

void test_ANDshortptrY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x91,0xD4,0x22};
	TEST_ASSERT_EQUAL_STRING("AND  A,[$22.w],Y",buffer = disassembler(memory));
	free(buffer);
}


              //INC
void test_INCA_(void)
{
	char* buffer;
	uint8_t memory[]= {0x4C};
	TEST_ASSERT_EQUAL_STRING("INC A",buffer = disassembler(memory));
	free(buffer);
}

void test_INCshortmem_(void)
{
	char* buffer;
	uint8_t memory[]= {0x3C,0x24};
	TEST_ASSERT_EQUAL_STRING("INC$24",buffer = disassembler(memory));
	free(buffer);
}

void test_INClongmem_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0x5C,0x23,0x24};
	TEST_ASSERT_EQUAL_STRING("INC$2324",buffer = disassembler(memory));
	free(buffer);
}

void test_INCX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x7C};
	TEST_ASSERT_EQUAL_STRING("INC(X)",buffer = disassembler(memory));
	free(buffer);
}

void test_INCshortoffX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x6C,0x33};
	TEST_ASSERT_EQUAL_STRING("INC($33,X)",buffer = disassembler(memory));
	free(buffer);
}

void test_INClongoffX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0x4C,0X44,0X55};
	TEST_ASSERT_EQUAL_STRING("INC($4455,X)",buffer = disassembler(memory));
	free(buffer);
}

void test_INCY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0x7C};
	TEST_ASSERT_EQUAL_STRING("INC(Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_INCshortoffY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0x6C,0x23};
	TEST_ASSERT_EQUAL_STRING("INC($23,Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_INClongoffY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0x4C,0x23,0x33};
	TEST_ASSERT_EQUAL_STRING("INC($2333,Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_INCshortoffSP_(void)
{
	char* buffer;
	uint8_t memory[]= {0x0C,0x23};
	TEST_ASSERT_EQUAL_STRING("INC($23,SP)",buffer = disassembler(memory));
	free(buffer);
}

void test_INCshortptr_(void)
{
	char* buffer;
	uint8_t memory[]= {0x92,0x3C,0x22};
	TEST_ASSERT_EQUAL_STRING("INC[$22.w]",buffer = disassembler(memory));
	free(buffer);
}

void test_INClongptr_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0x3C,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("INC[$2233.w]",buffer = disassembler(memory));
	free(buffer);
}

void test_INCshortptrX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x92,0x6C,0x22};
	TEST_ASSERT_EQUAL_STRING("INC[$22.w],X",buffer = disassembler(memory));
	free(buffer);
}

void test_INClongptrX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0x6C,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("INC[$2233.w],X",buffer = disassembler(memory));
	free(buffer);
}

void test_INCshortptrY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x91,0x6C,0x22};
	TEST_ASSERT_EQUAL_STRING("INC[$22.w],Y",buffer = disassembler(memory));
	free(buffer);
}

void test_INCWord_X_(void)
{
	char* buffer;
	uint8_t memory[]= {0x5C};
	TEST_ASSERT_EQUAL_STRING("INCW X",buffer = disassembler(memory));
	free(buffer);
}

void test_INCWord_Y_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0x5C};
	TEST_ASSERT_EQUAL_STRING("INCW Y",buffer = disassembler(memory));
	free(buffer);
}
		//ADDW
void test_ADDWword_(void)
{
	char* buffer;
	uint8_t memory[]= {0x1C,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("ADDW X,#$2233",buffer = disassembler(memory));
	free(buffer);
}

void test_ADDWlongmem_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0xBB,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("ADDW X,$2233",buffer = disassembler(memory));
	free(buffer);
}

void test_ADDWshortoffSP_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0xFB,0x22};
	TEST_ASSERT_EQUAL_STRING("ADDW X,($22,SP)",buffer = disassembler(memory));
	free(buffer);
}

void test_ADDWwordY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0xA9,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("ADDW Y,#$2233",buffer = disassembler(memory));
	free(buffer);
}

void test_ADDWlongmemY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0xB9,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("ADDW Y,$2233",buffer = disassembler(memory));
	free(buffer);
}

void test_ADDWshortoffSPY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0xF9,0x22};
	TEST_ASSERT_EQUAL_STRING("ADDW Y,($22,SP)",buffer = disassembler(memory));
	free(buffer);
}

void test_ADDWSP_(void)
{
	char* buffer;
	uint8_t memory[]= {0x5B,0x22};
	TEST_ASSERT_EQUAL_STRING("ADDW SP,#$22",buffer = disassembler(memory));
	free(buffer);
}

			//BCP
void test_BCPbyte_(void)
{
	char* buffer;
	uint8_t memory[]= {0xA5,0x23};
	TEST_ASSERT_EQUAL_STRING("BCP  A,#$23",buffer = disassembler(memory));
	free(buffer);
}

void test_BCPshortmem_(void)
{
	char* buffer;
	uint8_t memory[]= {0xB5,0x24};
	TEST_ASSERT_EQUAL_STRING("BCP  A,$24",buffer = disassembler(memory));
	free(buffer);
}

void test_BCPlongmem_(void)
{
	char* buffer;
	uint8_t memory[]= {0xC5,0x23,0x24};
	TEST_ASSERT_EQUAL_STRING("BCP  A,$2324",buffer = disassembler(memory));
	free(buffer);
}

void test_BCPX_(void)
{
	char* buffer;
	uint8_t memory[]= {0xF5};
	TEST_ASSERT_EQUAL_STRING("BCP  A,(X)",buffer = disassembler(memory));
	free(buffer);
}

void test_BCPshortoffX_(void)
{
	char* buffer;
	uint8_t memory[]= {0xE5,0x33};
	TEST_ASSERT_EQUAL_STRING("BCP  A,($33,X)",buffer = disassembler(memory));
	free(buffer);
}

void test_BCPlongoffX_(void)
{
	char* buffer;
	uint8_t memory[]= {0xD5,0x33,0X44};
	TEST_ASSERT_EQUAL_STRING("BCP  A,($3344,X)",buffer = disassembler(memory));
	free(buffer);
}

void test_BCPY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0xF5};
	TEST_ASSERT_EQUAL_STRING("BCP  A,(Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_BCPshortoffY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0xE5,0x23};
	TEST_ASSERT_EQUAL_STRING("BCP  A,($23,Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_BCPlongoffY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0xD5,0x23,0x33};
	TEST_ASSERT_EQUAL_STRING("BCP  A,($2333,Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_BCPshortoffSP_(void)
{
	char* buffer;
	uint8_t memory[]= {0x15,0x23};
	TEST_ASSERT_EQUAL_STRING("BCP  A,($23,SP)",buffer = disassembler(memory));
	free(buffer);
}

void test_BCPshortptr_(void)
{
	char* buffer;
	uint8_t memory[]= {0x92,0xC5,0x22};
	TEST_ASSERT_EQUAL_STRING("BCP  A,[$22.w]",buffer = disassembler(memory));
	free(buffer);
}

void test_BCPlongptr_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0xC5,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("BCP  A,[$2233.w]",buffer = disassembler(memory));
	free(buffer);
}

void test_BCPshortptrX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x92,0xD5,0x22};
	TEST_ASSERT_EQUAL_STRING("BCP  A,[$22.w],X",buffer = disassembler(memory));
	free(buffer);
}

void test_BCPlongptrX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0xD5,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("BCP  A,[$2233.w],X",buffer = disassembler(memory));
	free(buffer);
}

void test_BCPshortptrY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x91,0xD5,0x22};
	TEST_ASSERT_EQUAL_STRING("BCP  A,[$22.w],Y",buffer = disassembler(memory));
	free(buffer);
}

void test_BREAK_(void)
{
	char* buffer;
	uint8_t memory[]= {0x8B};
	TEST_ASSERT_EQUAL_STRING("BREAK",buffer = disassembler(memory));
	free(buffer);
}

void test_BitComplement_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0x16,0x22,0x1B};
	TEST_ASSERT_EQUAL_STRING("BCPL $221b,#2",buffer = disassembler(memory));
	free(buffer);
}

void test_BCCM_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0x13,0x22,0x1B};
	TEST_ASSERT_EQUAL_STRING("BCCM $221b,#2",buffer = disassembler(memory));
	free(buffer);
}

void test_BitReset_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0x1D,0x22,0x1B};
	TEST_ASSERT_EQUAL_STRING("BRES $221b,#7",buffer = disassembler(memory));
	free(buffer);
}

void test_Bitset_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0x1A,0x22,0x1B};
	TEST_ASSERT_EQUAL_STRING("BSET $221b,#1",buffer = disassembler(memory));
	free(buffer);
}

void test_BitTestJumpFalse_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0x03,0x22,0x1B,0X20};
	TEST_ASSERT_EQUAL_STRING("BTJF $221b,#1,20",buffer = disassembler(memory));
	free(buffer);
}

void test_BitTestJumpTrue_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0x0A,0x22,0x1B,0X20};
	TEST_ASSERT_EQUAL_STRING("BTJT $221b,#1,20",buffer = disassembler(memory));
	free(buffer);
}

void test_CALLlongmem_(void)
{
	char* buffer;
	uint8_t memory[]= {0xCD,0x23,0x24};
	TEST_ASSERT_EQUAL_STRING("CALL$2324",buffer = disassembler(memory));
	free(buffer);
}

void test_CALLX_(void)
{
	char* buffer;
	uint8_t memory[]= {0xFD};
	TEST_ASSERT_EQUAL_STRING("CALL(X)",buffer = disassembler(memory));
	free(buffer);
}

void test_CALLshortoffX_(void)
{
	char* buffer;
	uint8_t memory[]= {0xED,0x33};
	TEST_ASSERT_EQUAL_STRING("CALL($33,X)",buffer = disassembler(memory));
	free(buffer);
}

void test_CALLlongoffX_(void)
{
	char* buffer;
	uint8_t memory[]= {0xDD,0X44,0X55};
	TEST_ASSERT_EQUAL_STRING("CALL($4455,X)",buffer = disassembler(memory));
	free(buffer);
}

void test_CALLY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0xFD};
	TEST_ASSERT_EQUAL_STRING("CALL(Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_CALLshortoffY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0xED,0x23};
	TEST_ASSERT_EQUAL_STRING("CALL($23,Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_CALLlongoffY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0xDD,0x23,0x33};
	TEST_ASSERT_EQUAL_STRING("CALL($2333,Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_CALLshortptr_(void)
{
	char* buffer;
	uint8_t memory[]= {0x92,0xCD,0x22};
	TEST_ASSERT_EQUAL_STRING("CALL[$22.w]",buffer = disassembler(memory));
	free(buffer);
}

void test_CALLlongptr_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0xCD,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("CALL[$2233.w]",buffer = disassembler(memory));
	free(buffer);
}

void test_CALLshortptrX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x92,0xDD,0x22};
	TEST_ASSERT_EQUAL_STRING("CALL[$22.w],X",buffer = disassembler(memory));
	free(buffer);
}

void test_CALLlongptrX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0xDD,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("CALL[$2233.w],X",buffer = disassembler(memory));
	free(buffer);
}

void test_CALLshortptrY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x91,0xDD,0x22};
	TEST_ASSERT_EQUAL_STRING("CALL[$22.w],Y",buffer = disassembler(memory));
	free(buffer);
}

void test_CALLR_(void)
{
	char* buffer;
	uint8_t memory[]= {0xAD,0x22};
	TEST_ASSERT_EQUAL_STRING("CALLR$22",buffer = disassembler(memory));
	free(buffer);
}

void test_CALLFextmem_(void)
{
	char* buffer;
	uint8_t memory[]= {0x8D,0x22,0x33,0x44};
	TEST_ASSERT_EQUAL_STRING("CALLF $223344",buffer = disassembler(memory));
	free(buffer);
}

void test_CALLFlongptr_(void)
{
	char* buffer;
	uint8_t memory[]= {0x92,0x8D,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("CALLF [$2233.e]",buffer = disassembler(memory));
	free(buffer);
}

void test_CCF_(void)
{
	char* buffer;
	uint8_t memory[]= {0x8C};
	TEST_ASSERT_EQUAL_STRING("CCF",buffer = disassembler(memory));
	free(buffer);
}

			//CLEAR
void test_CLRA_(void)
{
	char* buffer;
	uint8_t memory[]= {0x4F};
	TEST_ASSERT_EQUAL_STRING("CLR A",buffer = disassembler(memory));
	free(buffer);
}

void test_CLRshortmem_(void)
{
	char* buffer;
	uint8_t memory[]= {0x3F,0x24};
	TEST_ASSERT_EQUAL_STRING("CLR$24",buffer = disassembler(memory));
	free(buffer);
}

void test_CLRlongmem_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0x5F,0x23,0x24};
	TEST_ASSERT_EQUAL_STRING("CLR$2324",buffer = disassembler(memory));
	free(buffer);
}

void test_CLRX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x7F};
	TEST_ASSERT_EQUAL_STRING("CLR(X)",buffer = disassembler(memory));
	free(buffer);
}

void test_CLRshortoffX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x6F,0x33};
	TEST_ASSERT_EQUAL_STRING("CLR($33,X)",buffer = disassembler(memory));
	free(buffer);
}

void test_CLRlongoffX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0x4F,0X44,0X55};
	TEST_ASSERT_EQUAL_STRING("CLR($4455,X)",buffer = disassembler(memory));
	free(buffer);
}

void test_CLRY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0x7F};
	TEST_ASSERT_EQUAL_STRING("CLR(Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_CLRshortoffY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0x6F,0x23};
	TEST_ASSERT_EQUAL_STRING("CLR($23,Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_CLRlongoffY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0x4F,0x23,0x33};
	TEST_ASSERT_EQUAL_STRING("CLR($2333,Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_CLRshortoffSP_(void)
{
	char* buffer;
	uint8_t memory[]= {0x0F,0x23};
	TEST_ASSERT_EQUAL_STRING("CLR($23,SP)",buffer = disassembler(memory));
	free(buffer);
}

void test_CLRshortptr_(void)
{
	char* buffer;
	uint8_t memory[]= {0x92,0x3F,0x22};
	TEST_ASSERT_EQUAL_STRING("CLR[$22.w]",buffer = disassembler(memory));
	free(buffer);
}

void test_CLRlongptr_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0x3F,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("CLR[$2233.w]",buffer = disassembler(memory));
	free(buffer);
}

void test_CLRshortptrX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x92,0x6F,0x22};
	TEST_ASSERT_EQUAL_STRING("CLR[$22.w],X",buffer = disassembler(memory));
	free(buffer);
}

void test_CLRlongptrX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0x6F,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("CLR[$2233.w],X",buffer = disassembler(memory));
	free(buffer);
}

void test_CLRshortptrY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x91,0x6F,0x22};
	TEST_ASSERT_EQUAL_STRING("CLR[$22.w],Y",buffer = disassembler(memory));
	free(buffer);
}

void test_CLRWX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x5F};
	TEST_ASSERT_EQUAL_STRING("CLRW X",buffer = disassembler(memory));
	free(buffer);
}

void test_CLRWY_(void)
{
	char* buffer;
	uint8_t memory[]= {0X90,0x5F};
	TEST_ASSERT_EQUAL_STRING("CLRW Y",buffer = disassembler(memory));
	free(buffer);
}

			//compare
void test_CPbyte_(void)
{
	char* buffer;
	uint8_t memory[]= {0xA1,0x23};
	TEST_ASSERT_EQUAL_STRING("CP  A,#$23",buffer = disassembler(memory));
	free(buffer);
}

void test_CPshortmem_(void)
{
	char* buffer;
	uint8_t memory[]= {0xB1,0x24};
	TEST_ASSERT_EQUAL_STRING("CP  A,$24",buffer = disassembler(memory));
	free(buffer);
}

void test_CPlongmem_(void)
{
	char* buffer;
	uint8_t memory[]= {0xC1,0x23,0x24};
	TEST_ASSERT_EQUAL_STRING("CP  A,$2324",buffer = disassembler(memory));
	free(buffer);
}

void test_CPX_(void)
{
	char* buffer;
	uint8_t memory[]= {0xF1};
	TEST_ASSERT_EQUAL_STRING("CP  A,(X)",buffer = disassembler(memory));
	free(buffer);
}

void test_CPshortoffX_(void)
{
	char* buffer;
	uint8_t memory[]= {0xE1,0x33};
	TEST_ASSERT_EQUAL_STRING("CP  A,($33,X)",buffer = disassembler(memory));
	free(buffer);
}

void test_CPlongoffX_(void)
{
	char* buffer;
	uint8_t memory[]= {0xD1,0x33,0X44};
	TEST_ASSERT_EQUAL_STRING("CP  A,($3344,X)",buffer = disassembler(memory));
	free(buffer);
}

void test_CPY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0xF1};
	TEST_ASSERT_EQUAL_STRING("CP  A,(Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_CPshortoffY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0xE1,0x23};
	TEST_ASSERT_EQUAL_STRING("CP  A,($23,Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_CPlongoffY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0xD1,0x23,0x33};
	TEST_ASSERT_EQUAL_STRING("CP  A,($2333,Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_CPshortoffSP_(void)
{
	char* buffer;
	uint8_t memory[]= {0x11,0x23};
	TEST_ASSERT_EQUAL_STRING("CP  A,($23,SP)",buffer = disassembler(memory));
	free(buffer);
}

void test_CPshortptr_(void)
{
	char* buffer;
	uint8_t memory[]= {0x92,0xC1,0x22};
	TEST_ASSERT_EQUAL_STRING("CP  A,[$22.w]",buffer = disassembler(memory));
	free(buffer);
}

void test_CPlongptr_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0xC1,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("CP  A,[$2233.w]",buffer = disassembler(memory));
	free(buffer);
}

void test_CPshortptrX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x92,0xD1,0x22};
	TEST_ASSERT_EQUAL_STRING("CP  A,[$22.w],X",buffer = disassembler(memory));
	free(buffer);
}

void test_CPlongptrX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0xD1,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("CP  A,[$2233.w],X",buffer = disassembler(memory));
	free(buffer);
}

void test_CPshortptrY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x91,0xD1,0x22};
	TEST_ASSERT_EQUAL_STRING("CP  A,[$22.w],Y",buffer = disassembler(memory));
	free(buffer);
}

void test_CPwordX_(void)
{
	char* buffer;
	uint8_t memory[]= {0xA3,0x23,0x24};
	TEST_ASSERT_EQUAL_STRING("CPW X,#$2324",buffer = disassembler(memory));
	free(buffer);
}

void test_CPWshortmemX_(void)
{
	char* buffer;
	uint8_t memory[]= {0xB3,0x24};
	TEST_ASSERT_EQUAL_STRING("CPW X,$24",buffer = disassembler(memory));
	free(buffer);
}

void test_CPWlongmemX_(void)
{
	char* buffer;
	uint8_t memory[]= {0xC3,0x23,0x24};
	TEST_ASSERT_EQUAL_STRING("CPW X,$2324",buffer = disassembler(memory));
	free(buffer);
}

void test_CPWY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0xF3};
	TEST_ASSERT_EQUAL_STRING("CPW X,(Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_CPWshortoffY_X_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0xE3,0x23};
	TEST_ASSERT_EQUAL_STRING("CPW X,($23,Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_CPWlongoffY_X_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0xD3,0x23,0x33};
	TEST_ASSERT_EQUAL_STRING("CPW X,($2333,Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_CPWshortoffSP_X_(void)
{
	char* buffer;
	uint8_t memory[]= {0x13,0x23};
	TEST_ASSERT_EQUAL_STRING("CPW X,($23,SP)",buffer = disassembler(memory));
	free(buffer);
}

void test_CPWshortptr_X_(void)
{
	char* buffer;
	uint8_t memory[]= {0x92,0xC3,0x22};
	TEST_ASSERT_EQUAL_STRING("CPW X,[$22.w]",buffer = disassembler(memory));
	free(buffer);
}

void test_CPWlongptr_X_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0xC3,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("CPW X,[$2233.w]",buffer = disassembler(memory));
	free(buffer);
}

void test_CPWshortptrY_X(void)
{
	char* buffer;
	uint8_t memory[]= {0x91,0xD3,0x22};
	TEST_ASSERT_EQUAL_STRING("CPW X,[$22.w],Y",buffer = disassembler(memory));
	free(buffer);
}

void test_CPwordY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0xA3,0x23,0x24};
	TEST_ASSERT_EQUAL_STRING("CPW Y,#$2324",buffer = disassembler(memory));
	free(buffer);
}

void test_CPWshortmem_Y_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0xB3,0x24};
	TEST_ASSERT_EQUAL_STRING("CPW Y,$24",buffer = disassembler(memory));
	free(buffer);
}

void test_CPWlongmemX_Y_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0xC3,0x23,0x24};
	TEST_ASSERT_EQUAL_STRING("CPW Y,$2324",buffer = disassembler(memory));
	free(buffer);
}

void test_CPWX_(void)
{
	char* buffer;
	uint8_t memory[]= {0xF3};
	TEST_ASSERT_EQUAL_STRING("CPW Y,(X)",buffer = disassembler(memory));
	free(buffer);
}

void test_CPWshortoffX_Y_(void)
{
	char* buffer;
	uint8_t memory[]= {0xE3,0x23};
	TEST_ASSERT_EQUAL_STRING("CPW Y,($23,X)",buffer = disassembler(memory));
	free(buffer);
}

void test_CPWlongoffX_Y_(void)
{
	char* buffer;
	uint8_t memory[]= {0xD3,0x23,0x33};
	TEST_ASSERT_EQUAL_STRING("CPW Y,($2333,X)",buffer = disassembler(memory));
	free(buffer);
}

void test_CPWshortptr_Y_(void)
{
	char* buffer;
	uint8_t memory[]= {0x91,0xC3,0x22};
	TEST_ASSERT_EQUAL_STRING("CPW Y,[$22.w]",buffer = disassembler(memory));
	free(buffer);
}

void test_CPWshortptrX_Y_(void)
{
	char* buffer;
	uint8_t memory[]= {0x92,0xD3,0x22};
	TEST_ASSERT_EQUAL_STRING("CPW Y,([$22.w],X)",buffer = disassembler(memory));
	free(buffer);
}

void test_CPWlongptrY_Y(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0xD3,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("CPW Y,([$2233.w],X)",buffer = disassembler(memory));
	free(buffer);
}

void test_CPLA_(void)
{
	char* buffer;
	uint8_t memory[]= {0x43};
	TEST_ASSERT_EQUAL_STRING("CPL A",buffer = disassembler(memory));
	free(buffer);
}

void test_CPLshortmem_(void)
{
	char* buffer;
	uint8_t memory[]= {0x33,0x24};
	TEST_ASSERT_EQUAL_STRING("CPL$24",buffer = disassembler(memory));
	free(buffer);
}

void test_CPLlongmem_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0x53,0x23,0x24};
	TEST_ASSERT_EQUAL_STRING("CPL$2324",buffer = disassembler(memory));
	free(buffer);
}

void test_CPLX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x73};
	TEST_ASSERT_EQUAL_STRING("CPL(X)",buffer = disassembler(memory));
	free(buffer);
}

void test_CPLshortoffX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x63,0x33};
	TEST_ASSERT_EQUAL_STRING("CPL($33,X)",buffer = disassembler(memory));
	free(buffer);
}

void test_CPLlongoffX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0x43,0X44,0X55};
	TEST_ASSERT_EQUAL_STRING("CPL($4455,X)",buffer = disassembler(memory));
	free(buffer);
}

void test_CPLY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0x73};
	TEST_ASSERT_EQUAL_STRING("CPL(Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_CPLshortoffY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0x63,0x23};
	TEST_ASSERT_EQUAL_STRING("CPL($23,Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_CPLlongoffY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0x43,0x23,0x33};
	TEST_ASSERT_EQUAL_STRING("CPL($2333,Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_CPLshortoffSP_(void)
{
	char* buffer;
	uint8_t memory[]= {0x03,0x23};
	TEST_ASSERT_EQUAL_STRING("CPL($23,SP)",buffer = disassembler(memory));
	free(buffer);
}

void test_CPLshortptr_(void)
{
	char* buffer;
	uint8_t memory[]= {0x92,0x33,0x22};
	TEST_ASSERT_EQUAL_STRING("CPL[$22.w]",buffer = disassembler(memory));
	free(buffer);
}

void test_CPLlongptr_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0x33,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("CPL[$2233.w]",buffer = disassembler(memory));
	free(buffer);
}

void test_CPLshortptrX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x92,0x63,0x22};
	TEST_ASSERT_EQUAL_STRING("CPL[$22.w],X",buffer = disassembler(memory));
	free(buffer);
}

void test_CPLlongptrX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0x63,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("CPL[$2233.w],X",buffer = disassembler(memory));
	free(buffer);
}

void test_CPLshortptrY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x91,0x63,0x22};
	TEST_ASSERT_EQUAL_STRING("CPL[$22],Y",buffer = disassembler(memory));
	free(buffer);
}

void test_CPLWX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x53};
	TEST_ASSERT_EQUAL_STRING("CPLW X",buffer = disassembler(memory));
	free(buffer);
}

void test_CPLWY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0x53};
	TEST_ASSERT_EQUAL_STRING("CPLW Y",buffer = disassembler(memory));
	free(buffer);
}

void test_DECA_(void)
{
	char* buffer;
	uint8_t memory[]= {0x4A};
	TEST_ASSERT_EQUAL_STRING("DEC A",buffer = disassembler(memory));
	free(buffer);
}

void test_DECshortmem_(void)
{
	char* buffer;
	uint8_t memory[]= {0x3A,0x24};
	TEST_ASSERT_EQUAL_STRING("DEC$24",buffer = disassembler(memory));
	free(buffer);
}

void test_DEClongmem_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0x5A,0x23,0x24};
	TEST_ASSERT_EQUAL_STRING("DEC$2324",buffer = disassembler(memory));
	free(buffer);
}

void test_DECX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x7A};
	TEST_ASSERT_EQUAL_STRING("DEC(X)",buffer = disassembler(memory));
	free(buffer);
}

void test_DECshortoffX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x6A,0x33};
	TEST_ASSERT_EQUAL_STRING("DEC($33,X)",buffer = disassembler(memory));
	free(buffer);
}

void test_DEClongoffX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0x4A,0X44,0X55};
	TEST_ASSERT_EQUAL_STRING("DEC($4455,X)",buffer = disassembler(memory));
	free(buffer);
}

void test_DECY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0x7A};
	TEST_ASSERT_EQUAL_STRING("DEC(Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_DECshortoffY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0x6A,0x23};
	TEST_ASSERT_EQUAL_STRING("DEC($23,Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_DEClongoffY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0x4A,0x23,0x33};
	TEST_ASSERT_EQUAL_STRING("DEC($2333,Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_DECshortoffSP_(void)
{
	char* buffer;
	uint8_t memory[]= {0x0A,0x23};
	TEST_ASSERT_EQUAL_STRING("DEC($23,SP)",buffer = disassembler(memory));
	free(buffer);
}

void test_DECshortptr_(void)
{
	char* buffer;
	uint8_t memory[]= {0x92,0x3A,0x22};
	TEST_ASSERT_EQUAL_STRING("DEC[$22.w]",buffer = disassembler(memory));
	free(buffer);
}

void test_DEClongptr_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0x3A,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("DEC[$2233.w]",buffer = disassembler(memory));
	free(buffer);
}

void test_DECshortptrX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x92,0x6A,0x22};
	TEST_ASSERT_EQUAL_STRING("DEC[$22.w],X",buffer = disassembler(memory));
	free(buffer);
}

void test_DEClongptrX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0x6A,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("DEC[$2233.w],X",buffer = disassembler(memory));
	free(buffer);
}

void test_DECshortptrY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x91,0x6A,0x22};
	TEST_ASSERT_EQUAL_STRING("DEC[$22],Y",buffer = disassembler(memory));
	free(buffer);
}

void test_DECWX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x5A};
	TEST_ASSERT_EQUAL_STRING("DECW X",buffer = disassembler(memory));
	free(buffer);
}

void test_DECWY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0x5A};
	TEST_ASSERT_EQUAL_STRING("DECW Y",buffer = disassembler(memory));
	free(buffer);
}

void test_DivideUnsignedX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x62};
	TEST_ASSERT_EQUAL_STRING("DIV X,A",buffer = disassembler(memory));
	free(buffer);
}

void test_DivideUnsignedY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0x62};
	TEST_ASSERT_EQUAL_STRING("DIV Y,A",buffer = disassembler(memory));
	free(buffer);
}

void test_DivideSigned_(void)
{
	char* buffer;
	uint8_t memory[]= {0x65};
	TEST_ASSERT_EQUAL_STRING("DIV X,Y",buffer = disassembler(memory));
	free(buffer);
}

void test_EXG_X_(void)
{
	char* buffer;
	uint8_t memory[]= {0x41};
	TEST_ASSERT_EQUAL_STRING("EXG A,XL",buffer = disassembler(memory));
	free(buffer);
}

void test_EXG_Y_(void)
{
	char* buffer;
	uint8_t memory[]= {0x61};
	TEST_ASSERT_EQUAL_STRING("EXG A,YL",buffer = disassembler(memory));
	free(buffer);
}

void test_EXG_longmem_(void)
{
	char* buffer;
	uint8_t memory[]= {0x31,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("EXG A,$2233",buffer = disassembler(memory));
	free(buffer);
}

void test_EXGW_(void)
{
	char* buffer;
	uint8_t memory[]= {0x51};
	TEST_ASSERT_EQUAL_STRING("EXGW X,Y",buffer = disassembler(memory));
	free(buffer);
}

void test_HALT_(void)
{
	char* buffer;
	uint8_t memory[]= {0x8E};
	TEST_ASSERT_EQUAL_STRING("HALT",buffer = disassembler(memory));
	free(buffer);
}

void test_Interrupt_(void)
{
	char* buffer;
	uint8_t memory[]= {0x82,0x22,0x33,0x44};
	TEST_ASSERT_EQUAL_STRING("INT $223344",buffer = disassembler(memory));
	free(buffer);
}

void test_InterruptReturn_(void)
{
	char* buffer;
	uint8_t memory[]= {0x80};
	TEST_ASSERT_EQUAL_STRING("IRET",buffer = disassembler(memory));
	free(buffer);
}

				//JUMP
void test_JPlongmem_(void)
{
	char* buffer;
	uint8_t memory[]= {0xCC,0x23,0x24};
	TEST_ASSERT_EQUAL_STRING("JP$2324",buffer = disassembler(memory));
	free(buffer);
}

void test_JPX_(void)
{
	char* buffer;
	uint8_t memory[]= {0xFC};
	TEST_ASSERT_EQUAL_STRING("JP(X)",buffer = disassembler(memory));
	free(buffer);
}

void test_JPshortoffX_(void)
{
	char* buffer;
	uint8_t memory[]= {0xEC,0x33};
	TEST_ASSERT_EQUAL_STRING("JP($33,X)",buffer = disassembler(memory));
	free(buffer);
}

void test_JPlongoffX_(void)
{
	char* buffer;
	uint8_t memory[]= {0xDC,0X44,0X55};
	TEST_ASSERT_EQUAL_STRING("JP($4455,X)",buffer = disassembler(memory));
	free(buffer);
}

void test_JPY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0xFC};
	TEST_ASSERT_EQUAL_STRING("JP(Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_JPshortoffY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0xEC,0x23};
	TEST_ASSERT_EQUAL_STRING("JP($23,Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_JPlongoffY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0xDC,0x23,0x33};
	TEST_ASSERT_EQUAL_STRING("JP($2333,Y)",buffer = disassembler(memory));
	free(buffer);
}

void test_JPshortptr_(void)
{
	char* buffer;
	uint8_t memory[]= {0x92,0xCC,0x22};
	TEST_ASSERT_EQUAL_STRING("JP[$22.w]",buffer = disassembler(memory));
	free(buffer);
}

void test_JPlongptr_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0xCC,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("JP[$2233.w]",buffer = disassembler(memory));
	free(buffer);
}

void test_JPshortptrX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x92,0xDC,0x22};
	TEST_ASSERT_EQUAL_STRING("JP[$22.w],X",buffer = disassembler(memory));
	free(buffer);
}

void test_JPlongptrX_(void)
{
	char* buffer;
	uint8_t memory[]= {0x72,0xDC,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("JP[$2233.w],X",buffer = disassembler(memory));
	free(buffer);
}

void test_JPshortptrY_(void)
{
	char* buffer;
	uint8_t memory[]= {0x91,0xDC,0x22};
	TEST_ASSERT_EQUAL_STRING("JP[$22.w],Y",buffer = disassembler(memory));
	free(buffer);
}


void test_JPFextmem_(void)
{
	char* buffer;
	uint8_t memory[]= {0xAC,0x22,0x33,0x44};
	TEST_ASSERT_EQUAL_STRING("JPF $223344",buffer = disassembler(memory));
	free(buffer);
}

void test_JPFlongptr_(void)
{
	char* buffer;
	uint8_t memory[]= {0x92,0xAC,0x22,0x33};
	TEST_ASSERT_EQUAL_STRING("JPF [$2233.e]",buffer = disassembler(memory));
	free(buffer);
}

void test_JumpRelativeAlways_(void)
{
	char* buffer;
	uint8_t memory[]= {0x20,0x22};
	TEST_ASSERT_EQUAL_STRING("JRA $22",buffer = disassembler(memory));
	free(buffer);
}

void test_Carry_(void)
{
	char* buffer;
	uint8_t memory[]= {0x25,0x22};
	TEST_ASSERT_EQUAL_STRING("JRC $22",buffer = disassembler(memory));
	free(buffer);
}

void test_Equal_(void)
{
	char* buffer;
	uint8_t memory[]= {0x27,0x22};
	TEST_ASSERT_EQUAL_STRING("JREQ $22",buffer = disassembler(memory));
	free(buffer);
}

void test_False_(void)
{
	char* buffer;
	uint8_t memory[]= {0x21,0x22};
	TEST_ASSERT_EQUAL_STRING("JRF $22",buffer = disassembler(memory));
	free(buffer);
}

void test_HalfCarry_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0x29,0x22};
	TEST_ASSERT_EQUAL_STRING("JRH $22",buffer = disassembler(memory));
	free(buffer);
}

void test_InterruptHigh_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0x2F,0x22};
	TEST_ASSERT_EQUAL_STRING("JRIH $22",buffer = disassembler(memory));
	free(buffer);
}

void test_InterruptLow_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0x2E,0x22};
	TEST_ASSERT_EQUAL_STRING("JRIL $22",buffer = disassembler(memory));
	free(buffer);
}

void test_InterruptMask_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0x2D,0x22};
	TEST_ASSERT_EQUAL_STRING("JRM $22",buffer = disassembler(memory));
	free(buffer);
}

void test_Minus_(void)
{
	char* buffer;
	uint8_t memory[]= {0x2B,0x22};
	TEST_ASSERT_EQUAL_STRING("JRMI $22",buffer = disassembler(memory));
	free(buffer);
}

void test_NotCarry_(void)
{
	char* buffer;
	uint8_t memory[]= {0x24,0x22};
	TEST_ASSERT_EQUAL_STRING("JRNC $22",buffer = disassembler(memory));
	free(buffer);
}

void test_NotEqual_(void)
{
	char* buffer;
	uint8_t memory[]= {0x26,0x22};
	TEST_ASSERT_EQUAL_STRING("JRNE $22",buffer = disassembler(memory));
	free(buffer);
}

void test_NotHalfCarry_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0x28,0x22};
	TEST_ASSERT_EQUAL_STRING("JRNH $22",buffer = disassembler(memory));
	free(buffer);
}

void test_NotInterruptMask_(void)
{
	char* buffer;
	uint8_t memory[]= {0x90,0x2C,0x22};
	TEST_ASSERT_EQUAL_STRING("JRNM $22",buffer = disassembler(memory));
	free(buffer);
}

void test_NotOverflow_(void)
{
	char* buffer;
	uint8_t memory[]= {0x28,0x22};
	TEST_ASSERT_EQUAL_STRING("JRNV $22",buffer = disassembler(memory));
	free(buffer);
}

void test_Plus_(void)
{
	char* buffer;
	uint8_t memory[]= {0x2A,0x22};
	TEST_ASSERT_EQUAL_STRING("JRPL $22",buffer = disassembler(memory));
	free(buffer);
}

void test_SignGreaterOrEqual_(void)
{
	char* buffer;
	uint8_t memory[]= {0x2E,0x22};
	TEST_ASSERT_EQUAL_STRING("JRSGE $22",buffer = disassembler(memory));
	free(buffer);
}

void test_SignGreaterThan_(void)
{
	char* buffer;
	uint8_t memory[]= {0x2C,0x22};
	TEST_ASSERT_EQUAL_STRING("JRSGT $22",buffer = disassembler(memory));
	free(buffer);
}

void test_SignLowerOrEqual_(void)
{
	char* buffer;
	uint8_t memory[]= {0x2D,0x22};
	TEST_ASSERT_EQUAL_STRING("JRSLE $22",buffer = disassembler(memory));
	free(buffer);
}

void test_SignLowerThan_(void)
{
	char* buffer;
	uint8_t memory[]= {0x2F,0x22};
	TEST_ASSERT_EQUAL_STRING("JRSLT $22",buffer = disassembler(memory));
	free(buffer);
}

void test_True_(void)
{
	char* buffer;
	uint8_t memory[]= {0x20,0x22};
	TEST_ASSERT_EQUAL_STRING("JRT $22",buffer = disassembler(memory));
	free(buffer);
}*/

/*void test_UnsignGreaterOrEqual_(void)
{
	char* buffer;
	uint8_t memory[]= {0x24,0x22};
	TEST_ASSERT_EQUAL_STRING("JRUGE $22",buffer = disassembler(memory));
	free(buffer);
}*/

/*{
	char* buffer;
	uint8_t memory[]= {0x22,0x22};
	TEST_ASSERT_EQUAL_STRING("JRUGT $22",buffer = disassembler(memory));
	free(buffer);
}

void test_UnsignLowerOrEqual_(void)
{
	char* buffer;
	uint8_t memory[]= {0x23,0x2a};
	TEST_ASSERT_EQUAL_STRING("JRULE $2a",buffer = disassembler(memory));
	free(buffer);
}

/*void test_UnsignLowerThan_(void)
{
	char* buffer;
	uint8_t memory[]= {0x25,0x22};
	TEST_ASSERT_EQUAL_STRING("JRULT $22",buffer = disassembler(memory));
	free(buffer);
}*/

void test_Overflow_(void)
{
	char* buffer;
	uint8_t memory[]= {0x29,0x22};
	uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("JRV $22",buffer = disassembler(&code));
	CEXCEPTION_T ex = NULL;
  char *str = "movwf  0x3 ###########";

  OperatorToken token = {
    .type = TOKEN_OPERATOR_TYPE,
    .startColumn = 11,
    .length = 11,
    .originalStr = str,
    .str = "###########",
  };

  Try {
    throwException(ERR_INVALID_OPERAND, (void *)&token,                     \
                   "Invalid operand, expecting a ',', but received '%s'\n", \
                    token.str);
  } Catch(ex) {
//    dumpException(ex);
    dumpErrorMessage(ex, 3);
  }
  freeException(ex);
	free(buffer);
}

void test_try_(void)
{
	uint8_t memory[]= {0x92,0xAC,0x22,0x29,0x29,0x33,0x2F,0x55};
	uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("JPF [$2229.e]JRULE $33",disassembleNCodes(&code,3));
}

void dumpErrorMessage(CEXCEPTION_T ex, int lineNo) {
  Token *token = (Token *)ex->data;
  int i = token->length - 1;
  if(i < 0) i = 0;

  printf("Error %d:\n", lineNo);
  printf("%s\n", ex->msg);
  printf("%s\n", token->originalStr);
  printf("%*s", token->startColumn + 1, "^");
  while(i--)
    printf("~");
  putchar('\n');

}
