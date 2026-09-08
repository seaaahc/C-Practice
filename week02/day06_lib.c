#include "day06_lib.h"
#include "wrong_header.h"
//전부 다 시험에 나올듯...
extern int a; // extern을 사용할 때는 변수 초기화를 하면 안됨

void swap(int* ap, int* bp) {
	int temp;
	temp = *ap;
	*ap = *bp;
	*bp = temp;
}

void scanf_ary(int* ary, int n) {
	int amx = -1;// 나올 수 있는 값보다 더 작은것
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &ary[i]);
	}
}

void print_ary(int* ary, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", ary[i]);
	}
}

// 배열의 입력을 받는 작업과 max 찾는 작업을 동시에 하는 경우
// 좋지 않은 방법, 입력과 max 찾는 것을 분리하는 것이 좋음
int findmax_input(int* ary, int n) {
	int max = -1; // 입력 가능한 값보다 더 작은 값 또는 입력 가능한 최솟값
	for (int i = 0; i < n; ++i) {
		(void)scanf("%d", &ary[i]);
		ary[i] = max;
		if (max < ary[i]) max = ary[i];
	}
	return max;
}


// 배열에 값이 모두 저장되어 있는 경우
int findmax_ary(int* ary, int n) {
	int max = ary[0];
	for (int i = 1; i < n; i++) {
		if (max < ary[i]) {
			max = ary[i];
		}
	}
	return max;
}

int findmaxidx_ary(int* ary, int n) {
	int maxidx = 0;
	for (int i = 1; i < n; i++) {
		if (ary[maxidx] < ary[i]) {
			maxidx = i;
		}
	}
	return maxidx;
}

int findmin_input(int* ary, int n) {
	int min = 100;
	for (int i = 0; i < n; ++i) {
		(void)scanf("%d", &ary[i]);
		
		if (min > ary[i]) min = ary[i];
	}
	return min;
}

int findmin_ary(int* ary, int n) {
	int min = ary[0];
	for (int i = 1; i < n; i++) {
		if (min > ary[i]) {
			min = ary[i];
		}
	}
	return min;
}

int findminidx_ary(int* ary, int n) {
	int minidx = 0;
	for (int i = 1; i < n; i++) {
		if (ary[minidx] > ary[i]) {
			minidx = i;
		}
	}
	return minidx;
}

void find_min_max(int* ary, int n) {
	int min = ary[0];
	int max = ary[0];

	for (int i = 1; i < n; ++i) {
		if (max < ary[i]) {
			max = ary[i];
		}
		if (min > ary[i]) { 
			min = ary[i];
		}
	}
	printf("\nmax = %d, min = %d", max, min);
}

int sum_ary(int* ary, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += ary[i];
	}
	return sum;
}

int avg_ary(int* ary, int n) {
	return sum_ary(ary, n) / n;
}

// 분산 = 편차 제곱의 평균
// 편차 = (관찰값 - 평균)
double var_ary(int* ary, int n) {
	int a[5];
	double var = 0;
	int t = 0;
	int avg = avg_ary(ary, n);
	
	for (int i = 0; i < n; ++i) {
		a[i] = ary[i] - avg;
		a[i] *= a[i];
		t += a[i];
	}
	return (double)t / n;
}

// 표준편차 = 분산의 양의 제곱근
double std_ary(int* ary, int n) {
	double sum = 0.0;
	double avg;
	double variance = 0.0;

	// 1. 평균 구하기
	for (int i = 0; i < n; ++i) {
		sum += ary[i];
	}
	avg = sum / n;

	// 2. 분산 구하기
	for (int i = 0; i < n; ++i) {
		double diff = ary[i] - avg;
		variance += diff * diff;
	}
	variance /= n;

	// 3. 표준편차 = 분산의 제곱근
	return sqrt(variance);
}

// 정렬 - 오름차순
void sort_ary(int* ary, int n) {
	for (int i = 0; i < n - 1; ++i) { //n-1보다 n이 좀 더 효율적임
		for (int j = i + 1; j < n; ++j) {
			if (ary[i] > ary [j])
				swap(&ary[i], &ary[j]); //swap(ary + i, ary + j)
		}
	}
}

// 정렬 - 내림차순
void sort2_ary(int* ary, int n) {
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (ary[i] < ary[j])
				swap(&ary[i], &ary[j]);
		}
	}
}

void test08_3(void) {
	char ch1, ch2;
	(void)scanf("%c %c", &ch1, &ch2);
	printf("[%c%c]", ch1, ch2);
}

void test08_4(void) {
	int ch;
	ch = getchar();
	putchar(ch);
	putchar('\n');
}


// getchar 함수를 사용하여 n글자 미만의 글자를 입력받는 함수를 작성한다.
// n글자 이상의 글자를 입력해도 오류 없이 n-1개의 글자를 출력한다.


void mygets(char* str, int n) {
	int i = 0;
	char ch;

	while (i < n - 1) {
		ch = getchar();
		if (ch == '\n') {
			break;
		}
			
		str[i] = ch;
		i++;
	}
	str[i] = '\0';
}

// str 배열의 내용 중 소문자('a' ~ 'z')를 대문자('A' ~ 'Z')로 수정하는 함수를 작성한다.
// str에 전달 받은 값 그대로 반환한다.
char* to_upper(char* str) {
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] - ('a' - 'A');
		}
	}
	return str;
}