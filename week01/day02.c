#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 정수의 승격
#if 0
int main(void) {
	unsigned char a = 0xF0;
	char b = 0xF0;
	unsigned char c = 0x0F;
	char d = 0x0F;
	//a = 0x000000F0
	//b = 0xFFFFFFF0
	//c = 0x0000000F ~c = 0xFFFFFFF0
	//d = 0x0000000F ~d = 0xFFFFFFF0
	printf("%d %d %d %d\n", a == ~c, a == ~d, b == ~c, b == ~d);

	return 0;
}
#endif

// ++ 연산 / post 연산
#if 0
int main(void) {
	int a = 10, b = 5;
	b = a+++b;
	printf("a = %d, b = %d", a, b);

	return 0;
}
#endif

// 1개 bit의 set, clear, toggle 연산
#if 0
// 1로 만드는 동작: Set (|)
unsigned int SetBit(int num, int pos) {
	return num | (1 << pos);
}

// 0으로 만드는 동작: Clear
unsigned int ClearBit(int num, int pos) {
	return num & ~(1 << pos);
}

// 0 <-> 1 동작: Toggle
unsigned int ToggleBit(int num, int pos) {
	return num ^ (1 << pos);
}

// 특정 비트를 가져오기: Check, Is, Get ...
unsigned int isBitSet(int num, int pos) {
	//return (num & (1 << pos)) >> pos
	return (num >> pos) & 1;
}

int main(void) {
	int num = 0b11010; // 2진수
	num = SetBit(num, 2);
	printf("%X\n", num); // 1E 1110
	num = ClearBit(num, 1);
	printf("%X\n", num); // 1C 1100
	num = ToggleBit(num, 3);
	printf("%X\n", num); // 14 0100

	num = isBitSet(num, 2);
	printf("%X", num);
	
	return 0;
}
#endif

// Shift 연산
#if 0
// 산술 shift: 양수는 0, 음수는 shift right 1 (shift left: 0, shift right: 부호)
// 논리 shift: 패딩은 무조건 0
int main(void) {
	int a = 0x7FFF0000;
	int b = 0777; //8진수
	int c = 0x9090F0F0;

	printf("%x %x\n", a >> 4, a << 4);
	printf("%o %o %o \n", b, b << 3, b >> 3);
	printf("%d %X %d %X %d %X", c, c, c << 4, c << 4, c >> 4, c << 4);

	return 0;
}
#endif

#if 0
int main(void) {
	int a = 10, b = 5;

	printf("%d\n", (a > b) ? 1 : 0); //1
	printf("%d\n", a > b); //2
	printf("%d\n", (a > b) ? a : b); //3

	// 컴파일러 최적화에 의해 1, 2는 동일하게 동작한다. ? 1:0 을 무시한다.

	return 0;
}
#endif

// 3항 연산에서 ? 1:0은 무시된다. (최적화)
#if 0
int main(void) {
	int a = 10, b = 5;

	printf("%d\n", (a > b) ? 1 : 0); //1
	printf("%d\n", a > b); //2
	printf("%d\n", (a > b) ? a : b); //3

	// 컴파일러 최적화에 의해 1, 2는 동일하게 동작한다. ? 1:0 을 무시한다.

	return 0;
}
#endif

// short-circuit 원리
#if 0
int main(void) {
	// func1()의 결과가 거짓이면 func2()를 실행하지 않음
	if (func1() && func2()) {} 

	// func1(), func2()가 모두 실행되고 그 결과에 따라 if의 참일 때 수행명령이 동작되거나 되지 않음
	a = func1();
	b = func2();
	if(a&& b){}

	return 0;
}
#endif

// postfix ++/--
#if 0
int main(void) {
	int a = 5, b = 5;
	int pre = 0, post = 0;
	pre = (++a) * 3;
	post = (b++) * 3;
	printf("%d %d\n", a, b);
	printf("%d %d\n", pre, post);
	return 0;
}
#endif

// postfix ++/-- 이해
#if 0

int main(void) {
	char arr[10] = "Hello";
	char* p = arr; //arr은 상수, p는 변수
	char ch = 0;

	printf("p = %p ch = %c arr = %s\n", p, ch, arr);
	ch = *p++; //ch = *p; p = p + 1;
	printf("p = %p ch = %c arr = %s\n", p, ch, arr);
	ch = (*p)++; //ch = *p; *p = *p + 1;
	printf("p = %p ch = %c arr = %s\n", p, ch, arr);

	ch = ++*p; //*p; *p = *p + 1; ch = *p;
	printf("p = %p ch = %c arr = %s\n", p, ch, arr);
	ch = ++(*p); //*p; *p = *p + 1; ch = *p;
	printf("p = %p ch = %c arr = %s\n", p, ch, arr);

	return 0;
}
#endif

// scanf로 문자열 입력
#if 0
int main(void) {
	char arr[5] = { 0 };
	(void)scanf("%s", arr); //&arr와 arr 주소값이 같아서 문제가 없었음 따라서 &arr 쓰지 말자
	printf("arr = %s\n", arr);
	return 0;
}
#endif

// scanf로 정수 입력
#if 0
// int scanf(const char* format, ...);
// 성공적으로 입력받아 저장한 항목의 개수를 반환합니다.
int main(void) {
	int a = 0;
	(void)scanf("%d", &a);
	printf("a = %d\n", a);
	return 0;
}
#endif

// const char* from을 사용한 이유는 무엇일까?
// mystrcpy를 사용하는 사용자에게 from에는 read only 메모리의 주소를
// 사용해도 된다는 것을 알려준 것이다.
#if 0
char* mystrcpy(char* to, const char* from) {
	char* save = to;
	while (*to++ = *from++);
	return save;
}

int main(void) {
	char a[10] = { 0 };
	char* b = "Hello";

	mystrcpy(a, b);
	printf("a = %s\n", mystrcpy(a, b));

	return 0;
}
#endif

//const의 이해 - const는 이름을 const로 만들어 준다
#if 0
int main(void) {
	int const a = 100;

	int* p = (int*)&a;
	*p = 150;

	printf("%d\n", a);

	return 0;
}
#endif