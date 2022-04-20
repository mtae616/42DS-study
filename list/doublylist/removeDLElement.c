#include "doublylist.h"

int removeDLElement(DoublyList *pList, int position)
{
    DoublyListNode	*buf;

	if (IS_BIG(position, 0) || IS_BIG(pList->currentElementCount, position))
		return (FALSE);
	NULLCHECK(pList);
	if (ZERO(position))
	{
		buf = pList->headerNode.pRLink;
		buf->pRLink->pLLink = buf->pLLink;
		buf->pLLink->pRLink = buf->pRLink;
	}
	else
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
