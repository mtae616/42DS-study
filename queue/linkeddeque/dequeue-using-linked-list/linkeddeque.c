#include "linkeddeque.h"

LinkedDeque* createLinkedDeque()
{
    LinkedDeque *temp;

    temp = calloc(1, sizeof(LinkedDeque));
    return (temp);
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element);

int insertRearLD(LinkedDeque* pDeque, DequeNode element);

DequeNode* deleteFrontLD(LinkedDeque* pDeque);

DequeNode* deleteRearLD(LinkedDeque* pDeque);

DequeNode* peekFrontLD(LinkedDeque* pDeque);

DequeNode* peekRearLD(LinkedDeque* pDeque);

void deleteLinkedDeque(LinkedDeque* pDeque);

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
    return (pDeque->currentElementCount == 0);
}
