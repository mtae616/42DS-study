#include "linkedstack.h"

StackNode* peekLS(LinkedStack* pStack)
{
    if(!(pStack->pTopElement))
        return (NULL);
    return (pStack->pTopElement);
}