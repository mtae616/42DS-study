#include "polynomial.h"

int	removePLElement(LinkedList *pList, int position)
{
	ListNode	*headNode;
	int			i;

	if (position < 0 || position >= pList->currentElementCount)
		return (FALSE);
	i = 0;
	headNode = pList->headerNode.pRLink;
	while (i++ < position)
		headNode = headNode->pRLink;
	headNode->pLLink->pRLink = headNode->pRLink;
	headNode->pRLink->pLLink = headNode->pLLink;
	pList->currentElementCount--;
	if (ZERO(position) && UPPER_ZERO(pList->currentElementCount))
		pList->headerNode.pRLink = headNode->pRLink;
	headNode->pLLink = NULL;
	headNode->pRLink = NULL;
	free(headNode);
	headNode = NULL;
	printf("pList->len = %d\n", pList->currentElementCount);
	return (TRUE);
}