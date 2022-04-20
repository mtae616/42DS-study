#ifndef _DOUBLYLIST_
#define _DOUBLYLIST_

#include <stdio.h>
#include <stdlib.h>

#define ZERO(x) (x == 0 ? 1 : 0)
#define UPPER_ZERO(x) (x > 0 ? 1 : 0)
#define NULLCHECK(x) (!x ? exit(1) : x)
#define IS_BIG(x, y) (x < y ? 1 : 0)

typedef struct DoublyListNodeType
{
	int data;
	struct DoublyListNodeType	*pLLink;
	struct DoublyListNodeType	*pRLink;
} DoublyListNode;

typedef struct DoublyListType
{
	int	currentElementCount;	
	DoublyListNode	headerNode;
}	DoublyList;

DoublyList		*createDoublyList();
DoublyListNode	*getDLElement(DoublyList *pList, int position);

int				addDLElement(DoublyList *pList, int position, DoublyListNode element);
int				removeDLElement(DoublyList *pList, int position);
int				getDoublyListLength(DoublyList *pList);

void			*nullcheck(void *ptr);

void			deleteDoublyList(DoublyList *pList);
void			clearDoublyList(DoublyList *pList);
void			displayDoublyList(DoublyList *pList);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif