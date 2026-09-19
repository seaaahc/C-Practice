#include "day14_lib.h"

#if 01
int main(void) {
	//타입데프한거 적기
	return 0;
}
#endif

#if 0
#define NDEBUG // 이거 쓰는 이유가 있다던데 음.. 입력하지 않는다? 지피티한테 물어보자
#include <stdio.h>
#include <assert.h>

int main() {
	int x;

	printf("\nEnter an integer value: ");
	(void)scanf("%d", &x);

	assert(x >= 0);

	printf("You entered %d.", x);

	return(0);
}
#endif

#if 0
#define string(x) printf(#x" is %d\n", x)       // 문자열화 연산자
#define charr(x) printf("%c is %c\n", #@x, x)  // 문자화 연산자
#define concat(x,i) printf("%s is %d\n", #i, x##i)  // 결합 연산자

int main(void)
{
	int s = 10, c = 97, ca = 7, cb = 9;

	string(s);
	printf("s" " is %d \n", s);
	charr(c);
	printf("%c is %c \n", 'c', c);
	concat(c, a);
	printf("%s is %d \n", "a", ca);
	concat(c, b);
	printf("%s is %d \n", "b", cb);

	return 0;
}
#endif

#if 0
#define Assert(x) { \
    if((x) >= 4) printf("Range error : %s, %d\n", __FILE__, __LINE__);\
    }

int main(void) {
	int a[4] = { 10,20,30,40 };
	int i;

	for (i = 0; i <= 4; ++i) {
// #line 100
		Assert(i);
		printf("a[%d] = %d\n", i, a[i]);
	}
}
#endif

#if 0
#define SOUND_DEVICE_TYPE 1

int main(void) {
#if !SOUND_DEVICE_TYPE
	printf("사운드 장치를 사용하지 않음\n");
#else
#error CODE 10 : Unknown Device!
#endif

	printf("사운드 모드 = %d\n", SOUND_DEVICE_TYPE);
}
#endif


// 매크로
#if 0
#define MUL1(x, y) x * y
#define MUL2(x, y) ((x) * (y))
#define SWAP(x, y) temp = x; \
x = y; \
y = temp; // 매크로 함수는 한 줄로 만들어 줘야함

int main(void) {
	int a = 100, b = 2, x = 200, y = 3;

	printf("%d %d %d\n", MUL1(2, 5), MUL1(a, b), MUL1(x, y));
	printf("%d %d %d\n", 2 * 5, a * b, x * y);
	printf("%d\n", 300 / MUL1(2, 5)); // printf("%d\n", 300 / 2 * 5);
	printf("%d\n", 300 / MUL2(2, 5)); // printf("%d\n", 300 / (2 * 5));
	printf("%d\n", 300 / MUL2(2 + 3 * 5, 5)); // printf("%d\n", 300 / ((2+3*5) * 5));
	
	
	int temp;

	printf("%d %d\n", a, b);
	SWAP(a, b);
	printf("%d %d\n", a, b);
	
	return 0;
}
#endif
