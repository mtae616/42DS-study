#include "polynomial.h"

LinkedList	*createPolynomialList()
{
	LinkedList	*lst;

	lst = calloc(1, sizeof(LinkedList));
	NULLCHECK(lst);
	lst->currentElementCount = 0;
	return (lst);
}