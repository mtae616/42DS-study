#include "arrayqueue.h"

ArrayQueue* createArrayQueue(int maxElementCount)
{
    ArrayQueue  *pQueue;

    if (maxElementCount < 0)
        return (NULL);
    pQueue = calloc(1, sizeof(ArrayQueue));
    pQueue->pElement = calloc(maxElementCount, sizeof(char));
    pQueue->maxElementCount = maxElementCount;
    return (pQueue);
}

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
    if (isArrayQueueFull(pQueue))
        return FALSE;
    pQueue->pElement[pQueue->rear].data = element.data;
    pQueue->rear += 1;
    pQueue->currentElementCount += 1;
    return TRUE;
}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
    ArrayQueueNode *temp = calloc(1, sizeof(ArrayQueueNode));
    
    if (isArrayQueueEmpty(pQueue))
        return NULL;
    temp->data = pQueue->pElement[pQueue->front].data;
    pQueue->pElement[pQueue->front].data = 0;
    pQueue->currentElementCount -= 1;
    pQueue->front += 1;
    return (temp);
}

ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{
    if (isArrayQueueEmpty(pQueue))
        return NULL;
    return (&pQueue->pElement[pQueue->front]);
}

void deleteArrayQueue(ArrayQueue* pQueue)
{
    free(pQueue->pElement);
    free(pQueue);
    pQueue->pElement = NULL;
    pQueue = NULL;
}

int isArrayQueueFull(ArrayQueue* pQueue)
{
    return (pQueue->rear == pQueue->maxElementCount);
}

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
    return (pQueue->currentElementCount == 0 ? 1 : 0);
}
