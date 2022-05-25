#include "../linkedgraph/linkedgraph.h"
#include "./queue-using-linked-list/linkedqueue.h"
#include <stdio.h>

void traversal_bfs(LinkedGraph *graph, int from)
{
	LinkedQueue *queue = createLinkedQueue();
	QueueNode	buf;
	QueueNode	*queueNode;
	int	*visited = calloc(graph->maxVertexCount, sizeof(int));

	buf.data = from;
	insertLQ(queue, buf);
	visited[from] = 1;
	while (queue->currentElementCount > 0)
	{
		queueNode = deleteLQ(queue);
		printf("%d ", queueNode->data);
		ListNode *temp = graph->ppAdjEdge[queueNode->data]->headerNode.pLink;
		while (temp)
		{
			if (!visited[temp->data.vertexID])
			{
				visited[temp->data.vertexID] = 1;
				buf.data = temp->data.vertexID;
				insertLQ(queue,buf);
			}
			temp = temp->pLink;
		}
	}
}

// int main()
// {
// 	LinkedGraph	*temp;

// 	temp = createLinkedGraph(10);
// 	addVertexLG(temp, 0);
// 	addVertexLG(temp, 1);
// 	addVertexLG(temp, 2);
// 	addVertexLG(temp, 3);

// 	addEdgeLG(temp, 0, 1);
// 	addEdgeLG(temp, 1, 3);
// 	addEdgeLG(temp, 0, 2);

// 	traversal_bfs(temp, 0);
// 	return 0;
// }