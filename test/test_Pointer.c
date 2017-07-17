#include <stdio.h>
#include "unity.h"
#include "Disassembler.h"
#include <stdlib.h>
#include "exception.h"
#include "CException.h"

void setUp(void)
{}

void tearDown(void)
{}

//void test_pointer(void)
//{
/*	uint8_t memory[]= {0xA9,0x3, 0xab};
	uint8_t* codePtr = memory;
	printf("0x%02x %02x %02x, ", codePtr[0],codePtr[1],codePtr[2]);*/
	
void test_ADCY_(void)
{
  CEXCEPTION_T ex;
	char* buffer;
	uint8_t memory[]= {0x90,0xF9};
  Try{
	TEST_ASSERT_EQUAL_STRING("ADC  A,(Y)",buffer = disassembler(memory));
	free(buffer);	
  }Catch(ex){
    dumpException(ex);
 }
	
}

//}
