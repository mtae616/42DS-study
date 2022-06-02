#include "../linkedgraph/linkedgraph.h"
#include "./minheap_kruskal/minheap.h"
#include "./stack/linkedstack.h"

Heap	*sorted_heap(LinkedGraph *graph)
{
	Heap	*temp = createHeap(graph->currentEdgeCount);
	ListNode	*listNode;
	HeapNode	insertNode = {0, };

	for(int i = 0; i < graph->maxVertexCount; i++)
	{
		listNode = graph->ppAdjEdge[i]->headerNode.pLink;
		while(listNode)
		{
			if (i < listNode->data.vertexID)
			{
				insertNode.from = i;
				insertNode.to = listNode->data.vertexID;
				insertNode.key = listNode->data.weight;
				insertMinHeapNode(temp, insertNode);
			}
			listNode = listNode->pLink;
		}
	}
	return (temp);
}

int traversal_dfs(LinkedGraph *graph, int from, int to)
{
	int *visited = calloc(graph->maxVertexCount, sizeof(int));
	LinkedStack	*stack = calloc(1, sizeof(LinkedStack));
	ListNode	*temp;
	StackNode	buf;
	StackNode	*stackNode;

	buf.data = from;
	pushLS(stack, buf);
	visited[from] = 1;
	while(!isLinkedStackEmpty(stack))
	{
		stackNode = popLS(stack);
		if (stackNode->data == to)
			return (FALSE);
		temp = graph->ppAdjEdge[stackNode->data]->headerNode.pLink;
		while(temp)
		{
			if (!visited[temp->data.vertexID])
			{
				visited[temp->data.vertexID] = 1;
				buf.data = temp->data.vertexID;
				pushLS(stack, buf);
			}
			temp = temp->pLink;
		}
	}
	return (TRUE);
}

void kruskal(LinkedGraph *graph)
{
	int		all_edge = graph->currentVertexCount - 1;
	Heap	*heap = sorted_heap(graph);
	HeapNode	buf;
	LinkedGraph	*ret = createLinkedGraph(graph->maxVertexCount);


	for(int i = 0; i < graph->currentEdgeCount; i++)
	{
		buf = popMinHeapNode(heap);
		if (traversal_dfs(ret, buf.from, buf.to))
		{
			addVertexLG(ret, buf.from);
			addVertexLG(ret, buf.to);
			addEdgewithWeightLG(ret, buf.from, buf.to, buf.key);
		}
	}
	displayLinkedGraph(ret);
}


int main()
{
	LinkedGraph *graph = createLinkedGraph(6);
	for(int i = 0; i < 6; i++)
		addVertexLG(graph, i);
	
	addEdgewithWeightLG(graph, 0, 1, 4);
	addEdgewithWeightLG(graph, 0, 2, 3);
	addEdgewithWeightLG(graph, 1, 2, 2);
	addEdgewithWeightLG(graph, 2, 3, 1);
	addEdgewithWeightLG(graph, 3, 4, 1);
	addEdgewithWeightLG(graph, 3, 5, 5);
	addEdgewithWeightLG(graph, 4, 5, 6);

	// displayLinkedGraph(graph);

	kruskal(graph);
	

	return 0;
}