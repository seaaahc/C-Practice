#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 10보다 작거나 같은 수 입력(while문과 do-while문)
#if 0
int main(void) {
	int a = 0;
	int b = 0;

	//while문
	printf("a 입력: "); // 애초에 a를 11로 만들어버리면 아래 while을 무조건 실행하게 됨... 그래서 scanf한번 더 안써도 되는구나......
	(void)scanf("%d", &a); // 나중에 10을 n으로 놓고 11을 n+1로 놓으면 유지보수 면에서 짱

	while (a > 10) {
		printf("a 입력: ");
		(void)scanf("%d", &a);
	}

	//do-while문
	do {
		printf("b 입력: ");
		(void)scanf("%d", &b);
	} while (b > 10);

	printf("%d %d", a, b);
	return 0;
}
#endif

//등급 나누기 프로그램
#if 0
int main(void) {
	int a;
	char grade;
	printf("정수를 입력해주세요(0 ~ 100): ");
	(void)scanf("%d", &a);

	//switch문 활용
	switch (a / 10) {
	case 10:
	case 9:
		grade = 'A';
		break;
	case 8:
		grade = 'B';
		break;
	case 7:
		grade = 'C';
		break;
	case 6:
		grade = 'D';
		break;
	default:
		grade = 'F';
		break;
	}
	printf("%c\n", grade);
	

	//if문 활용
	if (a >= 90) {
		grade = 'A';
	}
	else if (a >= 80) {
		grade = 'B';
	}
	else if (a >= 70) {
		grade = 'C';
	}
	else if (a >= 60) {
		grade = 'D';
	}
	else {
		grade = 'F';
	}
	printf("%c\n", grade);

	//문자열 활용
	char arr[] = "FFFFFFDCBAA";
	printf("%c", arr[a / 10]);

	//무조건 문자열이 좋은게 아님. 확장성은 switch문이나 if문이 훨씬 좋음.

	return 0;
}
#endif

//합격/불합격 판정 프로그램
#if 0
int main(void) {

	int a;

	printf("정수를 입력해주세요(0 ~ 100): ");
	(void)scanf("%d", &a);

	//if ~ else if ~ else 문
	if (a >= 70) {
		printf("합격입니다.\n");
	}
	else if(a >= 60){
		printf("재시험 보세요.\n");
	}
	else {
		printf("불합격입니다.\n");
	}

	//중첩 if문
	if (a < 70) {
		if (a >= 60) {
			printf("재시험 보세요\n");
		}
		else {
			printf("불합격입니다.\n");
		}
	}
	else {
		printf("합격입니다.\n");
	}

	//조건연산자
	printf("%s\n", (a >= 70) ? "합격입니다." : (a >= 60) ? "재시험 보세요." : "불합격입니다.");

	//배열 사용
	char* c[] = {"합격입니다.", "재시험 보세요", "불합격입니다."};
	printf("%s\n", c[(a >= 60) + (a < 70)]);

	printf("감사합니다.");
	
	return 0;
}
#endif

//배수 판단 프로그램
#if 0
int main(void) {

	int a;

	printf("정수를 입력해주세요: ");
	(void)scanf("%d", &a);

	if (a % 2 == 0) {
		printf("2\n");
	}
	else if (a % 3 == 0) {
		printf("3\n");
	}
	else if (a % 5 == 0) {
		printf("5\n");
	}
	else {
		printf("0\n");
	}
	//만약 함수 안에서 if를 쓴다면 else 쓰지 말것.

	//if else 없이 짤 수 있는가?
	//2의 배수와 3의 배수 5의 배수가 각각 다른 정수를 가리켜야 함.
	int arr[]  = {0, 2, 3, 5};
	printf("%d", arr[((a % 2 == 0) + ((a % 3 == 0) + 1)) + ((a % 5 == 0) + 2)]);

	return 0;
	 
}
#endif
	
//짝수/홀수 판정 프로그램
#if 0
int main(void) {

	int a;
	char* msg[2] = { "짝수", "홀수" };

	printf("정수를 입력해주세요: ");
	(void)scanf("%d", &a);

	//if else문
	if (a % 2 == 0) {
		printf("짝수입니다.\n");
	}
	else {
		printf("홀수입니다.\n");
	}

	//조건연산자
	printf("%s입니다.\n", (a % 2 == 0) ? "짝수" : "홀수");

	//조건문 안 쓰고 배열쓰기
	printf("%s입니다.", msg[a % 2]);


	return 0;
}
#endif

//if else 문과 조건연산자의 변환
#if 0
int main(void) {

	int a = 10;
	int b = 5;

	if (a > b) {
		printf("%d\n", a);
	}
	else {
		printf("%d\n", b);
	}

	int t = (a > b) ? a : b;
	printf("%d\n", t);

	return 0;
}
#endif
