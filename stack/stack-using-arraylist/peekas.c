#include "arraystack.h"

StackNode* peekAS(ArrayStack* pStack)
{
    return (&pStack->pElement[pStack->currentElementCount - 1]);
}