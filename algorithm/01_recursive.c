#include "01_recursive_lib.h"


#if 0
int N = 3;
int M = 10;
int data[10];

void printData(int* arr, int n) {
	for (int i = 1; i <= n; ++i) {
		printf("%d ", data[i]);
	}
	printf("\n");
}

void test07(int L, int start){
	if (L > N) {
		printData(data, N);
		return;
	} 

	/*for (int i = 1; i <= 4; i++) {
		for (int j = i + 1; j <= 5; j++) {
			for (int k = j + 1; k <= 6; k++) {
				printf("%d %d %d\n", i, j, k);
			}
		}
	}*/

	for (int i = start; i <= 6; ++i) {
		data[L] = i; // 현재자리(L)에 i 넣음
		test07(L + 1, i + 1);
	}
}

int cal(int* data, int n) {
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		ret += data[i];
	}
	return ret;
}

void test06(int L) {
	if (L > N) {
		if (cal(data, L) == M)
			printData(data, N);
		return;
	}

	for (int i = 1; i <= 6; i++) {
		data[L] = i;
		test06(L + 1);
	}

}

static int used[10] = { 0 };
void test05_3(int L) {
	if (L > N) {
		printData(data, N);
		return;
	}
	for (int i = 1; i <= 5; i++) {
		if (used[i]) continue;
		used[i] = 1;
		data[L] = i;
		test05_3(L + 1);
		used[i] = 0;
	}
}

void test05(int L) {
	if (L > N) {
		printData(data, N);
		return;
	}

	for (int i = 1; i <= 3; i++) {
		if (used[i]) continue;
		used[i] = 1; // 이 코드를 사용했는가?
		data[L] = i;
		test05(L + 1);
		used[i] = 0;

	}

}

void prtest05_2(void) {
	int i = 1, j = 1, k = 1;
	int used[4] = { 0 };
	for (i = 1; i <= 3; i++) {

		used[i] = i;
		for (j = 1; j <= 3; j++) {
			if (used[j]) {

				continue;
			}
			used[j] = j;
			for (k = 1; k <= 3; k++) {
				if (used[k]) {

					continue;
				}
				used[k] = k;
				printf("%d %d %d\n", used[i], used[j], used[k]);
				used[k] = 0;
			}
			used[j] = 0;
		}
		used[i] = 0;
	}
}

void test04(int L) {
	if (L > N) {
		printData(data, N);
		return;
	}

	for (int i = 1; i <= 6; i++) {
		data[L] = i;
		test04(L + 1);
	}

}

void test03(int L) {
	if (L > N) {
		printData(data, N);
		return;
	}

	data[L] = 1;
	test03(L + 1);
	data[L] = 2;
	test03(L + 1);
	data[L] = 3;
	test03(L + 1);
	data[L] = 4;
	test03(L + 1);

}

void test02(int L) {
	if (L > N) {
		printData(data, N);
		return;
	}

	data[L] = 1;
	test02(L + 1);
	data[L] = 2;
	test02(L + 1);
	data[L] = 3;
	test02(L + 1);

}

void test01(int L) {
	if (L > N) {
		printData(data, N);
		return;
	}

	data[L] = 0;
	test01(L + 1);
	data[L] = 1;
	test01(L + 1);

}

int main(void) {
	test07(1, 1);
	return 0;
}
#endif

// reculsive.c 
// 동적인 반복을 할 때 사용할 수 있음
// 배열을 쓰지 말자 : 로컬 변수를 쓰지 말자(스택 영역이 낭비되니까 재귀를 얼마 하지 못함.) // 쓸 거면 static을 붙여주자
#if 0
extern int N;
//static int cnt1 = 0, cnt2 = 0, cnt3 = 0;




void func09_2(int L, int S) {
	if (L > N) {
		return;
	}
	if (S <= L) {
		printf("*");
		func09_2(L, S + 1);
	}
	else {
		printf("\n");
		func09_2(L + 1, 1);
	}
}

void func09(int L) {
	if (L > N) {
		return;
	}
	for (int i = 1; i <= L; ++i) {
		printf("*");
	}
	printf("\n");
	func09(L + 1);
}


int N = 5;

int main(void) {
	func09_2(1, 1);
	return 0;
}
#endif
