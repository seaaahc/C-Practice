#include "day06_lib.h"
#include "wrong_header.h"

//int a = 100; // 다른 파일과 공유해서 사용할 수 있는 전역변수 선언 방법

// mygets 함수 작성
#if 0
#define SIZE(a) sizeof(a)/sizeof(a[0])
int main(void) {
	char ary[10];
	mygets(ary, SIZE(ary));
	printf("%s\n", ary);
	printf("%s\n", to_upper(ary));

	return 0;
}
#endif

// char의 입력 확인
#if 0
int main(void) {
	//test08_3();
	test08_4();
	return 0;
}
#endif

// 배열 등가 포인터 연습
#if 0
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))

int main(void) {
	(void)freopen("array01.txt", "r", stdin);
	int ary[5] = { 0 };

	scanf_ary(ary, SIZE(ary));
	print_ary(ary, SIZE(ary));
	printf("\nmax = %d", findmax_ary(ary, SIZE(ary)));
	printf("\nmin = %d", findmin_ary(ary, SIZE(ary)));
	printf("\nsum = %d", sum_ary(ary, SIZE(ary)));
	printf("\navg = %d", avg_ary(ary, SIZE(ary)));
	printf("\nary[%d] = %d", findmaxidx_ary(ary, SIZE(ary)), findmax_ary(ary, SIZE(ary)));
	printf("\nvar = %.2lf", var_ary(ary, SIZE(ary)));
	find_min_max(ary, SIZE(ary));
	double var = var_ary(ary, SIZE(ary));
	double std = var;

	return 0;
}
#endif

// swap 함수의 사용
#if 0
int main(void) {
	int a = 20, b = 10;
	printf("a = %d, b = %d\n", a, b);
	swap(&a, &b);
	printf("a = %d, b = %d\n", a, b);

	return 0;
}
#endif

// 전역변수 a를 사용하는 코드
#if 0
int main(void) {
	printf("%d\n", a);

	return 0;
}
#endif