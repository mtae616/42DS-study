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

	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
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

int removeVertexLG(LinkedGraph* pGraph, int vertexID)
{
	LinkedList	*temp;

	if (!checkVertexValid(pGraph, vertexID))
		return (FALSE);
	temp = pGraph->ppAdjEdge[vertexID];
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		removeEdgeLG(pGraph, i, vertexID);
		if (pGraph->graphType == 1)
			removeEdgeLG(pGraph, vertexID, i);
	}
	pGraph->pVertex[vertexID] = 0;
	return (TRUE);
}

int	findById(LinkedList *pList, int vertexID)
{
	int	i = 0;
	ListNode	*temp;

	temp = pList->headerNode.pLink;
	while(temp)
	{
		if (temp->data.vertexID == vertexID)
			break ;
		temp = temp->pLink;
		i++;
	}
	return i;
}

int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FALSE);
	removeLLElement(pGraph->ppAdjEdge[fromVertexID], findById(pGraph->ppAdjEdge[fromVertexID], toVertexID));
	if (pGraph->graphType == 0)
		removeLLElement(pGraph->ppAdjEdge[toVertexID], findById(pGraph->ppAdjEdge[toVertexID], fromVertexID));
	return 0;
}

void displayLinkedGraph(LinkedGraph* pGraph)
{
	LinkedList	*temp;
	ListNode	*buf;

	for (int i = 0; i < pGraph->currentVertexCount; i++)
	{
		temp = pGraph->ppAdjEdge[i];
		buf = temp->headerNode.pLink;
		for(int j = 0; j < temp->currentElementCount; j++)
		{
			printf("from : %d to : %d \n", i, buf->data.vertexID);
			buf = buf->pLink;
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

	addEdgeLG(temp, 0, 1);
	addEdgeLG(temp, 0, 2);
	removeVertexLG(temp, 1);
	displayLinkedGraph(temp);

	return 0;
}