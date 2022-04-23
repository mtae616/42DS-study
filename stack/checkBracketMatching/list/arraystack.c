#include "arraystack.h"

ArrayStack* createArrayStack(int maxElementCount)
{
    ArrayStack *lst;

    if (!maxElementCount)
        return (FALSE);
    lst = calloc(1, sizeof(ArrayStack));
    lst->maxElementCount = maxElementCount;
    lst->pElement = calloc(lst->maxElementCount, sizeof(StackNode));
    return (lst);
}