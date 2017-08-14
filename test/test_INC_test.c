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


              //INC
void test_INCA_(void)
{
  uint8_t memory[]= {0x4C};
  uint8_t *code = memory;
  TEST_ASSERT_EQUAL_STRING("INC A",disassembler(&code));
}

void test_INCshortmem_(void)
{
	uint8_t memory[]= {0x3C,0x24};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("INC$24",disassembler(&code));
}

void test_INClongmem_(void)
{
	uint8_t memory[]= {0x72,0x5C,0x23,0x24};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("INC$2324",disassembler(&code));
}

void test_INCX_(void)
{
	uint8_t memory[]= {0x7C};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("INC(X)",disassembler(&code));
}

void test_INCshortoffX_(void)
{
	uint8_t memory[]= {0x6C,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("INC($33,X)",disassembler(&code));
}

void test_INClongoffX_(void)
{
	uint8_t memory[]= {0x72,0x4C,0X44,0X55};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("INC($4455,X)",disassembler(&code));
}

void test_INCY_(void)
{
	uint8_t memory[]= {0x90,0x7C};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("INC(Y)",disassembler(&code));
}

void test_INCshortoffY_(void)
{
	uint8_t memory[]= {0x90,0x6C,0x23};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("INC($23,Y)",disassembler(&code));
}

void test_INClongoffY_(void)
{
	uint8_t memory[]= {0x90,0x4C,0x23,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("INC($2333,Y)",disassembler(&code));
}

void test_INCshortoffSP_(void)
{
	uint8_t memory[]= {0x0C,0x23};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("INC($23,SP)",disassembler(&code));
}

void test_INCshortptr_(void)
{
	uint8_t memory[]= {0x92,0x3C,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("INC[$22.w]",disassembler(&code));
}

void test_INClongptr_(void)
{
	uint8_t memory[]= {0x72,0x3C,0x22,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("INC[$2233.w]",disassembler(&code));
}

void test_INCshortptrX_(void)
{
	uint8_t memory[]= {0x92,0x6C,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("INC[$22.w],X",disassembler(&code));
}

void test_INClongptrX_(void)
{
	uint8_t memory[]= {0x72,0x6C,0x22,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("INC[$2233.w],X",disassembler(&code));
}

void test_INCshortptrY_(void)
{
	uint8_t memory[]= {0x91,0x6C,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("INC[$22.w],Y",disassembler(&code));
}

void test_INCWord_X_(void)
{
	uint8_t memory[]= {0x5C};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("INCW X",disassembler(&code));
}

void test_INCWord_Y_(void)
{
	uint8_t memory[]= {0x90,0x5C};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("INCW Y",disassembler(&code));
}
