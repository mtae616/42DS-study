#include "arraystack.h"

int isArrayStackEmpty(ArrayStack* pStack)
{
    return (pStack->currentElementCount == 0 ? (TRUE) : (FALSE));
}