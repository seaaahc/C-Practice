#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//혼공 205p
#if 0
int main(void) {
	int a;
	int count = 0;
	printf("2 이상의 정수를 입력하세요: ");
	(void)scanf("%d", &a);

	for (int i = 2; i <= a; ++i) {
		int p = 1;
		for (int j = 2; j < i; ++j) {
			if (i % j == 0) {
				p++;
				break;
			}
			
		}
		if (p == 1) {
			printf("%3d ", i);
			count++;

			if (count % 5 == 0) {
				printf("\n");
			}
		}
	} 
	return 0;
}
#endif

// 정올 구구단
#if 0
int main(void) {
	int a;
	int b;
	(void)scanf("%d %d", &a, &b);

	if (a < b) {
		for (int i = a; i <= b; ++i) {
			for (int j = 1; j <= 9; ++j) {
				printf("%d * %d = %d\n", i, j, i*j);
			}
			printf("\n");
		}
	}
	else {
		for (int i = a; i >= b; --i) {
			for (int j = 1; j <= 9; ++j) {
				printf("%d * %d = %d\n", i, j, i*j);
			}
			printf("\n");
		}
	}
	return 0;
}
#endif

// 정올 문자입력
#if 0
int main(void) {
	char arr[11] = { '0' };
	for (int i = 0; i < sizeof(arr); ++i) {
		(void)scanf("%s", &arr[i]);
		printf("%c", arr[i]);
	}

	return 0;
}
#endif

//c100제 13번
#if 0
#include<stdio.h>
int main()
{
	char s[10] = { 'a','b','c','d','e' }; //10
	char t[] = { 'a','b','c','d','e','\0' };//6
	char u[] = "abcde";//6
	char v[] = "안녕하세요";//11 저도 11나오네요...
	printf("s = |%s| size = %d\n", s, sizeof(s)); // 10칸을 만들어놨으니까 10
	printf("t = |%s| size = %d\n", s, sizeof(t)); // 맨 뒤 널문자까지 6개
	printf("u = |%s| size = %d\n", s, sizeof(u)); // 맨 뒤 널문자까지 6개
	printf("v = |%s| size = %d\n", s, sizeof(v)); // 제 비주얼스튜디오는 한글을 2바이트로 보나봅니다...
	return 0;
}
#endif

//혼공 148p
#if 0
int main(void) {
	float h = 0;
	int w = 0;
	printf("몸무게(kg)와 키(cm) 입력: ");
	(void)scanf("%d %f", &w, &h);
	float mh = h / 100;
	float bmi = w / (mh * mh);
	if ((bmi < 25.0) && (bmi >= 20.0)) {
		printf("표준입니다.");
	}
	else {
		printf("체중 관리가 필요합니다."); 
	 }

	return 0;
}
#endif

//혼공 180p
#if 0
int main(void) {
	int num1;
	int num2;
	char op;

	printf("사칙연산 입력(정수): ");
	(void)scanf("%d %c %d", &num1, &op, &num2);

	if (op == '+') {
		printf("%d %c %d = %d", num1, op, num2, num1 + num2);
	}
	else if (op == '-') {
		printf("%d %c %d = %d", num1, op, num2, num1 - num2);
	}
	else if (op == '*') {
		printf("%d %c %d = %d", num1, op, num2, num1 * num2);
	}
	else if (op == '/') {
		printf("%d %c %d = %d", num1, op, num2, num1 / num2);
	}

	return 0;
}
#endif

#if 0
void input_nums(int* lotto_nums);
void print_nums(int* lotto_nums);

int main() {
	int lotto_nums[6];

	input_nums(lotto_nums);
	print_nums(lotto_nums);

	return 0;
}
void input_nums(int* lotto_nums) {
	for (int i = 0; i < 6; i++) {
		printf("번호 입력: ");
		(void)scanf("%d", &lotto_nums[i]);

		printf("같은 번호가 있습니다!");
	}

}
void print_nums(int* lotto_nums) {
	for (int i = 0; i < 6; i++) {
		printf("로또 번호: %d ", lotto_nums[i]);
	}
}
#endif

#if 0
int main() {
	printf("(1)\n");
	for (int i = 1; i <= 5; ++i) {
		for (int j = 1; j <= i; ++j) {
			printf("*");
		}
		printf("\n");
	}

	printf("\n(2)\n");
	for (int i = 1; i <= 9; i = i + 2) {
		for (int j = 1; j <= i; ++j) {
			printf("*");
		}
		printf("\n");
	}

	printf("\n(3)\n");
	for (int i = 5; i >= 1; --i) {
		for (int j = 1; j <= i; ++j) {
			printf("*");
		}
		printf("\n");
	}

	printf("\n(4)\n");
	for (int i = 1; i <= 5; ++i) {
		for (int k = 4; k >= i; --k) {
			printf(" ");
		}
		for (int j = 1; j <= i; ++j) {
			printf("*");
		}
		printf("\n");
	}

	printf("\n(5)\n");
	for (int i = 1; i <= 9; i = i + 2) {
		for (int k = 8; k >= i; k = k - 2) {
			printf(" ");
		}
		for (int j = 1; j <= i; ++j) {
			printf("*");
		}
		printf("\n");
	}

	printf("\n(6)\n");
	for (int i = 1; i <= 9; i = i + 2) {
		for (int k = 1; k < i; k = k + 2) {
			printf(" ");
		}
		for (int j = 9; j >= i; --j) {
			printf("*");
		}
		printf("\n");
	}


	return 0;
}
#endif

#if 0
int main() {
	int arr[10] = { 0 };
	int sum = 0;

	for (int i = 0; i < 10; i++) {
		printf("%d번째 숫자를 입력하세요: ", i + 1);
		scanf("%d", &arr[i]);
	}

	int min = arr[0];
	int max = arr[0];

	for (int i = 0; i < 10; i++) {
		printf("%d\t", arr[i]);

		if (arr[i] > max) {
			max = arr[i];
		}

		if (arr[i] < min) {
			min = arr[i];
		}

		sum += arr[i];
	}

	printf("\nmin=%d, max=%d, average=%.2f", min, max, sum / 10.0);

	return 0;
}
#endif