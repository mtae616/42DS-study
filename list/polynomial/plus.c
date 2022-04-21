#include "polynomial.h"

LinkedList	*plus(LinkedList *aList, LinkedList *bList) // 다항식의 덧셈
{
	LinkedList	*newList = createPolynomialList();
	alloc_calc_node(newList, aList, 0);
	alloc_calc_node(newList, bList, 0);
	return (newList);
}