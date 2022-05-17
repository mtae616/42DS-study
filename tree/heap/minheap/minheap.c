#include "minheap.h"

Heap*	createHeap(int maxElementCount)
{
    Heap*   temp;

    temp = calloc(1, sizeof(Heap));
    temp->pElement = calloc(maxElementCount, sizeof(HeapNode));
    return (temp);
}

int insertMinHeapNode(Heap* hList, HeapNode element)
{
    int i;

    i = hList->currentElementCount;
    while(i != 0 && hList->pElement[i / 2].key > element.key)
    {
        hList->pElement[i] = hList->pElement[i / 2];
        i = i / 2;
    }
    hList->pElement[i] = element;
    hList->currentElementCount += 1;
    return (TRUE);
}

HeapNode	popMinHeapNode(Heap* hList)
{
    HeapNode    root = hList->pElement[0];
    HeapNode    temp = hList->pElement[hList->currentElementCount - 1];
    int parent, child;

    hList->currentElementCount -= 1;
    parent = 0;
    child = 1;
    while (child <= hList->currentElementCount)
    {
        if ((child < hList->currentElementCount) && hList->pElement[child].key > hList->pElement[child + 1].key) child += 1;
        if (temp.key <= hList->pElement[parent].key) break;
        hList->pElement[parent] = hList->pElement[child];
        parent = child;
        child *= 2;
    }
    hList->pElement[parent] = temp;
    return (root);
}

void deleteMinHeap(Heap* hList)
{
    free(hList->pElement);
    hList->pElement = NULL;
    free(hList);
    hList = NULL;
}

int isMinHeapFull(Heap* hList)
{
    return (hList->currentElementCount == hList->maxElementCount);
}

int	getMinHeapLength(Heap* hList)
{
    return (hList->currentElementCount);
}

int main()
{
    Heap    *temp = createHeap(10);
    HeapNode    buf;

    buf.key = 12;
    insertMinHeapNode(temp, buf);
    buf.key = 10;
    insertMinHeapNode(temp, buf);
    buf.key = 2;
    insertMinHeapNode(temp, buf);
    buf.key = 6;
    insertMinHeapNode(temp, buf);
    buf.key = 9;
    insertMinHeapNode(temp, buf);
    buf.key = 8;
    insertMinHeapNode(temp, buf);
    buf.key = 11;
    insertMinHeapNode(temp, buf);
    popMinHeapNode(temp);
    for(int i = 0; i < 7; i++)
        printf("%d ", temp->pElement[i].key);

    return 0;
}