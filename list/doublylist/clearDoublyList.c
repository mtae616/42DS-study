#include "doublylist.h"

void	clearDoublyList(DoublyList *pList) // 내부 node 전체 삭제
{
    DoublyListNode  *buf;
    DoublyListNode  *next;

    buf = pList->headerNode.pRLink;
    while (UPPER_ZERO(pList->currentElementCount)) // 현재 node 개수로 반복문을 돌려준다.
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
