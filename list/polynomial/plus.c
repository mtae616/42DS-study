#include "polynomial.h"

LinkedList	*plus(LinkedList *aList, LinkedList *bList) // 다항식의 덧셈
{
	ListNode	*aHead;
	ListNode	*bHead;
	ListNode	*newNode;
	LinkedList	*newList = createPolynomialList();
	int			aidx = aList->currentElementCount; // 연산을 위해 a list node 갯수를 저장한다.
	int			bidx = bList->currentElementCount; // 연산을 위해 b list node 갯수를 저장한다.

	aHead = aList->headerNode.pRLink;
	bHead = bList->headerNode.pRLink;
	while (aidx--)
	{
		newNode = malloc(sizeof(ListNode));
		newNode->degree = aHead->degree;
		newNode->coef = aHead->coef;
		addPLElement(newList, *newNode); // node를 새로운 list에 할당한다.
		free(newNode);
		aHead = aHead->pRLink;
	}
	while (bidx--)
	{
		newNode = malloc(sizeof(ListNode));
		newNode->degree = bHead->degree;
		newNode->coef = bHead->coef;
		addPLElement(newList, *newNode); // node를 새로운 list에 할당한다.
		free(newNode);
		bHead = bHead->pRLink;
	}
	newNode = NULL;
	// 계수 0된 쉑 free
	deletePolynomialList(aList);
	deletePolynomialList(bList);
	return (newList);
}