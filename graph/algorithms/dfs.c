#include <stdio.h>
#include "../linkedgraph/linkedgraph.h"
#include "./stack/linkedstack.h"

void traversal_dfs(LinkedGraph *graph, int from)
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
		printf("%d ", stackNode->data);
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
}

int main()
{
	LinkedGraph	*temp;

	temp = createLinkedGraph(10);
	addVertexLG(temp, 0);
	addVertexLG(temp, 1);
	addVertexLG(temp, 2);
	addVertexLG(temp, 3);

	addEdgeLG(temp, 0, 1);
	addEdgeLG(temp, 1, 3);
	addEdgeLG(temp, 0, 2);

	traversal_dfs(temp, 0);
	return 0;
}