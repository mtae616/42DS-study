#include "doublylist.h"

void	deleteDoublyList(DoublyList *pList)
{
	NULLCHECK(pList);
	clearDoublyList(pList);
	pList->headerNode.pRLink = NULL;
	pList->headerNode.pLLink = NULL;
	free(pList);
	pList = NULL;
}
