#include "unity.h"
#include "Disassembler.h"
#include "exception.h"
#include "CException.h"
#include "CExceptionConfig.h"
void setUp(void)
{
}

void tearDown(void)
{
}


              //ADD
void test_ADDbyte_(void)
{
	uint8_t memory[]= {0xAB,0x23};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("ADD  A,#$23",disassembler(&code));
}

void test_ADDshortmem_(void)
{
	uint8_t memory[]= {0xBB,0x24};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("ADD  A,$24",disassembler(&code));
}

void test_ADDlongmem_(void)
{
	uint8_t memory[]= {0xCB,0x23,0x24};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("ADD  A,$2324",disassembler(&code));
}

void test_ADDX_(void)
{
	uint8_t memory[]= {0xFB};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("ADD  A,(X)",disassembler(&code));
}

void test_ADDshortoffX_(void)
{
	uint8_t memory[]= {0xEB,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("ADD  A,($33,X)",disassembler(&code));
}

void test_ADDlongoffX_(void)
{
	uint8_t memory[]= {0xDB,0x33,0X44};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("ADD  A,($3344,X)",disassembler(&code));
}

void test_ADDY_(void)
{
	uint8_t memory[]= {0x90,0xFB};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("ADD  A,(Y)",disassembler(&code));
}

void test_ADDshortoffY_(void)
{
	uint8_t memory[]= {0x90,0xEB,0x23};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("ADD  A,($23,Y)",disassembler(&code));
}

void test_ADDlongoffY_(void)
{
	uint8_t memory[]= {0x90,0xDB,0x23,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("ADD  A,($2333,Y)",disassembler(&code));
}

void test_ADDshortoffSP_(void)
{
	uint8_t memory[]= {0x1B,0x23};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("ADD  A,($23,SP)",disassembler(&code));
}

void test_ADDshortptr_(void)
{
	uint8_t memory[]= {0x92,0xCB,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("ADD  A,[$22.w]",disassembler(&code));
}

void test_ADDlongptr_(void)
{
	uint8_t memory[]= {0x72,0xCB,0x22,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("ADD  A,[$2233.w]",disassembler(&code));
}

void test_ADDshortptrX_(void)
{
	uint8_t memory[]= {0x92,0xDB,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("ADD  A,[$22.w],X",disassembler(&code));
}

void test_ADDlongptrX_(void)
{
	uint8_t memory[]= {0x72,0xDB,0x22,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("ADD  A,[$2233.w],X",disassembler(&code));
}

void test_ADDshortptrY_(void)
{
	uint8_t memory[]= {0x91,0xDB,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("ADD  A,[$22.w],Y",disassembler(&code));
}
