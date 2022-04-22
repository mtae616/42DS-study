#include "polynomial.h"

void	displayPLLinkedList(LinkedList *pList) // 내부 node 전부를 보여준다.
{
	ListNode	*head;
	int			idx = pList->currentElementCount;

	head = pList->headerNode.pRLink;
	while (idx)
	{
		if (idx == pList->currentElementCount)
		{
			if (head->degree == 0) // degree 0 이면 x 출력 안 함
				printf("%d^%d ", head->coef, head->degree);	
			else
				printf("%dx^%d ", head->coef, head->degree);
		}
		else if (head->coef > 0)
		{
			if (head->degree == 0)
				printf("%d^%d ", head->coef, head->degree);	
			else
				printf("+ %dx^%d ", head->coef, head->degree);
		}
		else
		{
			if (head->degree == 0)
				printf("%d^%d ", head->coef, head->degree);	
			else
				printf("- %dx^%d ", -head->coef, head->degree);
		}
		head = head->pRLink;
		idx--;
	}
	printf("\n");
}