#include "day09_lib.h"

//step 3
#if 01
int compstr_02(void* a, void* b) {
	char* ca = *(char**)a;
	char* cb = *(char**)b;

	return strcmp(ca, cb);
}

int compint_02(void * a, void*b) {
	int ia = *(int*)a;
	int ib = *(int*)b;

	if (ia > ib) return 1;
	if (ia == ib) return 0;
	return -1;
}
void swap_03(void* a, void* b, int size) {
	char* temp = NULL;
	temp = malloc(size);
	memmove(temp, a, size);
	memmove(a, b, size);
	memmove(b, temp, size);
	free(temp);
}

// 모든 타입의 배열을 대상으로 정렬함
// base: 배열의 시작 주소
// num: 배열의 요소 개수
// size: 1개 요소의 크기
void mysort(void* base, int num, int size, int (*comp) (void*, void*)) { //void때문에 size도 알려줘야함 // compint가 왜 comp가 되는지 지피티한테 물어보기
	char* cbase = (char*)base;
	int s = num - 1;
	for (int i = 0; i < s; ++i) { // i번째 원소를 i 다음으로 오는 원소들이랑 하나씩 비교 // s에 만약 2를 넣는다면 가장 작은 두 개 뽑을 수 있음
		for (int j = i + 1; j < num; ++j) {
			char* a = cbase + i * size;
			char* b = cbase + j * size;
			if (comp(a, b)>0) {
				swap_03(a, b, size);
			}
		}
	}
}

void sort_int(int* ary, int num) {
	int s = num - 1;
	for (int i = 0; i < s; ++i) { // i번째 원소를 i 다음으로 오는 원소들이랑 하나씩 비교 // s에 만약 2를 넣는다면 가장 작은 두 개 뽑을 수 있음
		for (int j = i + 1; j < num; ++j) {
			if (ary[i] > ary[j]) {
				swap_03(ary + i, ary + j, sizeof(*ary));
			}

		}
	}
}
int main(void) {
	int ary[5] = { 4,2,5,1,3 };
	char* animal[5] = { "rabbit", "seal", "snake", "dog", "cat" };
	double B[5] = { 2.3,2.1,2.6,2.7,2.4 };

	print_1Darray(ary, SIZE(ary));
	mysort(ary, SIZE(ary), sizeof(*ary), compint_02);
	print_1Darray(ary, SIZE(ary));

	print_strings03(animal, SIZE(animal));
	mysort(animal, SIZE(animal), sizeof(*animal), compstr_02);
	print_strings03(animal, SIZE(animal));

	print_1Darray_d(B, SIZE(B));
	mysort(B, SIZE(B), sizeof(*B), compdouble);
	print_1Darray_d(B, SIZE(B));

	return 0;
}

#endif

//step 2
#if 0
void swap_03(void* a, void* b, int size) {
	char* temp = NULL;
	temp = malloc(size);
	memmove(temp, a, size);
	memmove(a, b, size);
	memmove(b, temp, size);
	free(temp);
}

void sort_int(int* ary, int num) {
	int s = num - 1;
	for (int i = 0; i < s; ++i) { // i번째 원소를 i 다음으로 오는 원소들이랑 하나씩 비교 // s에 만약 2를 넣는다면 가장 작은 두 개 뽑을 수 있음
		for (int j = i + 1; j < num; ++j) {
			if (ary[i] > ary[j]) {
				swap_03(ary + i, ary + j, sizeof(*ary));
			}
		}
	}
}

int main(void) {
	int ary[5] = { 4,2,5,1,3 };

	print_1Darray(ary, SIZE(ary));
	sort_int(ary, SIZE(ary));
	print_1Darray(ary, SIZE(ary));

	return 0;
}
#endif

// 오름차순/내림차순 정렬
// 정수 배열 정렬 -> 타입에 상관없는 배열 정렬
//step 1
#if 0
void sort_int(int* ary, int num) {
	int s = num - 1;
	for (int i = 0; i < s; ++i) { // i번째 원소를 i 다음으로 오는 원소들이랑 하나씩 비교 // s에다가 만약 2를 넣는다면 가장 작은 두개 뽑을 수 있음
		for (int j = i + 1; j < num; ++j) {
			if (ary[i] > ary[j]) {
				int temp = ary;
				temp = ary[i];
				ary[i] = ary[j];
				ary[j] = temp;
			}
		}
	}
}
int main(void) {
	int ary[5] = { 4,2,5,1,3 };

	print_1Darray(ary, SIZE(ary));
	sort_int(ary, SIZE(ary));
	print_1Darray(ary, SIZE(ary));

	return 0;
}
#endif

// 오름차순/내림차순 정렬
#if 0
int main(void) {
	int ary[5] = { 4,2,5,1,3 };
	print_1Darray(ary, SIZE(ary));
	sort(ary, SIZE(ary), sizeof(*ary), compint);
	print_1Darray(ary, SIZE(ary));

	return 0;
}
#endif

// 3차 - 사용자에게 어떤 연산을 할지에 대해 선택을 받고 동작 결과를 출력
/*
메뉴 출력 -> 사용자가 메뉴 번호 선택 -> 결과 출력 -> 메뉴 출력 ...

1. 더하기
2. 빼기
3. 곱하기
4. 나누기

연산 번호를 입력 하시오 : 1
결과는 20 + 5 = 25 입니다.
*/

//  2차 - 구조체로 변경함
#if 0
#define ARR_MAX (5)
typedef struct op {
	char* name;
	int (*func)(int, int);
}op_t;

int main(void) {
	int a = 20, b = 5;
	int result, tot = 0;
	op_t data[] = {
		{"sum", add},
		{"sub", sub},
		{"mul", mul},
		{"divi", divi},
		{"mod", mod},
	};
	op_t* op = NULL;

	tot = 0;
	for (int i = 0; i < SIZE(data); ++i) {
		op = &data[i];
		result = op->func(a, b);
		tot += result;
		printf("%s = %d\n", op->name, result);
	}
	printf("tot = %d\n", tot);
	return 0;
}
#endif

//  1차 - 배열구조로 변경함
#if 0
#define ARR_MAX (5)
int main(void) {
	int a = 20, b = 5;
	int result[ARR_MAX] = { 0 };
	int tot = 0;
	char* str[ARR_MAX] = { "sum", "sub", "mul", "divi", "mod" };
	int (*func[ARR_MAX])(int, int) = { add, sub, mul, divi,mod };
	tot = 0;
	for (int i = 0; i < SIZE(result); ++i) {
		result[i] = func[i](a, b);
		tot += result[i];
		printf("%s = %d\n", str[i], result[i]);
	}
	printf("tot = %d\n", tot);
	return 0;
}
#endif

// qsort의 활용
#if 0
/*void qsort(
    void *base,  // 배열 시작 주소
    size_t num,  // 배열 요소의 크기
    size_t size, // 1개 요소의 크기
	// a, b: 비교 대상의 주소
    int (*compare)(const void *a, const void *b)  // 비교 함수 (a == b: 0, a > b: 양수, a < b: 음수) 반환
);
*/

int main(void) {
	int A[10] = { 5,4,3,2,10,4,5,6,3,8 };
	char* animal [5] = { "rabbit", "seal", "snake", "dog", "cat" };
	double B[5] = { 2.3,2.1,2.6,2.7,2.4 };

	print_1Darray_d(B, SIZE(B));
	qsort(B, SIZE(B), sizeof(B[0]), compdouble);
	print_1Darray_d(B, SIZE(B));

	print_strings03(animal, SIZE(animal));
	qsort(animal, SIZE(animal), sizeof(animal[0]), compstr);
	print_strings03(animal, SIZE(animal));

	print_1Darray(A, SIZE(A));
	qsort(A, SIZE(A), sizeof(A[0]), compint); // sizeof(A[0]) == sizeof(*A)
	print_1Darray(A, SIZE(A));

	return 0;
}
#endif

// 함수 포인터 사용
#if 0
int main(void) {
	int a = 10, b = 2;
	int (*func)(int, int);

	func = add;
	printf("%d", func(a, b));

	return 0;
}
#endif

// 함수 포인터
#if 0
int add(int a, int b) {
	return a + b;
}

int main(void) {
	//함수 포인터 변수
	int (*p)(int, int) = add; // a, b 생략 가능

	printf("%p %p %p %p\n", add, *add, **add, &add); //함수의 이름은 함수 포인터가 끝
	printf("%d %d\n", add(10, 20), p(10, 20));
}
#endif

// 포인터 배열 2
#if 0
int main(void) {
	int ary1[] = { 4,1,2,3,4 };
	int ary2[] = { 3,1,2,3 };
	int ary3[] = { 6,1,2,3,4,5,6 };

	int* pary[3] = { ary1, ary2, ary3 };
	print_var_array(pary, SIZE(pary));

	return 0;
}
#endif

// 포인터 배열
#if 0
int main(void) {
	// char animal[5][10] = { "dog", "elephant", "horse", "tiger", "lion" };
	char* pary[5] = { "dog", "elephant", "horse", "tiger", "lion" };
	print_strings03(pary, SIZE(pary));

	return 0;
}
#endif

// 다중 포인터 연습
#if 0
int main(void) {
	int a = 10, b = 5;
	int* ap = &a, * bp = &b;
	int** app = &ap, ** bpp = &bp;

	//exchange0(&a, &b);
	printf("%d %d %p %p %p %p\n", a, b, ap, bp, app, bpp);

	//exchange1(&ap, &bp);
	//printf("%d %d %p %p %p %p\n", a, b, ap, bp, app, bpp);
	
	//exchange2(&app, &bpp);
	//printf("%d %d %p %p %p %p\n", a, b, ap, bp, app, bpp);
	
	//exchange3(&ap, &bp);
	//printf("%d %d %p %p %p %p\n", a, b, ap, bp, app, bpp);
	
	//exchange4(&app, &bpp);
	//printf("%d %d %p %p %p %p\n", a, b, ap, bp, app, bpp);

	//exchange5(&app, &bpp);
	//printf("%d %d %p %p %p %p\n", a, b, ap, bp, app, bpp);

	return 0;
}
#endif

// 배열의 모든 요소 합계를 구하는 함수 작성
#if 0
int main(void) {
	int A[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int B[2][3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12,1,2,3,4,5,6,7,8,9,10,11,12 };
	int sum = 0;

	sum = sum2D(A, SIZE(A), SIZE(A[0]));
	printf("%d\n", sum);

	sum = sum3D(B, SIZE(B), SIZE(B[0]), SIZE(B[0][0]));
	printf("%d\n", sum);

	sum1D(A[0], SIZE(A[0]));

	return 0;
}
#endif

// 2차원 배열에서의 &, sizeof 사용
#if 0
int main(void) {
	int A[3][4] = { 0 };
	printf("%p %p %p %p %p\n", &A, A, &A[0], A[0], &A[0][0]); // 0x1000
	printf("%p %p %p %p %p\n", &A + 1, A + 1, &A[0] + 1, A[0] + 1, &A[0][0] + 1); // 0x1030, 0x1010, 0x1010, 0x1004, 0x1004
	printf("%zu %zu %zu %zu %zu %zu\n", sizeof(&A), sizeof(A), sizeof(&A[0]), sizeof(A[0]), sizeof(&A[0][0]), sizeof(A[0][0])); // 4, 48, 4, 16, 4, 4

	return 0;
}
#endif

// 1차원 배열에서의 &, sizeof 사용
#if 0
int main(void) {
	int iary[5] = { 1,2,3,4,5 };
	printf("%p %p %p\n", &iary, iary, &iary[0]);
	printf("%p %p %p\n", &iary + 1, iary + 1, &iary[0] + 1);
	printf("%zu %zu\n", sizeof(&iary), sizeof(iary));

	char cary[10] = "rabbit";
	printf("%p %p %p\n", &cary, cary, &cary[0]);
	printf("%p %p %p\n", &cary + 1, cary + 1, &cary[0] + 1);
	printf("%zu %zu\n", sizeof(&cary), sizeof(cary));

	char (*p)[7] = &"rabbit";
	printf("%zu %zu\n", sizeof(&"rabbit"), sizeof("rabbit"));
	printf("%p %p\n", &"rabbit", "rabbit");
	printf("%c %c %c\n", p[0][4], (*p)[4], *(*p + 4)); // i
	// p[0][4] = 'j'

	return 0;
}
#endif