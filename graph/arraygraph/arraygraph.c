#include "arraygraph.h"

ArrayGraph* createArrayGraph(int maxVertexCount)
{
	ArrayGraph *temp;

	temp = calloc(1, sizeof(ArrayGraph));
	temp->ppAdjEdge = calloc(maxVertexCount, sizeof(int *));
	temp->maxVertexCount = maxVertexCount;
	temp->pVertex = calloc(maxVertexCount, sizeof(int *));
	return (temp);
}

ArrayGraph* createArrayDirectedGraph(int maxVertexCount);

void deleteArrayGraph(ArrayGraph* pGraph)
{
	for(int i = pGraph->currentVertexCount; i > 0; i--)
		free(pGraph->ppAdjEdge[i - 1]);
	free(pGraph);
}

int isEmptyAG(ArrayGraph* pGraph)
{
	return (pGraph->currentVertexCount == 0);
}

int addVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (pGraph->currentVertexCount == pGraph->maxVertexCount || pGraph->pVertex[vertexID])
		return (FALSE);
	pGraph->pVertex[vertexID] = pGraph->currentVertexCount;
	pGraph->currentVertexCount += 1;
	return (TRUE);
}

int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (fromVertexID < 0 || fromVertexID > pGraph->maxVertexCount)
		return (FALSE);
	if (toVertexID < 0 || toVertexID > pGraph->maxVertexCount)
		return (FALSE);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = 1;
	pGraph->ppAdjEdge[toVertexID][fromVertexID] = 1;
	return (TRUE);
}

int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	if (fromVertexID < 0 || fromVertexID > pGraph->maxVertexCount)
		return (FALSE);
	if (toVertexID < 0 || toVertexID > pGraph->maxVertexCount)
		return (FALSE);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
}

int checkVertexValid(ArrayGraph* pGraph, int vertexID)
{
	return pGraph->pVertex[vertexID];
}

int removeVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (vertexID < 0 || vertexID > pGraph->maxVertexCount)
		return (FALSE);
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		pGraph->ppAdjEdge[vertexID][i] = 0;
		pGraph->ppAdjEdge[i][vertexID] = 0;
	}
	pGraph->pVertex[vertexID] = 0;
}

int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;
	pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
}

void displayArrayGraph(ArrayGraph* pGraph)
{
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		for (int j = 0; j < pGraph->maxVertexCount; j++)
		{
			printf("%d ", pGraph->ppAdjEdge[i][j]);
		}
		printf("\n");
	}
}
