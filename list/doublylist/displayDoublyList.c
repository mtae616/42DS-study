#include "doublylist.h"

void	displayDoublyList(DoublyList *pList)
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