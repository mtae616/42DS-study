#include "arraystack.h"

StackNode* popAS(ArrayStack* pStack)
{
    StackNode   *buf;

    if (pStack->currentElementCount == 0)
        return (FALSE);
    buf = calloc(1, sizeof(StackNode));
    buf->data = pStack->pElement[pStack->currentElementCount - 1].data;
    pStack->pElement[pStack->currentElementCount - 1].data = 0;
    pStack->currentElementCount -= 1;
    return (buf);
}