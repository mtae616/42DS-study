#include "doublylist.h"

void	deleteDoublyList(DoublyList *pList) // list 까지 생성
{
	NULLCHECK(pList);
	clearDoublyList(pList);
	pList->headerNode.pRLink = NULL;
	pList->headerNode.pLLink = NULL;
	free(pList);
	pList = NULL;
}
