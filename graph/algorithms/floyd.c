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
	int	**arr = arr_init(graph); // 결과 그래프를 초기화한다.
	
	for (int k = 0; k < graph->maxVertexCount; k++) // 꼭짓점 K
	{
		for(int j = 0; j < graph->maxVertexCount; j++)
		{
			for(int i = 0; i < graph->maxVertexCount; i++)		
			{
				if (arr[i][j] > arr[i][k] + arr[k][j]) 
				// (i,j) 가 (i,k) + (k,j)보다 크다면 업데이트한다.
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
	display(arr, graph->maxVertexCount);
}
