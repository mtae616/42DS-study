#include "linkedstack.h"

void deleteLinkedStack(LinkedStack* pStack) // stack 제거
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