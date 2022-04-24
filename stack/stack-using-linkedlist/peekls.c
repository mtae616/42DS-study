#include "linkedstack.h"

StackNode* peekLS(LinkedStack* pStack)
{
    StackNode   *buf;

    if(!(pStack->pTopElement))
        return (NULL);
    buf = calloc(1, sizeof(StackNode));
    buf->data = pStack->pTopElement->data;
    return (buf);
}