#include "polynomial.h"

void	clearPolynomialList(LinkedList *pList)
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