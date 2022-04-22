#include "doublylist.h"

void	displayDoublyList(DoublyList *pList) // node 전부 출력
{
	int				i;
	DoublyListNode	*buf;

	i = 0;
	buf = pList->headerNode.pRLink;
	while (IS_BIG(i, pList->currentElementCount))
	{
		printf("pList[%d] = %d\n", i++, buf->data);
		buf = buf->pRLink;
	}
}