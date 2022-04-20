#include "polynomial.h"

LinkedList	*plus(LinkedList *aList, LinkedList *bList)
{
	ListNode	*aHead;
	ListNode	*bHead;
	ListNode	*newNode;
	LinkedList	*newList = createPolynomialList();
	int			aidx = aList->currentElementCount;
	int			bidx = bList->currentElementCount;
	aHead = aList->headerNode.pRLink;
	bHead = bList->headerNode.pRLink;
	
	while (aidx--)
	{
		newNode = malloc(sizeof(ListNode));
		newNode->degree = aHead->degree;
		newNode->coef = aHead->coef;
		addPLElement(newList, *newNode);
		free(newNode);
		aHead = aHead->pRLink;
	}
	while (bidx--)
	{
		newNode = malloc(sizeof(ListNode));
		newNode->degree = bHead->degree;
		newNode->coef = bHead->coef;
		addPLElement(newList, *newNode);
		free(newNode);
		bHead = bHead->pRLink;
	}
	newNode = NULL;
	// 계수 0된 쉑 free
	deletePolynomialList(aList);
	deletePolynomialList(bList);
	return (newList);
}