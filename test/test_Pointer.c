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

void test_pointer(void)
{
	uint8_t memory[]= {0xA9,0x3, 0xab};
	uint8_t* codePtr = memory;
	/*
	int i;
	for(i = 0; i < 3; i++) {
		printf("0x%02x, ", *codePtr & 0xff);
		codePtr++;
	}
	*/
	printf("0x%02x %02x %02x, ", codePtr[0],codePtr[1],codePtr[2]);
}