#include "graphlinkedlist.h"

LinkedList* createLinkedList()
{
	LinkedList *temp;
	temp = calloc(1, sizeof(LinkedList));

	return (temp);
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode	*temp;
	ListNode	*buf;
	int			i = 1;

	temp = calloc(1, sizeof(ListNode));
	*temp = element;
	temp->data.vertexID = position;
	temp->pLink = NULL; // element 포인팅하면서 쓰레기 값 들어오는 듯 Stack이라
	if (!pList->currentElementCount)
		pList->headerNode.pLink = temp; // header
	else
	{
		buf = pList->headerNode.pLink;
		while(buf->pLink)
			buf = buf->pLink;
		buf->pLink = temp;
	}
	pList->currentElementCount += 1;
	return (TRUE);
}

int removeLLElement(LinkedList* pList, int position)
{
	ListNode	*buf;
	ListNode	*prev;

	if (!(getLLElement(pList, position)) || !(pList->currentElementCount))
		return (FALSE);
	buf = pList->headerNode.pLink;
	while(buf->pLink)
	{
		if (buf->data.vertexID == position)
			break ;
		prev = buf;
		buf = buf->pLink;
	}
	if (buf == pList->headerNode.pLink)
		pList->headerNode.pLink = buf->pLink;
	else
		prev->pLink = buf->pLink;
	free(buf);
	pList->currentElementCount -= 1;
	return (TRUE);
}

ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode	*temp;

	temp = pList->headerNode.pLink;
	while (temp)
	{
		if (temp->data.vertexID == position)
			break;
		temp = temp->pLink;
	}
	return (temp);
}

void clearLinkedList(LinkedList* pList)
{
	ListNode	*del;
	ListNode	*next;

	del = pList->headerNode.pLink;
	while(pList->currentElementCount)
	{
		next = del->pLink;
		free(del);
		del = next;
		pList->currentElementCount -= 1;
	}
}

int getLinkedListLength(LinkedList* pList)
{
	return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList* pList)
{
	clearLinkedList(pList);
	free(pList);
}

int main()
{
	LinkedList	*temp = createLinkedList();
	ListNode	buf;
	ListNode	*nxt;

	addLLElement(temp, 0, buf);
	addLLElement(temp, 1, buf);
	addLLElement(temp, 2, buf);
	removeLLElement(temp, 0);

	nxt = temp->headerNode.pLink;
	for(int i = 0; i < temp->currentElementCount; i++)
	{
		printf("%d", nxt->data.vertexID);
		nxt = nxt->pLink;
	}
	// deleteLinkedList(temp);
	// system("leaks a.out");
	return 0;
}