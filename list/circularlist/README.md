# 원형 연결 리스트

<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2F80fBj%2Fbtrz3kJsm7r%2FJnjgrIMyeRrV6h01fNHc90%2Fimg.png" />

원형 연결 리스트는 일반적인 연결 리스트에 마지막 노드와 처음 노드를 연결시켜 원형으로 만든 구조이다.  
단일 연결 리스트와 동일한 특징을 갖지만, 가장 첫 노드와 끝 노드가 연결된다는 특징을 갖는다.  
원형 연결 리스트는 Cpu scheduling 에서 Ready queue나 스트림 버퍼를 구현하는 데에 많이 사용된다.
단, header는 tail과 동일하여 list의 0번째 node는 header의 다음 node가 된다.

<br />

## 특징

-   노드를 탐색하면서 순회에 용이하다.
-   반복적인 순회에서 끝을 확인해야할 필요가 없음.
-	header 다음 node가 0번째 node가 된다.
-   이외에는 단일 연결리스트와 동일하다.
-   [단일 연결 리스트](https://liltdevs.tistory.com/73)

<br />

## 구현

-   리스트 생성
-   원소 추가
-   원소 반환
-   원소 제거
-   리스트 제거

<br />

### 리스트 생성

```C
typedef struct CircularListNodeType
{
	int data;
	struct CircularListNodeType	*pRLink;
} CircularListNode;

typedef struct CircularListType
{
	int	currentElementCount;	
	CircularListNode	headerNode;
}	CircularList;
```

구조체는 위와 같이 선언한다.

```C
CircularList	*createCircularList() // list 생성
{
	CircularList	*lst;

	lst = calloc(1, sizeof(CircularList)); // list 초기화
	return (lst);
}
```
list를 생성하여 반환한다.


### 원소 추가

```C
int	addCLElement(CircularList *pList, int position, CircularListNode element) // node 추가
{
	CircularListNode	*buf;
	CircularListNode	*new;

	new = calloc(1, sizeof(CircularListNode));
	new->data = element.data;
	if (ZERO(pList->currentElementCount)) // node가 없는 경우
	{
		pList->headerNode.pRLink = new; // header 지정
		new->pRLink = pList->headerNode.pRLink; // pRlink를 자기 자신으로 하여 순회할 수 있게 한다.
	}
	else // node가 있는 경우
	{
		buf = getCLElement(pList, position - 1); // 삽입할 포지션 전의 것을 지정한다.
		new->pRLink = buf->pRLink; // node 간 연결
		buf->pRLink = new;
		if (position == pList->currentElementCount) // 만약 position이 맨 끝일 경우 header 로 지정한다.
			pList->headerNode.pRLink = new;
	}
	pList->currentElementCount += 1; // node 개수를 늘려준다.
	return (TRUE);
}
```

header 다음 node가 0번째 node이므로 유의해야 한다.

### 원소 반환
```C
CircularListNode	*getCLElement(CircularList *pList, int position) // node 반환
{
	CircularListNode	*head;

	head = pList->headerNode.pRLink->pRLink; // header 는 tail이므로 0 index는 header의 다음이 된다.
	while (position > 0) // position 만큼 이동한다.
	{
		head = head->pRLink;
		position--;
	}
	return (head); // 원하는 node 반환
}

```

원하는 position을 탐색하여 반환한다.

### 원소 제거

```C
int	removeCLElement(CircularList *pList, int position) // 개별 node 삭제
{
	CircularListNode	*buf;
	CircularListNode	*delNode;

	if (!(position)) // postion이 0 이라면
	{
		delNode = pList->headerNode.pRLink->pRLink; // 삭제할 node
		buf = pList->headerNode.pRLink; // header
		buf->pRLink = delNode->pRLink; // header의 다음을 delnode의 다음으로 지정한다.
	}
	else // position이 0이 아니라면
	{
		buf = getCLElement(pList, position - 1); // position 전의 node
		delNode = getCLElement(pList, position); // position node
		buf->pRLink = delNode->pRLink; // 이어준다.
	}
	free(delNode);
	delNode = NULL;
	pList->currentElementCount--;
	return (TRUE);
}
```

마찬가지로 header의 다음이 0번째 node라는 것에 유의해야 한다.

### 리스트 제거

```C
void			clearCircularList(CircularList *pList) // 내부 node 전체 삭제
{
	CircularListNode	*head;
	CircularListNode	*next;
	int					idx;

	head = pList->headerNode.pRLink->pRLink; // 0번째 node는 header 다음이다.
	while (idx < pList->currentElementCount) // 개수만큼 삭제한다.
	{
		next = head->pRLink;
		head->pRLink = NULL;
		free(head);
		head = next;
		idx++;
	}
	head = NULL;
	next = NULL;
	pList->currentElementCount = 0;
}

void			deleteCircularList(CircularList *pList) // node와 list를 삭제한다.
{
	clearCircularList(pList);
	free(pList);
	pList = NULL;
}
```

순환에 있어서도 0번째 다음을 시작 node로 지정해야 한다.