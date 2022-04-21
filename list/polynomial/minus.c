#include "polynomial.h"

LinkedList	*minus(LinkedList *aList, LinkedList *bList) // 다항식의 뺏셈
{
	ListNode	*aHead;
	ListNode	*bHead;
	ListNode	*newNode;
	LinkedList	*newList = createPolynomialList();
	int			aidx = aList->currentElementCount; // 연산을 위해 a list node 갯수를 저장한다.
	int			bidx = bList->currentElementCount; // 연산을 위해 b list node 갯수를 저장한다.

	aHead = aList->headerNode.pRLink;
	bHead = bList->headerNode.pRLink;
	newNode = malloc(sizeof(ListNode));
	while (aidx--)
	{
		newNode->degree = aHead->degree;
		newNode->coef = aHead->coef;
		addPLElement(newList, *newNode); // node를 새로운 list에 할당한다.
		aHead = aHead->pRLink;
	}
	while (bidx--)
	{
		newNode->degree = bHead->degree;
		newNode->coef = -(bHead->coef);
		addPLElement(newList, *newNode); // node를 새로운 list에 할당한다.
		bHead = bHead->pRLink;
	}
	free(newNode);
	newNode = NULL;
	deletePolynomialList(aList);
	deletePolynomialList(bList);
	aList = NULL;
	bList = NULL;
	return (newList);
}