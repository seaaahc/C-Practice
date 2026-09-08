#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#if 0
int main(void) {
	int a = 10;
	int* p = NULL;

	p = &a;
	*p = 20;
	printf("%d %d\n", a, *p);

	return 0;
}
#endif 

// char 배열의 선언과 초기화
#if 0
#include <string.h>

int main(void) {
	char str1[80] = "applejam";
	char str2[80];
	char ch;
	
	strcpy(str2, str1);
	printf("%s %s\n", str1, str2);

	printf("문자열 입력: ");
	(void)scanf("%s", str2); // 입력의 끝을 Enter/Tab/Space Bar 입력 시 Enter/Tab/Space Bar를 입력하지 않고 입력 종료
	printf("입력 후 문자열: %s\n", str2);

	gets(str2); // Enter 입력 시 Enter까지 입력 받고 종료
	puts(str2); // 문자열 출력 후 줄변경('\n'이 기본 출력 됨)
	printf("%d %s\n", strlen(str2), str2);

	(void)scanf("%c", &ch); // 1개 문자를 입력 받음(줄 변경도 1개 문자로 취급)
	printf("%c\n", ch);

	return 0;
}
#endif

// 성적저리 프로그램
#if 0
#define SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))

// 파라미터에 쓸 수 없는거 배열과 함수...	
void inputData(int* score, int n) {
	for (int i = 0; i < n; ++i) {
		(void)scanf("%d", &score[i]);
	}
}

int totalData(int* score, int n) {
	int total = 0;
	for (int i = 0; i < n; ++i) {
		total += score[i];
	}
	return total;
}

void printData(int* score, int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d ", score[i]);
	}
}
// 40 50 60 70 80
int main(void) {
	int score[5] = { 0 };
	int total = 0;

	inputData(score, SIZE(score));
	printData(score, SIZE(score));
	
	printf("\n%d\n", totalData(score, SIZE(score))/SIZE(score));

	return 0;
}
#endif

#if 0
// type? - 이름을 제외한 나머지
// int a; - a의 자료형 int
// char * b; - char *
// char c; - char
// int arr[10]; - int [10]
// char ** d; - char **
// int ary[5]; - a의 자료형: int [5], a[n]의 자료형: int

// 가리키는 자료형? - 이름과 *을 제외한 나머지
// char *a; - char
// int *b; - int
// int (*c)[4]; - int [4]
int main(void) {
	int ary[5] = { 1,2,3,4,5 };
	printf("%p\n", ary);        // 1000
	printf("%p\n", ary + 2);	// 1008, ary + sizeof(int) *2 // 덧셈 연산할 땐 배열이 아니라 포인터로 역할
	printf("%d\n", ary[2]);		// 3 // *(ary + 2)

	return 0;
}
#endif

#if 0
// "1234":포인터 상수
// a: 포인터 변수
// b: 배열
int main(void) {
	char ch = 'X';
	char* a = "1234";
	char b[] = "1234";

	// a의 연산
	// %p: 주소값 출력(주소의 종류는 상관 없음)
	// %s: xhar *를 사용, 주소에 가서 char를 꺼내 출력하는 동작을 연속으로 진행하며, '\0'를 만났을 때 종료
	printf("%p %p %s %s\n","1234", a, "1234", a); //2000, 2000, 1234, 1234
	printf("%p %p\n", &a, &a + 1);                // a가 할당 받은 스택의 주소, char** - 이중 포인터
	printf("%p %p\n", &"1234", &"1234" + 1);      // "1234" 가 할당 받은 rodata의 주소, char(*)[5] - 배열 포인터
	printf("%c %c\n", *a, *"1234");				  // a에 저장된 주소에 접근해서 char 값을 읽어 printf에 전달

	ch = *a;    // *a를 읽어 ch변수에 저장: *a에서 read 동작 함
	//*a = 'A'; // *a에 'A'를 저장: *a에 write 동작 못함

	a = b;      // a에 배열 b의 주소를 저장 (b: 스택 메모리를 사용하는 char배열, b = &b[0])
	ch = *a;    // *a를 읽어 ch변수에 저장: *a에서 read 동작 함
	*a = 'A';   // *a에 'A'를 저장: *a에 write 동작 함

	printf("%c %c %c %c %c\n", ch, *a, a[0], *b, b[0]); // a = b라고 했기 때문에 a는 배열 b처럼 사용할 수 있음

	printf("%p %p\n", a, a + 1);   // 4 커짐(char*는 4byte라서) a는 char* 변수, a + 1: a가 가리키는 것의 크기만큼 1개 더하기
	printf("%p %p\n", &a, &a + 1); // &a는 char** 상수, &a + 1: &a가 가리키는 것(char *)의 크기만큼 1개 더하기
	printf("%p %p\n", b, b + 1);   // 5 커짐(배열이 5byte라서) b는 char* 상수, b + 1: b가 가리키는 것의 크기만큼 1개 더하기
	printf("%p %p\n", &b, &b + 1); // &b는 char(*)[5] 상수, &b + 1: b가 가리키는 것(char[5])의 크기만큼 1개 더하기

	char* p = &b[4];
	printf("%d\n", p - a); //4: p와 a 사이에 존재하는 요소의 개수

	// b[]= {'A', '2', '3', '4', 0}
	// b는 포인터 상수이며 배열이다. 
	printf("%p %c\n", b, *b);
	printf("%p %d\n", b + 1, p - b);
	// b = p; //배열의 이름은 포인터 '상수'이기 때문에 l-value로 사용할 수 없음
	// &, sizeof 연산자와 함께 사용될때 '배열'로 동작함.
	printf("%p %p %p\n", b, &b, &b + 1); //&b는 char(*)[5] 상수, 배열 포인터
	printf("%zu %zu %zu %zu", sizeof(a), sizeof(b), sizeof(&b), sizeof(*&b)); //&가 붙는 순간 포인터가 되므로 4, *과 &는 서로 반대의 동작을 하므로 상쇄되어 5

	return 0;
}
#endif