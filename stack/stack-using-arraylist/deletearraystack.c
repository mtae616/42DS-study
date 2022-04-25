#include "arraystack.h"

void deleteArrayStack(ArrayStack* pStack) // 스택 제거
{
    free(pStack->pElement); // 배열 할당 해제
    pStack->currentElementCount = 0;
    pStack->maxElementCount = 0;
    free(pStack); // 스택 해제
    pStack->pElement = NULL;
    pStack = NULL;
}