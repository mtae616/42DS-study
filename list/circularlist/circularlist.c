#include "circularlist.h"

CircularList	*createCircularList()
{
	CircularList	*lst;

	lst = calloc(1, sizeof(CircularList));
	return (lst);
}

int	addCLElement(CircularList *pList, int position, CircularListNode element)
{
	CircularListNode	*buf;
	CircularListNode	*new;

	new = calloc(1, sizeof(CircularListNode));
	new->data = element.data;
	if (ZERO(pList->currentElementCount))
	{
		pList->headerNode.pRLink = new;
		new->pRLink = pList->headerNode.pRLink;
	}
	else
	{
		buf = getCLElement(pList, position - 1);
		new->pRLink = buf->pRLink;
		buf->pRLink = new;
		if (position == pList->currentElementCount)
			pList->headerNode.pRLink = new;
	}
	pList->currentElementCount += 1;
	return (TRUE);
}

CircularListNode	*getCLElement(CircularList *pList, int position)
{
	CircularListNode	*head;

	head = pList->headerNode.pRLink->pRLink;
	while (position > 0)
	{
		head = head->pRLink;
		position--;
	}
	return (head);
}

int	removeCLElement(CircularList *pList, int position)
{
	CircularListNode	*buf;
	CircularListNode	*delNode;

	if (!(position))
	{
		delNode = pList->headerNode.pRLink->pRLink;
		buf = pList->headerNode.pRLink;
		buf->pRLink = delNode->pRLink;
		pList->headerNode.pRLink = buf;
	}
	else
	{
		buf = getCLElement(pList, position - 1);
		delNode = getCLElement(pList, position);
		buf->pRLink = delNode->pRLink;
	}
	free(delNode);
	delNode = NULL;
	pList->currentElementCount--;
	return (TRUE);
}

int				getCircularListLength(CircularList *pList)
{
	return (pList->currentElementCount);
}

void			clearCircularList(CircularList *pList)
{
	CircularListNode	*head;
	CircularListNode	*next;
	int					idx;

	head = pList->headerNode.pRLink->pRLink;
	while (idx < pList->currentElementCount)
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

void			deleteCircularList(CircularList *pList)
{
	clearCircularList(pList);
	free(pList);
	pList = NULL;
}

void			displayCircularList(CircularList *pList)
{
	CircularListNode	*head;
	int					idx;

	head = pList->headerNode.pRLink->pRLink;
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
	removeCLElement(lst, 1);
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