#ifndef __DAY12_LIB_H__
#define __DAY12_LIB_H__

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE(a) (sizeof(a)/sizeof(a[0]))

struct profile {
	int age;
	double height;
	char* name;
	char phone[14];
};

struct student {
	struct profile pf;
	int num;
	double grade;
};

struct student2 {
	int id;
	int scores[3];
	char name[20];
};

#endif