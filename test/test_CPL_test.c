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


void test_CPLA_(void)
{
	uint8_t memory[]= {0x43};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPL A",buffer = disassembler(&code));
}

void test_CPLshortmem_(void)
{
	uint8_t memory[]= {0x33,0x24};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPL$24",buffer = disassembler(&code));
}

void test_CPLlongmem_(void)
{
	uint8_t memory[]= {0x72,0x53,0x23,0x24};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPL$2324",buffer = disassembler(&code));
}

void test_CPLX_(void)
{
	uint8_t memory[]= {0x73};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPL(X)",buffer = disassembler(&code));
}

void test_CPLshortoffX_(void)
{
	uint8_t memory[]= {0x63,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPL($33,X)",buffer = disassembler(&code));
}

void test_CPLlongoffX_(void)
{
	uint8_t memory[]= {0x72,0x43,0X44,0X55};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPL($4455,X)",buffer = disassembler(&code));
}

void test_CPLY_(void)
{
	uint8_t memory[]= {0x90,0x73};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPL(Y)",buffer = disassembler(&code));
}

void test_CPLshortoffY_(void)
{
	uint8_t memory[]= {0x90,0x63,0x23};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPL($23,Y)",buffer = disassembler(&code));
}

void test_CPLlongoffY_(void)
{
	uint8_t memory[]= {0x90,0x43,0x23,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPL($2333,Y)",buffer = disassembler(&code));
}

void test_CPLshortoffSP_(void)
{
	uint8_t memory[]= {0x03,0x23};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPL($23,SP)",buffer = disassembler(&code));
}

void test_CPLshortptr_(void)
{
	uint8_t memory[]= {0x92,0x33,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPL[$22.w]",buffer = disassembler(&code));
}

void test_CPLlongptr_(void)
{
	uint8_t memory[]= {0x72,0x33,0x22,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPL[$2233.w]",buffer = disassembler(&code));
}

void test_CPLshortptrX_(void)
{
	uint8_t memory[]= {0x92,0x63,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPL[$22.w],X",buffer = disassembler(&code));
}

void test_CPLlongptrX_(void)
{
	uint8_t memory[]= {0x72,0x63,0x22,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPL[$2233.w],X",buffer = disassembler(&code));
}

void test_CPLshortptrY_(void)
{
	uint8_t memory[]= {0x91,0x63,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPL[$22],Y",buffer = disassembler(&code));
}

void test_CPLWX_(void)
{
	uint8_t memory[]= {0x53};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPLW X",buffer = disassembler(&code));
}

void test_CPLWY_(void)
{
	uint8_t memory[]= {0x90,0x53};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPLW Y",buffer = disassembler(&code));
}
