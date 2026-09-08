#include "day10_lib.h"

#if 0

int sum(int x, int y) {
	return x + y;
}

int sub2(int x, int y) {
	return x - y;
}

int mul2(int x, int y) {
	return x * y;
}

int divd(int x, int y) {
	return x / y;
}

int mod(int x, int y) {
	return x % y;
}

int main(void) {
	int menu;
	int x, y;

	int (*func[5])(int, int) = { sum, sub2, mul2, divd, mod };

	while (1) {
		printf("1. 덧셈\n");
		printf("2. 뺄셈\n");
		printf("3. 곱셈\n");
		printf("4. 나눗셈(몫)\n");
		printf("5. 나눗셈(나머지)\n");
		printf("0. 종료\n");

		printf("메뉴 선택 : ");
		(void)scanf("%d", &menu);

		if (menu == 0) {
			break;
		}

		if (menu < 1 || menu > 5) {
			printf("잘못된 메뉴입니다.\n\n");
			continue;
		}

		printf("두 정수 입력 : ");
		(void)scanf("%d %d", &x, &y);

		if ((menu == 4 || menu == 5) && y == 0) {
			printf("0으로 나눌 수 없습니다.\n\n");
			continue;
		}

		printf("결과 : %d\n\n", func[menu - 1](x, y));
	}

	return 0;
}
#endif

#if 0
void swap_10(int **a,  int **b) {
	int* temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int comprow10(int* a, int* b, int size) {
	for (int k = 0; k < size; ++k) {
		if (a[k] > b[k]) {
			return 1;
		}
		if (a[k] < b[k]) {
			return 0;
		}
	}
	return 0;
}
int main(void) {
	int arr[5][3] = {
		{3,5,1},
		{1,4,3},
		{7,1,5},
		{3,2,2},
		{5,3,4}
	};

	int* parr[5] = { arr[0], arr[1], arr[2], arr[3], arr[4] };

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (comprow10(parr[j], parr[j+ 1], SIZE(arr[0]))) {
				swap_10(&parr[j], &parr[j + 1]);
			}
		}
	}

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 3; ++j) {
			printf("%d ", parr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
#endif

#if 0
int main(void) {
	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	printf("%d", **(a + 1) + 2);
	
	return 0;
}
#endif