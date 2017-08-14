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


		//ADDW
void test_ADDWword_(void)
{
	uint8_t memory[]= {0x1C,0x22,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("ADDW X,#$2233",disassembler(&code));
}

void test_ADDWlongmem_(void)
{
	uint8_t memory[]= {0x72,0xBB,0x22,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("ADDW X,$2233", disassembler(&code));
}

void test_ADDWshortoffSP_(void)
{
	uint8_t memory[]= {0x72,0xFB,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("ADDW X,($22,SP)",disassembler(&code));
}

void test_ADDWwordY_(void)
{
	uint8_t memory[]= {0x72,0xA9,0x22,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("ADDW Y,#$2233",disassembler(&code));
}

void test_ADDWlongmemY_(void)
{
	uint8_t memory[]= {0x72,0xB9,0x22,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("ADDW Y,$2233",disassembler(&code));
}

void test_ADDWshortoffSPY_(void)
{
	uint8_t memory[]= {0x72,0xF9,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("ADDW Y,($22,SP)",disassembler(&code));
}

void test_ADDWSP_(void)
{
	uint8_t memory[]= {0x5B,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("ADDW SP,#$22",disassembler(&code));
}

			//BCP
void test_BCPbyte_(void)
{
	uint8_t memory[]= {0xA5,0x23};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("BCP  A,#$23",buffer = disassembler(&code));
}

void test_BCPshortmem_(void)
{
	uint8_t memory[]= {0xB5,0x24};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("BCP  A,$24",disassembler(&code));
}

void test_BCPlongmem_(void)
{
	uint8_t memory[]= {0xC5,0x23,0x24};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("BCP  A,$2324",disassembler(&code));
}

void test_BCPX_(void)
{
	uint8_t memory[]= {0xF5};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("BCP  A,(X)",disassembler(&code));
}

void test_BCPshortoffX_(void)
{
	uint8_t memory[]= {0xE5,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("BCP  A,($33,X)",disassembler(&code));
}

void test_BCPlongoffX_(void)
{
	uint8_t memory[]= {0xD5,0x33,0X44};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("BCP  A,($3344,X)",disassembler(&code));
}

void test_BCPY_(void)
{
	uint8_t memory[]= {0x90,0xF5};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("BCP  A,(Y)",disassembler(&code));
}

void test_BCPshortoffY_(void)
{
	uint8_t memory[]= {0x90,0xE5,0x23};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("BCP  A,($23,Y)",disassembler(&code));
}

void test_BCPlongoffY_(void)
{
	uint8_t memory[]= {0x90,0xD5,0x23,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("BCP  A,($2333,Y)",disassembler(&code));
}

void test_BCPshortoffSP_(void)
{
	uint8_t memory[]= {0x15,0x23};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("BCP  A,($23,SP)",disassembler(&code));
}

void test_BCPshortptr_(void)
{
	uint8_t memory[]= {0x92,0xC5,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("BCP  A,[$22.w]",disassembler(&code));
}

void test_BCPlongptr_(void)
{
	uint8_t memory[]= {0x72,0xC5,0x22,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("BCP  A,[$2233.w]",disassembler(&code));
}

void test_BCPshortptrX_(void)
{
	uint8_t memory[]= {0x92,0xD5,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("BCP  A,[$22.w],X",disassembler(&code));
}

void test_BCPlongptrX_(void)
{
	uint8_t memory[]= {0x72,0xD5,0x22,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("BCP  A,[$2233.w],X",disassembler(&code));
}

void test_BCPshortptrY_(void)
{
	uint8_t memory[]= {0x91,0xD5,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("BCP  A,[$22.w],Y",disassembler(&code));
}
