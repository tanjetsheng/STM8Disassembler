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

//JUMP
void test_JPlongmem_(void)
{
uint8_t memory[]= {0xCC,0x23,0x24};
uint8_t *code = memory;
TEST_ASSERT_EQUAL_STRING("JP$2324",disassembler(&code));
}

void test_JPX_(void)
{
uint8_t memory[]= {0xFC};
uint8_t *code = memory;
TEST_ASSERT_EQUAL_STRING("JP(X)",disassembler(&code));
}

void test_JPshortoffX_(void)
{
uint8_t memory[]= {0xEC,0x33};
uint8_t *code = memory;
TEST_ASSERT_EQUAL_STRING("JP($33,X)",disassembler(&code));
}

void test_JPlongoffX_(void)
{
  uint8_t memory[]= {0xDC,0X44,0X55};
  uint8_t *code = memory;
  TEST_ASSERT_EQUAL_STRING("JP($4455,X)",disassembler(&code));
}

void test_JPY_(void)
{
uint8_t memory[]= {0x90,0xFC};
uint8_t *code = memory;
TEST_ASSERT_EQUAL_STRING("JP(Y)",disassembler(&code));
}

void test_JPshortoffY_(void)
{
uint8_t memory[]= {0x90,0xEC,0x23};
uint8_t *code = memory;
TEST_ASSERT_EQUAL_STRING("JP($23,Y)",disassembler(&code));
}

void test_JPlongoffY_(void)
{
uint8_t memory[]= {0x90,0xDC,0x23,0x33};
uint8_t *code = memory;
TEST_ASSERT_EQUAL_STRING("JP($2333,Y)",disassembler(&code));
}

void test_JPshortptr_(void)
{
uint8_t memory[]= {0x92,0xCC,0x22};
uint8_t *code = memory;
TEST_ASSERT_EQUAL_STRING("JP[$22.w]",disassembler(&code));
}

void test_JPlongptr_(void)
{
uint8_t memory[]= {0x72,0xCC,0x22,0x33};
uint8_t *code = memory;
TEST_ASSERT_EQUAL_STRING("JP[$2233.w]",disassembler(&code));
}

void test_JPshortptrX_(void)
{
uint8_t memory[]= {0x92,0xDC,0x22};
uint8_t *code = memory;
TEST_ASSERT_EQUAL_STRING("JP[$22.w],X",disassembler(&code));
}

void test_JPlongptrX_(void)
{
uint8_t memory[]= {0x72,0xDC,0x22,0x33};
uint8_t *code = memory;
TEST_ASSERT_EQUAL_STRING("JP[$2233.w],X",disassembler(&code));
}

void test_JPshortptrY_(void)
{
uint8_t memory[]= {0x91,0xDC,0x22};
uint8_t *code = memory;
TEST_ASSERT_EQUAL_STRING("JP[$22.w],Y",disassembler(&code));
}


void test_JPFextmem_(void)
{
uint8_t memory[]= {0xAC,0x22,0x33,0x44};
uint8_t *code = memory;
TEST_ASSERT_EQUAL_STRING("JPF $223344",disassembler(&code));
}

void test_JPFlongptr_(void)
{
uint8_t memory[]= {0x92,0xAC,0x22,0x33};
uint8_t *code = memory;
TEST_ASSERT_EQUAL_STRING("JPF [$2233.e]",disassembler(&code));
}

void test_JumpRelativeAlways_(void)
{
uint8_t memory[]= {0x20,0x22};
uint8_t *code = memory;
TEST_ASSERT_EQUAL_STRING("JRA $22",disassembler(&code));
}
