#include "doublylist.h"

DoublyListNode	*getDLElement(DoublyList *pList, int position)
{
	DoublyListNode	*buf;

	buf = pList->headerNode.pRLink;
	while (UPPER_ZERO(position)) {
		buf = buf->pRLink;
		position--;
	}
	return(buf);
}