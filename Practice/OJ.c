#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE(a) (sizeof(a)/sizeof((a)[0]))








// oj 에디터 - 배열
#if 0
#define MAX 1000

int main(void){
	char text[MAX] = { 0 };
	char cmd;
	char ch;

	scanf("%s", text);

	int cursor = strlen(text);

	int n;
	scanf("%d", &n);

	for (int k = 0; k < n; ++k){
		scanf(" %c", &cmd);

		if (cmd == 'L'){
			if (cursor > 0) {
				cursor--;
			}
		}
		else if (cmd == 'D'){
			if (cursor < strlen(text))
				cursor++;
		}
		else if (cmd == 'B'){
			if (cursor > 0)	{
				int len = strlen(text);
				for (int i = cursor - 1; i < len; ++i){
					text[i] = text[i + 1];
				}
				cursor--;
			}
		}
		else if (cmd == 'P'){
			scanf(" %c", &ch);

			int len = strlen(text);

			for (int i = len; i >= cursor; --i){
				text[i + 1] = text[i];
			}
			text[cursor] = ch;
			cursor++;
		}
	}

	printf("%s\n", text);

	return 0;// 1. head, tail 초기화
	void Initial(node * *head, node * *tail);

	// 2. 입력 문자열을 노드로 만들어 연결
	void MakeStr(node * tail, const char* str);

	// 3. 커서 왼쪽 이동
	void CursorLeft_L(node * *curr, node * head);

	// 4. 커서 오른쪽 이동
	void CursorRight_D(node * *curr, node * tail);

	// 5. 커서 왼쪽 문자 삭제
	void Backspace_B(node * curr, node * head);

	// 6. 커서 왼쪽에 문자 삽입
	void Pluschar_P(node * curr, char ch);

	// 7. 출력
	void PrintStr(node * head, node * tail);

	// 8. 전체 동적 메모리 해제
	void Destroy(node * *head);
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _node {
	char val;
	struct _node* next;
	struct _node* prev;
}node;

node* Init_Head(void) {
	node* head = (node*)calloc(1, sizeof(node));
	if (head == NULL) exit(0);
	head->val = 0;
	head->next = head;
	head->prev = head;

	return head;
}

void MakeStr(node* head, char* arr) {
	int l = strlen(arr);
	for (int i = 0; i < l; i++) {
		node* newnode = (node*)calloc(1, sizeof(node));
		if (newnode == NULL) exit(0);
		newnode->val = arr[i];
		newnode->prev = head->prev;
		newnode->next = head;
		head->prev->next = newnode;
		head->prev = newnode;
	}
}

void CursorLeft_L(node** curr, node* head) {
	if ((*curr) != head)
		*curr = (*curr)->prev;
}
void CursorRight_D(node** curr, node* head) {
	if ((*curr)->next != head)
		*curr = (*curr)->next;
}
void backspace_B(node** curr, node* head) {
	if ((*curr) != head) {
		(*curr)->prev->next = (*curr)->next;
		(*curr)->next->prev = (*curr)->prev;
		node* tmp = (*curr);
		(*curr) = (*curr)->prev;
		free(tmp);
	}
}
void Pluschar_P(node** curr, char ch) {
	node* newnode = (node*)calloc(1, sizeof(node));
	if (newnode == NULL) exit(0);
	newnode->val = ch;
	newnode->next = (*curr)->next;
	newnode->prev = (*curr);
	(*curr)->next->prev = newnode;
	(*curr)->next = newnode;
	(*curr) = (*curr)->next;
}

void calloc_calloc_calloc(node** head) {
	node* curr = (*head)->next;
	while (curr != *head) {
		node* next = curr->next;
		printf("%c", curr->val);
		free(curr);
		curr = next;
	}
	free(*head);
	*head = NULL;
}

int main(void) {
	char arr[100001] = { 0 };
	(void)scanf("%s", arr);
	
	node* head = Init_Head();
	MakeStr(head, arr);

	node* curr = head->prev;
	char cmd, ch;
	int n;
	(void)scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		(void)scanf(" %c", &cmd);
		if (cmd == 'L') {
			CursorLeft_L(&curr, head);
		}
		else if (cmd == 'D') {
			CursorRight_D(&curr, head);
		}
		else if (cmd == 'B') {
			backspace_B(&curr, head);
		}
		else if (cmd == 'P') {
			(void)scanf(" %c", &ch);
			Pluschar_P(&curr, ch);
		}
	}
	calloc_calloc_calloc(&head);

	return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node {
	char val;
	struct _node* next;
	struct _node* prev;
}node;

void print_str(node* head) {
	node* curr = head->next;
	while (curr != head) {
		printf("%c", curr->val);
		curr = curr->next;
	}
	printf("\n");
}

node* Init_Head(void) {
	node* head = (node*)calloc(1, sizeof(node));
	if (head == NULL) exit(0);
	head->val = 0;
	head->next = head;
	head->prev = head;

	return head;
}

void MakeStr(node* head, char* arr) {
	for (int i = 0; i < strlen(arr); i++) {
		node* newnode = (node*)calloc(1, sizeof(node));
		if (newnode == NULL) exit(0);
		newnode->val = arr[i];
		newnode->prev = head->prev;
		newnode->next = head;
		head->prev->next = newnode;
		head->prev = newnode;
	}
}

void CursorLeft_L(node** curr, node* head) {
	if (curr != head) {

		*curr = (*curr)->prev;
	}
}
void CursorRight_D(node** curr, node* head) {
	if ((*curr)->next != head) {
		*curr = (*curr)->next;
	}
}
void backspace_B(node** curr, node* head) {
	if (curr != head) {
		(*curr)->prev->next = (*curr)->next;
		(*curr)->next->prev = (*curr)->prev;
		node* tmp = (*curr);
		(*curr) = (*curr)->prev;
		free(tmp);
	}
}
void Pluschar_P(node** curr, char ch) {
	node* newnode = (node*)calloc(1, sizeof(node));
	if (newnode == NULL) exit(0);
	newnode->val = ch;
	newnode->next = (*curr)->next;
	newnode->prev = (*curr);
	(*curr)->next->prev = newnode;
	(*curr)->next = newnode;
	(*curr) = (*curr)->next;
}

void calloc_calloc_calloc(node** head) {
	node* curr = (*head)->next;
	while (curr != *head) {
		node* next = curr->next;
		free(curr);
		curr = next;
	}
	free(*head);
	*head = NULL;
}

int main(void) {
	char arr[100001] = { 0 };
	(void)scanf("%s", arr);
	int l = strlen(arr);
	node* head = Init_Head();
	MakeStr(head, arr);

	node* curr = head->prev;
	char cmd, ch;
	int n;
	(void)scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		(void)scanf(" %c", &cmd);
		if (cmd == 'L') {
			 CursorLeft_L(&curr, head);
		}
		else if (cmd == 'D') {
			CursorRight_D(&curr, head);
		}
		else if (cmd == 'B') {
			backspace_B(&curr, head);
		}
		else if (cmd == 'P') {
			(void)scanf(" %c", &ch);
			Pluschar_P(&curr, ch);
		}
	}
	print_str(head);
	calloc_calloc_calloc(&head);

	return 0;
}
#endif

// oj 에디터 - DLL
#if 0
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char data;
	struct node* prev;
	struct node* next;
} Node;

int main(void){
	char str[100000];
	scanf("%s", str);

	Node* head = (Node*)calloc(1, sizeof(Node));
	Node* tail = (Node*)calloc(1, sizeof(Node));

	head->next = tail;
	tail->prev = head;

	for (int i = 0; str[i] != '\0'; ++i) {
		Node* newnode = (Node*)calloc(1, sizeof(Node));
		newnode->data = str[i];

		newnode->prev = tail->prev;
		newnode->next = tail;

		tail->prev->next = newnode;
		tail->prev = newnode;
	}

	Node* cursor = tail;

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {

		char cmd;
		scanf(" %c", &cmd);

		if (cmd == 'L') {
			if (cursor->prev != head) {
				cursor = cursor->prev;
			}
		}
		else if (cmd == 'D') {
			if (cursor != tail) {
				cursor = cursor->next;
			}
		}
		else if (cmd == 'B') {
			if (cursor->prev != head) {
				Node* del = cursor->prev;
				del->prev->next = cursor;
				cursor->prev = del->prev;

				free(del);
			}
		}
		else if (cmd == 'P') {
			char ch;
			scanf(" %c", &ch);

			Node* newnode =	(Node*)calloc(1, sizeof(Node));

			newnode->data = ch;

			newnode->prev = cursor->prev;
			newnode->next = cursor;

			cursor->prev->next = newnode;
			cursor->prev = newnode;
		}
	}

	for (Node* p = head->next; p != tail; p = p->next) {
		printf("%c", p->data);
	}
	printf("\n");

	Node* p = head;

	while (p != NULL) {
		Node* next = p->next;
		free(p);
		p = next;
	}
	return 0;
}
#endif

// oj 2-6
#if 0
#include <stdio.h>

int main(void) {
	int arr[5][5] = { 0 };

	arr[0][0] = 1;
	arr[0][2] = 1;
	arr[0][4] = 1;

	for (int i = 1; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (j == 0) {
				arr[i][j] = arr[i - 1][j + 1];
			}
			else if (j == 4) {
				arr[i][j] = arr[i - 1][j - 1];
			}
			else {
				arr[i][j] = arr[i - 1][j - 1]
					+ arr[i - 1][j + 1];
			}
		}
	}

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
#endif

//oj 2-5
#if 0
int main(void) {
	int arr[4][3];
	int sum;

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 3; ++j) {
			(void)scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < 4; ++i) {
		sum = 0;

		for (int j = 0; j < 3; ++j) {
			sum += arr[i][j];
		}

		printf("%dclass : %d\n", i + 1, sum);
	}

	return 0;
}
#endif

//oj 2-4
#if 0
#include <stdio.h>

int main(void) {
	int arr[4][3] = {
		{3,5,9},
		{2,11,5},
		{8,30,10},
		{22,5,1}
	};

	int sum = 0;

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 3; ++j) {
			printf("%d ", arr[i][j]);
			sum += arr[i][j];
		}
		printf("\n");
	}

	printf("%d\n", sum);

	return 0;
}
#endif

//oj 2-3
#if 0
#include <stdio.h>

int main(void) {
	int a, b;
	int arr[10];

	(void)scanf("%d %d", &a, &b);

	arr[0] = a;
	arr[1] = b;

	for (int i = 2; i < 10; ++i) {
		arr[i] = (arr[i - 2] + arr[i - 1]) % 10;
	}

	for (int i = 0; i < 10; ++i) {
		printf("%d ", arr[i]);
	}

	return 0;
}
#endif

//oj 2-2
#if 0
#include <stdio.h>

int main(void) {
	int score;
	int count[11] = { 0 };

	while (1) {
		(void)scanf("%d", &score);

		if (score == 0) {
			break;
		}

		count[score / 10]++;
	}

	for (int i = 10; i >= 0; --i) {
		if (count[i] > 0) {
			printf("%d : %d person\n", i * 10, count[i]);
		}
	}

	return 0;
}
#endif

// oj 2-1
#if 0
int main(void) {
	int count[10] = { 0 };
	int i;
	int num;
	for (i = 0; i < 10; ++i) {
		(void)scanf(" %d", &num);
		count[num]++;
	}
	for (i = 1; i <= 6; ++i) {
		printf("%d : %d\n", i, count[i]);
	}
}
#endif

// oj 2-1 // static 한번 써보고 싶었어요...
#if 0
static int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
int main(void) {
	int arr[10];
	int count[6];
	for (int i = 0; i < 10; ++i) {
		(void)scanf(" %d", &arr[i]);
		if (arr[i] == 1) {
			a++;
		}
		if (arr[i] == 2) {
			b++;
		}
		if (arr[i] == 3) {
			c++;
		}
		if (arr[i] == 4) {
			d++;
		}
		if (arr[i] == 5) {
			e++;
		}
		if (arr[i] == 6) {
			f++;
		}
	}
	printf("1 : %d\n", a);
	printf("2 : %d\n", b);
	printf("3 : %d\n", c);
	printf("4 : %d\n", d);
	printf("5 : %d\n", e);
	printf("6 : %d\n", f);

	return 0;
}
#endif

// oj 회전초밥  (못함...)
#if 0
int main(void) {
	int N, d, k, c;


	return 0;
}
#endif

// oj 1-10
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n;
	int arr[20];
	int temp;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}
#endif

// oj 1-9
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num;
	int arr[100];
	int count = 0;

	while (1)
	{
		scanf("%d", &num);

		if (num == 0)
		{
			break;
		}

		if (num % 2 == 0)
		{
			arr[count] = num / 2;
		}
		else
		{
			arr[count] = num * 2;
		}
		count++;
	}

	printf("%d\n", count);

	for (int i = 0; i < count; i++)
	{
		printf("%d", arr[i]);

		if (i < count - 1)
		{
			printf(" ");
		}
	}

	return 0;
}
#endif

// oj 1-8
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num;
	int count = 0;
	int sum = 0;
	double avg = 0.0;

	while (1)
	{
		scanf("%d", &num);

		if (num == 0)
		{
			break;
		}

		if (num % 5 == 0)
		{
			count++;
			sum += num;
		}
	}

	if (count != 0)
	{
		avg = (double)sum / count;
	}

	printf("Multiples of 5 : %d\n", count);
	printf("sum : %d\n", sum);
	printf("avg : %.1f\n", avg);

	return 0;
}
#endif

// oj 1-7
#if 0
int main(void) {
	signed int arr[100];
	signed int max = 0, min = 0;


	for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); ++i) {

		(void)scanf("%d", &arr[i]);
		if (arr[i] == 999) {
			break;
		}
		if (i == 0) {
			max = arr[i];
			min = arr[i];
		}

		if (max < arr[i]) {
			max = arr[i];
		}
		else if (min > arr[i]) {
			min = arr[i];
		}
	}

	printf("max : %d\nmin : %d", max, min);
	return 0;
}
#endif

// oj 1-6
#if 0
int main(void) {
	char arr[6] = { 'J', 'U', 'N', 'G', 'O', 'L' };
	char ch;

	(void)scanf("%c", &ch);
	for (int i = 0; i < sizeof(arr); ++i) {
		if (arr[i] == ch) {
			printf("%d", i);
			return 0;
		}
	}
	printf("none");
	return 0;
}
#endif

// oj 1-5
#if 0
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
int main(void) {
	float arr[6];
	float sum = 0.0;

	for (int i = 0; i < SIZE(arr); ++i) {
		(void)scanf(" %f", &arr[i]);
		sum += arr[i];
	}

	printf("%.1f", sum / SIZE(arr));

	return 0;
}
#endif

// oj 1-4
#if 0
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
int main(void) {
	int arr[100];
	int i;

	for (i = 0; i < SIZE(arr); ++i) {
		(void)scanf(" %d", &arr[i]);
		if (arr[i] == -1) {
			break;
		}
	}
	if (i < 3) {
		for (int j = 0; j < i; ++j) {
			printf("%d ", arr[j]);
		}
	}
	else {
		for (int j = i - 3; j < i; ++j) {
			printf("%d ", arr[j]);
		}
	}

	return 0;
}
#endif

// oj 1-3
#if 0
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
int main(void) {
	int arr[10];
	int even = 0, odd = 0;
	for (int i = 0; i < SIZE(arr); ++i) {
		(void)scanf(" %d", &arr[i]);
	}

	for (int i = 0; i < SIZE(arr); i = i + 2) {
		odd += arr[i];
	}

	for (int i = 1; i < SIZE(arr); i = i + 2) {
		even += arr[i];
	}

	printf("odd : %d\neven : %d", odd, even);
	return 0;
}
#endif

// oj 1-2
#if 0
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

int main(void) {
	int arr[5];
	int sum = 0;
	for (int i = 0; i < SIZE(arr); ++i) {
		(void)scanf(" %d", &arr[i]);
	}
	for (int j = 0; j < SIZE(arr); j = j + 2) {
		sum += arr[j];
	}
	printf("%d", sum);
	return 0;
}
#endif

// oj 1-1
#if 0
int main(void) {
	char arr[10];

	for (int i = 0; i < sizeof(arr); ++i) {
		(void)scanf(" %c", &arr[i]);
	}

	for (int j = sizeof(arr) - 1; j >= 0; --j) {
		printf("%c ", arr[j]);
	}

	return 0;
}
#endif