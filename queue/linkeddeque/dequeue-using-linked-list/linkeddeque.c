#include "linkeddeque.h"

LinkedDeque* createLinkedDeque() // 생성
{
    LinkedDeque *temp;

    temp = calloc(1, sizeof(LinkedDeque));
    return (temp);
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element) // front 삽입
{
    DequeNode   *temp = calloc(1, sizeof(DequeNode));

    *temp = element;
    if (isLinkedDequeEmpty(pDeque)) // node가 없다면
    {
        pDeque->pFrontNode = temp; // front 는 자기 자신이다.
        pDeque->pRearNode = temp; // rear도 자기 자신이다.
        pDeque->currentElementCount += 1;
        return (TRUE);
    }
    pDeque->pFrontNode->pLLink = temp; // front의 왼편에 새로 들어온 node 설정
    temp->pRLink = pDeque->pFrontNode; // front를 자기 다음으로 설정
    pDeque->pFrontNode = temp; // front 갱신
    pDeque->currentElementCount += 1;
    return (TRUE);
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element) // rear 삽입
{
    DequeNode *temp = calloc(1, sizeof(DequeNode));

    *temp = element;
    if (isLinkedDequeEmpty(pDeque)) // node가 없다면
    {
        pDeque->pFrontNode = temp; // front는 자기 자신이다.
        pDeque->pRearNode = temp; // Rear도 자기 자신이다.
        pDeque->currentElementCount += 1;
        return (TRUE);
    }
    pDeque->pRearNode->pRLink = temp; // rear의 오른편에 새로 들어온 node 설정
    temp->pLLink = pDeque->pRearNode; // rear를 자기 전으로 설정
    pDeque->pRearNode = temp; // rear 갱신
    pDeque->currentElementCount += 1;
    return (TRUE);
}

DequeNode* deleteFrontLD(LinkedDeque* pDeque) // Front 반환
{
    DequeNode   *temp;

    temp = pDeque->pFrontNode;
    if (!temp) // temp가 없는 경우
        return NULL;
    if (pDeque->currentElementCount == 1) // node가 1개만 있다면
    {
        pDeque->pFrontNode = NULL; 
        pDeque->pRearNode = NULL; // front와 Rear를 자기자신으로 설정했기 때문에 모두 해제한다.
        pDeque->currentElementCount -= 1;
        return (temp);
    }
    pDeque->pFrontNode = temp->pRLink; // 앞에서 반환되기 때문에 새로운 front는 front 오른편으로 설정한다.
    pDeque->pFrontNode->pLLink = NULL; // front의 왼편을 해제한다.
    temp->pRLink = NULL;
    pDeque->currentElementCount -= 1;
    return (temp);
}

DequeNode* deleteRearLD(LinkedDeque* pDeque) // rear 반환
{
    DequeNode   *temp;

    temp = pDeque->pRearNode;
    if (!temp) // temp가 없는 경우
        return NULL;
    if (pDeque->currentElementCount == 1) // node가 1개만 있다면
    {
        pDeque->pFrontNode = NULL;
        pDeque->pRearNode = NULL; // front와 Rear를 자기자신으로 설정했기 때문에 모두 해제한다.
        pDeque->currentElementCount -= 1;
        return (temp);
    }
    pDeque->pRearNode = temp->pLLink; // 뒤에서 반환되기 때문에 새로운 Rear는 Rear의 왼편이다.
    pDeque->pRearNode->pRLink = NULL; // Rear의 오른편을 해제한다.
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