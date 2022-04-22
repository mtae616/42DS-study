#include "doublylist.h"

int addDLElement(DoublyList	*pList, int position, DoublyListNode element) // node 생성
{
	DoublyListNode *buf;
	DoublyListNode *new;

	if (position < 0 || pList->currentElementCount < position) // position이 음수이거나, position이 더 클 수 없다.
        return (FALSE);
	new = (DoublyListNode *)calloc(1, sizeof(DoublyListNode));
	NULLCHECK(new);
	new->data = element.data;
	if (ZERO(pList->currentElementCount)) // 만약 첫 node 라면
	{
		pList->headerNode.pRLink = new; // right, left를 자기 자신으로 둔다.
		new->pLLink = new;
		new->pRLink = new;
		pList->currentElementCount = 1;
	}
	else
	{
		buf = getDLElement(pList, position - 1); // 삽입할 위치 전의 것을 가져온다.
		new->pLLink = buf;
		new->pRLink = buf->pRLink;
		buf->pRLink->pLLink = new;
		buf->pRLink = new;
		pList->currentElementCount += 1;
	}
	return (TRUE);
}
