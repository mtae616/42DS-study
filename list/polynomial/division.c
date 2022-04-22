#include "polynomial.h"

LinkedList	*division(LinkedList *aList, LinkedList *bList) // 나눗셈 연산
{
	int	alen = getPolynomialListLength(aList) - 1;
	int	blen;
    LinkedList	*newList = createPolynomialList();
	ListNode	*newNode = calloc(1, sizeof(ListNode));
	ListNode	*aHeadNode = aList->headerNode.pRLink;
	ListNode	*bHeadNode;
	
	while(alen--) {
		blen = getPolynomialListLength(bList) - 1;
		bHeadNode = bList->headerNode.pRLink;
		while(blen--) {
			newNode->coef = aHeadNode->coef / bHeadNode->coef; // 각 계수는 빼준다.
			newNode->degree = aHeadNode->degree - bHeadNode->degree; // 각 차수는 나눠준다.
			addPLElement(newList, *newNode);
			bHeadNode = bHeadNode->pRLink;
		}
		aHeadNode = aHeadNode->pRLink;
	}
    deletePolynomialList(aList);
    deletePolynomialList(bList);
    aList = NULL;
    bList = NULL;
	return (newList);
}