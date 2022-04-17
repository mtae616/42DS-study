# Lists
- <a href="#a1">ArrayList</a>
- <a href="#singlyLinkedList">singly LinkedList</a>

# <Label id="a1">배열 리스트 (Array List)</Label>

배열리스트는 자료를 순서대로 저장하는 자료구조로,  
논리적 순서(저장)와 물리적 순서(저장)가 동일하다.  
원소의 위치 인덱스는 0부터 시작하고,  
정적배열로 최대 갯수가 정해져 있고,이는 배열과 동일하다.  
C에서는 라이브러리로 배열리스트를 지원하지 않기 때문에,  
개발자가 직접 구현해야하는 기능으로는,

-   리스트 생성
-   원소 추가
    -   원소 추가 가능 여부 판단
-   원소 반환
-   원소 제거
    -   리스트 초기화
-   리스트 삭제

를 꼽을 수 있다.

## 특징

저장순서가 순차적이기 때문에 Index가 곧 위치로, 탐색(O(1))에 용이하지만,  
배열이 공백을 허용하지 않아 삽입이나 삭제 시에는 노드가 끊기지 않아야 하기 때문에,  
삽입이 됐을 떄에는 기존 노드를 뒤로 미루거나, 삭제가 됐을 때에는 원래 노드들을 앞으로 땡기는 등의 작업이 필요하다(O(N)).  
또한 정적배열로 저장할 수 있는 최대 갯수가 정해져 있어 이를 넘어가는 저장은 불가하다.

# 구현

## 생성

```
typedef struct ArrayListNodeType // List에 들어갈 Node
{
    int data;
} ArrayListNode;

typedef struct ArrayListType
{
    int maxElementCount;        // 최대 원소 개수
    int currentElementCount;    // 현재 원소의 개수
    ArrayListNode *pElement;    // 원소 저장을 위한 1차원 배열
} ArrayList;
```

위와 같이 헤더를 선언하여, list를 생성한다.

```
ArrayList* createArrayList(int maxElementCount) // ArrayList 생성
{
    ArrayList *buf;

    if (maxElementCount < 0)
        return (FALSE);
    buf = malloc(sizeof(ArrayList *)); // ArrayList 생성
    buf->pElement = malloc(sizeof(int) * maxElementCount); // 실제 Node가 들어갈 배열
    buf->maxElementCount = maxElementCount; // 정적 배열로 최대 몇 개가 들어갈 것인지 미리 정한다.
    buf->currentElementCount = 0;
    return (buf);
}
```

위의 구조체 선언대로 List를 생성한다.

## 추가

```
int addALElement(ArrayList* pList, int position, ArrayListNode element) // ArrayList node 추가
{
    int i;

    if (pList->maxElementCount <= position) // max 넘겨 node 추가할 때
        return (FALSE);
    if (pList->maxElementCount < pList->currentElementCount) // 원소 + 1 <= maxCount
        return (FALSE);
    i = pList->currentElementCount + 1; // node 추가를 위한 인덱싱
    while(i >= position) {
        pList->pElement[i].data = pList->pElement[i - 1].data; // 원래 값들을 한 칸 뒤로 이동시킨다.
        i--;
    }
    pList->pElement[position].data = element.data; // position 에 원하는 값 입력
    pList->currentElementCount += 1;
    return (TRUE);
}
```

위와 같이 원래 Node가 있을 때를 고려하거나, MaxCount보다 넘기는 값인지에 대해 유의해야 한다.  
이 때 원래 값들을 뒤로 밀어줘야 하기 때문에 O(N)으로 Linked List와 비교하여 단점을 지닌다.

## 탐색

```
ArrayListNode* getALElement(ArrayList* pList, int position) // 원소의 주소 반환
{

    return &(pList->pElement[position]); // 원하는 위치의 주소값 반환
}
```

ArrayList는 특성 상 Index 값을 통해 탐색하기 때문에  
O(1) 의 속도를 갖는다.

## 개별 삭제

```
int removeALElement(ArrayList* pList, int position) // 원소를 지운다.
{
    int i;

    if (!pList)
        return (FALSE);
    i = position;
    pList->pElement[position].data = 0; // position의 값 지운 후
    while (i <= pList->currentElementCount - 1)
    {
        pList->pElement[i].data = pList->pElement[i + 1].data; // 값들을 앞으로 땡긴다.
        i++;
    }
    pList->pElement[i].data = 0;
    pList->currentElementCount -= 1;
    return (TRUE);
}
```

개별 원소를 삭제할 때에는 삭제된 뒤의 Node들을 앞으로 땡겨줘야 하기 때문에  
O(N)으로 Linked List와 비교하여 단점을 지닌다.

## 전체 삭제

```

void clearArrayList(ArrayList* pList) // 내부 원소들을 지운다.
{
    size_t  i;

    if(!pList)
        return ;
    i = 0;
    while (pList->pElement[i].data)
    {
        pList->pElement[i].data = 0;
        i++;
    }
    pList->currentElementCount = 0;
    free(pList->pElement);
    pList->pElement = NULL;
}

void deleteArrayList(ArrayList* pList) // 모든 원소와 list를 지운다.
{
    if (!pList)
        return ;
    clearArrayList(pList);
    free(pList);
    pList = NULL;
}
```

# <Label id="singlyLinkedList">단일 연결 리스트 (singly Linked List)</Label>

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/9/9c/Single_linked_list.png/800px-Single_linked_list.png" />

단일 연결 리스트는 각 노드들이 한 줄로 연결되어 있는 자료구조이다. 
이름에서 말하듯이 데이터를 담고 있는 노드들이 연결되어 있는데, 노드의 포인터가 다음이나 이전의 노드와의 연결을 담당하게 된다.
연결 리스트는 늘어선 노드의 중간지점에서도 자료의 추가와 삭제가 O(1)의 시간에 가능하다는 장점을 갖는다.
(다만, 오늘 구현할 것은 tail을 갖지 않는 linked list로 1번의 반복문을 거치게 된다.)
다만, 기존 링크를 해제하거나 삽입할 때에는 기존 링크의 전이나 다음 노드 관리에 대해 유의해야 한다.
또한 배열이나 트리 구조와는 달리 특정 위치의 데이터를 검색해 내는데에는 O(n)의 시간이 걸리는 단점도 갖고 있다.
특히 단일 연결 리스트는 각 노드에 자료 공간과 한 개의 포인터 공간이 있고, 각 노드의 포인터는 다음 노드를 가리킨다.

<br />

# 특징

- 동적으로 메모리 할당이 가능하다.
- 삭제나 추가가 빠르다.
- 데이터가 빈틈 없이 연속적이다.
- 대용량 데이터 처리에 탁월하다.
- 구현이 어렵다.
- 탐색에 오래 걸린다. (O(N))
- 논리적 순서와 물리적 순서가 동일하지 않다.

<br />

# 구현

-   리스트 생성
-   원소 추가
-   원소 반환
-   원소 제거
-   리스트 삭제

## 생성

```C
typedef struct ListNodeType // List에 들어갈 Node
{
	int data;
	struct ListNodeType* pLink;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;	// 현재 저장된 원소의 개수
	ListNode headerNode;		// 헤더 노드(Header Node)
} LinkedList;
```

위와 같이 헤더를 선언하여 List를 생성한다.

```C
LinkedList* createLinkedList() // Linked list 생성
{
	LinkedList* buf;

	buf = malloc(sizeof(LinkedList));
	buf->currentElementCount = 0;
	buf->headerNode.data = 0;
	buf->headerNode.pLink = NULL;
	return (buf);
}
```

## 추가

```C
int addLLElement(LinkedList* pList, int position, ListNode element) // Node 추가
{
	int		i;
	ListNode	*buf;
	ListNode	*curr;
	ListNode	*prev;
	
	if (position < 0)
		return (FALSE);
	if(position == 0)
	{
		if (pList->currentElementCount == 0) // Header Node가 없을 때
		{
			pList->headerNode = element; // 인자로 들어온 Node를 할당한다.
			pList->currentElementCount = 1;
			pList->headerNode.pLink = NULL;
		}
		else // Header Node가 있을 때
		{
			curr = malloc(sizeof(ListNode)); // 원래 header 의 데이터 복사
			curr->data = pList->headerNode.data;
			curr->pLink = pList->headerNode.pLink;
			element.pLink = curr; // 새로 들어온 element를 헤더로 바꾸기 위해 복사한 포인터를 next로 지칭
			pList->headerNode = element; // 새로 들어온 element를 헤더로 바꿔준다.
			pList->currentElementCount += 1;
		}
		return (TRUE);
	}
	buf = &(pList->headerNode);
	i = 0;
	while(buf && i < position)
	{
		if (i + 1 == position) // 새로 들어올 node를 위해 position 이전의 node의 주소를 저장한다.
			prev = buf;
		buf = buf->pLink;
		i++;
	}
	if (position == i) // Node 추가
	{
		curr = malloc(sizeof(ListNode)); // node 추가를 위한 데이터 복사
		curr->data = element.data;
		curr->pLink = buf; // 원래 위치의 node를 밀어내로
		prev->pLink = curr; // 원래 node 전의 node 의 next로 연결한다.
		pList->currentElementCount += 1;
		return (TRUE);
	}
	else
		return (FALSE);
}
```

생성을 하면서 Header인지 아닌지로 크게 분기한 이후,
들어갈 전의 node와 후의 node 관리에 유의해야 한다.

## 반환

```C
ListNode* getLLElement(LinkedList* pList, int position) // 원하는 위치의 Node를 얻는다.
{
	ListNode *buf;

	// 위치가 음수인 것과 현재 엘리먼트 갯수보다 큰 위치의 노드는 없다!
    if (!(position >= 0 && position <= pList->currentElementCount))
        return (FALSE);
	buf = &(pList->headerNode);
	while(position--) // position 만큼 이동한다.
		buf = buf->pLink;
    return (buf);
}
```

position 만큼 반복문을 통해 반환한다.
특성상 탐색에는 O(N)이라는 시간이 걸린다.

## 제거

```C
int removeLLElement(LinkedList* pList, int position) // node를 지운다.
{
	size_t		i;
	ListNode	*buf;
	ListNode	*prev;
	ListNode	*next;
	// 위치가 음수인 것과 현재 엘리먼트 갯수보다 큰 위치의 노드는 없다!
	if (!(position >= 0 && position < pList->currentElementCount))
		return (FALSE);
	i = 0;
	buf = &(pList->headerNode);
	if (position == 0) // Header Node일 때
	{
		if (!(buf->pLink)) // Header Node 의 Next가 없을 때
		{
			buf->data = 0x00;
			buf->pLink = NULL;
			pList->currentElementCount -= 1;
		}
		else // Header Node 의 Next가 있을 때
		{
			buf->data = 0x00;
			next = buf->pLink;
			pList->headerNode = *next; // Header Node Next로 교체한다.
			next = NULL;
			pList->currentElementCount -= 1;
		}
		return (TRUE);
	}
	while (buf != NULL && i < position)
	{
		if (i + 1 == position)
			prev = buf;
		buf = buf->pLink;
		i++;
	}
	if (buf && i == position) // Header Node가 아닐 때
	{
		next = buf->pLink; // 현재 위치 다음 것을
		prev->pLink = next; // 현재 위치 전의 것에 연결해준다.
		buf->data = 0x00;
		buf->pLink = NULL;
		free(buf);
		pList->currentElementCount -= 1;
		return (TRUE);
	}
	else
		return (FALSE);
}
```

마찬가지로 삭제하면서 Header인지 아닌지로 크게 분기한 이후,
HeaderNode가 Pointer가 아니기 때문에 next가 있는지를 판별하고,
들어갈 전의 node와 후의 node 관리에 유의해야 한다.

## 제거

```C
void clearLinkedList(LinkedList* pList) // 내부 Node를 전부 없애준다.
{
	ListNode *buf;
	ListNode *next;

	buf = pList->headerNode.pLink;
	while(buf)
	{
		next = buf->pLink;
		buf->data = 0x00;
		free(buf);
        buf = NULL;
		buf = next;
	}
	pList->headerNode.data = 0x00;
	pList->headerNode.pLink = NULL;
	pList->currentElementCount = 0;
}

void deleteLinkedList(LinkedList* pList) // List와 Node를 제거한다.
{
	clearLinkedList(pList);
	free(pList);
    pList = NULL;
}
```

반복문을 돌면서 순차적으로 삭제하는데,
이 때 dangling pointer에 유의하여 주소에 NULL을 넣어준다.

# 배열 리스트와 연결 리스트의 장점과 단점

|| 배열 리스트 | 연결 리스트 |
| --- | --- | --- |
| 장점 | 내적으로 배열을 사용하기 떄문에 인덱스를 이용해서 접근이 빠르다. | 동적으로 메모리 사용이 가능하다. <br /> 최대 원소 개수 지정이 불필요하다. <br /> 추가시 원소를 이동하는 연산이 불필요하다. <br /> 대용량 데이터 처리에 적합하다. |
| 단점 | 배열 내의 데이터 이동 및 재구성이 어렵다. <br /> 동적으로 사용하기 힘들다. | 구현이 어렵다. <br /> 탐색 연산의 시간 복잡도 (O(N)) 가 좇지 않다. <br /> 메모리를 추가적으로 사용해야 한다. <br /> 논리적 순서와 물리적 저장 순서가 일치하지 않는다. |