#include "arraystack.h"

StackNode* peekAS(ArrayStack* pStack)
{
    StackNode   *buf;

    buf = calloc(1, sizeof(StackNode));
    buf->data = pStack->pElement[pStack->currentElementCount - 1].data;
    return (buf);
}