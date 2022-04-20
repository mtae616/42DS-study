#ifndef _LINKEDLIST_
#define _LINKEDLIST_


#include <stdlib.h>
#include <stdio.h>

typedef struct ListNodeType
{
	int coef;
	int	degree;
	struct ListNodeType *pLLink;
	struct ListNodeType *pRLink;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;	// 현재 저장된 원소의 개수
	ListNode headerNode;		// 헤더 노드(Header Node)
} LinkedList;

LinkedList* createPolynomialList();
int addPLElement(LinkedList* pList, ListNode element);
int	removePLElement(LinkedList *pList, int position);
ListNode	*getPLElement(LinkedList* pList, int position);

void	clearPolynomialList(LinkedList *pList);
int	getPolynomialListLength(LinkedList *pList);
void	deletePolynomialList(LinkedList *pList);
void	displayPLLinkedList(LinkedList *pList);
LinkedList	*plus(LinkedList *aList, LinkedList *bList);
LinkedList	*minus(LinkedList *aList, LinkedList *bList);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE	1
#define FALSE	0
#define ZERO(x) (x == 0 ? TRUE : FALSE)
#define UPPER_ZERO(x) (x > 0 ? TRUE : FALSE)
#define NULLCHECK(x) (!x ? NULL : x)
#define IS_BIG(x, y) (x < y ? TRUE : FALSE)
#define IS_LOWER(x, y) (x > y ? TRUE : FALSE)
#define IS_SAME(x, y) (x == y ? TRUE : FALSE)

#endif
