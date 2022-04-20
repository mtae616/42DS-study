#include "polynomial.h"

void	deletePolynomialList(LinkedList *pList)
{
	clearPolynomialList(pList);
	free(pList);
	pList = NULL;
}