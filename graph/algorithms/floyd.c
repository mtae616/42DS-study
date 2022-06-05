#include "../linkedgraph/linkedgraph.h"

int	INF = 99999999;

int **arr_init(LinkedGraph *graph)
{
	int **arr = calloc(graph->currentVertexCount, sizeof(int *));
	ListNode *temp;
	for(int i = 0; i < graph->currentVertexCount; i++)
		arr[i] = calloc(graph->currentVertexCount, sizeof(int));
	for (int i = 0; i < graph->currentVertexCount; i++)
	{
		for(int j = 0; j < graph->currentVertexCount; j++)
		{
			arr[i][j] = INF;
			if (i == j)
				arr[i][j] = 0;
		}
	}
	for (int i = 0; i < graph->currentVertexCount; i++)
	{
		temp = graph->ppAdjEdge[i]->headerNode.pLink;
		while(temp)
		{
			arr[i][temp->data.vertexID] = temp->data.weight;
			temp = temp->pLink;
		}
	}
	return arr;
}

void	display(int **arr, int length)
{
	for(int i = 0; i < length; i++)
	{
		for(int j = 0; j < length; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void	floyd(LinkedGraph *graph)
{
	int	**arr = arr_init(graph);
	
	for (int k = 0; k < graph->maxVertexCount; k++)
	{
		for(int j = 0; j < graph->maxVertexCount; j++)
		{
			for(int i = 0; i < graph->maxVertexCount; i++)		
			{
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
	display(arr, graph->maxVertexCount);
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

	floyd(graph);

	return 0;
}