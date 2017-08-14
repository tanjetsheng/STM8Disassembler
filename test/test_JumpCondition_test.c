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


void test_Carry_(void)
{
	uint8_t memory[]= {0x25,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("JRC $22",disassembler(&code));
}

void test_Equal_(void)
{
	uint8_t memory[]= {0x27,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("JREQ $22",disassembler(&code));
}

void test_False_(void)
{
	uint8_t memory[]= {0x21,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("JRF $22",disassembler(&code));
}

void test_HalfCarry_(void)
{
	uint8_t memory[]= {0x90,0x29,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("JRH $22",disassembler(&code));
}

void test_InterruptHigh_(void)
{
	uint8_t memory[]= {0x90,0x2F,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("JRIH $22",disassembler(&code));
}

void test_InterruptLow_(void)
{
	uint8_t memory[]= {0x90,0x2E,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("JRIL $22",disassembler(&code));
}

void test_InterruptMask_(void)
{
	uint8_t memory[]= {0x90,0x2D,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("JRM $22",disassembler(&code));
}

void test_Minus_(void)
{
	uint8_t memory[]= {0x2B,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("JRMI $22",disassembler(&code));
}

void test_NotCarry_(void)
{
	uint8_t memory[]= {0x24,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("JRNC $22",disassembler(&code));
}

void test_NotEqual_(void)
{
	uint8_t memory[]= {0x26,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("JRNE $22",disassembler(&code));
}

void test_NotHalfCarry_(void)
{
	uint8_t memory[]= {0x90,0x28,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("JRNH $22",disassembler(&code));
}

void test_NotInterruptMask_(void)
{
	uint8_t memory[]= {0x90,0x2C,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("JRNM $22",disassembler(&code));
}

void test_NotOverflow_(void)
{
	uint8_t memory[]= {0x28,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("JRNV $22",disassembler(&code));
}

void test_Plus_(void)
{
	uint8_t memory[]= {0x2A,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("JRPL $22",disassembler(&code));
}

void test_SignGreaterOrEqual_(void)
{
	uint8_t memory[]= {0x2E,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("JRSGE $22",disassembler(&code));
}

void test_SignGreaterThan_(void)
{
	uint8_t memory[]= {0x2C,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("JRSGT $22",disassembler(&code));
}

void test_SignLowerOrEqual_(void)
{
	uint8_t memory[]= {0x2D,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("JRSLE $22",disassembler(&code));
}

void test_SignLowerThan_(void)
{
	uint8_t memory[]= {0x2F,0x22};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("JRSLT $22",disassembler(&code));
}



void test_UnsignLowerOrEqual_(void)
{
	uint8_t memory[]= {0x23,0x2a};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("JRULE $2a",disassembler(&code));
}

void test_carry_(void)
{
	uint8_t memory[]= {0x25,0x2a};
  uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("JRC $2a",disassembler(&code));
}
