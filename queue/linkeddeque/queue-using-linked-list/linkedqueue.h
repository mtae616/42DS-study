#ifndef _LINKED_QUEUE_
#define _LINKED_QUEUE_

#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNodeType
{
	char data;
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