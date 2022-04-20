#include "doublylist.h"

void	clearDoublyList(DoublyList *pList)
{
    DoublyListNode  *buf;
    DoublyListNode  *next;

    buf = pList->headerNode.pRLink;
    while (UPPER_ZERO(pList->currentElementCount))
    {
        next = buf->pRLink;
        buf->data = 0x00;
        buf->pLLink = NULL;
        buf->pRLink = NULL;
        free(buf);
		pList->currentElementCount--;
        buf = next;
    }
	buf = NULL;
	next = NULL;
	pList->currentElementCount = 0;
}
