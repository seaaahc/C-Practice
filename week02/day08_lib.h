#ifndef __DAY08_LIB_H__
#define __DAY08_LIB_H__

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE(a) (sizeof(a)/sizeof(a[0]))

void input1Darray(int* score, int n);
void input2Darray(int (*score)[4], int r, int c);
void print2Darray(int(*score)[4], int r, int c);
void input_string(char (*animal)[10], int s);
void print_string(char (*animal)[10], int s);
void print_string02(char** animal, int s);

#endif
