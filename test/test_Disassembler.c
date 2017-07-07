#include "unity.h"
#include "Disassembler.h"

void setUp(void)
{}

void tearDown(void)
{}

void test_Disassembler_(void)
{
  char *memory;
  uint8_t *code = memory;
  memory[0] = 0xA9;
  memory[1] = 0x23;
  disassembler(&code);
 
 char* result = ADCbyte(0xA923);
 TEST_ASSERT_EQUAL_STRING("ADC  A #$,23",result);
}
