#include "doublylist.h"

DoublyListNode	*getDLElement(DoublyList *pList, int position)
{
	DoublyListNode	*buf;

	if (position >= pList->currentElementCount / 2)
	{
		buf = pList->headerNode.pRLink;
		while (UPPER_ZERO(position)) {
			buf = buf->pRLink;
			position--;
		}
	}
	else
	{
		position = pList->currentElementCount - position - 1;
		buf = pList->headerNode.pRLink;
		while (UPPER_ZERO(position)) {
			buf = buf->pRLink;
			position--;
		}
	}
	return(buf);
}