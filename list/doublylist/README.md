# 이중 연결 리스트 (Doubly Linked list)

<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fbv1k5W%2FbtrzYiUrMjt%2FXJN1rAQgCeFkeoDmuy9a0k%2Fimg.png" />

이중 연결 리스트의 구조는 단일 연결 리스트와 비슷하지만,  
포인터 공간이 두 개가 있고 각각의 포인터는 앞의 노드와 뒤의 노드를 가리킨다.

<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FYwiWI%2FbtrzS2daX1c%2FuToz7rrRRElhP1vRb4C32K%2Fimg.png" />

탐색에서는 단일 연결 리스트보다 시간적 우위를 지닌다.  
기준에 따라 Head에서 출발하거나, Tail에서 출발하는 것이 가능하다.  
단, 각 노드의 관리에 유의해야 하기 때문에, 작업량이 많아지고 자료구조의 크기와 사용 메모리가 증가한다.

## 특징

-   탐색에 용이하다.
-   자료구조의 크기가 증가한다.
-   메모리 사용량이 증가한다.
-   단일 연결 리스트보다 관리에 유의해야 한다.
-   이 외에는 단일 연결 리스트와 비슷한다.
-   [단일 연결 리스트](https://liltdevs.tistory.com/73)

## 구현

-   리스트 생성
-   원소 추가
-   원소 반환
-   원소 제거
-   리스트 제거

### 리스트 생성

```C
typedef struct DoublyListNodeType
{
	int data;
	struct DoublyListNodeType	*pLLink;
	struct DoublyListNodeType	*pRLink;
} DoublyListNode;

typedef struct DoublyListType
{
	int	currentElementCount;	
	DoublyListNode	headerNode;
}	DoublyList;
```

```C
#include "doublylist.h"

DoublyList	*createDoublyList() // list 생성
{
	DoublyList	*buf;

	buf = (DoublyList *)calloc(1, sizeof(DoublyList)); // calloc으로 초기화 하면서 생성
	NULLCHECK(buf);
	return (buf);
}
```

헤더에 구조체를 선언하고, 메모리 할당해준다.

### 원소 추가

```C
#include "doublylist.h"

int addDLElement(DoublyList	*pList, int position, DoublyListNode element) // node 생성
{
	DoublyListNode *buf;
	DoublyListNode *new;

	if (position < 0 || pList->currentElementCount < position) // position이 음수이거나, position이 더 클 수 없다.
        return (FALSE);
	new = (DoublyListNode *)calloc(1, sizeof(DoublyListNode));
	NULLCHECK(new);
	new->data = element.data;
	if (ZERO(pList->currentElementCount)) // 만약 첫 node 라면
	{
		pList->headerNode.pRLink = new; // right, left를 자기 자신으로 둔다.
		new->pLLink = new;
		new->pRLink = new;
		pList->currentElementCount = 1;
	}
	else
	{
		buf = getDLElement(pList, position - 1); // 삽입할 위치 전의 것을 가져온다.
		new->pLLink = buf;
		new->pRLink = buf->pRLink;
		buf->pRLink->pLLink = new;
		buf->pRLink = new;
		pList->currentElementCount += 1;
	}
	return (TRUE);
}

```

추가하면서, 왼쪽 node와 오른쪽 node를 고려해야 한다.

### 원소 반환

```C
#include "doublylist.h"

DoublyListNode	*getDLElement(DoublyList *pList, int position) // 원하는 node 반환
{
	DoublyListNode	*buf;

	if (position >= pList->currentElementCount / 2) // 중간 기준 왼쪽에 있는 node
	{
		buf = pList->headerNode.pRLink;
		while (UPPER_ZERO(position)) {
			buf = buf->pRLink;
			position--;
		}
	}
	else // 중간 기준 오른쪽에 있는 node
	{
		position = pList->currentElementCount - position - 1;
		buf = pList->headerNode.pRLink;
		while (UPPER_ZERO(position)) {
			buf = buf->pRLink;
			position--;
		}
	}
	return(buf);
}
```

중간을 기준으로 하여 왼쪽부터 탐색할지 오른쪽부터 탐색할지를 정해 시간복잡도를 줄일 수 있다.

### 원소 제거

```C
#include "doublylist.h"

int removeDLElement(DoublyList *pList, int position) // 개별 node 삭제
{
    DoublyListNode	*buf;

	if (IS_BIG(position, 0) || IS_BIG(pList->currentElementCount, position)) // position이 0 보다 작거나, 현재 node 개수보다 크면 안된다.
		return (FALSE);
	NULLCHECK(pList);
	if (ZERO(position)) // position이 0 일 때
	{
		buf = pList->headerNode.pRLink;
		buf->pRLink->pLLink = buf->pLLink;
		buf->pLLink->pRLink = buf->pRLink;
		pList->headerNode.pRLink = buf->pRLink; // header 갱신
	}
	else // position이 0이 아닐 때
	{
		buf = getDLElement(pList, position);
		buf->pLLink->pRLink = buf->pRLink;
		buf->pRLink->pLLink = buf->pLLink;
	}
	free(buf);
	buf = NULL;
    pList->currentElementCount--;
    return (TRUE);
}
```

원소를 제거하면서도 왼쪽과 오른쪽 node에 대한 주의를 기울여야 한다.


### 리스트 제거

```C
#include "doublylist.h"

void	clearDoublyList(DoublyList *pList) // 내부 node 전체 삭제
{
    DoublyListNode  *buf;
    DoublyListNode  *next;

    buf = pList->headerNode.pRLink;
    while (UPPER_ZERO(pList->currentElementCount)) // 현재 node 개수로 반복문을 돌려준다.
    {
        next = buf->pRLink;
        buf->data = 0x00;
        buf->pLLink = NULL;
        buf->pRLink = NULL;
        free(buf);
		pList->currentElementCount--;
        buf = next;
    }
	buf = NULL;
	next = NULL;
	pList->currentElementCount = 0;
}
#include "doublylist.h"

void	deleteDoublyList(DoublyList *pList) // list 까지 생성
{
	NULLCHECK(pList);
	clearDoublyList(pList);
	pList->headerNode.pRLink = NULL;
	pList->headerNode.pLLink = NULL;
	free(pList);
	pList = NULL;
}
```

clear와 함께 delete를 통해 list전체 삭제를 할 수 있게 한다.