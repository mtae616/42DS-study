# <Label id="a1">배열 리스트 (Array List)</Label>

배열리스트는 자료를 순서대로 저장하는 자료구조로,  
논리적 순서(저장)와 물리적 순서(저장)가 동일하다.  
원소의 위치 인덱스는 0부터 시작하고,  
정적배열로 최대 갯수가 정해져 있고,이는 배열과 동일하다.  
C에서는 라이브러리로 배열리스트를 지원하지 않기 때문에,  
개발자가 직접 구현해야하는 기능으로는,

-   리스트 생성
-   원소 추가
    -   원소 추가 가능 여부 판단
-   원소 반환
-   원소 제거
    -   리스트 초기화
-   리스트 삭제

를 꼽을 수 있다.

## 특징

저장순서가 순차적이기 때문에 Index가 곧 위치로, 탐색(O(1))에 용이하지만,  
배열이 공백을 허용하지 않아 삽입이나 삭제 시에는 노드가 끊기지 않아야 하기 때문에,  
삽입이 됐을 떄에는 기존 노드를 뒤로 미루거나, 삭제가 됐을 때에는 원래 노드들을 앞으로 땡기는 등의 작업이 필요하다(O(N)).  
또한 정적배열로 저장할 수 있는 최대 갯수가 정해져 있어 이를 넘어가는 저장은 불가하다.

# 구현

## 생성

```
typedef struct ArrayListNodeType // List에 들어갈 Node
{
    int data;
} ArrayListNode;

typedef struct ArrayListType
{
    int maxElementCount;        // 최대 원소 개수
    int currentElementCount;    // 현재 원소의 개수
    ArrayListNode *pElement;    // 원소 저장을 위한 1차원 배열
} ArrayList;
```

위와 같이 헤더를 선언하여, list를 생성한다.

```
ArrayList* createArrayList(int maxElementCount) // ArrayList 생성
{
    ArrayList *buf;

    if (maxElementCount < 0)
        return (FALSE);
    buf = malloc(sizeof(ArrayList *)); // ArrayList 생성
    buf->pElement = malloc(sizeof(int) * maxElementCount); // 실제 Node가 들어갈 배열
    buf->maxElementCount = maxElementCount; // 정적 배열로 최대 몇 개가 들어갈 것인지 미리 정한다.
    buf->currentElementCount = 0;
    return (buf);
}
```

위의 구조체 선언대로 List를 생성한다.

## 추가

```
int addALElement(ArrayList* pList, int position, ArrayListNode element) // ArrayList node 추가
{
    int i;

    if (pList->maxElementCount <= position) // max 넘겨 node 추가할 때
        return (FALSE);
    if (pList->maxElementCount < pList->currentElementCount) // 원소 + 1 <= maxCount
        return (FALSE);
    i = pList->currentElementCount + 1; // node 추가를 위한 인덱싱
    while(i >= position) {
        pList->pElement[i].data = pList->pElement[i - 1].data; // 원래 값들을 한 칸 뒤로 이동시킨다.
        i--;
    }
    pList->pElement[position].data = element.data; // position 에 원하는 값 입력
    pList->currentElementCount += 1;
    return (TRUE);
}
```

위와 같이 원래 Node가 있을 때를 고려하거나, MaxCount보다 넘기는 값인지에 대해 유의해야 한다.  
이 때 원래 값들을 뒤로 밀어줘야 하기 때문에 O(N)으로 Linked List와 비교하여 단점을 지닌다.

## 탐색

```
ArrayListNode* getALElement(ArrayList* pList, int position) // 원소의 주소 반환
{

    return &(pList->pElement[position]); // 원하는 위치의 주소값 반환
}
```

ArrayList는 특성 상 Index 값을 통해 탐색하기 때문에  
O(1) 의 속도를 갖는다.

## 개별 삭제

```
int removeALElement(ArrayList* pList, int position) // 원소를 지운다.
{
    int i;

    if (!pList)
        return (FALSE);
    i = position;
    pList->pElement[position].data = 0; // position의 값 지운 후
    while (i <= pList->currentElementCount - 1)
    {
        pList->pElement[i].data = pList->pElement[i + 1].data; // 값들을 앞으로 땡긴다.
        i++;
    }
    pList->pElement[i].data = 0;
    pList->currentElementCount -= 1;
    return (TRUE);
}
```

개별 원소를 삭제할 때에는 삭제된 뒤의 Node들을 앞으로 땡겨줘야 하기 때문에  
O(N)으로 Linked List와 비교하여 단점을 지닌다.

## 전체 삭제

```

void clearArrayList(ArrayList* pList) // 내부 원소들을 지운다.
{
    size_t  i;

    if(!pList)
        return ;
    i = 0;
    while (pList->pElement[i].data)
    {
        pList->pElement[i].data = 0;
        i++;
    }
    pList->currentElementCount = 0;
    free(pList->pElement);
    pList->pElement = NULL;
}

void deleteArrayList(ArrayList* pList) // 모든 원소와 list를 지운다.
{
    if (!pList)
        return ;
    clearArrayList(pList);
    free(pList);
    pList = NULL;
}
```