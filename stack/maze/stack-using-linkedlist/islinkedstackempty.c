#include "linkedstack.h"

int isLinkedStackEmpty(LinkedStack* pStack)
{
    return (pStack->currentElementCount == 0 ? (TRUE) : (FALSE));
}