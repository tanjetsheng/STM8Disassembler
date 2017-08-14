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

/*ADC*/

void test_ADCbyte_(void)
{
  uint8_t memory[]= {0xA9,0x23};
  uint8_t *code = memory;
  TEST_ASSERT_EQUAL_STRING("ADC  A,#$23",disassembler(&code));
}

void test_ADCshortmem_(void)
{
  uint8_t memory[]= {0xB9,0x24};
  uint8_t *code = memory;
  TEST_ASSERT_EQUAL_STRING("ADC  A,$24",disassembler(&code));
}

void test_ADClongmem_(void)
{

  uint8_t memory[]= {0xC9,0x23,0x24};
  uint8_t *code = memory;
  TEST_ASSERT_EQUAL_STRING("ADC  A,$2324",disassembler(&code));

}

void test_ADCX_(void)
{

  uint8_t memory[]= {0xF9};
  uint8_t *code = memory;
  TEST_ASSERT_EQUAL_STRING("ADC  A,(X)",disassembler(&code));

}

void test_ADCshortoffX_(void)
{

  uint8_t memory[]= {0xE9,0x33};
  uint8_t *code = memory;
  TEST_ASSERT_EQUAL_STRING("ADC  A,($33,X)",disassembler(&code));

}

void test_ADClongoffX_(void)
{

  uint8_t memory[]= {0xD9,0x33,0X44};
  uint8_t *code = memory;
  TEST_ASSERT_EQUAL_STRING("ADC  A,($3344,X)",disassembler(&code));

}

void test_ADCY_(void)
{

  uint8_t memory[]= {0x90,0xF9};
  uint8_t *code = memory;
  TEST_ASSERT_EQUAL_STRING("ADC  A,(Y)",disassembler(&code));

}

void test_ADCshortoffY_(void)
{

  uint8_t memory[]= {0x90,0xE9,0x23};
  uint8_t *code = memory;
  TEST_ASSERT_EQUAL_STRING("ADC  A,($23,Y)",disassembler(&code));

}

void test_ADClongoffY_(void)
{

  uint8_t memory[]= {0x90,0xD9,0x23,0x33};
  uint8_t *code = memory;
  TEST_ASSERT_EQUAL_STRING("ADC  A,($2333,Y)",disassembler(&code));

}

void test_ADCshortoffSP_(void)
{

  uint8_t memory[]= {0x19,0x23};
  uint8_t *code = memory;
  TEST_ASSERT_EQUAL_STRING("ADC  A,($23,SP)",disassembler(&code));

}

void test_ADCshortptr_(void)
{

  uint8_t memory[]= {0x92,0xC9,0x22};
  uint8_t *code = memory;
  TEST_ASSERT_EQUAL_STRING("ADC  A,[$22.w]",disassembler(&code));

}

void test_ADClongptr_(void)
{

  uint8_t memory[]= {0x72,0xC9,0x22,0x33};
  uint8_t *code = memory;
  TEST_ASSERT_EQUAL_STRING("ADC  A,[$2233.w]",disassembler(&code));

}

void test_ADCshortptrX_(void)
{

  uint8_t memory[]= {0x92,0xD9,0x22};
  uint8_t *code = memory;
  TEST_ASSERT_EQUAL_STRING("ADC  A,[$22.w],X",disassembler(&code));

}

void test_ADClongptrX_(void)
{

  uint8_t memory[]= {0x72,0xD9,0x22,0x33};
  uint8_t *code = memory;
  TEST_ASSERT_EQUAL_STRING("ADC  A,[$2233.w],X",disassembler(&code));

}

void test_ADCshortptrY_(void)
{

  uint8_t memory[]= {0x91,0xD9,0x22};
  uint8_t *code = memory;
  TEST_ASSERT_EQUAL_STRING("ADC  A,[$22.w],Y",disassembler(&code));

}
