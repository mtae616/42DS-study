# 스택 Stack

<!-- 이미지 삽입 -->

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

## 배열리스트를 활용한 Stack, ArrayStack

### 스택 생성
```C
typedef struct StackNodeType
{
	char data;
} StackNode;

typedef struct ArrayStackType
{
	int maxElementCount;		// 최대 원소 개수
	int currentElementCount;	// 현재 원소의 개수
	StackNode* pElement;		// Top node
} ArrayStack;
```

구조체를 할당하여 선언한다.
이때 정적 배열리스트를 활용하므로 최대 개수를 정해준다.

```C
ArrayStack* createArrayStack(int maxElementCount) // 스택 생성
{
    ArrayStack *lst;

    if (!maxElementCount)
        return (FALSE);
    lst = calloc(1, sizeof(ArrayStack));
    lst->maxElementCount = maxElementCount; // 최대 개수 지정
    lst->pElement = calloc(lst->maxElementCount, sizeof(StackNode));
    return (lst);
}
```

### Push
```C
int pushAS(ArrayStack* pStack, StackNode element) // 스택 삽입
{
    if (pStack->currentElementCount >= pStack->maxElementCount) // 최대 개수를 넘어갈 수 없다.
        return (FALSE);
    pStack->pElement[pStack->currentElementCount].data = element.data;
    pStack->currentElementCount += 1;
    return (TRUE);
}
```

정적 배열을 사용하므로 해당 인덱스에 데이터만 넣어준다.

### Pop
```C
StackNode* popAS(ArrayStack* pStack) // 맨 위 노드 반환
{
    StackNode   *buf;
	
	if (pStack->currentElementCount == 0)
		return (FALSE);
    buf = calloc(1, sizeof(StackNode));
    buf->data = pStack->pElement[pStack->currentElementCount - 1].data;
    pStack->pElement[pStack->currentElementCount - 1].data = 0;
    pStack->currentElementCount -= 1;
    return (buf);
}
```

해당 데이터를 새로 할당한 Node를 반환한다.
이후 반환된 데이터는 삭제한다.

### Peek

```C
StackNode* peekAS(ArrayStack* pStack) // 맨 위 노드의 데이터 반환
{
    return (&pStack->pElement[pStack->currentElementCount - 1]);
}
```

맨 위 node의 데이터를 반환한다.
이 때 Pop과 다른 점은 데이터를 제거하지 않는다.

### 제거
```C
void deleteArrayStack(ArrayStack* pStack) // 스택 제거
{
    free(pStack->pElement); // 배열 할당 해제
    pStack->currentElementCount = 0;
    pStack->maxElementCount = 0;
    free(pStack); // 스택 해제
    pStack->pElement = NULL;
    pStack = NULL;
}
```