#include "polynomial.h"

LinkedList	*minus(LinkedList *aList, LinkedList *bList) // 다항식의 뺏셈
{
	LinkedList	*newList = createPolynomialList();
	alloc_calc_node(newList, aList, 0);
	alloc_calc_node(newList, bList, 1);
	return (newList);
}