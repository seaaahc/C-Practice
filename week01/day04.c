#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#if 0
#define pwd 1357

int main() {
	int limit = 3;
	int n = 0;
	/*while (limit--) {
		scanf_s("%d", &n);
		if (n == pwd) {
			printf("로그인 성공!");
			return 0;
		}
	}
	printf("관리자에게 문의하세요\n");
	return 0;*/
	
	char* msg[2] = { "로그인 성공!", "관리자에게 문의하세요.\n" };
	do {
		(void)scanf("%d", &n);
		if (n == pwd) {
			break;
		}
	} while (--limit);
	printf("%s", msg[!limit]);
	return 0;

	int num;
	int i = 3;

	while (i--) {
		(void)scanf("%d", &num);
		if (num == 1357) {
			printf("로그인 성공!\n");
			break;
		}
	}
	// i의 값까지 구해야 성공 여부를 확인 가능
	if (i == -1) printf("관리자에게 문의하세요.\n");
	// break로 나왔는지, 반복횟수가 다 되어서 나왔는지 확인해야하므로 if문이 들어감
	return 0;

	while (i--) {
		(void)scanf("%d", &num);
		if (num == 1357) {
			printf("로그인 성공!\n");
			return 0;
		}
	}
	printf("관리자에게 문의하세요.\n");
	return 0; 
	
}
#endif

//자릿수 구하기 프로그램
#if 0
int main(void) {
	char a[8];
	int i = 0;
	(void)scanf("%s", a);

	while (a[i++] != '\0');
	printf("%d\n", i);

	/* 원래는
	while(i < 8){
		if (a[i] == '\0') {
			break;
		}
		i++;
	}
	printf("%d", i); 이렇게 했음ㅠㅠ 마인드를 고치자 세아야 제발*/

	/* 근데 이것도 안좋댄다.... 파이썬에서 이렇게 하는거래....
	*   int i = 1 (어차피 1부터 시작하니까 자릿수로 1 이상이므로 1로 초기화)
		while (num /= 10) {
        ++i;
		}
	*/

	//이걸 한 줄로 printf("%zu", strlen(a));
	return 0;
}
#endif

//암호 확인 프로그램
#if 0
#define MAX_TRY 3
#define PASSWORD 1357 

int main(void) {
	int num;
	for (int i = 0; i < MAX_TRY; ++i) {
		printf("암호를 입력하세요: ");
		(void)scanf("%d", &num);
		if (num == PASSWORD) {
			printf("로그인 성공!\n");
			return 0;
		}
	}
	printf("관리자에게 문의하세요.\n");
	return 0;
	/* 더 나은 코드
	char* msg[2] = { "로그인 성공!", "관리자에게 문의하세요.\n" };
	do {
		(void)scanf("%d", &num);
		if (n == PASSWORD) {
			break;
		}
	} while (--MAX_TRY);
	printf("%s", msg[!MAX_TRY]);
	return 0;
	*/
}
#endif

//양수 덧셈 프로그램
#if 0
int main(void) {
	int a;
	int sum = 0;

	for (;;) {
		(void)scanf("%d", &a);
		if (a == 0) {
			break;
		}
		else if (a > 0) {
			sum += a;
		}
	}
	/* 개선하면
	do {
		(void)scanf("%d", &a);

		if (a > 0) {sum += a;}
	} while (a != 0)
	*/

	printf("%d\n", sum);
	return 0;

	
}
#endif

//구구단 프로그램 작성
//배열이나 문자열 관련 함수를 사용하여 printf를 1회 줄이는 프로그램 생성
#if 0
int main(void) {
	
	for (int i = 2; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			printf("%d * %d = %2d\n", i, j, i * j); //printf 72회 호출
		}
	}
	//구구단 출력 내용을 char 배열에 차례대로 저장
	return 0;
}
#endif

//2, 3, 5 배수
#if 0
#define SIZE(a) sizeof(a)/sizeof(a[0])

int mul02(int number) {
	if (number % 2 == 0) {
		return 2;
	}
	if (number % 3 == 0) {
		return 3;
	}
	if (number % 5 == 0) {
		return 5;
	}
	return 0;
}

// 반복문을 사용하면 2, 3, 5의 배수를 구하는 것이 수정이 유연해짐(유지보수성)
int mul03(int number) {
	int mul;
	int nums[3] = { 2, 3, 5 };
	int number = 15;
	int answer = 0;

	for (int i = 0; i < SIZE(nums); i++) {
		mul = nums[i];
		if (number % nums[i] == 0) {
			return mul;
		}
	}
}

int main(void) {
	printf("%d의 배수입니다.\n", answer);
	return 0;
}
#endif

// 합격, 재시험, 불합격
#if 0

void checkPass(int score) {
	char* res[3] = {
		"합격입니다.",
		"재시험보세요.",
		"불합격입니다." };

	// 어셈블 코드량 증가
	// res[0], res[1], res[2]의 중복적인 연산 반복 
	// score < 70 : 불필요한 코드 실행
	printf("%s", score >= 70 ? res[0] : score >= 60 && score < 70 ? res[1] : res[2]);

	// score >= 60 및 + 연산을 항상 수행해야 함
	// score >= 70의 상황이 많은 경우 연산의 수가 불필요하게 증가 (runtime)
	printf("%s\n감사합니다.\n", res[(score >= 70) + (score >= 60)]);

	// 가독성의 문제 및 약간의 추가 연산 필요
	printf("%s\n감사합니다.\n", res[score >= 70 ? 0 : score >= 60 ? 1 : 2]);

	// 가장 최적화된 형태로 가독성이 좋으며, 어셈블리 코드도 간략함
	int n;
	if (score >= 70) n = 0;
	else if (score >= 60) n = 1;
	else n = 2;
	printf("%s\n감사합니다.\n", res[n]);

}

int main(void) {
	int score = 0;
	(void)scanf("%d", &score);
	checkPass(score);
	return 0;
}
#endif