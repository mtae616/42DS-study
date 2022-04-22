#include "doublylist.h"

DoublyListNode	*getDLElement(DoublyList *pList, int position) // 원하는 node 반환
{
	DoublyListNode	*buf;

	if (position >= pList->currentElementCount / 2) // 중간 기준 왼쪽에 있는 node
	{
		buf = pList->headerNode.pRLink;
		while (UPPER_ZERO(position)) {
			buf = buf->pRLink;
			position--;
		}
	}
	else // 중간 기준 오른쪽에 있는 node
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