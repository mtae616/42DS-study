#ifndef _CIRCULAR_LIST_
#define _CIRCULAR_LIST_

#include <stdio.h>
#include <stdlib.h>

#define ZERO(x) (x == 0 ? 1 : 0)
#define UPPER_ZERO(x) (x > 0 ? 1 : 0)
#define NULLCHECK(x) (!x ? exit(1) : x)
#define IS_BIG(x, y) (x < y ? 1 : 0)

typedef struct CircularListNodeType
{
	int data;
	struct CircularListNodeType	*pRLink;
} CircularListNode;

typedef struct CircularListType
{
	int	currentElementCount;	
	CircularListNode	headerNode;
}	CircularList;

CircularList		*createCircularList();
CircularListNode	*getCLElement(CircularList *pList, int position);

int	addCLElement(CircularList *pList, int position, CircularListNode element);
int				removeCLElement(CircularList *pList, int position);
int				getCircularListLength(CircularList *pList);

void			deleteCircularList(CircularList *pList);
void			clearCircularList(CircularList *pList);
void			displayCircularList(CircularList *pList);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif