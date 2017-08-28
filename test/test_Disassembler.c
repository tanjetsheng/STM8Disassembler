#include "unity.h"
#include "Disassembler.h"
#include <stdlib.h>
#include "exception.h"
#include "CException.h"
#include "CExceptionConfig.h"
#include <stdint.h>
#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>
#include <string.h>
#include "error.h"
#include <ctype.h>

void setUp(void)
{}

void tearDown(void)
{}

  CEXCEPTION_T ex ;

void test_error_in_1st_code_expect_error_code(void)
{
  uint8_t memory[]={0x95,0xAC,0x22,0x29,0x21,0x33,0x2F,0x55};
  uint8_t *code = memory;
  Try{
    TEST_ASSERT_EQUAL_STRING("error code",disassembleNCodes(&code,3));
  }
  Catch(ex) {
    dumpErrorMessage(ex);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND,errorcode);
    TEST_ASSERT_EQUAL_STRING("invalid instruction 0x95",message);
  }
}

void test_error_in_2nd_code_expect_error_code(void)
{
  uint8_t memory[]={0x92,0xAC,0x22,0x29,0x99,0x33,0x2F,0x55};
  uint8_t *code = memory;
  Try{
    TEST_ASSERT_EQUAL_STRING("error code",disassembleNCodes(&code,3));
  }
  Catch(ex) {
    dumpErrorMessage(ex);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND,errorcode);
    TEST_ASSERT_EQUAL_STRING("invalid instruction 0x99",message);
  }
}

void test_error_in_code1_expect_error_code(void)
{
  uint8_t memory[]={0x92,0xAC,0x22,0x29,0xFF,0x33,0x2F,0x55};
  uint8_t *code = memory;
  Try{
    TEST_ASSERT_EQUAL_STRING("error code",disassembleNCodes(&code,3));
  }
  Catch(ex) {
    dumpErrorMessage(ex);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND,errorcode);
    TEST_ASSERT_EQUAL_STRING("invalid instruction 0xff",message);
  }
}

void test_2_code_expect_pass_(void)
{
	uint8_t memory[]= {0x5F,0x90,0x7C};
	uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CLRW X\nINC(Y)\n",disassembleNCodes(&code,2));
}

void test_3_code_expect_pass_(void)
{
	uint8_t memory[]= {0x92,0xAC,0x22,0x29,0x21,0x33,0x2F,0x55};
	uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("JPF [$2229.e]\nJRF $33\nJRSLT $55\n",disassembleNCodes(&code,3));
	TEST_ASSERT_EQUAL(3,i);
}

void test_ADDWwordY_DEClongoffX_ANDY_INCshortptr_CPshortptr_ANDX_expect_pass_(void)
{
	uint8_t memory[]= {0x72,0xA9,0x53,0xf5,0x72,0x4A,0x34,0x66,0x90,0xF4,0x91,0x6C,0x55,0x92,0xC1,0x33,0xFB};
	uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("ADDW Y,#$53f5\nDEC($3466,X)\nAND  A,(Y)\nINC[$55.w],Y\nCP  A,[$33.w]\nADD  A,(X)\n",disassembleNCodes(&code,6));
	TEST_ASSERT_EQUAL(6,i);
}

void test_JPX_DECX_ANDshortptr_DECY_JPlongptrX_expect_pass_(void)
{
	uint8_t memory[]= {0xFC,0x7A,0x92,0xC4,0x56,0x90,0x7A,0x72,0xDC,0x56,0x23};
	uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("JP(X)\nDEC(X)\nAND  A,[$56.w]\nDEC(Y)\nJP[$5623.w],X\n",disassembleNCodes(&code,5));
	TEST_ASSERT_EQUAL(5,i);
}
