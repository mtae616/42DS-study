#include "../linkedgraph/linkedgraph.h"

void	prim(LinkedGraph *graph)
{
	LinkedGraph	*ret = createLinkedGraph(graph->maxVertexCount);
	// 값을 저장할 그래프
	int	selected[graph->maxVertexCount];
	ListNode	*temp;
	int INF = 999999999;
	int			i = 0;

	for(int i = 0; i < graph->maxVertexCount; i++)
		selected[i] = INF; // 선택되지 않은 값들은 INF로 한다.
	while (i < graph->maxVertexCount)
	{
		temp = graph->ppAdjEdge[i]->headerNode.pLink;
		int min = 999999999;
		int id = temp->data.vertexID;
		while(temp) // 노드 간 최소 값을 구한다.
		{	
			if (selected[i] && min > temp->data.weight)
			{
				min = temp->data.weight;
				id = temp->data.vertexID;
			}
			temp = temp->pLink;
		}
		if (selected[i] && min != INF) 
		// 선택되지 않았고, 최소값이 INF가 아니라면 ret에 저장해준다.
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
