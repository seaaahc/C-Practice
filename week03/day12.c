#include "day12_lib.h"

// malloc만 사용
#if 01
#define N (5)
int main(void){
    char* arr[N] = { 0 };

    char* s = (char*)malloc(SIZE(arr) * 80);
    if (s == NULL) {
        exit(0);
    }

    for (int i = 0; i < 5; ++i) {
        arr[i] = s;
        gets(s);
        s += strlen(s) + 1;
    }

    for (int i = 0; i < N; ++i) {
        printf("%s\n", arr[i]);
    }

    free(arr[0]);
    arr[0] = NULL;

    return 0;
}
#endif

// realloc까지 사용
#if 0
int main(void){
    char* arr = (char*)malloc(5 * 80);
    if (arr == NULL) {
        exit(0);
    }

    char* pos = arr;

    // 문자열 5개 입력
    for (int i = 0; i < 5; ++i) {
        gets(pos);

        // 다음 문자열을 저장할 위치로 이동
        pos += strlen(pos) + 1;
    }

    // 실제 사용한 크기 계산
    size_t used = pos - arr;

    // 실제 사용한 만큼으로 축소
    char* p = realloc(arr, used);

    if (p == NULL) {
        free(arr);
        return 1;
    }

    arr = p;

    // 출력할 때 다시 처음부터 시작
    pos = arr;

    for (int i = 0; i < 5; ++i) {
        printf("%s\n", pos);

        // 다음 문자열로 이동
        pos += strlen(pos) + 1;
    }

    free(arr);
    arr = NULL;

    return 0;
}

#endif