#include "day11_lib.h"

// 내가 짠 거....
#if 0
int main(void) {
    char* arr[5] = { 0 };
    char temp[5][80] = { 0 };

    for (int i = 0; i < SIZE(arr); ++i) {
        gets(temp[i]);
    }

    int total = 0;
    for (int i = 0; i < SIZE(arr); ++i) {
        total += strlen(temp[i]) + 1;
    }

    char* data = calloc(total, sizeof(char));
    if (data == NULL) {
        exit(0);
    }
    char* p = data;

    for (int i = 0; i < SIZE(arr); ++i) {
        arr[i] = p;

        strcpy(arr[i], temp[i]);
        p += strlen(temp[i]) + 1;
    }

    for (int i = 0; i < SIZE(arr); ++i) {
        printf("%s\n", arr[i]);
    }

    free(data);
    data = NULL;
}
#endif

// 강사님이 strcpy 쓰고 싶지 않아서 이렇게
#if 0
int main(void) {
    char* arr[5] = { 0 };
    int pos = 0;

    arr[0] = (char*)malloc(5 * 80);
    if (arr[0] == NULL) { exit(0); }
    gets(arr[0]);

    arr[1] = arr[0] + strlen(arr[0]) + 1;
    gets(arr[1]);

    arr[2] = arr[1] + strlen(arr[1]) + 1;
    gets(arr[2]);

    arr[3] = arr[2] + strlen(arr[2]) + 1;
    gets(arr[3]);

    arr[4] = arr[3] + strlen(arr[3]) + 1;
    gets(arr[4]);

    for (int i = 0; i < 5; ++i) {
        printf("%s\n", arr[i]);
    }
    free(arr[0]);
    arr[0] = 0;

    return 0;
}
#endif

// 가변 배열
#if 0
#define MAX (20)

int main(void) {
    char* arr[5] = { 0 };
    char temp[80] = { 0 };

    for (int i = 0; i < SIZE(arr); ++i) {
        gets(temp);
        arr[i] = (char*)calloc(strlen(temp) + 1, sizeof(char));
        if (arr[i] == NULL) {
            exit(0);
        }
        strcpy(arr[i], temp);
    }
    for (int i = 0; i < SIZE(arr); ++i) {
        printf("%s\n", arr[i]);
    }
    for (int i = 0; i < SIZE(arr); ++i) {
        free(arr[i]);
        arr[i] = NULL;
    }

    return 0;
}
#endif

// char 배열 만들기
#if 0
#define MAX (20)

int main(void) {
    char* str = NULL;

    str = (char*)malloc(MAX * sizeof(*str));
    if (str == NULL) {
        exit(0);
    }
    (void)scanf("%s", str);
    printf("%s\n", str);

    free(str);
    str = NULL;

    return 0;
}
#endif

// 2차원 배열 만들기
#if 0
#define R (3)
#define C (4)
void print2Darray(int(*score)[4], int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            (void)printf("%3d ", score[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int(*arr)[C] = NULL;
    //arr = malloc(sizeof(*arr) * 12);
    arr = (int(*)[C])calloc(R, sizeof(*arr));
    if (arr == NULL) {
        // 리소스 해지 위치
        exit(0);
    }
    for (int i = 0; i < R * C; ++i) {
        ((int*)arr)[i] += i;
    }
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            arr[i][j] = C * i + j;
        }
    }
    print2Darray(arr, R, C);
    free(arr);
    arr = NULL;

    return 0;
}
#endif

// 12개 int를 요소로 하는 int 배열 만들기
#if 0
#define MAX (12)
int main(void) {
    int* arr;
    //arr = malloc(sizeof(*arr) * 12);
    arr = (int*)calloc(MAX, sizeof(*arr));
    if (arr == NULL) {
        // 리소스 해지 위치
        exit(0);
    }
    for (int i = 0; i < MAX; ++i) {
        arr[i] += i;
    }
    print1Darray(arr, MAX);
    
    free(arr);
    arr = NULL;

    return 0;
}
#endif

// 동적 메모리 할당 - malloc, calloc, realloc
// 동적 메모리를 할당하겠다 == heap 메모리를 쓰겠다
#if 0
int arr[1000][1000] = { 0 };
int main(void) {
    int* a = 0;
    int* b = 0;
    int* c = 0;
    a = (int*)malloc(80 * sizeof(*a));
    if (a == NULL) {
        return -1;
    }
    b = (int*)calloc(80, sizeof(*a));
    if (b == NULL) {
        return -1;
    }
    c = (int*)realloc(NULL, 80); // 주소를 안주고 80이라고 쓰면 malloc이랑 똑같음 << 무슨 소리임?
    if (c == NULL) {
        return -1;
    }
    
    printf("%d %d %d", *a, *b, *c);
    print1Darray(a, 10);
    print1Darray(b, 10);
    print1Darray(c, 10);
    free(a); free(b); free(c);
    a = NULL;
    free(a); // free 두 번하면 오류나지만 널값을 넣어놓으면 ㄱㅊ음 << 왜?

    return 0;
}
#endif

#if 0
int arr[1000][1000] = { 0 }; // 전역도 가능하지만 한계가 있음
int main(void) {
    int arr[1000][1000] = { 0 }; // 불가능
    printf("%.1fM\n", sizeof(arr)/1024/(double)1024);
    return 0;
}
#endif

#if 0
int comp2D(const void* a, const void* b) {
    const int* rowA = (const int*)a;
    const int* rowB = (const int*)b;

    for (int i = 0; i < 3; ++i) {
        if (rowA[i] != rowB[i]) {
            return (rowA[i] > rowB[i]) ? 1 : -1;
        }
    }
    return 0;
}
/* 강사님이라면 이렇게 하실거라고...
int comp2D(const void* a, const void* b){
     int *rowA = *(int(*)[3]) a;
     int *rowB = *(int(*)[3]) b;

     for(int i=0; i<3; i++){
          if(rowA[i] > rowB[i]){
               return 1;
           }
          if (rowA[i] < rowB[i]){
               return -1;
          }
     }
     return 0;
}*/

int compare2D(const void* a, const void* b) {
    int* x = (int*)a;
    int* y = (int*)b;
    for (int i = 0; i < 3; ++i) {
        if (*(x + i) > *(y + i)) return 1;
        if (*(x + i) < *(y + i)) return -1;
    }
    return 0;
}

void print2Darray(int(*score)[3], int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            (void)printf("%3d ", score[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print2DarrayP(int** score, int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            printf("%3d ", score[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int comparr1(const void* a, const void* b) {
    int ia = (*(int (*)[3])a)[0];
    int ib = (*(int (*)[3])b)[0];

    if (ia > ib) return 1;
    if (ia < ib) return -1;
    return 0;
}

int comparr2(const void* a, const void* b) {
    int ia = ((int*)a)[0];
    int ib = ((int*)b)[0];

    if (ia > ib) return 1;
    if (ia < ib) return -1;
    return 0;
}

int comparr3(const void* a, const void* b) {
    int ia = **(int**)a;
    int ib = **(int**)b;

    if (ia > ib) return 1;
    if (ia < ib) return -1;
    return 0;
}

int main(void) {
    int arr[5][3] = {
        {3, 5, 1},
        {1, 4, 3},
        {7, 1, 5},
        {3, 2, 2},
        {5, 3, 4}
    };

    int* parr[5] = { arr[0], arr[1], arr[2], arr[3], arr[4] };

    print2Darray(arr, SIZE(arr), SIZE(arr[0]));

    qsort(arr, SIZE(arr), sizeof(*arr), comparr1);
    print2Darray(arr, SIZE(arr), SIZE(arr[0]));

    qsort(arr, SIZE(arr), sizeof(*arr), comparr2);
    print2Darray(arr, SIZE(arr), SIZE(arr[0]));

    qsort(parr, SIZE(parr), sizeof(*parr), comparr3);
    print2DarrayP(parr, SIZE(parr), SIZE(arr[0]));

    return 0;
}
#endif

#if 0
typedef struct {
    char* name;
    char* sign;
    int(*func)(int, int);
}op_t;

void print_arr(op_t* p, int menu_size) {
    for (int i = 1; i < menu_size; ++i) {
        printf("%d. %s \n", i, p[i].name);
    }
    printf("%d. %s \n", 0, p[0].name);
    printf("\n");
}
int get_menu(op_t* name, int n) {
    int id = 0;
    print_arr(name, n);
    (void)scanf("%d", &id);

    return id;
}
int main(void) {
    int a, b, id;
    const int menu_size = 6;
    op_t menu[6] = {
        {"종료", "종료", NULL},
        {"덧셈","+", sum},
        {"뺄셈","-", sub2},
        {"곱셈","*", mul2},
        {"나눗셈(몫)","/", divd},
        {"나눗셈(나머지)","%", mod},
    };

    op_t* op_ptr = NULL;


    while (id = getmenu(menu, menu_size)) {
        op_ptr = &menu[id];
        printf("두 정수 입력 : ");
        (void)scanf("%d %d", &a, &b);

        printf("결과는 %d %s %d = %d입니다.\n", a, op_ptr->sign, b, op_ptr->func(a, b));
    }
    printf("프로그램을 종료합니다.\n");

    return 0;
}
#endif

#if 0
int get_menu(void) {
    int menu;
    while (1) {
        printf("1. 덧셈\n");
        printf("2. 뺄셈\n");
        printf("3. 곱셈\n");
        printf("4. 나눗셈(몫)\n");
        printf("5. 나눗셈(나머지)\n");
        printf("0. 종료\n");

        printf("메뉴 선택 : ");
        (void)scanf("%d", &menu);
        return menu;
    }
}

int main(void) {
    int menu;
    int x, y;

    int (*func[6])(int, int) = { 0, sum, sub2, mul2, divd, mod };

    while (menu = get_menu()) {
        printf("두 정수 입력 : ");
        (void)scanf("%d %d", &x, &y);
        printf("결과 : %d\n\n", func[menu](x, y));
    }

    return 0;
}
#endif