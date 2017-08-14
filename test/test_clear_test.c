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


			//CLEAR
void test_CLRA_(void)
{
	uint8_t memory[]= {0x4F};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CLR A",disassembler(&code));
}

void test_CLRshortmem_(void)
{
	uint8_t memory[]= {0x3F,0x24};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CLR$24",disassembler(&code));
}

void test_CLRlongmem_(void)
{
	uint8_t memory[]= {0x72,0x5F,0x23,0x24};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CLR$2324",disassembler(&code));
}

void test_CLRX_(void)
{
	uint8_t memory[]= {0x7F};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CLR(X)",disassembler(&code));
}

void test_CLRshortoffX_(void)
{
	uint8_t memory[]= {0x6F,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CLR($33,X)",disassembler(&code));
}

void test_CLRlongoffX_(void)
{
	uint8_t memory[]= {0x72,0x4F,0X44,0X55};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CLR($4455,X)",disassembler(&code));
}

void test_CLRY_(void)
{
	uint8_t memory[]= {0x90,0x7F};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CLR(Y)",disassembler(&code));
}

void test_CLRshortoffY_(void)
{
	uint8_t memory[]= {0x90,0x6F,0x23};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CLR($23,Y)",disassembler(&code));
}

void test_CLRlongoffY_(void)
{
	uint8_t memory[]= {0x90,0x4F,0x23,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CLR($2333,Y)",disassembler(&code));
}

void test_CLRshortoffSP_(void)
{
	uint8_t memory[]= {0x0F,0x23};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CLR($23,SP)",disassembler(&code));
}

void test_CLRshortptr_(void)
{
	uint8_t memory[]= {0x92,0x3F,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CLR[$22.w]",disassembler(&code));
}

void test_CLRlongptr_(void)
{
	uint8_t memory[]= {0x72,0x3F,0x22,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CLR[$2233.w]",disassembler(&code));
}

void test_CLRshortptrX_(void)
{
	uint8_t memory[]= {0x92,0x6F,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CLR[$22.w],X",disassembler(&code));
}

void test_CLRlongptrX_(void)
{
	uint8_t memory[]= {0x72,0x6F,0x22,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CLR[$2233.w],X",disassembler(&code));
}

void test_CLRshortptrY_(void)
{
	uint8_t memory[]= {0x91,0x6F,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CLR[$22.w],Y",disassembler(&code));
}

void test_CLRWX_(void)
{
	uint8_t memory[]= {0x5F};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CLRW X", disassembler(&code));
}

void test_CLRWY_(void)
{
	uint8_t memory[]= {0X90,0x5F};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CLRW Y",disassembler(&code));
}
