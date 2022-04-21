#include "polynomial.h"

int	removePLElement(LinkedList *pList, int position) // 개별 node 삭제
{
	ListNode	*headNode;
	int			i;

	if (position < 0 || position >= pList->currentElementCount)
	// position이 음수이거나, 현재 node 개수 이상일 수 없다.
		return (FALSE);
	i = 0;
	headNode = pList->headerNode.pRLink;
	while (i++ < position)
		headNode = headNode->pRLink;
	headNode->pLLink->pRLink = headNode->pRLink;
	headNode->pRLink->pLLink = headNode->pLLink;
	pList->currentElementCount--;
	if (ZERO(position) && UPPER_ZERO(pList->currentElementCount)) // 만약 header node 라면
		pList->headerNode.pRLink = headNode->pRLink; // header를 갱신한다.
	headNode->pLLink = NULL;
	headNode->pRLink = NULL;
	free(headNode);
	headNode = NULL;
	return (TRUE);
}