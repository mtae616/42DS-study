#include "maxheap.h"

Heap*	createHeap(int maxElementCount)
{
	Heap	*temp;

	temp = calloc(1, sizeof(Heap));
	temp->pElement = calloc(maxElementCount, sizeof(HeapNode));
	return temp;
}

int insertMaxHeapNode(Heap* hList, HeapNode element)
{
	int	i;

	i = hList->currentElementCount;
	while ((i != 0) && element.key > hList->pElement[i / 2].key)
	{
		hList->pElement[i] = hList->pElement[i / 2];
		i = i / 2;
	}
	hList->pElement[i] = element;
	hList->currentElementCount += 1;
	return TRUE;
}

HeapNode	popMaxHeapNode(Heap* hList)
{
	HeapNode	root, temp;
	int			i, parent, child;

	root = hList->pElement[0];
	i = hList->currentElementCount;
	temp = hList->pElement[i - 1];
	parent = 0;
	child = 1;
	while(child <= hList->currentElementCount)
	{
		if((child < hList->currentElementCount) && hList->pElement[child].key < hList->pElement[child + 1].key)
			child += 1;
		if (temp.key >= hList->pElement[child].key) break;
		hList->pElement[parent] = hList->pElement[child];
		parent = child;
		child *= 2;
	}
	hList->pElement[parent] = temp;
	return root;
}

void deleteMaxHeap(Heap* hList)
{
	free(hList->pElement);
	hList->pElement = NULL;
	free(hList);
	hList = NULL;
}

int isMaxHeapFull(Heap* hList)
{
	return (hList->currentElementCount == hList->maxElementCount);
}

int	getMaxHeapLength(Heap* hList)
{
	return (hList->currentElementCount);
}

int main()
{
	Heap	*temp = createHeap(10);
	HeapNode	buf;

	buf.key = 8;
	insertMaxHeapNode(temp, buf);
	buf.key = 10;
	insertMaxHeapNode(temp, buf);
	buf.key = 4;
	insertMaxHeapNode(temp, buf);
	buf.key = 2;
	insertMaxHeapNode(temp, buf);
	buf.key = 12;
	insertMaxHeapNode(temp, buf);
	buf.key = 6;
	insertMaxHeapNode(temp, buf);
	buf.key = 20;
	insertMaxHeapNode(temp, buf);
	// buf.key = 100;
	// insertMaxHeapNode(temp, buf);
	// buf.key = 100;
	// insertMaxHeapNode(temp, buf);
	// buf.key = 100;
	// insertMaxHeapNode(temp, buf);

	for(int i = temp->currentElementCount; i > 0; i--)
		printf("%d ", temp->pElement[i - 1].key);
	buf = popMaxHeapNode(temp);
	printf("\n%d\n", buf.key);
	for(int i = temp->currentElementCount; i > 0; i--)
		printf("%d ", temp->pElement[i - 1].key);
	return 0;
}