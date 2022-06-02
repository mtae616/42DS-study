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
		dp[i] = INF;
	dp[from] = 0;
	insertMinHeapNode(heap, buf);
	while (getMinHeapLength(heap) != 0)
	{
		buf = popMinHeapNode(heap);
		temp = graph->ppAdjEdge[buf.idx]->headerNode.pLink;
		while(temp)
		{
			if (dp[temp->data.vertexID] > temp->data.weight + buf.key)
			{
				dp[temp->data.vertexID] = temp->data.weight + buf.key;
				insertNode.key = dp[temp->data.vertexID];
				insertNode.idx = temp->data.vertexID;
				insertMinHeapNode(heap, insertNode);
			}
			temp = temp->pLink;
		}
	}
	for (int i = 0; i < 6; i++)
		printf("%d ", dp[i]);
}

// int main()
// {
// 	LinkedGraph *graph = createLinkedGraph(6);
// 	for(int i = 0; i < 6; i++)
// 		addVertexLG(graph, i);
	
// 	addEdgewithWeightLG(graph, 0, 1, 1);
// 	addEdgewithWeightLG(graph, 0, 2, 4);
// 	addEdgewithWeightLG(graph, 1, 2, 2);
// 	addEdgewithWeightLG(graph, 2, 3, 1);
// 	addEdgewithWeightLG(graph, 3, 4, 8);
// 	addEdgewithWeightLG(graph, 3, 5, 3);
// 	addEdgewithWeightLG(graph, 4, 5, 4);

// 	// displayLinkedGraph(graph);

// 	dijkstra(graph, 0);

// 	return 0;
// }