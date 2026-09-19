#ifndef __DAY11_LIB_H__
#define __DAY11_LIB_H__

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE(a) (sizeof(a)/sizeof(a[0]))
int add(int x, int y);
int sub(int x, int y);
int mul(int x, int y);
int divi(int x, int y);
int mod(int x, int y);
void print1Darray(int* ary, int n);
#endif