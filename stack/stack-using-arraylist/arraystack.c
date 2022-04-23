#include "arraystack.h"

ArrayStack* createArrayStack(int maxElementCount)
{
    ArrayStack *lst;

    lst = calloc(1, sizeof(ArrayStack));
    lst->maxElementCount = maxElementCount;
    lst->pElement = calloc(lst->maxElementCount, sizeof(StackNode));
    return (lst);
}