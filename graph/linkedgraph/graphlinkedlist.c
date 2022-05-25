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

	// position이 왜 필요하지... 그냥 뒤에다가 넣으면 되는데
	if (pList->currentElementCount != position || position < 0)
		return (FALSE);
	temp = calloc(1, sizeof(ListNode));
	*temp = element;
	temp->data.vertexID = position;
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

int removeLLElement(LinkedList* pList, int position) // 헤더는 못 지우게? || clear 에서?
{
	ListNode	*buf;
	ListNode	*prev;

	if (position < 0 || pList->currentElementCount < position)
		return (FALSE);
	buf = getLLElement(pList, position);
	if (position < pList->currentElementCount - 1) // link 남아 있으면...
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

	nxt = temp->headerNode.pLink;
	for(int i = 0; i < temp->currentElementCount; i++)
	{
		printf("%d", nxt->data.vertexID);
		nxt = nxt->pLink;
	}
	deleteLinkedList(temp);
	system("leaks a.out");
	return 0;
}