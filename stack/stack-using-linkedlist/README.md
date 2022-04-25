# 스택 Stack

<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fn7UYN%2FbtrAlgH9CF5%2F5b0ZwuSvvGkbEIokYqB4t1%2Fimg.png" />

<br />

스택(stack)의 접근은 목록의 끝에서만 일어난다. 
끝먼저내기 목록(Pushdown list)이라고도 한다.

<br />

스택은 한 쪽 끝에서만 자료를 넣거나 뺄 수 있는 선형 구조(LIFO - Last In First Out)으로 되어 있다.
자료를 넣는 것을 '밀어넣는다' 하여 푸쉬(push)라고 하고 반대로 넣어둔 자료를 꺼내는 것을 팝(pop)이라고 하는데, 
이때 꺼내지는 자료는 가장 최근에 푸쉬한 자료부터 나오게 된다. 이처럼 나중에 넣은 값이 먼저 나오는 것을 LIFO 구조라고 한다.

<br />

연결리스트를 활용한 스택과 배열리스트를 활용한 스택의 차이점을 아래에서 알아본다.

## 구현
- 스택 생성
- Push
- Pop
- Peek
- 제거

## 연결리스트를 활용한 Stack, LinkedStack

### 스택 생성
```C
typedef struct StackNodeType
{
	char data;
	struct StackNodeType* pLink;
} StackNode;

typedef struct LinkedStackType
{
	int currentElementCount;	// 현재 노드 개수
	StackNode* pTopElement;		// Top Node
} LinkedStack;
```

구조체를 할당하여 선언한다.
이때 연결리스트를 활용하므로 pLink로 next node를 지정한다.

```C
LinkedStack* createLinkedStack()
{
    LinkedStack *buf;

    buf = calloc(1, sizeof(LinkedStack));
    return (buf);
}
```

calloc을 통해 초기화하며 할당한다.

### Push

```C
int pushLS(LinkedStack* pStack, StackNode element) // 스택에 삽입
{
    StackNode   *new_one;

    new_one = calloc(1, sizeof(StackNode));
    new_one->data = element.data;
    new_one->pLink = pStack->pTopElement;
    pStack->pTopElement = new_one; // top element 갱신
    pStack->currentElementCount += 1;
    return (TRUE);
}
```

새로운 node를 할당하여 linkedlist에 연결한다.
LIFO 구조에 유의하여 새로 들어온 node는 무조건 맨 위에 할당한다.

### Pop
```C
StackNode* popLS(LinkedStack* pStack) // 맨 위 노드 반환
{
    StackNode   *buf;
    StackNode   *delNode;

    if(!(pStack->pTopElement))
        return (NULL);
    buf = calloc(1, sizeof(StackNode));
    buf->data = pStack->pTopElement->data;
    delNode = pStack->pTopElement;
    delNode->data = 0;
    pStack->pTopElement = delNode->pLink; // header 갱신
    delNode->pLink = NULL;
    free(delNode);
    delNode = NULL;
    pStack->currentElementCount -= 1;
    return (buf);
}
```

가장 위에 있는 node를 list 에서 제거하고, 반환한다.

### Peek
```C
StackNode* peekLS(LinkedStack* pStack) // top node 데이터 반환
{
    if(!(pStack->pTopElement))
        return (NULL);
    return (pStack->pTopElement);
}
```

가장 위에 있는 node의 data를 반환한다.
Pop과 다른 점은 node를 제거하지 않는다는 점이다.

### 제거
```C
void deleteLinkedStack(LinkedStack* pStack) // stack 제거
{
    StackNode   *buf;
    StackNode   *next;

    buf = pStack->pTopElement;
    while(buf)
    {
        next = buf->pLink;
        buf->data = 0;
        buf->pLink = NULL;
        free(buf);
        buf = NULL;
        buf = next;
    }
    pStack->pTopElement = NULL;
}
```