#ifndef __DAY09_LIB_H__
#define __DAY09_LIB_H__

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE(a) (sizeof(a)/sizeof(a[0]))

int sum1D(int(*A), int a);
int sum2D(int (*A)[4], int a, int b);
int sum3D(int (*A)[3][4], int a, int b, int c);

void exchange0(int* a, int* b);
void exchange1(int** a, int** b);
void exchange2(int*** a, int*** b);
void exchange3(int** a, int** b);
void exchange4(int*** a, int*** b);
void exchange5(int*** a, int*** b);

void print_strings03(char** pary, int size);
void print_var_array(int** pary, int size);
void print_1Darray(int* ary, int n);

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int divi(int a, int b);

int compint(const void* a, const void* b);
int compdouble(const void* a, const void* b);
int compstr(const void* a, const void* b);
void print_1Darray_d(double* ary, double n);

void sort(void* base, int num, int size, int (*comp)(void*, void*));
void swap_02(void* ap, void* bp, int size);
#endif