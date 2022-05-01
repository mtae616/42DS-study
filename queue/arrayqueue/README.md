## 큐, Queue

[##_Image|kage@bFNfVq/btrAUyVFCVG/gTg7jJqtSzFqS7wGh5Zb81/img.png|CDM|1.3|{"originWidth":300,"originHeight":196,"style":"alignCenter","caption":"출처 :&amp;nbsp;https://en.wikipedia.org/wiki/Queue_(abstract_data_type)"}_##]

큐(queue)는 컴퓨터 과학 분야에서 쓰이는 컴퓨터의 기본적인 자료 구조의 한가지로,  
먼저 집어 넣은 데이터가 먼저 나오는 FIFO(First In First Out)구조로 저장하는 형식을 말한다.  
영어 단어 queue는 표를 사러 일렬로 늘어선 사람들로 이루어진 줄을 말하기도 하며,  
먼저 줄을 선 사람이 먼저 나갈 수 있는 상황을 연상하면 된다.

<br />

나중에 집어 넣은 데이터가 먼저 나오는 스택과는 반대되는 개념이다.  
프린터의 출력 처리(I/O)나 윈도 시스템의 메시지 처리기,  
프로세스 관리 (CPU Schduling) 등 데이터가 입력된 시간 순서대로 처리해야 할 필요가 있는 상황에 이용된다.

<br />

배열리스트로 구현하는 queue는 선형 큐와, 환형(원형) 큐로 나눌 수 있다.  
선형 큐는 막대 모양으로 된 큐이다. 크기가 제한되어 있고 빈 공간을 사용하려면 모든 자료를 꺼내거나 자료를 한 칸씩 옮겨야 한다는 단점이 있다.

<br />

환형(원형) 큐는 선형 큐의 문제점  
(배열로 큐를 선언할시 큐의 삭제와 생성이 계속 일어났을때, 마지막 배열에 도달후 실제로는 데이터공간이 남아있지만 오버플로우가 발생)  
을 보완한 것이 환형 큐이다.  
front가 큐의 끝에 닿으면 큐의 맨 앞으로 자료를 보내어 원형으로 연결 하는 방식이다.

<br />

## 구현

- 생성
- 삽입 (enqueue)
- 반환 (dequeue)
- peek
- 삭제

## 선형 큐, ArrayQueue

### 생성

```C
typedef struct ArrayQueueNodeType
{
    char data;
} ArrayQueueNode;

typedef struct ArrayQueueType
{
    int maxElementCount;        // 최대 원소 개수
    int currentElementCount;    // 현재 원소 개수
    int front;                    // front index
    int rear;                    // rear index
    ArrayQueueNode *pElement;    // node
} ArrayQueue;
```

위와 같이 구조체를 생성한 후

```C
ArrayQueue* createArrayQueue(int maxElementCount) // Queue 생성
{
    ArrayQueue  *pQueue;

    if (maxElementCount < 0)
        return (NULL);
    pQueue = calloc(1, sizeof(ArrayQueue));
    pQueue->pElement = calloc(maxElementCount, sizeof(char)); // max 만큼 char 배열 생성
    pQueue->maxElementCount = maxElementCount;
    return (pQueue);
}
```

malloc 을 통해 만들어 줄 수 있게 한다.

### 삽입 enqueue

```C
int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element) // 삽입
{
    if (isArrayQueueFull(pQueue))
        return FALSE;
    if (pQueue->rear > pQueue->maxElementCount)
        return (FALSE);
    pQueue->pElement[pQueue->rear].data = element.data; // 무조건 끝에 들어간다.
    pQueue->rear += 1;
    pQueue->currentElementCount += 1;
    return TRUE;
}
```

FIFO구조로, 들어온 대로 나갈 수 있게 맨 끝에 붙여준다.

### 반환 dequeue

```C
ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue) // 반환
{
    ArrayQueueNode *temp = calloc(1, sizeof(ArrayQueueNode));

    if (isArrayQueueEmpty(pQueue))
        return NULL;
    temp->data = pQueue->pElement[pQueue->front].data; // 무조건 앞에 있는 게 반환된다.
    pQueue->pElement[pQueue->front].data = 0;
    pQueue->currentElementCount -= 1;
    pQueue->front += 1;
    return (temp);
}
```

마찬가지로 FIFO구조로 들어온 순서대로 반환한다.

## 환형(원형)큐 Circular queue

- 선형큐와 다른 점인 enqueue 와 Dequeue를 알아본다.

### 삽입 enqueue

```C
int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element) // 삽입
{
    if (isArrayQueueFull(pQueue))
        return FALSE;
    pQueue->pElement[pQueue->rear].data = element.data;
    pQueue->rear += 1;
    if (pQueue->rear >= pQueue->maxElementCount)
        pQueue->rear = (pQueue->rear) % pQueue->maxElementCount;
        // maxcount로 나눈 나머지 값이 새로운 index가 되게 한다.
    pQueue->currentElementCount += 1;
    return TRUE;
}
```

maxcount가 4라면, 현재 0번째 node가 없고, rear가 4이기 때문에
4 % maxcount == 0 으로 새롭게 0번째에 삽입되게 된다.

### 반환 dequeue

```C
ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue) // 반환
{
    ArrayQueueNode *temp = calloc(1, sizeof(ArrayQueueNode));

    if (isArrayQueueEmpty(pQueue))
        return NULL;
    temp->data = pQueue->pElement[pQueue->front].data;
    pQueue->pElement[pQueue->front].data = 0;
    pQueue->currentElementCount -= 1;
    pQueue->front += 1;
    if (pQueue->front >= pQueue->maxElementCount)
        pQueue->front = (pQueue->front) % pQueue->maxElementCount;
        // maxcount로 나눈 나머지 값이 새로운 Index가 되게 한다.
    return (temp);
}
```

마찬가지로 front값을 조정하여 새로 들어온 node(rear % maxcount)여도 front가 되지 않게
maxcount로 나눠준다.

### 삭제

```C
void deleteArrayQueue(ArrayQueue* pQueue)
{
    free(pQueue->pElement);
    free(pQueue);
    pQueue->pElement = NULL;
    pQueue = NULL;
}
```

char list를 삭제하고 queue를 삭제한 이후
주소 값에 Null 처리하여 댕글리포인터를 방지한다.
