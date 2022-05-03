#include "simdef.h"

void insertCustomer(int arrivalTime, int processTime, LinkedQueue *pQueue)
{
    QueueNode   buf;

    buf.customer.arrivalTime = arrivalTime;
    buf.customer.serviceTime = processTime;
    insertLQ(pQueue, buf);
}

void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue)
{
    QueueNode   *temp;

    if (isLinkedQueueEmpty(pArrivalQueue))
        return ;
    temp = peekLQ(pArrivalQueue);
    if (currentTime == temp->customer.arrivalTime)
    {
        temp = deleteLQ(pArrivalQueue);
        temp->customer.status = arrival;
        insertLQ(pWaitQueue, *temp);
        free(temp);
        temp = NULL;
    }
}

QueueNode* processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue)
{
    QueueNode   *temp;

    if (isLinkedQueueEmpty(pWaitQueue))
        return (NULL);
    temp = peekLQ(pWaitQueue);
    if(temp->customer.status == arrival)
    {
        temp->customer.status = start;
        temp->customer.startTime = currentTime;
        return (NULL);
    }
    else if(temp->customer.startTime + temp->customer.serviceTime == currentTime)
        return temp;
    else
        return (NULL);
}

QueueNode* processServiceNodeEnd(int currentTime, QueueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime)
{
    if (!pServiceNode)
        return (NULL);
    *pServiceUserCount += 1;
    if (pServiceNode->customer.startTime - pServiceNode->customer.arrivalTime > 0)
        *pTotalWaitTime += pServiceNode->customer.startTime - pServiceNode->customer.arrivalTime;
    pServiceNode->customer.endTime = currentTime;
    pServiceNode->customer.status = end;
    return (pServiceNode);
}

void printSimCustomer(int currentTime, SimCustomer customer)
{
    printf("the customers arrival, service time : %d %d \n", customer.arrivalTime, customer.serviceTime);
}

void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue)
{
    QueueNode   *temp;

    printf("current time %d, waiting users %d \n", currentTime, pWaitQueue->currentElementCount);
    printf("====================================================================\n");
    temp = pWaitQueue->pFrontNode;
    for(int i = pWaitQueue->currentElementCount; i > 0; i--)
    {
        printSimCustomer(currentTime, temp->customer);
        temp = temp->pRLink;
    }
    printf("====================================================================\n");
}

void printReport(LinkedQueue *pWaitQueue, int serviceUserCount, int totalWaitTime)
{
    printf("user count : %d, wait Time : %d\n", serviceUserCount, totalWaitTime);
}

int main()
{
    LinkedQueue *ArrivalQueue = createLinkedQueue();
    LinkedQueue *WaitQueue = createLinkedQueue();
    QueueNode   *temp;
    int t = 0;
    int serviceUserCount = 0;
    int totalWaitTime = 0;

    insertCustomer(0, 3, ArrivalQueue);
    insertCustomer(2, 2, ArrivalQueue);
    insertCustomer(4, 1, ArrivalQueue);
    insertCustomer(6, 1, ArrivalQueue);
    insertCustomer(8, 3, ArrivalQueue);
    while(t < 12)
    {
        processArrival(t, ArrivalQueue, WaitQueue);
        printWaitQueueStatus(t, WaitQueue);
        temp = processServiceNodeStart(t, WaitQueue);
        if (temp)
        {
            processServiceNodeEnd(t, temp, &serviceUserCount, &totalWaitTime);
            deleteLQ(WaitQueue);
            free(temp);
            temp = NULL;
        }
        else
            t++;
    }
    printReport(WaitQueue, serviceUserCount, totalWaitTime);
    system("leaks a.out");
    return 0;
}