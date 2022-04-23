#include "arraystack.h"

int pushAS(ArrayStack* pStack, StackNode element)
{
    if (pStack->currentElementCount >= pStack->maxElementCount)
        return (FALSE);
    pStack->pElement[pStack->currentElementCount].data = element.data;
    pStack->currentElementCount += 1;
    return (TRUE);
}