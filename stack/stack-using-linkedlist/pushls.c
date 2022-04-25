#include "linkedstack.h"

int pushLS(LinkedStack* pStack, StackNode element) // 스택에 삽입
{
    StackNode   *new_one;

    new_one = calloc(1, sizeof(StackNode));
    new_one->data = element.data;
    new_one->pLink = pStack->pTopElement;
    pStack->pTopElement = new_one; // top element 갱신
    pStack->currentElementCount += 1;
    return (TRUE);
}