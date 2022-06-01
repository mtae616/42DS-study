#ifndef MIN_HEAP_H
#define	MIN_HEAP_H

// malloc, write
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct HeapNodeType
{
	int key;
	int idx;
} HeapNode;

typedef struct HeapType
{
	int maxElementCount;		// 최대 원소 개수
	int currentElementCount;	// 현재 원소의 개수
	HeapNode *pElement;	// 원소 저장을 위한 1차원 배열
} Heap;

// 힙 생성
Heap*	createHeap(int maxElementCount);
// 힙 삭제
void deleteMinHeap(Heap* hList);
// 자료 추가
int insertMinHeapNode(Heap* hList, HeapNode element);
// 자료 제거, 항상 root
HeapNode	popMinHeapNode(Heap* hList);

int isMinHeapFull(Heap* hList);
int	getMinHeapLength(Heap* hList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif