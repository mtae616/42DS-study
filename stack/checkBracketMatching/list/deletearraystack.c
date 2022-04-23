#include "arraystack.h"

void deleteArrayStack(ArrayStack* pStack)
{
    free(pStack->pElement);
    pStack->currentElementCount = 0;
    pStack->maxElementCount = 0;
    free(pStack);
    pStack->pElement = NULL;
    pStack = NULL;
}