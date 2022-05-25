#include "../linkedgraph/linkedgraph.h"
#include <stdio.h>

void traversal_bfs(ListNode	*temp)
{

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

	return 0;
}