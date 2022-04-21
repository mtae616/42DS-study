#include "polynomial.h"

LinkedList	*createPolynomialList() // list를 생성한다.
{
	LinkedList	*lst;

	lst = calloc(1, sizeof(LinkedList));
	NULLCHECK(lst);
	lst->currentElementCount = 0;
	return (lst);
}