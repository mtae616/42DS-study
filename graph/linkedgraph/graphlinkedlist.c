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

	if (pList->currentElementCount != position || position < 0)
		return (FALSE);
	temp = calloc(1, sizeof(ListNode));
	*temp = element;
	temp->pLink = NULL; // element 포인팅하면서 쓰레기 값 들어오는 듯 Stack이라
	if (!pList->currentElementCount)
		pList->headerNode.pLink = temp; // header
	else
	{
		buf = getLLElement(pList, position - 1);
		buf->pLink = temp;
	}
	pList->currentElementCount += 1;
	return (TRUE);
}

int removeLLElement(LinkedList* pList, int position)
{
	ListNode	*buf;
	ListNode	*prev;

	if (position < 0 || pList->currentElementCount < position)
		return (FALSE);
	buf = getLLElement(pList, position);
	if (!buf)
		return (FALSE);
	if (position == 0)
		pList->headerNode.pLink = buf->pLink;
	else if (position < pList->currentElementCount - 1) // link 남아 있으면...
	{
		prev = getLLElement(pList, position - 1);
		prev->pLink = buf->pLink;
	}
	free(buf);
	pList->currentElementCount -= 1;
	return (TRUE);
}

ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode	*temp;
	int			i = 0;

	temp = pList->headerNode.pLink;
	while (i < position)
	{
		temp = temp->pLink;
		i++;
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

// int main()
// {
// 	LinkedList	*temp = createLinkedList();
// 	ListNode	buf;
// 	ListNode	*nxt;

// 	buf.data.vertexID = 1;
// 	addLLElement(temp, 0, buf);

// 	buf.data.vertexID = 2;
// 	addLLElement(temp, 1, buf);

// 	buf.data.vertexID = 3;
// 	addLLElement(temp, 2, buf);
	
// 	removeLLElement(temp, 0);

// 	nxt = temp->headerNode.pLink;
// 	for(int i = 0; i < temp->currentElementCount; i++)
// 	{
// 		printf("%d ", nxt->data.vertexID);
// 		nxt = nxt->pLink;
// 	}
// 	// deleteLinkedList(temp);
// 	// system("leaks a.out");
// 	return 0;
// }