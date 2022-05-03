#include "simdef.h"

int t = 0;
int serviceUserCount = 0;
int totalWaitTime = 0;
int exit = 0;

void insertCustomer(int arrivalTime, int processTime, LinkedQueue *pQueue)
{
    QueueNode buf;
    LinkedQueue *WaitQueue = createLinkedQueue();
    QueueNode   *ServiceNode;
    
    // while(!exit)
    // {
    //     pServiceNode = processServiceNodeEnd(arrivalTime, pServiceNode, serviceUserCount, totalWaitTime);
        // pServiceNode = processServiceNodeStart(arrivalTime, pQueue);
        // while(pServiceNode == NULL)
        // {
        //     if (!pServiceNode)
        //     {
        //         buf.customer.arrivalTime = arrivalTime;
        //         buf.customer.serviceTime = processTime;
        //         insertLQ(pQueue, buf);
        //         processArrival(arrivalTime, pQueue, pWaitQueue);
        //         processServiceNodeEnd(arrivalTime, pServiceNode, serviceUserCount, totalWaitTime);
        //     }
        //     arrivalTime += 1;
        // }
    //     processArrival(arrivalTime, pQueue, pWaitQueue);
    // }

    processArrival(arrivalTime, pQueue, WaitQueue);
    ServiceNode = peekLQ(WaitQueue);
    while(t != ServiceNode->customer.endTime)
    {
        if (ServiceNode->customer.endTime == t)
        {
            processServiceNodeEnd(t, ServiceNode, serviceUserCount, totalWaitTime);
        }
        else
        {
            processServiceNodeStart(t, WaitQueue);
        }
        t++;
    }
    
}
// 1
void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue)
{
    QueueNode   *temp;
    temp = deleteLQ(pArrivalQueue);
    temp->customer.status = arrival;
    temp->customer.startTime = currentTime;
    temp->customer.endTime = currentTime + temp->customer.serviceTime;
    insertLQ(pWaitQueue, *temp);
    // processServiceNodeStart(currentTime, deleteLQ(pWaitQueue));
}
// 3
QueueNode* processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue)
{
    QueueNode   *temp;

    temp = peekLQ(pWaitQueue);
    if(!temp)
        return (NULL);
    else if(temp->customer.status == start)
        return (NULL);
    else if(temp->customer.endTime == currentTime + temp->customer.serviceTime)
        return temp;
    else if(temp->customer.status == end)
        return (NULL);
}
// 2
QueueNode* processServiceNodeEnd(int currentTime, QueueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime)
{
    if (!pServiceNode)
        return (NULL);
    *pServiceUserCount += 1;
    *pTotalWaitTime += pServiceNode->customer.serviceTime;
    
    pServiceNode->customer.startTime = currentTime;
    pServiceNode->customer.status = end;
    return pServiceNode;
}

void printSimCustomer(int currentTime, SimCustomer customer)
{
    printf("the customers arrival, service time : %d %d", customer.arrivalTime, customer.serviceTime);
    // insertCutomer(customer.arrivalTime, customer.serviceTime, );
}
// 4
void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue);
// 5
void printReport(LinkedQueue *pWaitQueue, int serviceUserCount, int totalWaitTime);

int main()
{
    LinkedQueue *pArrivalQueue = createLinkedQueue();
    SimCustomer s1;
    s1.arrivalTime = t;
    s1.serviceTime = 2;

    // processArrival(time, pArrivalQueue, pWaitQueue);

    // printSimCustomer(time, s1);
    insertCustomer(t, s1.serviceTime, pArrivalQueue);


    return 0;
}