#include "polynomial.h"

LinkedList	*minus(LinkedList *aList, LinkedList *bList)
{
	ListNode	*aHead;
	ListNode	*bHead;
	ListNode	*newNode;
	LinkedList	*newList = createPolynomialList();
	int			aidx = aList->currentElementCount;
	int			bidx = bList->currentElementCount;

	aHead = aList->headerNode.pRLink;
	bHead = bList->headerNode.pRLink;
	
	newNode = malloc(sizeof(ListNode));
	while (aidx--)
	{
		newNode->degree = aHead->degree;
		newNode->coef = aHead->coef;
		addPLElement(newList, *newNode);
		aHead = aHead->pRLink;
	}
	while (bidx--)
	{
		newNode->degree = bHead->degree;
		newNode->coef = -(bHead->coef);
		addPLElement(newList, *newNode);
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