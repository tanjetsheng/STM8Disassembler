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

void test_DECA_(void)
{
	uint8_t memory[]= {0x4A};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("DEC A",disassembler(&code));
}

void test_DECshortmem_(void)
{
	uint8_t memory[]= {0x3A,0x24};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("DEC$24",disassembler(&code));
}

void test_DEClongmem_(void)
{
	uint8_t memory[]= {0x72,0x5A,0x23,0x24};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("DEC$2324",disassembler(&code));
}

void test_DECX_(void)
{
	uint8_t memory[]= {0x7A};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("DEC(X)",disassembler(&code));
}

void test_DECshortoffX_(void)
{
	uint8_t memory[]= {0x6A,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("DEC($33,X)",disassembler(&code));
}

void test_DEClongoffX_(void)
{
	uint8_t memory[]= {0x72,0x4A,0X44,0X55};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("DEC($4455,X)",disassembler(&code));
}

void test_DECY_(void)
{
	uint8_t memory[]= {0x90,0x7A};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("DEC(Y)",disassembler(&code));
}

void test_DECshortoffY_(void)
{
	uint8_t memory[]= {0x90,0x6A,0x23};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("DEC($23,Y)",disassembler(&code));
}

void test_DEClongoffY_(void)
{
	uint8_t memory[]= {0x90,0x4A,0x23,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("DEC($2333,Y)",disassembler(&code));
}

void test_DECshortoffSP_(void)
{
	uint8_t memory[]= {0x0A,0x23};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("DEC($23,SP)",disassembler(&code));
}

void test_DECshortptr_(void)
{
	uint8_t memory[]= {0x92,0x3A,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("DEC[$22.w]",disassembler(&code));
}

void test_DEClongptr_(void)
{
	uint8_t memory[]= {0x72,0x3A,0x22,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("DEC[$2233.w]",disassembler(&code));
}

void test_DECshortptrX_(void)
{
	uint8_t memory[]= {0x92,0x6A,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("DEC[$22.w],X",disassembler(&code));
}

void test_DEClongptrX_(void)
{
	uint8_t memory[]= {0x72,0x6A,0x22,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("DEC[$2233.w],X",disassembler(&code));
}

void test_DECshortptrY_(void)
{
	uint8_t memory[]= {0x91,0x6A,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("DEC[$22],Y",disassembler(&code));
}

void test_DECWX_(void)
{
	uint8_t memory[]= {0x5A};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("DECW X",disassembler(&code));
}

void test_DECWY_(void)
{
	uint8_t memory[]= {0x90,0x5A};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("DECW Y",disassembler(&code));
}
