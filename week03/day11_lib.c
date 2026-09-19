#include "day11_lib.h"
int add(int x, int y) {
    return x + y;
}
int sub(int x, int y) {
    return x - y;
}
int mul(int x, int y) {
    return x * y;
}
int divi(int x, int y) {
    return x / y;
}
int mod(int x, int y) {
    return x % y;
}
void print1Darray(int* ary, int n) {// int* ary = 출력할 1차원의 배열의 첫 주소 , int n = 출력할 요소
    for (int i = 0; i < n; ++i) {
        printf("%d ", ary[i]);
    }
    printf("\n");
}