#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList* createLinkedList()
{
	LinkedList* buf;

	buf = malloc(sizeof(LinkedList));
	if (!buf)
		return (NULL);
	buf->currentElementCount = 0;
	return (buf);
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	int		i;
	ListNode	*buf;
	// ListNode	*new;
	
	if (!pList)
		return (FALSE);
	i = 0;
	if (pList->currentElementCount == 0)
	{
		pList->headerNode = element;
		pList->currentElementCount = 1;
		pList->headerNode.pLink = NULL;
		return (TRUE);
	}
	buf = &(pList->headerNode);
	while(buf)
	{
		buf = buf->pLink;
		i++;
	}
	// new = malloc(sizeof(ListNode));
	// new->data = element.data;
	// new->pLink = NULL;
	// printf("%d %d\n", i, position);
	if (position == i)
	{
		buf->pLink = &element;
		pList->currentElementCount += 1;
		return (TRUE);
	}
	else
		return (FALSE);
}

int removeLLElement(LinkedList* pList, int position)
{
	size_t		i;
	ListNode	*buf;
	ListNode	*prev;
	ListNode	*next;

	if (!pList)
		return (FALSE);
	i = 0;
	buf = &(pList->headerNode);
	if (position == 0)
	{
		if (!(buf->pLink))
		{
			buf->data = 0;
			buf->pLink = NULL;
			return (TRUE);
		}
		else
		{
			buf->data = 0;
			pList->headerNode = *(buf->pLink);
			return (TRUE);
		}
	}
	while (buf && i < position)
	{
		if (i + 1 == position)
			prev = buf;
		buf = buf->pLink;
		i++;
	}
	if (buf && i == position)
	{
		if (!(buf->pLink))
		{
			buf->data = 0;
			buf->pLink = NULL;
			return (TRUE);
		}
		else
		{
			next = buf->pLink;
			prev->pLink = next;
			buf->data = 0;
			buf->pLink = NULL;
			return (TRUE);
		}
	}
	return (FALSE);
}

ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode *buf;
	size_t	i;

	buf = &(pList->headerNode);
	i = 0;
	while(buf && i < position)
	{
		buf = buf->pLink;
		i++;
	}
	if (buf && i == position)
		return (buf);
	return (NULL);
}

void clearLinkedList(LinkedList* pList)
{
	ListNode *buf;
	ListNode *next;

	buf = &(pList->headerNode);
	while(buf)
	{
		next = buf->pLink;
		buf->data = 0;
		buf = next;
	}
}

int getLinkedListLength(LinkedList* pList)
{
	return (pList->currentElementCount);
}

int main()
{
	LinkedList *temp;
	
	ListNode a;
	ListNode b;
	ListNode c;
	ListNode d;

	a.data = 5;
	a.pLink = NULL;

	b.data = 1;
	b.pLink = NULL;

	c.data = 3;
	c.pLink = NULL;

	d.data = 4;
	d.pLink = NULL;

	temp = createLinkedList();
	addLLElement(temp, 0, a);
	addLLElement(temp, 1, b);
	addLLElement(temp, 2, c);
	addLLElement(temp, 3, d);
	
	ListNode *buf = &(temp->headerNode);

	while(buf)
	{
		printf("%d\n", buf->data);
		buf = buf->pLink;
	}
	printf("the lenth %d\n", temp->currentElementCount);

	// ListNode *aa = getLLElement(temp, 1);
	// printf("%d\n", aa->data);
	clearLinkedList(temp);
	
	buf = &(temp->headerNode);

	while(buf)
	{
		printf("%d\n", buf->data);
		buf = buf->pLink;
	}

	return 0;
}