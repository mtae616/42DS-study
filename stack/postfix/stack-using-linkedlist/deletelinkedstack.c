#include "linkedstack.h"

void deleteLinkedStack(LinkedStack* pStack)
{
    StackNode   *buf;
    StackNode   *next;

    buf = pStack->pTopElement;
    while(buf)
    {
        next = buf->pLink;
        buf->data = 0;
        buf->pLink = NULL;
        free(buf);
        buf = NULL;
        buf = next;
    }
    pStack->pTopElement = NULL;
}