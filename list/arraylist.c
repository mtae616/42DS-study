#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

ArrayList* createArrayList(int maxElementCount)
{
    ArrayList *buf;

    buf = malloc(sizeof(ArrayList *));
    if (!buf)
        return(FALSE);
    buf->pElement = malloc(sizeof(int) * maxElementCount + 1);
    if (!(buf->pElement))
        return (FALSE);
    buf->maxElementCount = maxElementCount;
    return (buf);
}

int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
    if (pList->maxElementCount <= position)
        return (FALSE);
    pList->pElement[position] = element;
    pList->currentElementCount += 1;
    return (TRUE);
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
    ArrayListNode *buf;

    buf = malloc(sizeof(ArrayListNode *));
    if (!buf)
        return (NULL);
    buf->data = pList->pElement[position].data;
    return (buf);
}

int main()
{
    ArrayList *new_one;
    ArrayListNode asd;
    asd.data = 5;
    new_one = createArrayList(50);
    int a;
    printf("%d\n", new_one->maxElementCount);
    addALElement(new_one, 0, asd);

    printf("%d", new_one->pElement[0].data);
    // getALElement()
    free(new_one);
    return 0;
}