#include "05_Queue.h"

// 여창훈님 코드 개선본
#if 01
typedef struct _nodeQ {
    int r;
    int c;
    struct _nodeQ* next;
} nodeQ;

typedef struct _queue_t {
    nodeQ* front;
    nodeQ* rear;
    nodeQ dummy;
} queue_t;

queue_t* init_Q(void) {
    queue_t* nq = (queue_t*)malloc(sizeof(queue_t));
    if (nq == NULL) return NULL;

    nq->dummy = (nodeQ){ 0 };

    nq->front = &nq->dummy;
    nq->rear = &nq->dummy;

    return nq;
}

int Enqueue(queue_t* q, nodeQ newdata) {
    nodeQ* node =  malloc(sizeof(nodeQ));
    if (node == NULL) {
        printf("Overflow!\n");
        return 0;
    }
    *node = newdata;

    q->rear->next = node;
    q->rear = node;
    
    return 1;
}

nodeQ* Dequeue(queue_t* q) {
    if (q->front->next == NULL) {
        printf("Underflow!\n");
        return NULL;
    }
    nodeQ* old = q->front->next;
    q->front->next = old->next;
    if (old == q->rear) q->rear = q->front;

    return old;
}

void printQ(queue_t* q) {
    int i = 0;
    for (nodeQ* p = q->front->next; p != NULL; p = p->next) {
        printf("%d : %d %d\n", i++, p->r, p->c);
    }
}

void free_Q(queue_t* q) {
    nodeQ* p = q->front->next;
    while (p != NULL) {
        nodeQ* next = p->next;
        free(p);
        p = next;
    }
    free(q);
}

int main(void) {
    queue_t* queue = NULL;
    char cmd;
    int n, s;
    int r, c;
    int i;

    (void)freopen("qdata.txt", "r", stdin);
    (void)scanf("%d %d", &s, &n);
    queue = init_Q();

    for (i = 0; i < n; ++i) {
        (void)scanf(" %c", &cmd);
        if (cmd == 'P') {
            (void)scanf("%d %d", &r, &c);
            if (!Enqueue(queue, (nodeQ) { r, c, NULL })) break;
        }
        else {
            nodeQ* popped = Dequeue(queue);
            if (!popped) break;
            free(popped);
        }
    }
    printQ(queue);
    free_Q(queue);
    queue = NULL;
    return 0;
}
#endif

// LinkedList로 구현하는 Queue
#if 0
typedef struct _nodeQ {
    int r;
    int c;
    struct _nodeQ* next;
}nodeQ;

typedef struct _queue_t {
    //nodeQ* data;
    nodeQ* front;
    nodeQ* rear;
}queue_t;

queue_t* init_Q(int size){
    queue_t* nq = NULL;
    nodeQ* first = NULL;
    nodeQ* prev = NULL;

    ++size;   // 더미 노드 1개

    nq = (queue_t*)calloc(1, sizeof(queue_t));
    if (nq == NULL)
        return NULL;

    for (int i = 0; i < size; ++i) {
        nodeQ* newnode = calloc(1, sizeof(nodeQ));
        if (newnode == NULL) {
            return NULL;
        }

        if (first == NULL) {
            first = newnode;
        }
        else {
            prev->next = newnode;
        }
        prev = newnode;
    }
    prev->next = first;

    nq->front = first;
    nq->rear = first;

    return nq;
}

//queue_t* init_Q(int size) {
//    queue_t* nq = NULL;
//    ++size;
//    nq = (queue_t*)calloc(1, sizeof(queue_t) + (size * sizeof(nodeQ)));
//    if (nq != NULL) {
//        nq->data = (nodeQ*)(nq + 1);
//        for (int i = 0; i < size - 1; ++i) {
//            nq->data[i].next = &nq->data[i + 1];
//        }
//        nq->data[size - 1].next = nq->data;
//
//        nq->front = nq->data;
//        nq->rear = nq->data;
//    }
//    return nq;
//}

int Enqueue(queue_t* q, nodeQ newdata) {
    nodeQ* next = q->rear->next;

    if (next == q->front) {
        printf("Overflow!\n");
        return 0;
    }
    q->rear->r = newdata.r;
    q->rear->c = newdata.c;

    q->rear = next;
    return 1;
}

nodeQ* Dequeue(queue_t* q) {
    if (q->front == q->rear) {
        printf("Underflow\n");
        return NULL;
    }
    nodeQ* data = q->front;
    q->front = q->front->next;

    return data;
}

void printQ(queue_t* q) {
    nodeQ* curr = q->front;
    while (curr != q->rear) {
        printf("%d %d\n", curr->r, curr->c);
        curr = curr->next;
    }
}
void Destroy_Q(queue_t* q){
    if (q == NULL)
        return;

    nodeQ* first = q->front;
    nodeQ* curr = first;

    do {
        nodeQ* next = curr->next;
        free(curr);
        curr = next;
    } while (curr != first);

    free(q);
}

int main(void) {
    queue_t* queue = NULL;
    nodeQ* data = NULL;
    char cmd;
    int n, s;
    int r, c;
    int i;

    (void)freopen("qdata.txt", "r", stdin);
    (void)scanf("%d %d", &s, &n);
    queue = init_Q(s);

    for (i = 0; i < n; ++i) {
        (void)scanf(" %c", &cmd);
        if (cmd == 'P') {
            (void)scanf("%d %d", &r, &c);
            if (!Enqueue(queue, (nodeQ) { r, c })) break;  //  Overflow인 경우 반복문 종료
        }
        else {
            if (!(data = Dequeue(queue))) break;
            printf("data : r=%d, c=%d\n", data->r, data->c);
        }
    }
    printf("%d\n", i);
    printQ(queue);
    Destroy_Q(queue);
    queue = NULL;

    return 0;
}
#endif

// 배열로 구현하는 원형 Queue
// rear+1을 큐의 최대 사이즈로 나누었을 때 front와 같다면 full
#if 0
typedef struct _nodeQ {
    int r;
    int c;
}nodeQ;

typedef struct _queue_t {
    nodeQ* data;
    int front;
    int rear;
    int size;
}queue_t;

queue_t* init_Q(int size) {
    queue_t* nq = NULL;
    ++size; // 더미노드를 위한 공간확보
    nq = (queue_t*)malloc(sizeof(queue_t) + (size * sizeof(nodeQ)));
    if (nq != NULL) {
        nq->data = (nodeQ*)(nq + 1);
        nq->front = 0;
        nq->rear = 0;
        nq->size = size;
    }
    return nq;
}

int Enqueue2(queue_t* q, nodeQ newdata) {
    int next = q->rear + 1
    if(next == q->size)


    if ((q->rear + 1) % q->size == q->front) {
        printf("Overflow!\n");
        return 0;
    }
    if (q->rear % 6 == 0) {
        int next = (q->rear + 1) % q->size;
        q->rear = next;
    }
    
    q->data[q->rear] = newdata;
    q->rear = q->rear + 1;
    return 1;
}

int Enqueue(queue_t* q, nodeQ newdata){
    int next = (q->rear + 1) % q->size;
    if (next == q->front){
        printf("Overflow!\n");
        return 0;
    }
    q->data[q->rear] = newdata;
    q->rear = next;
    return 1;
}

nodeQ* Dequeue(queue_t* q){
    if (q->front == q->rear)    {
        printf("Underflow\n");
        return NULL;
    }
    nodeQ* data = q->data + q->front;
    q->front = (q->front + 1) % q->size;
    return data;
}

void printQ(queue_t* q) {
    int i = q->front;
    while (i != q->rear) {
        printf("%d : %d %d\n", i, q->data[i].r, q->data[i].c);
        i = (i + 1) % q->size;
    }
}
int main(void) {
    queue_t* queue = NULL;
    nodeQ* data = NULL;
    char cmd;
    int n, s;
    int r, c;
    int i;

    (void)freopen("qdata.txt", "r", stdin);
    (void)scanf("%d %d", &s, &n);
    queue = init_Q(s);

    for (i = 0; i < n; ++i) {
        (void)scanf(" %c", &cmd);
        if (cmd == 'P') {
            (void)scanf("%d %d", &r, &c);
            if (!Enqueue2(queue, (nodeQ) { r, c })) break;  //  Overflow인 경우 반복문 종료
        }
        else {
            if (!(data = Dequeue(queue))) break;
            printf("data : r=%d, c=%d\n", data->r, data->c);
        }
    }
    printf("%d\n", i);
    printQ(queue);
    return 0;
}
#endif

// 배열로 구현하는 Simple Queue
#if 0

typedef struct _nodeSQ {
	int r;
	int c;
}nodeSQ;

// nodeSQ queue[MAX] = {0};
// int front, rear;
typedef struct _queue_t {
	nodeSQ* data; // 배열
	int size;
	int front;
	int rear;
}queue_t;

int Enqueue(queue_t* q, nodeSQ newdata) {
	if (q->rear >= q->size) {
		printf("Overflow!\n");
		return 0;
	}
	q->data[(q->rear)++] = newdata;
	return 1;
}

nodeSQ* Dequeue(queue_t* q){
	if (q->front >= q->rear) {
		printf("Underflow!\n");
		return NULL;
	}
	return &q->data[(q->front)++];
}

void printQ(queue_t* q) {
	for (int i = q->front; i < q->rear; ++i) {
		printf("%d : %d %d\n", i, q->data[i].r, q->data[i].c);
	}
}

queue_t* init_Q(int size) {
	queue_t* nq = NULL;
	nq = calloc(1, sizeof(queue_t) + size * sizeof(nodeSQ));
	if (nq == NULL) {
		exit(0);
	}
	// 안에 데이터들 초기화
	nq->data = (nodeSQ*)(nq + 1);
	nq->size = size;
	// front랑 rear는 켈록 하면서 0으로 초기화 되기 때문에 안씀
	return nq;
}

int main(void) {
	queue_t * queue = NULL;
	char cmd;
	int n, s;
	int r, c;

	(void)freopen("qdata.txt", "r", stdin);
	scanf("%d %d", &s, &n);
	queue = init_Q(s);

	for (int i = 0; i < n; i++) {
		char cmd;
		scanf(" %c", &cmd);
		if (cmd == 'P') {
			scanf("%d %d", &r, &c);
			if (!Enqueue(queue, (nodeSQ) { r, c })) break;
		}
		else {
			if (!Dequeue(queue)) break;
			printf("data : r%")
		}
	}
	printQ(queue);
	free(queue);
	queue = NULL;

	return 0;
}
#endif