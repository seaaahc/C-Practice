#ifndef __DAY06_LIB_H__
#define __DAY06_LIB_H__

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* ap, int* bp);
void scanf_ary(int* ary, int n);
void print_ary(int* ary, int n);
int findmax_ary(int* ary, int n);
int findmin_ary(int* ary, int n);
int sum_ary(int* ary, int n);
int avg_ary(int* ary, int n);
int findmaxidx_ary(int* ary, int n);
int findminidx_ary(int* ary, int n);
int findmax_input(int* ary, int n);
int findmin_input(int* ary, int n);
void find_min_max(int* ary, int n);
double var_ary(int* ary, int n);
void test08_3(void);
void test08_4(void);
void my_gets(char* str, int n);
char* to_upper(char* str);

#endif