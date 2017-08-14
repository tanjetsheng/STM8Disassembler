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
#include "Token.h"
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
    //TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND,e->msg);
  //  TEST_ASSERT_EQUAL_STRING("invalid instruction 0x95",e->msg);
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
  }
}

void test_2_code_expect_pass_(void)
{
	uint8_t memory[]= {0x5F,0x90,0x7C};
	uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("CLRW XINC(Y)",disassembleNCodes(&code,2));
}

void test_3_code_expect_pass_(void)
{
	uint8_t memory[]= {0x92,0xAC,0x22,0x29,0x21,0x33,0x2F,0x55};
	uint8_t *code = memory;
	TEST_ASSERT_EQUAL_STRING("JPF [$2229.e]JRF $33JRSLT $55",disassembleNCodes(&code,3));
}
