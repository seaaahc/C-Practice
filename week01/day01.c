#include <stdio.h>

// 이름 출력
#if 0
int main(void) {
	printf("저는 천세아입니다.");
	return 0;
}
#endif

// 2, 8, 10, 16진수 출력
#if 0
void print_binary(unsigned int n) {
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

void print_binary2(unsigned int n) {
    unsigned int n = 10;
    for (int i = 31; i >= 0; i--) {
        printf("%u", (n >> i) & 1);
    }
    printf("\n");
}

void print_bin(unsigned int v) {
    int start = 31;
    while (start > 0 && !(v >> start & 1)) start--;

    for (int i = start; i >= 0; i--)
        putchar((v >> i & 1) ? '1' : '0');
    putchar('\n');
}

void binary(int a)
{
    if (a > 1) binary(a / 2);
    printf("%d", a % 2);
}

int main(void) {
    int a = 13;
    printf("%b %o %d %x %X\n", a, a, a, a, a);
    return 0;
}
#endif


// 4비트 크기의 2진수 문자열로 변환
#if 0
char* to_bin(int n) {
    static char buf[5];
    for (int i = 3; i >= 0; i--) {
        buf[3 - i] = ((n >> i) & 1) ? '1' : '0';
    }
    buf[4] = '\0';
    return buf;
}

int main(void) {
    int a = 13;
    printf("%s %o %d %x\n", to_bin(a), a, a, a, a);

    return 0;
}
#endif

// 반올림하여 출력
// 5.5 (6), 6.5 (6)를 정수로 반올림 할 때 왜 차이가 있을까?
// 짝수일 때 내림됨
#if 0
#include <stdio.h>
int main(void) {
    float a = 3.5;
    printf("a = %.0f", a);
    return 0;
}
#endif

// l-value, r-value의 이해
#if 0
#include <stdio.h>
int main(void) {
    unsigned char a = -1;
    signed char b = -1;
    s
    printf("%d %d\n", a, b);

    if (a > b) printf("a > b");
    else if (a < b) printf("a < b");
    else printf("a == b");

    return 0;
}
#endif

// float의 유효범위
#if 0
#include <stdio.h>
int main(void) {
    float num = 123456789.0F;

    printf("점수 = %.1f", num);  // 123456792.0 - 유효숫자 7개를 넘는 숫자 사용했음
    return 0;
}
#endif
