#include "polynomial.h"

ListNode	*getPLElement(LinkedList* pList, int position)
{
	ListNode	*head;

	head = pList->headerNode.pRLink;
	while (position)
	{
		head = head->pRLink;
		position -= 1;
	}
	return (head);
}