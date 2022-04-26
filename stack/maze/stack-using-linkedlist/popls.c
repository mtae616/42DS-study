#include "linkedstack.h"

StackNode* popLS(LinkedStack* pStack) // 맨 위 노드 반환
{
    StackNode   *buf;
    StackNode   *delNode;

    if(!(pStack->pTopElement))
        return (NULL);
    buf = calloc(1, sizeof(StackNode));
    buf->data = pStack->pTopElement->data;
    delNode = pStack->pTopElement;
    // delNode->data = 0;
    pStack->pTopElement = delNode->pLink; // header 갱신
    delNode->pLink = NULL;
    free(delNode);
    delNode = NULL;
    pStack->currentElementCount -= 1;
    return (buf);
}