#ifndef _ARRAY_STACK_
#define _ARRAY_STACK_

#include <stdio.h>
#include <stdlib.h>
#include "./arraylist/arraylist.h"

typedef struct StackNodeType
{
	char data;
	struct StackNodeType* pLink;
} StackNode;

typedef struct ArrayStackType
{
	int currentElementCount;	// 현재 노드 개수
	StackNode* pTopElement;		// Top node
} ArrayStack;

ArrayStack* createArrayStack();
int pushAS(ArrayStack* pStack, StackNode element);
StackNode* popAS(ArrayStack* pStack);
StackNode* peekAS(ArrayStack* pStack);
void deleteArrayStack(ArrayStack* pStack);
int isArrayStackFull(ArrayStack* pStack);
int isArrayStackEmpty(ArrayStack* pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif