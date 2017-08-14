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


			//compare
void test_CPbyte_(void)
{
	uint8_t memory[]= {0xA1,0x23};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CP  A,#$23",disassembler(&code));
}

void test_CPshortmem_(void)
{
	uint8_t memory[]= {0xB1,0x24};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CP  A,$24",disassembler(&code));
}

void test_CPlongmem_(void)
{
	uint8_t memory[]= {0xC1,0x23,0x24};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CP  A,$2324",disassembler(&code));
}

void test_CPX_(void)
{
	uint8_t memory[]= {0xF1};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CP  A,(X)",disassembler(&code));
}

void test_CPshortoffX_(void)
{
	uint8_t memory[]= {0xE1,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CP  A,($33,X)",disassembler(&code));
}

void test_CPlongoffX_(void)
{
	uint8_t memory[]= {0xD1,0x33,0X44};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CP  A,($3344,X)",disassembler(&code));
}

void test_CPY_(void)
{
	uint8_t memory[]= {0x90,0xF1};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CP  A,(Y)",disassembler(&code));
}

void test_CPshortoffY_(void)
{
	uint8_t memory[]= {0x90,0xE1,0x23};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CP  A,($23,Y)",disassembler(&code));
}

void test_CPlongoffY_(void)
{
	uint8_t memory[]= {0x90,0xD1,0x23,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CP  A,($2333,Y)",disassembler(&code));
}

void test_CPshortoffSP_(void)
{
	uint8_t memory[]= {0x11,0x23};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CP  A,($23,SP)",disassembler(&code));
}

void test_CPshortptr_(void)
{
	uint8_t memory[]= {0x92,0xC1,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CP  A,[$22.w]",disassembler(&code));
}

void test_CPlongptr_(void)
{
	uint8_t memory[]= {0x72,0xC1,0x22,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CP  A,[$2233.w]",disassembler(&code));
}

void test_CPshortptrX_(void)
{
	uint8_t memory[]= {0x92,0xD1,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CP  A,[$22.w],X",disassembler(&code));
}

void test_CPlongptrX_(void)
{
	uint8_t memory[]= {0x72,0xD1,0x22,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CP  A,[$2233.w],X",disassembler(&code));
}

void test_CPshortptrY_(void)
{
	uint8_t memory[]= {0x91,0xD1,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CP  A,[$22.w],Y",disassembler(&code));
}

void test_CPwordX_(void)
{
	uint8_t memory[]= {0xA3,0x23,0x24};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPW X,#$2324",disassembler(&code));
}

void test_CPWshortmemX_(void)
{
	uint8_t memory[]= {0xB3,0x24};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPW X,$24",disassembler(&code));
}

void test_CPWlongmemX_(void)
{
	uint8_t memory[]= {0xC3,0x23,0x24};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPW X,$2324",disassembler(&code));
}

void test_CPWY_(void)
{
	uint8_t memory[]= {0x90,0xF3};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPW X,(Y)",disassembler(&code));
}

void test_CPWshortoffY_X_(void)
{
	uint8_t memory[]= {0x90,0xE3,0x23};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPW X,($23,Y)",disassembler(&code));
}

void test_CPWlongoffY_X_(void)
{
	uint8_t memory[]= {0x90,0xD3,0x23,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPW X,($2333,Y)",disassembler(&code));
}

void test_CPWshortoffSP_X_(void)
{
	uint8_t memory[]= {0x13,0x23};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPW X,($23,SP)",disassembler(&code));
}

void test_CPWshortptr_X_(void)
{
	uint8_t memory[]= {0x92,0xC3,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPW X,[$22.w]",disassembler(&code));
}

void test_CPWlongptr_X_(void)
{
	uint8_t memory[]= {0x72,0xC3,0x22,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPW X,[$2233.w]",disassembler(&code));
}

void test_CPWshortptrY_X(void)
{
	uint8_t memory[]= {0x91,0xD3,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPW X,[$22.w],Y",disassembler(&code));
}

void test_CPwordY_(void)
{
	uint8_t memory[]= {0x90,0xA3,0x23,0x24};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPW Y,#$2324",disassembler(&code));
}

void test_CPWshortmem_Y_(void)
{
	uint8_t memory[]= {0x90,0xB3,0x24};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPW Y,$24",disassembler(&code));
}

void test_CPWlongmemX_Y_(void)
{
	uint8_t memory[]= {0x90,0xC3,0x23,0x24};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPW Y,$2324",disassembler(&code));
}

void test_CPWX_(void)
{
	uint8_t memory[]= {0xF3};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPW Y,(X)",disassembler(&code));
}

void test_CPWshortoffX_Y_(void)
{
	uint8_t memory[]= {0xE3,0x23};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPW Y,($23,X)",disassembler(&code));
}

void test_CPWlongoffX_Y_(void)
{
	uint8_t memory[]= {0xD3,0x23,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPW Y,($2333,X)",disassembler(&code));
}

void test_CPWshortptr_Y_(void)
{
	uint8_t memory[]= {0x91,0xC3,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPW Y,[$22.w]",disassembler(&code));
}

void test_CPWshortptrX_Y_(void)
{
	uint8_t memory[]= {0x92,0xD3,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPW Y,([$22.w],X)",disassembler(&code));
}

void test_CPWlongptrY_Y(void)
{
	uint8_t memory[]= {0x72,0xD3,0x22,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CPW Y,([$2233.w],X)",disassembler(&code));
}
