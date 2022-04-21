#include "polynomial.h"

ListNode	*getPLElement(LinkedList* pList, int position) // 원하는 position의 node를 보여준다.
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