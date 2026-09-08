#include "day08_lib.h"
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))

void input1Darray(int *score, int n) {
	for (int i = 0; i < n; ++i) {
		(void)scanf("%d", &score[i]);
	}
}

void input2Darray(int (*score)[4], int r, int c) {
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			(void)scanf("%d", &score[i][j]);
		}
	}
}

void print2Darray(int(*score)[4], int r, int c) {
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			(void)printf("%3d ", score[i][j]);
		}
		printf("\n");
	}
}

void input_string(char (*animal)[10], int s) {
	for (int i = 0; i < s; i++) {
		(void)scanf("%s", animal[i]); // &animal[i]°¡ ¾Æ´Ô
	}
}

void print_string(char (*animal)[10], int s) {
	for (int i = 0; i < s; i++) {
		printf("%s ", animal[i]);
	}
	printf("\n");
}

void print_string02(char **animal, int s) {
	for (int i = 0; i < s; i++) {
		printf("%s ", animal[i]);
	}
	printf("\n");
}