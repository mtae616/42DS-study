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
    temp = deleteLQ(pArrivalQueue);
    temp->customer.status = arrival;
    temp->customer.startTime = currentTime;
    insertLQ(pWaitQueue, *temp);
}

QueueNode* processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue)
{
    QueueNode   *temp;

    temp = peekLQ(pWaitQueue);
    if(!temp)
        return (NULL);
    else if(temp->customer.status == arrival)
    {
        temp->customer.status = start;
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
    *pTotalWaitTime += pServiceNode->customer.startTime - pServiceNode->customer.arrivalTime;
    pServiceNode->customer.endTime = currentTime;
    pServiceNode->customer.status = end;
    // if (pServiceNode->pRLink)
    //     return (NULL);
    return (pServiceNode);
}

void printSimCustomer(int currentTime, SimCustomer customer)
{
    printf("the customers arrival, service time : %d %d", customer.arrivalTime, customer.serviceTime);
}

void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue);

void printReport(LinkedQueue *pWaitQueue, int serviceUserCount, int totalWaitTime)
{
    printf("user count : %d, wait Time : %d\n", serviceUserCount, totalWaitTime);
}

int main()
{
    LinkedQueue *ArrivalQueue = createLinkedQueue();
    LinkedQueue *WaitQueue = createLinkedQueue();
    QueueNode   *temp;
    QueueNode   *exitNode;
    SimCustomer s1;
    int t = 0;
    int serviceUserCount = 0;
    int totalWaitTime = 0;
    int exit = 0;

    s1.arrivalTime = t;
    s1.serviceTime = 2;

    insertCustomer(t, s1.serviceTime, ArrivalQueue);
    processArrival(t, ArrivalQueue, WaitQueue);

    insertCustomer(1, 2, ArrivalQueue);
    processArrival(2, ArrivalQueue, WaitQueue);
    
    while(!exit)
    {
        temp = processServiceNodeStart(t, WaitQueue);
        if (temp)
        {
            exitNode = processServiceNodeEnd(t, temp, &serviceUserCount, &totalWaitTime);
            deleteLQ(WaitQueue);
            if (isLinkedQueueEmpty(WaitQueue))
                exit = 1;
        }
        t++;
    }
    printReport(WaitQueue, serviceUserCount, totalWaitTime);
    
    return 0;
}