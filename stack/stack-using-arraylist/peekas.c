#include "arraystack.h"

StackNode* peekAS(ArrayStack* pStack) // 맨 위 노드의 데이터 반환
{
    return (&pStack->pElement[pStack->currentElementCount - 1]);
}