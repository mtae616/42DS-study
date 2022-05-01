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
    if (isLinkedQueueEmpty(pQueue))
    {
        pQueue->pFrontNode = temp;
        pQueue->pRearNode = temp;
        pQueue->currentElementCount += 1;
        return (TRUE);
    }
    pQueue->pRearNode->pRLink = temp;
    pQueue->pRearNode = temp;
    pQueue->currentElementCount += 1;
    return (TRUE);
}

QueueNode* deleteLQ(LinkedQueue* pQueue)
{
    QueueNode   *temp = calloc(1, sizeof(QueueNode));

    temp = pQueue->pFrontNode;
    if (pQueue->currentElementCount == 1)
    {
        pQueue->pFrontNode = NULL;
        pQueue->pRearNode = NULL;
        pQueue->currentElementCount -= 1;
        return (temp);
    }
    pQueue->pFrontNode = pQueue->pFrontNode->pRLink;
    temp->pRLink = NULL;
    pQueue->currentElementCount -= 1;
    return (temp);
}

QueueNode* peekLQ(LinkedQueue* pQueue)
{
    return (pQueue->pFrontNode);
}

void deleteLinkedQueue(LinkedQueue* pQueue)
{
    QueueNode   *curr;
    QueueNode   *next;

    curr = pQueue->pFrontNode;
    while(curr)
    {
        next = curr->pRLink;
        free(curr);
        curr = next;
    }
    free(pQueue);
    pQueue = NULL;
}

int isLinkedQueueEmpty(LinkedQueue* pQueue)
{
    return (pQueue->currentElementCount == 0);
}

int main()
{
    LinkedQueue *buf = createLinkedQueue();
    QueueNode   *curr;
    QueueNode   temp;

    temp.data = 'a';
    insertLQ(buf, temp);
    temp.data = 'b';
    insertLQ(buf, temp);
    temp.data = 'c';
    insertLQ(buf, temp);
    temp.data = 'd';
    insertLQ(buf, temp);
    deleteLQ(buf);
    deleteLQ(buf);
    deleteLQ(buf);
    deleteLQ(buf);
    temp.data = 'e';
    insertLQ(buf, temp);

    curr = buf->pFrontNode;
    for(int i = 0; i < buf->currentElementCount; i++)
    {
        printf("%c", curr->data);
        curr = curr->pRLink;
    }
    return 0;
}