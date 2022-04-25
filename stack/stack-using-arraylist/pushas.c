#include "arraystack.h"

int pushAS(ArrayStack* pStack, StackNode element) // 스택 삽입
{
    if (pStack->currentElementCount >= pStack->maxElementCount) // 최대 개수를 넘어갈 수 없다.
        return (FALSE);
    pStack->pElement[pStack->currentElementCount].data = element.data;
    pStack->currentElementCount += 1;
    return (TRUE);
}