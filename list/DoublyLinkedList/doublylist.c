#include "doublylist.h"

DoublyList* createDoublyList()
{
	DoublyList *buf;

	buf = (DoublyList *)calloc(1, sizeof(DoublyList));
	
	return (buf);
}

void deleteDoublyList(DoublyList* pList)
{

}

void check_error_up()
{

}

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
	DoublyListNode *buf;
	DoublyListNode *new;

	new = (DoublyListNode *)calloc(1, sizeof(DoublyListNode));
	new->data = element.data;
	if (pList->currentElementCount == 0)
	{
		pList->headerNode.pRLink = new;
		new->pLLink = new;
		new->pRLink = new;
		pList->currentElementCount = 1;
	}
	else
	{
		buf = getDLElement(pList, position - 1);
		new->pLLink = buf;
		buf->pRLink->pLLink= new;
		new->pRLink = buf->pRLink;
		buf->pRLink = new;
		pList->currentElementCount += 1;
	}
	return (TRUE);
}

int removeDLElement(DoublyList* pList, int position)
{
    DoublyListNode *buf;

	buf = getDLElement(pList, position);
    buf->pLLink->pRLink = buf->pRLink;
    buf->pRLink->pLLink = buf->pLLink;
    free(buf);
    buf = NULL;
    pList->currentElementCount--;

    return (TRUE);
}

void clearDoublyList(DoublyList* pList)
{
    DoublyListNode  *buf;
    DoublyListNode  *next;

    buf = pList->headerNode.pRLink;
    while (buf)
    {
        next = buf->pRLink;
        buf->data = 0;
        buf->pLLink = NULL;
        buf->pRLink = NULL;
        free(buf);
        buf = next;
    }
}

int getDoublyListLength(DoublyList* pList)
{
	return (pList->currentElementCount);
}

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
	DoublyListNode	*buf;

	buf = pList->headerNode.pRLink;
	while (position--) {
		buf = buf->pRLink;
	}
	return(buf);
}

void displayDoublyList(DoublyList* pList)
{
	int				i;
	DoublyListNode	*buf;

	i = -1;
	buf = pList->headerNode.pRLink;
	while (++i < pList->currentElementCount) {
		printf("pList[%d] = %d\n",i, buf->data);
		buf = buf->pRLink;
	}
}

int main()
{
	DoublyList	*temp;
	DoublyListNode a;
	DoublyListNode b;
	DoublyListNode c;
	DoublyListNode *d;

	temp = createDoublyList();

	

	a.data = 1;
	a.pLLink = NULL;
	a.pRLink = NULL;
	addDLElement(temp, 0, a);
	b.data = 2;
	b.pLLink = NULL;
	b.pRLink = NULL;
	addDLElement(temp, 1, b);
	c.data = 3;
	c.pLLink = NULL;
	c.pRLink = NULL;
	addDLElement(temp, 2, c);
	displayDoublyList(temp);
	
}