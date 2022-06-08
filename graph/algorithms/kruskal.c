#include "../linkedgraph/linkedgraph.h"
#include "./minheap_kruskal/minheap.h"
#include "./stack/linkedstack.h"

Heap	*sorted_heap(LinkedGraph *graph) 
// 간선의 가중치를 기준으로 최소로 정렬한다.
// 여기에선 key가 가중치가 된다.
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
// 만약 자기자신이 갖고 있는 정점이 연결하려는 to와 갖다면 연결하지 않는다.
// 이를 위해 dfs로 확인한다.
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
		// 간선의 가중치가 오름차순 정렬이 되어있으므로 작은 값부터 연결해준다.
		if (traversal_dfs(ret, buf.from, buf.to))
		// 사이클이 발생하지 않았다면 ret이라는 그래프에 삽입한다.
		{
			addVertexLG(ret, buf.from);
			addVertexLG(ret, buf.to);
			addEdgewithWeightLG(ret, buf.from, buf.to, buf.key);
		}
	}
	displayLinkedGraph(ret);
}
