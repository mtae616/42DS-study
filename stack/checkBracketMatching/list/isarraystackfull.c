#include "arraystack.h"

int isArrayStackFull(ArrayStack* pStack)
{
    return (pStack->currentElementCount == pStack->maxElementCount);
}