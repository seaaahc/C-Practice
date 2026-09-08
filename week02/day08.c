#include "day08_lib.h"

// 포인터 배열
#if 0
int main(void) {
	char* animal[5] = { "rabbit", "snake", "seal", "cat", "monkey" };
	char*(*p)[5] = &animal;
	print_string02(animal, SIZE(animal));

	return 0;
}
#endif

// char 2차원 배열 
#if 0
int main(void) {
	char animal[5][10] = { 0 };
	int i;
	(void)freopen("animal.txt", "r", stdin);
	input_string(animal, SIZE(animal));
	print_string(animal, SIZE(animal));
	 
	return 0;
}
#endif

// 배열 등가 포인터 연습 2
#if 0

int main(void) {
	int a[2][3][4] = { 0 }; // 요소의 개수 : 2, 요소의 타입 : int [3][4]
	int (*b[3])[4] = { 0 }; // 요소의 개수 : 3, 요소의 타입 : int (*)[4]
	int* (*c[2])(int*) = { 0 }; // 요소의 개수 : 2, 요소의 타입 : int* (*)(int*)
	int* d[3][4] = { 0 };   // 요소의 개수 : 3, 요소의 타입 : int* [4]
	int(*(*e[5])(void))[4];   // 함수 포인터 5개짜리 배열
	//  요소의 개수 : 5, 요소의 타입 : int(*(*)(void))[4]
	int (*ap)[3][4] = a;
	int (**bp)[4] = b;
	int* (**cp)(int*) = c;
	int* (*dp)[4] = d;
	int(*(**ep)(void))[4] = e;
	return 0;
}

#endif

// 배열 등가 포인터 연습 1
#if 0
int main(void) {
	int a1[4]; // 요소의 타입: int, 요소의 개수: 4, a1 = &a1[0], a1은 첫번쨰 요소를 가리키는 포인터
	int* a2[4];
	int a3[3][4];
	int a4[2][3][4];
	int (*a5[3])[4];

	int* p1 = a1;
	int** p2 = a2;
	int (*p3)[4] = a3;
	int (*p4)[3][4] = a4;
	int (**p5)[4] = a5;

	return 0;
}
#endif

// int 2차원 배열
#if 0
#define ARR_2D(func, arr) func(arr, SIZE(arr), SIZE(arr[0])) // 매크로 함수 

int main(void) {
	int score[3][4] = { 0 };

	(void)freopen("score.txt", "r", stdin);
	// input2Darray(score, SIZE(score), SIZE(score[0]));
	// print2Darray(score, SIZE(score), SIZE(score[0]));
	input1Darray((int *)score, SIZE(score) * SIZE(score[0])); // 배열에서의 "차원"은 논리적이라 1차원으로 입력해도 2차원으로 출력 가능
	//ARR_2D(input2Darray, score);
	ARR_2D(print2Darray, score);

	return 0;
}
#endif