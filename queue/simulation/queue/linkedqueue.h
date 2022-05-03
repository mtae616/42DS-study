#ifndef _LINKED_QUEUE_
#define _LINKED_QUEUE_

#include <stdio.h>
#include <stdlib.h>

typedef enum SimStatusType {arrival, start, end} SimStatus;

typedef struct SimCustomerType
{
    SimStatus status;
    int arrivalTime; // 도착 시각.
    int serviceTime; // 서비스 시간.
    int startTime; // 시작 시각.
    int endTime; // 종료 시각: 시작 시각 + 서비스 시간.
} SimCustomer;

typedef struct QueueNodeType
{
	SimCustomer customer;
	struct QueueNodeType* pRLink;
} QueueNode;

typedef struct LinkedQueueType
{
	int currentElementCount;	// 현재 원소 개수
	QueueNode* pFrontNode;		// Front node
	QueueNode* pRearNode;		// Rear node
} LinkedQueue;

LinkedQueue* createLinkedQueue();
int insertLQ(LinkedQueue* pQueue, QueueNode element);
QueueNode* deleteLQ(LinkedQueue* pQueue);
QueueNode* peekLQ(LinkedQueue* pQueue);
void deleteLinkedQueue(LinkedQueue* pQueue);
int isLinkedQueueEmpty(LinkedQueue* pQueue);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0

#endif