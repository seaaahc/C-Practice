#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//for, while 및 포인터 변수의 활용
#if 0
int main(void) {
    char* data = "1780341298712367";
    int ary[10] = { 0 };

    /*
    while (*data) { //for (*data != '\0')이랑 같음
        ary[*data++ - '0']++;
    }

    for (int i = 0; i < 10; i++) {
        printf("%d : %d\n", i, ary[i]);
    }

    return 0;
    나는 이렇게 생각했는데*/

    while (*data) { //for (*data != '\0')이랑 같음
        ary[*data++ - '0']++;
    }

    for (int i = 0; i < 10; i++) {
        printf("%d : %d\n", i, ary[i]);
    }

    return 0;
}
#endif