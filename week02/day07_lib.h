#ifndef __DAY07_LIB_H__
#define __DAY07_LIB_H__

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE(a) (sizeof(a)/sizeof(a[0]))
char* mystrcpy(char* to, const char* from);
int mystrlen(const char* str);
int mystrcmp(const char* str1, const char* str2);
int intcmp(const int* a, const int* b);
void printInt(void);


#endif