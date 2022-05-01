#include "arrayqueue.h"

ArrayQueue* createArrayQueue(int maxElementCount) // Queue 생성
{
    ArrayQueue  *pQueue;

    if (maxElementCount < 0)
        return (NULL);
    pQueue = calloc(1, sizeof(ArrayQueue));
    pQueue->pElement = calloc(maxElementCount, sizeof(char)); // max 만큼 char 배열 생성
    pQueue->maxElementCount = maxElementCount;
    return (pQueue);
}

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element) // 삽입
{
    if (isArrayQueueFull(pQueue))
        return FALSE;
    pQueue->pElement[pQueue->rear].data = element.data; // 무조건 끝에 들어간다.
    pQueue->rear += 1;
    pQueue->currentElementCount += 1;
    return TRUE;
}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue) // 반환
{
    ArrayQueueNode *temp = calloc(1, sizeof(ArrayQueueNode));
    
    if (isArrayQueueEmpty(pQueue))
        return NULL;
    temp->data = pQueue->pElement[pQueue->front].data; // 무조건 앞에 있는 게 반환된다.
    pQueue->pElement[pQueue->front].data = 0;
    pQueue->currentElementCount -= 1;
    pQueue->front += 1;
    return (temp);
}

ArrayQueueNode *peekAQ(ArrayQueue* pQueue) // header 확인
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
