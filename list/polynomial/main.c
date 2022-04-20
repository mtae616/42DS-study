#include "polynomial.h"
#include <time.h>

int	main(void)
{
	LinkedList	*lst;
	ListNode	*elem = malloc(sizeof(ListNode));
	ListNode	*elem2 = malloc(sizeof(ListNode));
	ListNode	*elem3 = malloc(sizeof(ListNode));
	ListNode	*elem4 = malloc(sizeof(ListNode));
	ListNode	*buf;
	lst = createPolynomialList();
	ListNode	*elem6 = malloc(sizeof(ListNode));
	elem6->degree = 1;
	elem6->coef = 1;
	addPLElement(lst, *elem6);

	elem->coef = 3;
	elem->degree = 3;
	addPLElement(lst, *elem);

	elem2->coef = 4;
	elem2->degree = 4;
	addPLElement(lst, *elem2);

	elem3->coef = 2;
	elem3->degree = 2;
	addPLElement(lst, *elem3);

	elem4->coef = 5;
	elem4->degree = 5;
	addPLElement(lst, *elem4);

	ListNode	*elem5 = malloc(sizeof(ListNode));
	elem5->degree = 5;
	elem5->coef = 1000;
	addPLElement(lst, *elem5);


	LinkedList *lst2 = createPolynomialList();
	ListNode	*elem8 = malloc(sizeof(ListNode));
	elem8->degree = 1;
	elem8->coef = 1;
	addPLElement(lst2, *elem8);

	elem->coef = -3;
	elem->degree = 3;
	addPLElement(lst2, *elem);

	elem2->coef = 4;
	elem2->degree = 4;
	addPLElement(lst2, *elem2);

	elem3->coef = -2;
	elem3->degree = 2;
	addPLElement(lst2, *elem3);

	elem4->coef = 5;
	elem4->degree = 5;
	addPLElement(lst2, *elem4);

	ListNode	*e7 = malloc(sizeof(ListNode));
	e7->degree = 5;
	e7->coef = 1000;
	addPLElement(lst2, *e7);
	printf("================================================\n");
	// buf = lst->headerNode.pRLink;
	displayPLLinkedList(lst);
	buf = getPLElement(lst, 0);
	printf("buf = %dx^%d\n", buf->coef, buf->degree);
	buf = getPLElement(lst2, 0);
	printf("buf = %dx^%d\n", buf->coef, buf->degree);
	printf("================================================\n");
	displayPLLinkedList(lst2);
	// for (int i = 0; i < lst->currentElementCount; i++)
	// {
	// 	printf("i : %d coef : %d degree : %d\n", i, buf->coef, buf->degree);
	// 	buf = buf->pRLink;
	// }
	printf("================================================\n");
	// removePLElement(lst2, 4);
	// buf = lst2->headerNode.pRLink;
	// for (int i = 0; i < lst2->currentElementCount; i++)
	// {
	// 	printf("i : %d coef : %d degree : %d\n", i, buf->coef, buf->degree);
	// 	buf = buf->pRLink;
	// }
	printf("================================================\n");
	LinkedList *lst3 = minus(lst, lst2);
	buf = lst3->headerNode.pRLink;
	for (int i = 0; i < lst3->currentElementCount; i++)
	{
		printf("i : %d coef : %d degree : %d\n", i, buf->coef, buf->degree);
		buf = buf->pRLink;
	}
	printf("================================================\n");
	printf("lst3 len = %d\n", lst3->currentElementCount);
	printf("lst2 len = %d\n", lst2->currentElementCount);
	printf("lst len = %d\n", lst->currentElementCount);
	deletePolynomialList(lst3);
	system("leaks a.out > leaks_result; cat leaks_result | \
        grep leaked && rm -rf leaks_result");
	return (0);
}
