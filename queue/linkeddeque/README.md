## 큐 Queue, 덱 Deque

<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2F0CxNF%2FbtrAVs8YlF3%2FLBuC0ElZYn2s9v2dwekAi0%2Fimg.png" />

<br />

**덱**(deque, "deck"과 발음이 같음 ← double-ended queue)은 양쪽 끝에서 삽입과 삭제가 모두 가능한 자료 구조의 한 형태이다.

두 개의 포인터를 사용하여, 양쪽에서 삭제와 삽입을 발생시킬 수 있다. 큐와 스택을 합친 형태로 생각할 수 있다.

## 큐 구현 Queue using linekd list

- 생성
- 삽입 (enqueue)
- 반환 (dequeue)
- peek
- 삭제

### 생성

```C
typedef struct QueueNodeType
{
	char data;
	struct QueueNodeType* pRLink;
} QueueNode;

typedef struct LinkedQueueType
{
	int currentElementCount;	// 현재 원소 개수
	QueueNode* pFrontNode;		// Front node
	QueueNode* pRearNode;		// Rear node
} LinkedQueue;

LinkedQueue* createLinkedQueue()
{
    LinkedQueue *temp;

    temp = calloc(1, sizeof(LinkedQueue));
    return (temp);
}
```

구조체를 선언하고 calloc을 통해 0으로 초기화한다.

### 삽입 Enqueue

```C
int insertLQ(LinkedQueue* pQueue, QueueNode element)
{
    QueueNode *temp = calloc(1, sizeof(QueueNode));

    *temp = element;
    if (isLinkedQueueEmpty(pQueue)) // node가 없을 때
    {
        pQueue->pFrontNode = temp; // front 는 자기 자신
        pQueue->pRearNode = temp; // rear 는 자기 자신
        pQueue->currentElementCount += 1;
        return (TRUE);
    }
    pQueue->pRearNode->pRLink = temp; // rear의 다음을 temp 로 지정하고
    pQueue->pRearNode = temp; // temp 를 Rear 로 둔다.
    pQueue->currentElementCount += 1;
    return (TRUE);
}
```

node가 이미 있었는지에 대한 여부를 관리하여
FIFO 구조로, 무조건 뒤에 붙여준다.

### 반환 Dequeue

```C
QueueNode* deleteLQ(LinkedQueue* pQueue)
{
    QueueNode   *temp = calloc(1, sizeof(QueueNode));

    temp = pQueue->pFrontNode;
    if (!temp) // node가 없었을 때
        return (NULL);
    if (pQueue->currentElementCount == 1) // 반환할 node가 딱 1개일 때
    {
        pQueue->pFrontNode = NULL;
        pQueue->pRearNode = NULL;
        pQueue->currentElementCount -= 1;
        return (temp);
    }
    pQueue->pFrontNode = pQueue->pFrontNode->pRLink; // front node 갱신
    temp->pRLink = NULL;
    pQueue->currentElementCount -= 1;
    return (temp);
}
```

node가 없었을 때, 1개만 있었을 때에 대한 조건을 구분하여
가장 먼저 들어온 Node를 반환해야 한다.

### peek

```C
QueueNode* peekLQ(LinkedQueue* pQueue) // 가장 첫 Node 반환
{
    return (pQueue->pFrontNode);
}
```

### 삭제

```C
void deleteLinkedQueue(LinkedQueue* pQueue) // 삭제
{
    QueueNode   *curr;
    QueueNode   *next;

    curr = pQueue->pFrontNode;
    while(curr) // 내부 모든 node 삭제
    {
        next = curr->pRLink;
        free(curr);
        curr = next;
    }
    free(pQueue); // queue 삭제
    pQueue = NULL;
}
```

## 덱 구현 Deque using linked list

- 생성
- front 삽입 (enqueue)
- rear 삽입 (enqueue)
- front 반환 (dequeue)
- rear 반환 (dequeue)
- peek
- 삭제

### 생성

```C
typedef struct DequeNodeType
{
	char data;
	struct DequeNodeType* pRLink;
	struct DequeNodeType* pLLink;
} DequeNode;

typedef struct LinkedDequeType
{
	int currentElementCount;	// 현재 원소 개수
	DequeNode* pFrontNode;		// Front node
	DequeNode* pRearNode;		// Rear node
} LinkedDeque;


LinkedDeque* createLinkedDeque()
{
    LinkedDeque *temp;

    temp = calloc(1, sizeof(LinkedDeque));
    return (temp);
}
```

Deque는 front와 rear 모두에서 dequeue enqueue가 가능하다.
따라서 pRlink (next), PLLink (prev)를 구현한다.

### Front 삽입 Enqueue

```C
int insertFrontLD(LinkedDeque* pDeque, DequeNode element) // front 삽입
{
    DequeNode   *temp = calloc(1, sizeof(DequeNode));

    *temp = element;
    if (isLinkedDequeEmpty(pDeque)) // node가 없다면
    {
        pDeque->pFrontNode = temp; // front 는 자기 자신이다.
        pDeque->pRearNode = temp; // rear도 자기 자신이다.
        pDeque->currentElementCount += 1;
        return (TRUE);
    }
    pDeque->pFrontNode->pLLink = temp; // front의 왼편에 새로 들어온 node 설정
    temp->pRLink = pDeque->pFrontNode; // front를 자기 다음으로 설정
    pDeque->pFrontNode = temp; // front 갱신
    pDeque->currentElementCount += 1;
    return (TRUE);
}
```

무조건 Rear에만 삽입됐던 일반적인 queue와는 다른 모습이다.

### Rear 삽입 Enqueue

```C
int insertRearLD(LinkedDeque* pDeque, DequeNode element) // rear 삽입
{
    DequeNode *temp = calloc(1, sizeof(DequeNode));

    *temp = element;
    if (isLinkedDequeEmpty(pDeque)) // node가 없다면
    {
        pDeque->pFrontNode = temp; // front는 자기 자신이다.
        pDeque->pRearNode = temp; // Rear도 자기 자신이다.
        pDeque->currentElementCount += 1;
        return (TRUE);
    }
    pDeque->pRearNode->pRLink = temp; // rear의 오른편에 새로 들어온 node 설정
    temp->pLLink = pDeque->pRearNode; // rear를 자기 전으로 설정
    pDeque->pRearNode = temp; // rear 갱신
    pDeque->currentElementCount += 1;
    return (TRUE);
}
```

일반 queue와 다른 점은 pRLink와 pLLink관리를 하여야 된다는 점이다.

### Front 반환 dequeue

```C
DequeNode* deleteFrontLD(LinkedDeque* pDeque) // Front 반환
{
    DequeNode   *temp;

    temp = pDeque->pFrontNode;
    if (!temp) // temp가 없는 경우
        return NULL;
    if (pDeque->currentElementCount == 1) // node가 1개만 있다면
    {
        pDeque->pFrontNode = NULL;
        pDeque->pRearNode = NULL; // front와 Rear를 자기자신으로 설정했기 때문에 모두 해제한다.
        pDeque->currentElementCount -= 1;
        return (temp);
    }
    pDeque->pFrontNode = temp->pRLink; // 앞에서 반환되기 때문에 새로운 front는 front 오른편으로 설정한다.
    pDeque->pFrontNode->pLLink = NULL; // front의 왼편을 해제한다.
    temp->pRLink = NULL;
    pDeque->currentElementCount -= 1;
    return (temp);
}
```

마찬가지로 pRLink와 pLLink에 대한 관리에 유의해야 한다.

### Rear 반환 dequeue

```C
DequeNode* deleteRearLD(LinkedDeque* pDeque) // rear 반환
{
    DequeNode   *temp;

    temp = pDeque->pRearNode;
    if (!temp) // temp가 없는 경우
        return NULL;
    if (pDeque->currentElementCount == 1) // node가 1개만 있다면
    {
        pDeque->pFrontNode = NULL;
        pDeque->pRearNode = NULL; // front와 Rear를 자기자신으로 설정했기 때문에 모두 해제한다.
        pDeque->currentElementCount -= 1;
        return (temp);
    }
    pDeque->pRearNode = temp->pLLink; // 뒤에서 반환되기 때문에 새로운 Rear는 Rear의 왼편이다.
    pDeque->pRearNode->pRLink = NULL; // Rear의 오른편을 해제한다.
    temp->pLLink = NULL;
    pDeque->currentElementCount -= 1;
    return (temp);
}
```

무조건 front에서 반환됐던 일반 queue와는 다른 모습이다.

### peek fron front and rear

```C
DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
    return (pDeque->pFrontNode);
}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
    return (pDeque->pRearNode);
}
```

구조체에서 각자 Front와 Rear로 저장하고 있어 반환할 수 있다.
