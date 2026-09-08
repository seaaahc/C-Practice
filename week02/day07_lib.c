#include "day07_lib.h"
#if 0

char* mystrcpy(char* to, const char* from) {
	char* save = to;
	for (; (*to = *from); ++from, ++to);
	return save;
}
#else
char* mystrcpy(char *to, const char *from) {
	char* save = to;
	while (*to ++ = *from++);
	return save;
}
#endif

int mystrlen(const char* str) {
	const char* s;

	if (str == 0) {
		return 0;
	}

	for (s = str; *s; ++s);

	return s - str;
}

// 같으면 0, str1이 크면 양수, str2이 크면 음수를 반환
int mystrcmp(const char* str1, const char* str2) {

	while (*str1 == *str2) {
		if (*str1 == 0)
			return 0;

		str1++;
		str2++;
	}
	return *(unsigned const char*)str1 - *(unsigned const char*)str2; // 캐
}
	
// 같으면 0, a가 크면 양수, b가 크면 음수를 반환
// 반복문, if ~ else, ? : 등 사용하지 않고 '식'으로 풀 것 - 비교 연산자 사용
int intcmp(const int* a, const int* b) {

	return *a - *b; // 
}

#if 0
extern int a;
// extern int b;
void printInt(void) {
	printf("a = %d\n", a);
	// printf("b = %d\n", b); // b는 static이기 때문에 extern 할 수 없음
}
#endif