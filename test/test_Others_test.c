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

void test_BREAK_(void)
{
	uint8_t memory[]= {0x8B};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("BREAK",disassembler(&code));
}

void test_BitComplement_(void)
{
	uint8_t memory[]= {0x90,0x16,0x22,0x1B};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("BCPL $221b,#2",disassembler(&code));
}

void test_BCCM_(void)
{
	uint8_t memory[]= {0x90,0x13,0x22,0x1B};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("BCCM $221b,#2",disassembler(&code));
}

void test_BitReset_(void)
{
	uint8_t memory[]= {0x72,0x1D,0x22,0x1B};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("BRES $221b,#7",disassembler(&code));
}

void test_Bitset_(void)
{
	uint8_t memory[]= {0x72,0x1A,0x22,0x1B};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("BSET $221b,#1",disassembler(&code));
}

void test_BitTestJumpFalse_(void)
{
	uint8_t memory[]= {0x72,0x03,0x22,0x1B,0X20};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("BTJF $221b,#1,20",disassembler(&code));
}

void test_BitTestJumpTrue_(void)
{
	uint8_t memory[]= {0x72,0x0A,0x22,0x1B,0X20};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("BTJT $221b,#1,20",disassembler(&code));
}

void test_DivideUnsignedX_(void)
{
	uint8_t memory[]= {0x62};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("DIV X,A",disassembler(&code));
}

void test_DivideUnsignedY_(void)
{
	uint8_t memory[]= {0x90,0x62};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("DIV Y,A",disassembler(&code));
}

void test_DivideSigned_(void)
{
	uint8_t memory[]= {0x65};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("DIV X,Y",disassembler(&code));
}

void test_EXG_X_(void)
{
	uint8_t memory[]= {0x41};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("EXG A,XL",disassembler(&code));
}

void test_EXG_Y_(void)
{
	uint8_t memory[]= {0x61};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("EXG A,YL",disassembler(&code));
}

void test_EXG_longmem_(void)
{
	uint8_t memory[]= {0x31,0x22,0x33};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("EXG A,$2233",disassembler(&code));
}

void test_EXGW_(void)
{
	uint8_t memory[]= {0x51};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("EXGW X,Y",disassembler(&code));
}

void test_HALT_(void)
{
	uint8_t memory[]= {0x8E};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("HALT",disassembler(&code));
}

void test_Interrupt_(void)
{
	uint8_t memory[]= {0x82,0x22,0x33,0x44};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("INT $223344",disassembler(&code));
}

void test_InterruptReturn_(void)
{
	uint8_t memory[]= {0x80};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("IRET",disassembler(&code));
}
