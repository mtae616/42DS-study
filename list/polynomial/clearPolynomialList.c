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