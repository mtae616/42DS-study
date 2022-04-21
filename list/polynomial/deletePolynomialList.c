#include "polynomial.h"

void	deletePolynomialList(LinkedList *pList) // 내부 node와 list를 삭제한다.
{
	clearPolynomialList(pList);
	free(pList);
	pList = NULL;
}