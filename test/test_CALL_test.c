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

void test_CALLlongmem_(void)
{
	uint8_t memory[]= {0xCD,0x23,0x24};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CALL$2324",disassembler(&code));
}

void test_CALLX_(void)
{
	uint8_t memory[]= {0xFD};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CALL(X)",disassembler(&code));
}

void test_CALLshortoffX_(void)
{
	uint8_t memory[]= {0xED,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CALL($33,X)",disassembler(&code));
}

void test_CALLlongoffX_(void)
{
	uint8_t memory[]= {0xDD,0X44,0X55};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CALL($4455,X)",disassembler(&code));
}

void test_CALLY_(void)
{
	uint8_t memory[]= {0x90,0xFD};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CALL(Y)",disassembler(&code));
}

void test_CALLshortoffY_(void)
{
	uint8_t memory[]= {0x90,0xED,0x23};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CALL($23,Y)",disassembler(&code));
}

void test_CALLlongoffY_(void)
{
	uint8_t memory[]= {0x90,0xDD,0x23,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CALL($2333,Y)",disassembler(&code));
}

void test_CALLshortptr_(void)
{
	uint8_t memory[]= {0x92,0xCD,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CALL[$22.w]",disassembler(&code));
}

void test_CALLlongptr_(void)
{
	uint8_t memory[]= {0x72,0xCD,0x22,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CALL[$2233.w]",disassembler(&code));
}

void test_CALLshortptrX_(void)
{
	uint8_t memory[]= {0x92,0xDD,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CALL[$22.w],X",disassembler(&code));
}

void test_CALLlongptrX_(void)
{
	uint8_t memory[]= {0x72,0xDD,0x22,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CALL[$2233.w],X",disassembler(&code));
}

void test_CALLshortptrY_(void)
{
	uint8_t memory[]= {0x91,0xDD,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CALL[$22.w],Y",disassembler(&code));
}

void test_CALLR_(void)
{
	uint8_t memory[]= {0xAD,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CALLR$22",disassembler(&code));
}

void test_CALLFextmem_(void)
{
	uint8_t memory[]= {0x8D,0x22,0x33,0x44};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CALLF $223344",disassembler(&code));
}

void test_CALLFlongptr_(void)
{
	uint8_t memory[]= {0x92,0x8D,0x22,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CALLF [$2233.e]",disassembler(&code));
}

void test_CCF_(void)
{
	uint8_t memory[]= {0x8C};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CCF",disassembler(&code));
}
