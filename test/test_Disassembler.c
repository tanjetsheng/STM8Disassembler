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


              /*ADD*/
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

              /*AND*/
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


              /*INC*/
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
















