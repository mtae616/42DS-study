#include "../linkedgraph/linkedgraph.h"
#include "./stack/linkedstack.h"

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

void	prim(LinkedGraph *graph)
{
	LinkedGraph	*ret = createLinkedGraph(graph->maxVertexCount);
	int	selected[graph->maxVertexCount];
	ListNode	*temp;
	int INF = 999999999;
	int			i = 0;

	for(int i = 0; i < graph->maxVertexCount; i++)
		selected[i] = INF;
	while (i < graph->maxVertexCount)
	{
		temp = graph->ppAdjEdge[i]->headerNode.pLink;
		int min = 999999999;
		int id = temp->data.vertexID;
		while(temp)
		{	
			if (selected[i] && min > temp->data.weight)
			{
				min = temp->data.weight;
				id = temp->data.vertexID;
			}
			temp = temp->pLink;
		}
		if (selected[i] && min != INF)
		{
			addVertexLG(ret, id);
			addVertexLG(ret, i);
			addEdgewithWeightLG(ret, i, id, min);
			selected[i] = 0;
		}
		i++;
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

	prim(graph);
	return 0;
}