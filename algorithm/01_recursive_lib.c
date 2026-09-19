#include "01_recursive_lib.h"
#if 0
extern int N;

// N이 5인 경우 func08(1)을 사용해서 1 2 3 4 5 4 3 2 1 출력
void func08_1(int L) {
	// cnt1++;
	if (L > N) {
		return;
	}
	printf("%d ", L);
	func08_1(L + 1);
	if (L < N) {
		printf("%d ", L);
	}
}

void func08_2(int L) {
	//cnt2++;
	if (L > N) return;
	printf("%d ", L);
	func08_2(L + 1);
	if (L > 1) {
		printf("%d ", L - 1);
	}
}

void func08_3(int L) {
	//cnt3++;
	printf("%d ", L);
	if (L > N - 1) {
		return;
	}
	func08_3(L + 1);
	printf("%d ", L);

}

// N이 5인 경우 func07(1)을 사용해서 1 2 3 4 5 1 2 3 4 5 출력
void func07(int L) {
	if (L > N) {
		return;
	}
	printf("%d ", L);
	func07(L + 1);
	printf("%d ", N + 1 - L);
}

// N이 5인 경우 func06(1)을 사용해서 1 2 3 4 5 5 4 3 2 1 출력
void func06(int L) {
	if (L > N) {
		return;
	}
	printf("%d ", L);
	func06(L + 1);
	printf("%d ", L);
}

// N이 5인 경우 func05(1)을 사용해서 5 4 3 2 1 출력
void func05(int L) {
	if (L > N) {
		return;
	}
	func05(L + 1);
	printf("%d ", L);
}

// N이 5인 경우 func04(1)을 사용해서 5 4 3 2 1 출력
void func04(int L) {
	if (L > N) {
		return;
	}
	printf("%d ", N + 1 - L);
	func04(L + 1);
}

// L을 이용하여 재귀 호출의 종료 조건을 생성함
// L이 N보다 작거나 같은 경우 동작, L이 N보다 큰 경우 종료
// N이 5인 경우 1 2 3 4 5 출력
void func03(int L) {
	if (L > N) {
		return;
	}
	printf("%d ", L);
	func03(L + 1);
}

// 3890번 정도 반복 호출
// static을 사용하면 데이터 영역을 사용 (스택 사용 안함)
void func02(int L) {
	static int arr[10] = { 0 }; // 함수를 여러번 재귀해도 arr은 같은 것을 쓰고 있음

	printf("%d %p\n", L, arr);
	func02(L + 1);
}

// 4750번 정도 반복 호출
void func01(int L) {
	printf("%d\n", L);
	func01(L + 1);
}

// 런타임 스택 오버플로우 발생
void func(void) {
	func();
}
#endif