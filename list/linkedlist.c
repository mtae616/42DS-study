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
	ListNode	*curr;
	
	if (!pList)
		return (FALSE);
	i = 0;
	if (pList->currentElementCount == 0) // header
	{
		pList->headerNode = element;
		pList->currentElementCount += 1;
		pList->headerNode.pLink = NULL;
		return (TRUE);
	}
	buf = &(pList->headerNode);
	i = 1;
	while(buf->pLink != NULL)
	{
		buf = buf->pLink;
		i++;
	}
	if (position == i) // Nodes
	{
		curr = malloc(sizeof(ListNode));
		curr->data = element.data;
		buf->pLink = curr;
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
	if (position == 0) // header
	{
		if (!(buf->pLink)) // dosent have a next one
		{
			buf->data = 0;
			buf->pLink = NULL;
			return (TRUE);
		}
		else // have a next one
		{
			buf->data = 0;
			pList->headerNode = *(buf->pLink);
			return (TRUE);
		}
	}
	while (buf != NULL && i < position)
	{
		if (i + 1 == position)
			prev = buf;
		buf = buf->pLink;
		i++;
	}
	if (buf && i == position) // non header
	{
		if (!(buf->pLink)) // dosent have a next one
		{
			buf->data = 0;
			buf->pLink = NULL;
			free(buf);
			return (TRUE);
		}
		else // have a next one
		{
			next = buf->pLink;
			prev->pLink = next;
			buf->data = 0;
			buf->pLink = NULL;
			free(buf);
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

void deleteLinkedList(LinkedList* pList)
{
	size_t	i;
	ListNode *buf;
	ListNode *next;

	buf = pList->headerNode.pLink;
	i = 1;
	while(i + 2 < pList->currentElementCount)
	{
		next = buf->pLink;
		buf->data = 0;
		buf->pLink = NULL;
		free(buf);
		buf = next;
		i++;
	}
	pList->currentElementCount = 0;
	pList->headerNode.data = 0;
	pList->headerNode.pLink = NULL;
	free(pList);
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
	// ListNode *aa = getLLElement(temp, 1);
	// printf("%d\n", aa->data);
	// clearLinkedList(temp);
	buf = &(temp->headerNode);
	deleteLinkedList(temp);
	while(buf)
	{
		printf("%d\n", buf->data);
		buf = buf->pLink;
	}
	printf("the length %d\n", getLinkedListLength(temp));
	return 0;
}