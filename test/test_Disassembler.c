#include "unity.h"
#include "Disassembler.h"
#include <stdlib.h>
#include "exception.h"
#include "CException.h"

void setUp(void)
{}

void tearDown(void)
{}

void test_ADCbyte_(void)
{
	char* buffer;
	uint8_t memory[]= {0xA9,0x23};
	TEST_ASSERT_EQUAL_STRING("ADC  A,#$23",buffer = disassembler(memory));
	free(buffer);
}

void test_ADCshortmem_(void)
{
	char* buffer;
	uint8_t memory[]= {0xB9,0x24};
	TEST_ASSERT_EQUAL_STRING("ADC  A,$24",buffer = disassembler(memory));
	free(buffer);
}

void test_ADClongmem_(void)
{
	char* buffer;
	uint8_t memory[]= {0xC9,0x23,0x24};
	TEST_ASSERT_EQUAL_STRING("ADC  A,$2324",buffer = disassembler(memory));
	free(buffer);
}

void test_ADCX_(void)
{
	char* buffer;
	uint8_t memory[]= {0xF9};
	TEST_ASSERT_EQUAL_STRING("ADC  A,(X)",buffer = disassembler(memory));
	free(buffer);
}

void test_ADCshortoff_(void)
{
	char* buffer;
	uint8_t memory[]= {0xE9,0x33};
	TEST_ASSERT_EQUAL_STRING("ADC  A,($33,X)",buffer = disassembler(memory));
	free(buffer);
}

void test_ADClongoff_(void)
{
	char* buffer;
	uint8_t memory[]= {0xD9,0x33,0X44};
	TEST_ASSERT_EQUAL_STRING("ADC  A,($3344,X)",buffer = disassembler(memory));
	free(buffer);
}

void test_ADCY_(void)
{
    CEXCEPTION_T ex;
	char* buffer;
	uint8_t memory[]= {0x90,0xF9};
	Try{
		TEST_ASSERT_EQUAL_STRING("ADC  A,(Y)",buffer = disassembler(memory));
		
	}Catch(ex){
		dumpException(ex);
	}
	free(buffer);
}