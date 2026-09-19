#include "day12_lib.h"

// 다양한 구조체 배열의 입력함수
#if 0
void input_data(struct student2 *stu, int size) {
	for (int i = 0; i < size; ++i) {
		struct student2* p = stu + i;
		(void)scanf("%d %d %d %d %s", &p->id, &p->scores[0], &p->scores[1], &p->scores[2], p->name);
	}
}
void input_data(struct student2* a, int n) {
	struct student2 * now = NULL;
	for (int i = 0; i < n; ++i) {
		now = (a + i);
		(void)scanf("%d", &(now->id));
		for (int j = 0; j < now )
	}
}


void print_data2(struct student2 *stu, int size) {
	for (int i = 0; i < size; ++i) {
		struct student2* p = stu + i;
		printf("%d %d %d %d %s\n", p->id, p->scores[0], p->scores[1], p->scores[2], p->name);
	}
}

int main(void) {
	struct student2 stu[5] = { 0 };
	(void)freopen("student.txt", "r", stdin);

	input_data(stu, SIZE(stu));
	print_data2(stu, SIZE(stu));
	
	return 0;
}
#endif

#if 0
int main(void) {
	struct student s1 = { {20, 175.5, "홍길동", "010-1234-5678"}, 1, 4.3 };
	struct student* p = &s1;
	struct student arr[3] = { { {20, 175.5, "홍길동", "010-1234-5678"}, 1, 4.3 } };
	arr[1] = arr[2] = arr[0]; // arr[0]에 있는 걸 arr[1], arr[2]에 넣음
	struct student *parr = arr;

	printf("%d %.1f %s %s %d %.1f\n", s1.pf.age, s1.pf.height, s1.pf.name, s1.pf.phone, s1.num, s1.grade);

	struct profile t = s1.pf;
	printf("%d %.1f %s %s %d %.1f\n", t.age, t.height, t.name, t.phone, s1.num, s1.grade);

	struct profile* t2 = &s1.pf;
	printf("%d %.1f %s %s %d %.1f\n", t2->age, t2->height, t2->name, t2->phone, p->num, p->grade);
	
	for (int i = 0; i < 3; i++) {
		struct profile* t3 = &arr[i].pf;
		char* t4 = t3->name;
		printf("%d %.1f %s %s %d %.1f\n", t3->age, t3->height, t3->name, t3->phone, arr[i].num, arr[i].grade);
	}

	for (int i = 0; i < 3; i++) {
		printf("%d %.1f %s %s %d %.1f\n", (parr + i)->pf.age, (parr + i)->pf.height, (parr + i)->pf.name, (parr + i)->pf.phone, (parr + i)->num, (parr + i)->grade);
	}
}
#endif

#if 0
int main(void) {
	struct student st = { 3, 4.5 };
	struct student* p = &st;
	struct student st2 = *p;
	printf("%d %.1f\n", st.num, st.grade);
	printf("%d %.1f\n", p->num, p->grade);
	printf("%d %.1f\n", st2.num, st2.grade);
	printf("%d %.1f\n", (*p).num, (*p).grade); //*보다 .이 우선순위가 더 높음

	return 0;
}
#endif