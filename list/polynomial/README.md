# 다항식

<a href="https://liltdevs.tistory.com/75?category=1068824">이중 연결리스트</a>

다항식의 항은 계수 + 차수로 이뤄진다.
단 각 항은 내림차순 정렬로 가장 큰 차수가 header node가 된다.
정렬은 node를 생성하면서 조건문을 통해 앞이나 뒤에 넣을 수 있게 하였다.
단, 이 때 차수가 같은 노드가 추가되면 새로 node를 생성하지 않고 기존 Node에 연산만을 할 수 있게 하였다.

<br />

계산의 경우에는 덧셈 뺄셈과 곱셈 나눗셈을 따로 분리하여 생각하여야 한다.
덧셈, 뺄셈의 경우 같은 차수에서만 연산이 이뤄지면 되는데,
곱셈, 나눗셈의 경우에는 매 항마다 연산이 이뤄져야 한다.

<br />

또한 계수가 0일 경우에는 해당 항이 지워질 수 있게 하였다.

<br />

## 구현

- 리스트 생성
- 원소 추가
- 원소 반환
- 제거
- 연산

<br />

### 생성

```C
typedef struct ListNodeType
{
	int coef;
	int	degree;
	struct ListNodeType *pLLink;
	struct ListNodeType *pRLink;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;	// 현재 저장된 원소의 개수
	ListNode headerNode;		// 헤더 노드(Header Node)
} LinkedList;

#include "polynomial.h"

LinkedList	*createPolynomialList() // list를 생성한다.
{
	LinkedList	*lst;

	lst = calloc(1, sizeof(LinkedList));
	NULLCHECK(lst);
	lst->currentElementCount = 0;
	return (lst);
}
```

header에 이중 연결리스트를 선언하고,
list를 생성하여 반환한다.

### 추가

```C
#include "polynomial.h"

int	find_degree(LinkedList *pList, ListNode element) // 차수가 같은지 판별하여 더해준다.
{
	ListNode	*headNode;
	int			i;

	headNode = pList->headerNode.pRLink->pLLink; // 뒤에서 부터 찾는다.
	i = pList->currentElementCount;
	while (i-- && !(headNode->degree == element.degree))
		headNode = headNode->pLLink;
	if (headNode->degree == element.degree) // 차수가 같다면
	{
		headNode->coef += element.coef; // 더해준다.
		if (ZERO(headNode->coef))
			removePLElement(pList, i);
		return (TRUE);
	}
	return (FALSE);
}

int	addPLElement(LinkedList *pList, ListNode element)
{
	ListNode	*newNode;
	ListNode	*headNode;
	int			i;

	newNode = calloc(1, sizeof(ListNode));
	newNode->coef = element.coef;
	newNode->degree = element.degree;
	if (ZERO(pList->currentElementCount)) { // header node 일 경우
		pList->headerNode.pRLink = newNode; // header로 지정한다.
		newNode->pLLink = pList->headerNode.pRLink; // 자기 자신을 지칭하게 한다.
		newNode->pRLink = newNode;
	}
	else
	{
		if (find_degree(pList, element)) // 만약 같은 차수가 있다면, 기존 node에 더해준다.
		{
			free(newNode);
			newNode = NULL;
			return (TRUE);
		}
		i = 0;
		headNode = pList->headerNode.pRLink->pLLink; // 뒤에서 부터 찾아준다.
		while (IS_BIG(headNode->degree, newNode->degree))
		// 새로 들어올 node의 차수가 더 작을 때 멈춰 차수로 정렬한다.
		{
			if (i++ == pList->currentElementCount) // while 문은 node 개수만큼만 반복한다.
				break ;
			headNode = headNode->pLLink;
		}
		newNode->pLLink = headNode; // 기존 list에 삽입한다.
		newNode->pRLink = headNode->pRLink;
		headNode->pRLink->pLLink = newNode;
		headNode->pRLink = newNode;
		headNode = &(pList->headerNode);
		if (headNode->pRLink->pLLink->degree - headNode->pRLink->degree > 0)
		// 만약 갱신된 node의 차수가 더 크다면 header를 갱신한다.
			headNode->pRLink = headNode->pRLink->pLLink;
	}
	pList->currentElementCount++;
	return (TRUE);
}
```

node를 추가하면서 find degree를 통해 같은 차수인지부터 판별하고,
만약 차수가 같다면 연산 이후 처리하지 않게 한다.
이후에는 while문을 통해 차수를 기준으로 내림차순 정렬할 수 있게 node를 추가하고
header를 갱신할 수 있게 한다.

### 반환

```C
#include "polynomial.h"

ListNode	*getPLElement(LinkedList* pList, int position) // 원하는 position의 node를 보여준다.
{
	ListNode	*head;

	head = pList->headerNode.pRLink;
	while (position)
	{
		head = head->pRLink;
		position -= 1;
	}
	return (head);
}
```

### 원소 제거

```C
#include "polynomial.h"

int	removePLElement(LinkedList *pList, int position) // 개별 node 삭제
{
	ListNode	*headNode;
	int			i;

	if (position < 0 || position >= pList->currentElementCount)
	// position이 음수이거나, 현재 node 개수 이상일 수 없다.
		return (FALSE);
	i = 0;
	headNode = pList->headerNode.pRLink;
	while (i++ < position)
		headNode = headNode->pRLink;
	headNode->pLLink->pRLink = headNode->pRLink;
	headNode->pRLink->pLLink = headNode->pLLink;
	pList->currentElementCount--;
	if (ZERO(position) && UPPER_ZERO(pList->currentElementCount)) // 만약 header node 라면
		pList->headerNode.pRLink = headNode->pRLink; // header를 갱신한다.
	headNode->pLLink = NULL;
	headNode->pRLink = NULL;
	free(headNode);
	headNode = NULL;
	return (TRUE);
}
```

header를 갱신하거나, 이전 이후 node를 잘 파악하여야 한다.

### 제거

```C
#include "polynomial.h"

void	clearPolynomialList(LinkedList *pList) // 내부 node를 전부 삭제한다.
{
	ListNode	*headNode;
	ListNode	*nextNode;

	headNode = pList->headerNode.pRLink;
	while (pList->currentElementCount)
	{
		nextNode = headNode->pRLink;
		headNode->pLLink = NULL;
		headNode->pRLink = NULL;
		free(headNode);
		headNode = nextNode;
		pList->currentElementCount -= 1;
	}
	nextNode = NULL;
	headNode = NULL;
}

#include "polynomial.h"

void	deletePolynomialList(LinkedList *pList) // 내부 node와 list를 삭제한다.
{
	clearPolynomialList(pList);
	free(pList);
	pList = NULL;
}
```

clear로 내부 node를 전부 삭제하고,
delete로 list까지 삭제한다.

### 덧셈, 뺄셈

```C
#include "polynomial.h"

LinkedList	*plus(LinkedList *aList, LinkedList *bList) // 다항식의 덧셈
{
	LinkedList	*newList = createPolynomialList();
	alloc_calc_node(newList, aList, 0);
	alloc_calc_node(newList, bList, 0);
	return (newList);
}

#include "polynomial.h"

LinkedList	*minus(LinkedList *aList, LinkedList *bList) // 다항식의 뺏셈
{
	LinkedList	*newList = createPolynomialList();
	alloc_calc_node(newList, aList, 0);
	alloc_calc_node(newList, bList, 1);
	return (newList);
}

#include "polynomial.h"

void alloc_calc_node(LinkedList *new_list, LinkedList *base_list, int flag)
{
	ListNode	*base_head;
	ListNode	*new_node;
	int			baseidx = base_list->currentElementCount; // 연산을 위해 base list node 갯수를 저장한다.

	base_head = base_list->headerNode.pRLink;
	new_node = malloc(sizeof(ListNode));
	while(baseidx--)
	{
		new_node->degree = base_head->degree;
		if (flag)
			new_node->coef = -(base_head->coef);
		else
			new_node->coef = base_head->coef;
		addPLElement(new_list, *new_node); // node를 새로운 list에 할당한다.
		base_head = base_head->pRLink;
	}
	free(new_node);
	new_node = NULL;
	deletePolynomialList(base_list);
	base_list = NULL;
}
```

list를 새로 하나 생성하여 각 node들에 대한 연산을 해준다.
이 때 add를 통해 이미 같은 차수에 대한 고려는 하였기 때문에, add를 통한 node 생성만 고려하면 된다.
단 flag를 통하여 minus일 경우에는 뒤의 항에 -연산을 해줘 빼 줄 수 있게 한다.

### 나눗셈, 곱셈

```C
#include "polynomial.h"

void alloc_calc_node(LinkedList *new_list, LinkedList *base_list, int flag)
{
	ListNode	*base_head;
	ListNode	*new_node;
	int			baseidx = base_list->currentElementCount; // 연산을 위해 base list node 갯수를 저장한다.

	base_head = base_list->headerNode.pRLink;
	new_node = malloc(sizeof(ListNode));
	while(baseidx--)
	{
		new_node->degree = base_head->degree;
		if (flag)
			new_node->coef = -(base_head->coef);
		else
			new_node->coef = base_head->coef;
		addPLElement(new_list, *new_node); // node를 새로운 list에 할당한다.
		base_head = base_head->pRLink;
	}
	free(new_node);
	new_node = NULL;
	deletePolynomialList(base_list);
	base_list = NULL;
}

#include "polynomial.h"

LinkedList	*division(LinkedList *aList, LinkedList *bList) // 나눗셈 연산
{
	int	alen = getPolynomialListLength(aList) - 1;
	int	blen;
    LinkedList	*newList = createPolynomialList();
	ListNode	*newNode = calloc(1, sizeof(ListNode));
	ListNode	*aHeadNode = aList->headerNode.pRLink;
	ListNode	*bHeadNode;

	while(alen--) {
		blen = getPolynomialListLength(bList) - 1;
		bHeadNode = bList->headerNode.pRLink;
		while(blen--) {
			newNode->coef = aHeadNode->coef / bHeadNode->coef; // 각 계수는 빼준다.
			newNode->degree = aHeadNode->degree - bHeadNode->degree; // 각 차수는 나눠준다.
			addPLElement(newList, *newNode);
			bHeadNode = bHeadNode->pRLink;
		}
		aHeadNode = aHeadNode->pRLink;
	}
    deletePolynomialList(aList);
    deletePolynomialList(bList);
    aList = NULL;
    bList = NULL;
	return (newList);
}
```

나눗셈과 곱셈은 각 항마다 모든 연산이 이뤄져야 하기 때문에 2중 반복문을 통해 구현하였다.
덧셈, 뺄셈과 마찬가지로 add에서 연산 이외의 고려가 되어있기 때문에 해당 함수에서는 연산만을 처리한다.
