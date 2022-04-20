#include "doublylist.h"

int main()
{
	DoublyList	*temp;
	DoublyListNode a;
	DoublyListNode b;
	DoublyListNode c;
	DoublyListNode *d;

	temp = createDoublyList();

	a.data = 1;
	a.pLLink = NULL;
	a.pRLink = NULL;
	addDLElement(temp, 0, a);
	b.data = 2;
	b.pLLink = NULL;
	b.pRLink = NULL;
	addDLElement(temp, 1, b);
	c.data = 3;
	c.pLLink = NULL;
	c.pRLink = NULL;
	addDLElement(temp, 2, c);
	displayDoublyList(temp);
	clearDoublyList(temp);
	printf("===================================\n");
	displayDoublyList(temp);
	printf("===================================\n");
	for (int i=0; i < 10; i++)
	{
		d = malloc(sizeof(DoublyListNode));
		d->data = i;
		d->pLLink = NULL;
		d->pRLink = NULL;
		addDLElement(temp, i, *d);
		printf("i = %d\n", i);
		printf("length = %d\n", temp->currentElementCount);
		displayDoublyList(temp);
		printf("===================================\n");
		free(d);
		d = NULL;
	}
	printf("===================================\n");
	for(int i=9; i >= 0; i--)
	{
		printf("i = %d\n", i);
		printf("length = %d\n", temp->currentElementCount);
		removeDLElement(temp, i);
		displayDoublyList(temp);
		printf("===================================\n");
	}
	a.data = 9999;
	a.pLLink = NULL;
	a.pRLink = NULL;
	addDLElement(temp, 0, a);
	a.data = 8888;
	a.pLLink = NULL;
	a.pRLink = NULL;
	addDLElement(temp, 0, a);
	a.data = 7777;
	a.pLLink = NULL;
	a.pRLink = NULL;
	addDLElement(temp, 10, a);
	displayDoublyList(temp);
	printf("======================================\n");
	deleteDoublyList(temp);
	temp = NULL;
	system("leaks a.out > leaks_result; cat leaks_result | \
        grep leaked && rm -rf leaks_result");
	return (0);
}