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
    pQueue->pElement[(pQueue->rear) % pQueue->maxElementCount].data = element.data;
    // maxcount로 나눈 나머지 값이 새로운 index가 되게 한다.
    pQueue->rear += 1;
    if (pQueue->rear >= pQueue->maxElementCount)
        pQueue->rear = (pQueue->rear) % pQueue->maxElementCount;
    pQueue->currentElementCount += 1;
    return TRUE;
}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue) // 반환
{
    ArrayQueueNode *temp = calloc(1, sizeof(ArrayQueueNode));
    
    if (isArrayQueueEmpty(pQueue))
        return NULL;
    temp->data = pQueue->pElement[pQueue->front].data;
    pQueue->pElement[pQueue->front].data = 0;
    pQueue->currentElementCount -= 1;
    pQueue->front += 1;
    if (pQueue->front >= pQueue->maxElementCount)
        pQueue->front = (pQueue->front) % pQueue->maxElementCount;
        // maxcount로 나눈 나머지 값이 새로운 Index가 되게 한다.
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
    return (pQueue->currentElementCount == pQueue->maxElementCount);
}

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
    return (pQueue->currentElementCount == 0 ? 1 : 0);
}

int main()
{
    ArrayQueue *temp = createArrayQueue(4);
    ArrayQueueNode buf;
    buf.data = 'a'; // 0
    enqueueAQ(temp, buf);
    buf.data = 'b'; // 1
    enqueueAQ(temp, buf);
    buf.data = 'c'; // 2
    enqueueAQ(temp, buf);
    buf.data = 'd'; // 3
    enqueueAQ(temp, buf);
    dequeueAQ(temp);
    dequeueAQ(temp);
    dequeueAQ(temp);
    dequeueAQ(temp);
    buf.data = 'z'; // 4
    enqueueAQ(temp, buf);
    buf.data = 'u'; // 5
    enqueueAQ(temp, buf);
    
    
    for(int i = 0; i < temp->currentElementCount; i++)
        printf("%c\n", temp->pElement[i].data);
    printf("%d\n", temp->rear);
    printf("%d", temp->front);
    return 0;
}