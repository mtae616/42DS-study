#include "polynomial.h"

int	find_degree(LinkedList *pList, ListNode element)
{
	ListNode	*headNode;
	int			i;

	headNode = pList->headerNode.pRLink->pLLink;
	i = pList->currentElementCount;
	while (i-- && !(headNode->degree == element.degree))
		headNode = headNode->pLLink;
	if (headNode->degree == element.degree)
	{
		headNode->coef += element.coef;
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
	if (ZERO(pList->currentElementCount)) {
		pList->headerNode.pRLink = newNode;
		newNode->pLLink = pList->headerNode.pRLink;
		newNode->pRLink = newNode;
	}
	else 
	{
		if (find_degree(pList, element))
		{
			free(newNode);
			newNode = NULL;
			return (TRUE);
		}
		i = 0;
		headNode = pList->headerNode.pRLink->pLLink;
		while (IS_BIG(headNode->degree, newNode->degree))
		{
			if (i++ == pList->currentElementCount)
				break ;
			headNode = headNode->pLLink;
		}
		newNode->pLLink = headNode;
		newNode->pRLink = headNode->pRLink;
		headNode->pRLink->pLLink = newNode;
		headNode->pRLink = newNode;
		headNode = &(pList->headerNode);
		if (headNode->pRLink->pLLink->degree - headNode->pRLink->degree > 0)
			headNode->pRLink = headNode->pRLink->pLLink;
	}
	pList->currentElementCount++;
	return (TRUE);
}
