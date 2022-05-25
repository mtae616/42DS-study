#include "linkedstack.h"

StackNode* peekLS(LinkedStack* pStack) // top node 데이터 반환
{
    if(!(pStack->pTopElement))
        return (NULL);
    return (pStack->pTopElement);
}