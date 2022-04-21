#include "circularlist.h"

CircularList	*createCircularList() // list 생성
{
	CircularList	*lst;

	lst = calloc(1, sizeof(CircularList)); // list 초기화
	return (lst);
}

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

int				getCircularListLength(CircularList *pList) // 길이값
{
	return (pList->currentElementCount);
}

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

void			displayCircularList(CircularList *pList) // 모든 node를 보여준다.
{
	CircularListNode	*head;
	int					idx;

	head = pList->headerNode.pRLink->pRLink; // 0번째 node는 header 다음 node이다.
	idx = 0;
	while (idx < pList->currentElementCount)
	{
		printf("pList[%d] = %d\n", idx++, head->data);
		head = head->pRLink;
	}
}

int	main(void)
{
	CircularList	*lst;
	CircularListNode	*e1 = malloc(sizeof(CircularListNode));
	CircularListNode	*e2 = malloc(sizeof(CircularListNode));
	CircularListNode	*e3 = malloc(sizeof(CircularListNode));
	CircularListNode	*e4 = malloc(sizeof(CircularListNode));
	lst = createCircularList();
	e1->data = 1;
	e2->data = 2;
	e3->data = 3;
	e4->data = 999;
	addCLElement(lst, 0, *e1);
	displayCircularList(lst);
	printf("====================================\n");
	addCLElement(lst, 0, *e2);
	displayCircularList(lst);
	printf("====================================\n");
	addCLElement(lst, 2, *e3);
	displayCircularList(lst);
	printf("====================================\n");
	addCLElement(lst, 1, *e4);
	displayCircularList(lst);
	printf("remove====================================\n");
	removeCLElement(lst, 0);
	displayCircularList(lst);
	printf("====================================\n");
	// free(e1);
	// free(e2);
	// free(e3);
	// free(e4);
	deleteCircularList(lst);
	system("leaks a.out > leaks_result; cat leaks_result | \
        grep leaked && rm -rf leaks_result");
	return (0);
}