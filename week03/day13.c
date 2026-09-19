#include "day13_lib.h"

#if 0
void input_data3(struct student3* stu, int n, int m) {
    for (int i = 0; i < n; ++i) {

        stu[i].id = atoi(strtok(NULL, " "));

        for (int j = 0; j < m ; ++j) {
            stu[i].score[j] = atoi(strtok(NULL, " "));
        }

        strcpy(stu[i].name, strtok(NULL, " \n")); 
    }
}

void print_data3(struct student3* stu, int n, int m) {
    char str[256];
    char* p = str;

    for (int i = 0; i < n; ++i) {
        p += sprintf(p, "%d ", stu[i].id);

        for (int j = 0; j < m; ++j) {
            p += sprintf(p, "%d ", stu[i].score[j]);
        }

        p += sprintf(p, "%s\n", stu[i].name);
    }
    printf("%s", str);
}


int main(void) {
    struct student3* stu;
    struct student3* pos;
    int* scores;
    int n = 0, m = 0;

    FILE* p_file;
    char str[256];

    p_file = fopen("student3.txt", "rt");
    if (p_file == NULL) {
        exit(1);
    }

    fgets(str, sizeof(str), p_file);
    n = atoi(strtok(str, " "));
    m = atoi(strtok(NULL, " "));

    stu = (struct student3*)malloc(sizeof(*stu) * n + sizeof(*scores) * n * m);

    if (stu == NULL) {
        exit(0);
    }

    // 구조체 배열 바로 뒤부터 점수 영역으로 사용
    scores = (int*)(stu + n);

    // 각 학생의 score 포인터 연결
    for (int i = 0; i < n; ++i) {
        pos = stu + i;
        pos->score = scores + i * m;
    }

    input_data3(stu, n, m);
    print_data3(stu, n, m);

    free(stu);
    stu = NULL;

    fclose(p_file);

    return 0;
}

#endif

#if 0
void input_data3(struct student3* stu, int n, int m) {
    struct student3* pos;
    int* scores;

    for (int i = 0; i < n; ++i) {
        pos = stu + i;
        scores = pos->score;

        
        // fgets를 사용해서 한줄로 입력 받고 토큰을 나눠서 숫자인 애들은 숫자로 바꾸고 
        (void)scanf("%d", &(pos->id));

        for (int j = 0; j < m; ++j) {
            (void)scanf("%d", scores + j);
        }

        (void)scanf("%s", pos->name);
    }
}

void print_data3(struct student3* stu, int n, int m) {
    struct student3* pos;
    int* scores;

    for (int i = 0; i < n; ++i) {
        pos = stu + i;
        scores = pos->score;

        printf("%d ", pos->id);

        for (int j = 0; j < m; ++j) {
            printf("%d ", scores[j]);
        }

        printf("%s\n", pos->name);
    }
}

int main(void) {
    struct student3* stu;
    struct student3* pos;
    int* scores;
    int n = 0, m = 0;
    char* token;


    FILE* p_file;
    char str[64];

    p_file = fopen("student2.txt", "rt");
    if (p_file != NULL) {
        fgets(str, 64, p_file);
    }
    n = atoi(strtok(str, " "));
    m = atoi(strtok(NULL, " "));
    printf("%d %d\n", n, m);

    //(void)freopen("student2.txt", "r", stdin);
    //(void)scanf("%d %d", &n, &m);

    stu = (struct student3*)malloc(sizeof(*stu) * n + sizeof(*scores) * n * m);

    if (stu == NULL) {
        exit(0);
    }

    // 구조체 배열 바로 뒤부터 점수 영역으로 사용
    scores = (int*)(stu + n);

    // 각 학생의 score 포인터 연결
    for (int i = 0; i < n; ++i) {
        pos = stu + i;
        pos->score = scores + i * m;
    }

    input_data3(stu, n, m);
    print_data3(stu, n, m);

    free(stu);
    stu = NULL;

    return 0;
}

#endif

#if 0
int main(void) {
    int a;
    int arr[5] = { 1,2,3,4,5 };
    a = (int)arr;
    printf("%d\n", ((int*)a)[2]);

    return 0;
}
#endif

#if 0
int func(int a, int b) {
    return a + b;
}
typedef int (*fp)(int, int);
int main(void) {
    int a = (int)func;
    printf("%d\n", func(3, 4));
    int b = ((fp)a) (3, 4); // 괄호를 해줘야 a가 함수 포인터가 됨
    printf("%d\n", b);

    return 0;
}
#endif

#if 0
int printAry(char(*ary)[10], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%s ", ary[i]);
    }
    printf("\n");
}

int main(void) {
    char fruit[][10] = { "apple", "melon", "cherry" };
    int (*fn) (char(*ary)[10], int size);
    fn = printAry;
    fn(fruit, sizeof(fruit) / sizeof(fruit[0]));
    return 0;
}
#endif

// 형 재정의
#if 0
int main(void) {
    int a;
    typedef int MYINT;
    MYINT b; // = int b;

    unsigned int c;
    typedef unsigned int UINT;
    UINT d; // = unsigned int d;

    int* p;
    typedef int* PINT;
    PINT p2; // = int* p2;
    
    typedef int i5arr[5]; // int 5개 배열
    i5arr x, y;

    typedef int (*i5arrp)[5]; //int 5개짜리 배열을 가리키는 포인터
    // typedef i5arr* i5arrp;

    return 0;
}
#endif

#if 0
int main(void) {
    unsigned int a = 0x12345678;
    printf("%x", a);
    return 0;
}
#endif

// 비트필드 구조체 특징 - 멤버가 주소를 가질 수 없음
#if 0
int main(void) {
    struct color1 a = { 0 };
    struct color2 b = { 0 };
    printf("%d %d\n", sizeof(a), sizeof(b));
    printf("%p %p\n", &a, &b);
    // printf("%p\n", &a.blue); // 비트 필드 멤버는 주소를 가져올 수 없음
    return 0;
}
#endif

#if 0
void input_data3(struct student3* stu, int n) {
    struct student3* sp;
    int* ip;
    for (int i = 0; i < n; i++) {
        sp = stu + i;
        ip = sp->score;
        (void)scanf("%d %d %d %d %s", &(sp->id), ip, ip + 1, ip + 2, sp->name);
    }
}
void print_data3(struct student3* stu, int n) {
    struct student3* sp;
    int* ip;
    for (int i = 0; i < n; i++) {
        sp = stu + i;
        ip = sp->score;
        printf("%d %d %d %d %s\n", sp->id, ip[0], ip[1], ip[2], sp->name);
    }
}
int main(void) {
    struct student3 stu[5] = { 0 };
    (void)freopen("student2.txt", "r", stdin);
    input_data3(stu, SIZE(stu));
    print_data3(stu, SIZE(stu));
    return 0;
}
#endif