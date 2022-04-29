#include "linkeddeque.h"

LinkedDeque* createLinkedDeque()
{
    LinkedDeque *temp;

    temp = calloc(1, sizeof(LinkedDeque));
    return (temp);
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
    DequeNode   *temp = calloc(1, sizeof(DequeNode));

    *temp = element;
    if (isLinkedDequeEmpty(pDeque))
    {
        pDeque->pFrontNode = temp;
        pDeque->pRearNode = temp;
        pDeque->currentElementCount += 1;
        return (TRUE);
    }
    pDeque->pFrontNode->pLLink = temp;
    temp->pRLink = pDeque->pFrontNode;
    pDeque->pFrontNode = temp;
    pDeque->currentElementCount += 1;
    return (TRUE);
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
    DequeNode *temp = calloc(1, sizeof(DequeNode));

    *temp = element;
    if (isLinkedDequeEmpty(pDeque))
    {
        pDeque->pFrontNode = temp;
        pDeque->pRearNode = temp;
        pDeque->currentElementCount += 1;
        return (TRUE);
    }
    pDeque->pRearNode->pRLink = temp;
    temp->pLLink = pDeque->pRearNode;
    pDeque->pRearNode = temp;
    pDeque->currentElementCount += 1;
    return (TRUE);
}

DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
    DequeNode   *temp;

    temp = pDeque->pFrontNode;
    if (pDeque->currentElementCount == 1)
    {
        pDeque->pFrontNode = NULL;
        pDeque->currentElementCount -= 1;
        return (temp);
    }
    pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
    pDeque->pFrontNode->pLLink = NULL;
    temp->pRLink = NULL;
    pDeque->currentElementCount -= 1;
    return (temp);
}

DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
    DequeNode   *temp;

    temp = pDeque->pRearNode;
    if (pDeque->currentElementCount == 1)
    {
        pDeque->pRearNode = NULL;
        pDeque->currentElementCount -= 1;
        return (temp);
    }
    pDeque->pRearNode = pDeque->pRearNode->pLLink;
    pDeque->pRearNode->pRLink = NULL;
    temp->pLLink = NULL;
    pDeque->currentElementCount -= 1;
    return (temp);
}

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
    return (pDeque->pFrontNode);
}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
    return (pDeque->pRearNode);
}

void deleteLinkedDeque(LinkedDeque* pDeque)
{
    DequeNode   *curr;
    DequeNode   *next;

    curr = pDeque->pFrontNode;
    while(curr)
    {
        next = curr->pRLink;
        free(curr);
        curr = next;
    }
    free(pDeque);
}

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
    return (pDeque->currentElementCount == 0);
}

int main()
{
    LinkedDeque *que = createLinkedDeque();
    DequeNode   temp;
    DequeNode   *curr;
    
    temp.data = 'A';
    insertFrontLD(que, temp);
    temp.data = 'B';
    insertFrontLD(que, temp);
    temp.data = 'C';
    insertRearLD(que, temp);
    temp.data = 'D';
    insertRearLD(que, temp);
    deleteRearLD(que);

    curr = que->pFrontNode;
    for (int i = 0; i < que->currentElementCount; i++)
    {
        printf("%c", curr->data);
        curr = curr->pRLink;
    }
    return 0;
}