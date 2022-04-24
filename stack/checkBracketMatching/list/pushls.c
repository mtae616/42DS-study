#include "linkedstack.h"

int pushLS(LinkedStack* pStack, StackNode element)
{
    StackNode   *new_one;

    new_one = calloc(1, sizeof(StackNode));
    new_one->data = element.data;
    new_one->pLink = pStack->pTopElement;
    pStack->pTopElement = new_one;
    pStack->currentElementCount += 1;
    return (TRUE);
}