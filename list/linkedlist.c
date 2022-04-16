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
	buf->headerNode.data = 0;
	buf->headerNode.pLink = NULL;
	return (buf);
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	int		i;
	ListNode	*buf;
	ListNode	*curr;
	ListNode	*prev;
	
	if (!pList)
		return (FALSE);
	// if (position == 0 && pList->currentElementCount == 0) // header
	// {
	// 	pList->headerNode = element;
	// 	pList->currentElementCount = 1;
	// 	pList->headerNode.pLink = NULL;
	// 	return (TRUE);
	// }
	// else if (position == 0 && pList->currentElementCount != 0)
	// {

	// }

	if(position == 0)
	{
		if (pList->currentElementCount == 0)
		{
			pList->headerNode = element;
			pList->currentElementCount = 1;
			pList->headerNode.pLink = NULL;
			return (TRUE);
		}
		else
		{
			// element.pLink = &(pList->headerNode);
			// pList->headerNode = element;
			//s~
			curr = malloc(sizeof(ListNode));
			curr->data = element.data;
			// curr->pLink = pList->headerNode;
			// prev->pLink = curr;
			curr->pLink = &(pList->headerNode);
			pList->headerNode = *curr;
			pList->currentElementCount += 1;
			//e
			return (TRUE);
		}
	}
	buf = &(pList->headerNode);
	i = 0;
	while(buf && i < position)
	{
		if (i + 1 == position)
			prev = buf;
		buf = buf->pLink;
		i++;
	}
	if (position == i) // Nodes
	{
		curr = malloc(sizeof(ListNode));
		curr->data = element.data;
		curr->pLink = buf;
		prev->pLink = curr;
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
			pList->currentElementCount -= 1;
			return (TRUE);
		}
		else // have a next one
		{
			buf->data = 0;
			next = buf->pLink;
			pList->headerNode = *next;
			next = NULL;
			pList->currentElementCount -= 1;
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
			pList->currentElementCount -= 1;
			return (TRUE);
		}
		else // have a next one
		{
			next = buf->pLink;
			prev->pLink = next;
			buf->data = 0;
			buf->pLink = NULL;
			free(buf);
			pList->currentElementCount -= 1;
			return (TRUE);
		}
	}
	return (FALSE);
}

ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode *buf;
	size_t	i;

	if (!pList)
		return (FALSE);
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

	buf = pList->headerNode.pLink;
	while(buf)
	{
		next = buf->pLink;
		buf->data = 0;
		free(buf);
		buf = next;
	}
	pList->headerNode.data = 0;
	pList->currentElementCount = 0;
	pList->headerNode.pLink = NULL;
}

int getLinkedListLength(LinkedList* pList)
{
	return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList* pList)
{
	ListNode *buf;
	ListNode *next;

	buf = pList->headerNode.pLink;
	while(buf)
	{
		next = buf->pLink;
		buf->data = 0;
		buf->pLink = NULL;
		free(buf);
		buf = next;
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
	ListNode e;

	a.data = 5;
	a.pLink = NULL;

	b.data = 1;
	b.pLink = NULL;

	c.data = 3;
	c.pLink = NULL;

	d.data = 4;
	d.pLink = NULL;

	e.data = 19;
	e.pLink = NULL;

	temp = createLinkedList();
	addLLElement(temp, 0, a); // 5 
	addLLElement(temp, 1, b); // 1
	addLLElement(temp, 2, c); // 3
	addLLElement(temp, 3, d); // 4
	addLLElement(temp, 0, e); // 19
	
	ListNode *buf = &(temp->headerNode);

	while(buf)
	{
		printf("%d\n", buf->data);
		buf = buf->pLink;
	}
	// removeLLElement(temp, 1);
	// ListNode *aa = getLLElement(temp, 1);
	// printf("thats what im talking about %d\n", aa->data);
	// clearLinkedList(temp);
	printf("==================remove header=======\n");
	buf = &(temp->headerNode);
	// deleteLinkedList(temp);
	while(buf)
	{
		printf("%d\n", buf->data);
		buf = buf->pLink;
	}
	printf("the length %d\n", getLinkedListLength(temp));
	return 0;
}