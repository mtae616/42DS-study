#include "doublylist.h"

int removeDLElement(DoublyList *pList, int position) // 개별 node 삭제
{
    DoublyListNode	*buf;

	if (IS_BIG(position, 0) || IS_BIG(pList->currentElementCount, position)) // position이 0 보다 작거나, 현재 node 개수보다 크면 안된다.
		return (FALSE);
	NULLCHECK(pList);
	if (ZERO(position)) // position이 0 일 때
	{
		buf = pList->headerNode.pRLink;
		buf->pRLink->pLLink = buf->pLLink;
		buf->pLLink->pRLink = buf->pRLink;
		pList->headerNode.pRLink = buf->pRLink; // header 갱신
	}
	else // position이 0이 아닐 때
	{
		buf = getDLElement(pList, position);
		buf->pLLink->pRLink = buf->pRLink;
		buf->pRLink->pLLink = buf->pLLink;
	}
	free(buf);
	buf = NULL;
    pList->currentElementCount--;
    return (TRUE);
}
