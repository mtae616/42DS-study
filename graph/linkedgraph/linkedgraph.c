#include "linkedgraph.h"

LinkedGraph* createLinkedGraph(int maxVertexCount)
{
	LinkedGraph *temp;

	temp = calloc(1, sizeof(LinkedGraph));
	temp->maxVertexCount = maxVertexCount;
	temp->pVertex = calloc(maxVertexCount, sizeof(int));
	temp->ppAdjEdge = calloc(maxVertexCount, sizeof(LinkedList *));
	for (int i = 0; i < maxVertexCount; i++)
		temp->ppAdjEdge[i] = createLinkedList();
	return (temp);
}

LinkedGraph* createLinkedDirectedGraph(int maxVertexCount)
{
	LinkedGraph *temp;

	temp = calloc(1, sizeof(LinkedGraph));
	temp->maxVertexCount = maxVertexCount;
	temp->graphType = 1;
	temp->pVertex = calloc(maxVertexCount, sizeof(int));
	temp->ppAdjEdge = calloc(maxVertexCount, sizeof(LinkedList *));
	return (temp);
}

void deleteLinkedGraph(LinkedGraph* pGraph)
{
	for (int i = pGraph->currentVertexCount; i > 0; i--)
		free(pGraph->ppAdjEdge[i]);
	free(pGraph->pVertex);
	free(pGraph);
}

int isEmptyLG(LinkedGraph* pGraph)
{
	return (pGraph->currentVertexCount == 0);
}

int addVertexLG(LinkedGraph* pGraph, int vertexID)
{
	if (pGraph->maxVertexCount <= vertexID || checkVertexValid(pGraph, vertexID))
		return (FALSE);
	pGraph->pVertex[vertexID] = 1;
	pGraph->currentVertexCount += 1;
	return (TRUE);
}

int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	return addEdgewithWeightLG(pGraph, fromVertexID, toVertexID, 1);
}

int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	ListNode	temp = {0, };
	LinkedList	*buf;

	if (checkVertexValid(pGraph, fromVertexID) || checkVertexValid(pGraph, toVertexID))
		return (FALSE);
	temp.data.vertexID = toVertexID;
	temp.data.weight = weight;
	buf = pGraph->ppAdjEdge[fromVertexID];
	addLLElement(buf, buf->currentElementCount, temp);
	if (!pGraph->graphType)
	{
		temp.data.vertexID = fromVertexID;
		buf = pGraph->ppAdjEdge[toVertexID];
		addLLElement(buf, buf->currentElementCount, temp);
	}
	return (TRUE);
}

int checkVertexValid(LinkedGraph* pGraph, int vertexID)
{
	return pGraph->pVertex[vertexID];
}

int removeVertexLG(LinkedGraph* pGraph, int vertexID);

int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);

void displayLinkedGraph(LinkedGraph* pGraph);

// int main()
// {
// 	return 0;
// }