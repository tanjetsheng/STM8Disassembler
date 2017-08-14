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

//AND
void test_ANDbyte_(void)
{
uint8_t memory[]= {0xA4,0x23};
uint8_t *code = memory;
TEST_ASSERT_EQUAL_STRING("AND  A,#$23",disassembler(&code));
}

void test_ANDshortmem_(void)
{
uint8_t memory[]= {0xB4,0x24};
uint8_t *code = memory;
TEST_ASSERT_EQUAL_STRING("AND  A,$24",disassembler(&code));
}

void test_ANDlongmem_(void)
{
uint8_t memory[]= {0xC4,0x23,0x24};
uint8_t *code = memory;
TEST_ASSERT_EQUAL_STRING("AND  A,$2324",disassembler(&code));
}

void test_ANDX_(void)
{
uint8_t memory[]= {0xF4};
uint8_t *code = memory;
TEST_ASSERT_EQUAL_STRING("AND  A,(X)",disassembler(&code));
}

void test_ANDshortoffX_(void)
{
uint8_t memory[]= {0xE4,0x33};
uint8_t *code = memory;
TEST_ASSERT_EQUAL_STRING("AND  A,($33,X)",disassembler(&code));
}

void test_ANDlongoffX_(void)
{
uint8_t memory[]= {0xD4,0x33,0X44};
uint8_t *code = memory;
TEST_ASSERT_EQUAL_STRING("AND  A,($3344,X)",disassembler(&code));
}

void test_ANDY_(void)
{
uint8_t memory[]= {0x90,0xF4};
uint8_t *code = memory;
TEST_ASSERT_EQUAL_STRING("AND  A,(Y)",disassembler(&code));
}

void test_ANDshortoffY_(void)
{
uint8_t memory[]= {0x90,0xE4,0x23};
uint8_t *code = memory;
TEST_ASSERT_EQUAL_STRING("AND  A,($23,Y)",disassembler(&code));
}

void test_ANDlongoffY_(void)
{
uint8_t memory[]= {0x90,0xD4,0x23,0x33};
uint8_t *code = memory;
TEST_ASSERT_EQUAL_STRING("AND  A,($2333,Y)",disassembler(&code));
}

void test_ANDshortoffSP_(void)
{
uint8_t memory[]= {0x14,0x23};
uint8_t *code = memory;
TEST_ASSERT_EQUAL_STRING("AND  A,($23,SP)",disassembler(&code));
}

void test_ANDshortptr_(void)
{
uint8_t memory[]= {0x92,0xC4,0x22};
uint8_t *code = memory;
TEST_ASSERT_EQUAL_STRING("AND  A,[$22.w]",disassembler(&code));
}

void test_ANDlongptr_(void)
{
uint8_t memory[]= {0x72,0xC4,0x22,0x33};
uint8_t *code = memory;
TEST_ASSERT_EQUAL_STRING("AND  A,[$2233.w]",disassembler(&code));
}

void test_ANDshortptrX_(void)
{
uint8_t memory[]= {0x92,0xD4,0x22};
uint8_t *code = memory;
TEST_ASSERT_EQUAL_STRING("AND  A,[$22.w],X",disassembler(&code));
}

void test_ANDlongptrX_(void)
{
uint8_t memory[]= {0x72,0xD4,0x22,0x33};
uint8_t *code = memory;
TEST_ASSERT_EQUAL_STRING("AND  A,[$2233.w],X",disassembler(&code));
}

void test_ANDshortptrY_(void)
{
uint8_t memory[]= {0x91,0xD4,0x22};
uint8_t *code = memory;
TEST_ASSERT_EQUAL_STRING("AND  A,[$22.w],Y",disassembler(&code));

}
