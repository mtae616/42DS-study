#include "../linkedgraph/linkedgraph.h"

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
			addEdgewithWeightLG(ret, id, i, min);
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