#include "arraystack.h"

ArrayStack* createArrayStack(int maxElementCount) // 스택 생성
{
    ArrayStack *lst;

    if (!maxElementCount)
        return (FALSE);
    lst = calloc(1, sizeof(ArrayStack));
    lst->maxElementCount = maxElementCount; // 최대 개수 지정
    lst->pElement = calloc(lst->maxElementCount, sizeof(StackNode));
    return (lst);
}