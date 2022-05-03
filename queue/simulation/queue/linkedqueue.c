#include "linkedqueue.h"

LinkedQueue* createLinkedQueue()
{
    LinkedQueue *temp;

    temp = calloc(1, sizeof(LinkedQueue));
    return (temp);
}

int insertLQ(LinkedQueue* pQueue, QueueNode element)
{
    QueueNode *temp = calloc(1, sizeof(QueueNode));

    *temp = element;
    if (isLinkedQueueEmpty(pQueue)) // node가 없을 때
    {
        pQueue->pFrontNode = temp; // front 는 자기 자신
        pQueue->pRearNode = temp; // rear 는 자기 자신
        pQueue->currentElementCount += 1;
        return (TRUE);
    }
    pQueue->pRearNode->pRLink = temp; // rear의 다음을 temp 로 지정하고
    pQueue->pRearNode = temp; // temp 를 Rear 로 둔다.
    pQueue->currentElementCount += 1;
    return (TRUE);
}

QueueNode* deleteLQ(LinkedQueue* pQueue)
{
    QueueNode   *temp;

    temp = pQueue->pFrontNode;
    if (!temp) // node가 없었을 때
        return (NULL);
    if (pQueue->currentElementCount == 1) // 반환할 node가 딱 1개일 때
    {
        pQueue->pFrontNode = NULL;
        pQueue->pRearNode = NULL;
        pQueue->currentElementCount -= 1;
        return (temp);
    }
    pQueue->pFrontNode = pQueue->pFrontNode->pRLink; // front node 갱신
    temp->pRLink = NULL;
    pQueue->currentElementCount -= 1;
    
    return (temp);
}

QueueNode* peekLQ(LinkedQueue* pQueue) // 가장 첫 Node 반환
{
    return (pQueue->pFrontNode);
}

void deleteLinkedQueue(LinkedQueue* pQueue) // 삭제
{
    QueueNode   *curr;
    QueueNode   *next;

    curr = pQueue->pFrontNode;
    while(curr) // 내부 모든 node 삭제
    {
        next = curr->pRLink;
        free(curr);
        curr = next;
    }
    free(pQueue); // queue 삭제
    pQueue = NULL;
}

int isLinkedQueueEmpty(LinkedQueue* pQueue)
{
    return (pQueue->currentElementCount == 0);
}
