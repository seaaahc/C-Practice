#include "day09_lib.h"

int sum1D(int* A, int a) {
	int sum = 0;
	for (int i = 0; i < a; ++i) {
		sum += A[i];
	}
	return sum;
}

int sum2D(int (*A)[4], int a, int b) {
	int sum = 0;
	for (int i = 0; i < a; ++i) {
		sum += sum1D(A[i], b);
	}
	return sum;
}

int sum3D(int (*A)[3][4], int a, int b, int c) {
	int sum = 0;
	for (int i = 0; i < a; ++i) {
		sum += sum2D(A[i], b, c);
	}
	return sum;
}

// main에 위치한 a, b 변수의 주소를 전달 받아 a, b값을 교환하는 함수
void exchange0(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// ap, bp 변수의 주소를 전달 받아 a, b값을 교환하는 함수
void exchange1(int **a, int **b) {
	int temp = **a;
	**a = **b;
	**b = temp;
}

// app, bpp 변수의 주소를 전달 받아 a, b값을 교환하는 함수
void exchange2(int ***a, int ***b) {
	int temp = ***a;
	***a = ***b;
	***b = temp;
}

// ap, bp 변수의 주소를 전달 받아 ap, bp값을 교환하는 함수
void exchange3(int **a, int **b) {
	int* temp = *a;
	*a = *b;
	*b = temp;
}

// app, bpp 변수의 주소를 전달 받아 ap, bp값을 교환하는 함수
void exchange4(int ***a, int ***b) {
	int* temp = **a;
	**a = **b;
	**b = temp;
}

// app, bpp 변수의 주소를 전달 받아 app, bpp값을 교환하는 함수
void exchange5(int ***a, int ***b) {
	int* temp = *a;
	*a = *b;
	*b = temp;
}

void print_strings03(char** pary, int size) {
	for (int i = 0; i < size; ++i) {
		printf("%s ", pary[i]);
	}
	printf("\n");
}

void print_1Darray(int* ary, int n) {// int* ary = 출력할 1차원의 배열의 첫 주소 , int n = 출력할 요소
	for (int i = 0; i < n; ++i) {
		printf("%d ", ary[i]);
	}
	printf("\n");
}

void print_var_array(int** pary, int size) { 
	for (int i = 0; i < size; ++i) {
		print_1Darray(pary[i] + 1, pary[i][0]);
	}
	printf("\n");
}

void print_var_arra02(int** pary, int size) {
	int a = 0;
	for (int i = 0; i < size; ++i) {
		a = pary[i];
		print_1Darray(a + 1, a);
	}
}

int add(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}
int mul(int a, int b) {
	return a * b;
}
int divi(int a, int b) {
	return a / b;
}

int compint(const void* a, const void* b) {
	int ia = *(int*)a;
	int ib = *(int*)b;
	
	if (ia == ib) return 0;
	if (ia > ib) return 1;  // else 쓰지 말 것!
 	return -1;
	
	//return (ia > ib) - (ia < ib); 와 같음. // 부호를 바꾸면 내림차순이 됨 // 3가지 연산(<, >, -)가 무조건 수행되는 단점이 있음
}

int compstr(const void* a, const void* b) {
	char* str1 = *(char**)a;
	char* str2 = *(char**)b;
	return strcmp(str1, str2);
}

int compdouble(const void* a, const void* b) {
	double da = *(double*)a;
	double db = *(double*)b;

	if (da == db) return 0;
	if (da > db) return 1;  // else 쓰지 말 것!
	return -1;
}

void print_1Darray_d(double* ary, double n) {
	for (int i = 0; i < n; ++i) {
		printf("%.1f ", ary[i]);
	}
	printf("\n");
}

void swap_02(void* ap, void* bp, int size) {
	void* temp = NULL;
	temp = malloc(size);
	memmove(temp, ap, size);
	memmove(ap, bp, size);
	memmove(bp, temp, size);
	free(temp);
}

// qsort를 함수포인터로 바꿀 수 있음..
// 정렬 - 함수 포인터 활용
void sort(void* base, int num, int size, int (*comp)(void*, void*)) {
	char *cbase = (char*)base;
	int s = num - 1;
	void* a;
	void* b;
	int temp = 0;
	for (int i = 0; i < s; ++i) { //n-1보다 n이 좀 더 효율적임
		for (int j = i + 1; j < num; ++j) {
			a = cbase + i * size;
			b = cbase + j * size;
			if (comp(a, b)) {
				swap_02(a, b, size);
			}	
		}
	}
}

