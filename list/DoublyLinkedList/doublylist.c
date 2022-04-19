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

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
	DoublyListNode *buf;
	DoublyListNode *new;

	buf = getDLElement(pList, position);
	new = (DoublyListNode *)calloc(1, sizeof(DoublyListNode));
	new = &element;
	new->pRLink = buf;
	new->pLLink = buf->pLLink;
	buf->pLLink->pRLink = new;
}

int removeDLElement(DoublyList* pList, int position)
{

}

void clearDoublyList(DoublyList* pList)
{

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
	while (++i <= pList->currentElementCount) {
		printf("pList[%d] = %d",i, buf->data);
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
	a.pRLink = &b;

	temp->headerNode.pRLink = &a;
	
	b.data = 2;
	b.pLLink = &a;
	b.pRLink = &c;

	c.data = 3;
	c.pLLink = &b;
	c.pRLink = NULL;

	d = malloc(sizeof(DoublyListNode));
	d = getDLElement(temp, 2);
	printf("%d", d->data);
	
}