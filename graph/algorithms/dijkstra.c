#include <stdio.h>
#include "../linkedgraph/linkedgraph.h"
#include "./minheap/minheap.h"

void	dijkstra(LinkedGraph *graph, int from)
{
	int			 INF = 9999999;
	int			 dp[graph->maxVertexCount];
	Heap		*heap = createHeap(graph->maxVertexCount);
	HeapNode	buf = {0, };
	HeapNode	insertNode = {0, };
	ListNode	*temp;
	
	for(int i = graph->maxVertexCount - 1; i >= 0; i--)
		dp[i] = INF; // 배열의 모든 값은 무한대로 설정한다.
	dp[from] = 0; // 시작점은 0으로 한다.
	insertMinHeapNode(heap, buf); // 시작점을 min heap 에 넣어준다.
	while (getMinHeapLength(heap) != 0)
	{
		buf = popMinHeapNode(heap);
		temp = graph->ppAdjEdge[buf.idx]->headerNode.pLink;
		while(temp)
		{
			if (dp[temp->data.vertexID] > temp->data.weight + buf.key)
			// 만약 배열에 저장 된 값보다 작다면
			{
				dp[temp->data.vertexID] = temp->data.weight + buf.key;
				insertNode.key = dp[temp->data.vertexID];
				insertNode.idx = temp->data.vertexID;
				insertMinHeapNode(heap, insertNode);
				// 업데이트 하고, 힙에 넣어주며 더 짧은 거리가 있는지 확인한다.
			}
			temp = temp->pLink;
		}
	}
	for (int i = 0; i < 6; i++)
		printf("%d ", dp[i]);
}
