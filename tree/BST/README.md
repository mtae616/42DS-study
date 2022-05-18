## 이진 탐색 트리, Binary search tree

<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FclAHlW%2FbtrCw8fLW5Y%2FihFRTC0TGsIWYserIuPNek%2Fimg.png" />

이진 탐색 트리는

- 각 노드에는 값이 있다.
- 값들은 전순서(임의의 원소를 비교할 수 있는 부분 순서 집합)가 있다.
- 노드의 왼쪽 서브트리에는 그 노드의 값보다 작은 값들을 지신 노드들로 이뤄진다.
- 노드의 오른쪽 서브트리에는 그 노드의 값보다 큰 값들을 지닌 노드들로 이워진다.

이진 탐색 트리는 일반적으로 탐색에서 O(log n)으로 장점을 갖는다.
다만, 편향 트리로 이뤄져있다면 O(n)의 가능성이 있다.
이 경우 red black tree를 이용할 수 있다.
아래에서는 Linked list를 사용한 이진 탐색 트리의 구현을 살펴본다.

## 구현

- 생성
- 삽입
- 개별 node 삭제
- Tree 삭제

### 생성

```C
typedef struct BinSearchTreeNodeType
{
	int key;

	struct BinSearchTreeNodeType* pLeftChild;
	struct BinSearchTreeNodeType* pRightChild;
} BinSearchTreeNode;

typedef struct BinTreeType
{
	struct BinSearchTreeNodeType* pRootNode;
} BinSearchTree;

BinSearchTree   *makeBinSearchTree(BinSearchTreeNode rootNode) // 생성
{
    BinSearchTree   *temp = calloc(1, sizeof(BinSearchTree));
    temp->pRootNode = calloc(1, sizeof(BinSearchTreeNode));
    *temp->pRootNode = rootNode;
    temp->pRootNode->pRightChild = 0;
    temp->pRootNode->pLeftChild = 0;
    return (temp);
}

```

key와 data를 가질 수 있지만,
이번에는 key만을 가진 이진 탐색 트리를 구현했다.

### 삽입

```C
BinSearchTreeNode   *insertBST(BinSearchTree *pBinSearchTree, BinSearchTreeNode element) // node 삽입
{
    BinSearchTreeNode   *buf;
    BinSearchTreeNode   *new_one = calloc(1, sizeof(BinSearchTreeNode));

    *new_one = element; // 새로 할당할 node
    new_one->pRightChild = 0;
    new_one->pLeftChild = 0;
    buf = pBinSearchTree->pRootNode; // root노드를 시작으로 들어갈 위치의 부모노드를 저장한다.
    while(1)
    {
        if (buf->key > new_one->key) // 새로들어갈 노드가 더 작다면
        {
            if (!(buf->pLeftChild)) // 부모노드의 left child가 없다면
            {
                buf->pLeftChild = new_one; // 부모 노드와 이어준다.
                return (new_one);
            }
            else // 내려가 다시 탐색한다.
                buf = buf->pLeftChild;
        }
        else if (buf->key < new_one->key) // 새로들어갈 노드가 더 크다면
        {
            if(!(buf->pRightChild)) // 부모노드의 right child가 없다면
            {
                buf->pRightChild = new_one; // 부모 노드와 이어준다.
                return (new_one);
            }
            else // 내려가 탐색한다.
                buf = buf->pRightChild;
        }
        else
            return (NULL);
    }
}
```

root node 는 tree를 생성하며 할당해주어, 이외의 케이스에 대해서만 고려하면 된다.
왼쪽 서브 트리는 항상 부모 노드보다 작다는 것, 오른쪽의 경우에는 항상 크다는 것을 유의하여야 한다.

### 개별 node 삭제

```C
BinSearchTreeNode *LorR(BinSearchTreeNode *temp, int searchKey) // 왼쪽, 오른쪽 자식 노드인지 판별
{
    BinSearchTreeNode   *buf;

    buf = NULL;
    if (searchKey == temp->pRightChild->key) // 만약 오른쪽 자식 노드라면
    {
        buf = temp->pRightChild; // 오른쪽 자식으로 할당한다.
        temp->pRightChild = NULL;
        if (buf->pLeftChild && !(buf->pRightChild)) // 자식 노드 1개때 부모 노드와의 연결을 끊는다.
            temp->pRightChild = buf->pLeftChild;
        else if (!(buf->pLeftChild) && buf->pRightChild)
            temp->pRightChild = buf->pRightChild;
    }
    else if (searchKey == temp->pLeftChild->key) // 만약 왼쪽 자식 노드라면
    {
        buf = temp->pLeftChild; // 왼쪽 자식 노드로 할당한다.
        temp->pLeftChild = NULL;
        if (buf->pLeftChild && !(buf->pRightChild)) // 자식 노드 1개때 부모 노드와의 연결을 끊는다.
            temp->pLeftChild = buf->pLeftChild;
        else if (!(buf->pLeftChild) && buf->pRightChild)
            temp->pLeftChild = buf->pRightChild;
    }
    return (buf);
}

void    deleteBST(BinSearchTree *pBinSearchTree, int searchKey) // 개별 노드 삭제
{
    BinSearchTreeNode   *temp, *delNode, *pSuccessor, *pPredecessor;
    // 각각 삭제할 노드의 부모노드, 삭제할 노드, 계승할 노드, 계승할 노드의 부모노드 이다.

    temp = pBinSearchTree->pRootNode; // 삭제할 노드의 부모노드로, Root로 시작한다.
    delNode = NULL;
    while (1)
    {
        if (temp->key == searchKey) // 만약 삭제할 노드가 root라면 delNode를 temp로 할당한다.
            delNode = temp;
        if ((temp->pRightChild && temp->pRightChild->key == searchKey) || (temp->pLeftChild && temp->pLeftChild->key == searchKey))
        { // 자식 중 delNode가 있다면,
            delNode = LorR(temp, searchKey); // 함수로 들어가 왼쪽인지 오른쪽인지 판별한다.
            break ;
        }
        if (temp->pLeftChild && temp->key > searchKey) // 자식 중 searchKey에 해당하지 않으면 다시 탐색한다.
            temp = temp->pLeftChild;
        else if (temp->pRightChild && temp->key < searchKey)
            temp = temp->pRightChild;
        else
            break ;
    }
    if (!delNode)
        return ;
    else if (delNode->pLeftChild && delNode->pRightChild) // 자식노드 2개라면,
    {
        pSuccessor = delNode->pLeftChild; // 삭제할 노드의 왼쪽으로 간 뒤 맨 오른쪽 노드가 계승노드로 둔다.
        while(pSuccessor->pRightChild)
        {
            pPredecessor = pSuccessor;
            pSuccessor = pSuccessor->pRightChild;
        }
        if (pSuccessor->pLeftChild) // 만약 계승노드에 자식노드 (무조건 왼쪽이다.)가 있다면 부모노드와 이어준다.
            pPredecessor->pRightChild = pSuccessor->pLeftChild;
        else // 계승노드에 자식노드가 없다면 연결을 끊어준다.
            pPredecessor->pRightChild = NULL;
        if (pBinSearchTree->pRootNode->key == searchKey) // 만약 삭제할 노드가 root 였다면
            pBinSearchTree->pRootNode = pSuccessor; // root를 갱신단다.
        else if (temp->key < pSuccessor->key) // 삭제한 노드의 부모노드와 이어준다.
            temp->pRightChild = pSuccessor;
        else if (temp->key > pSuccessor->key) // 삭제한 노드의 부모노드와 이어준다.
            temp->pLeftChild = pSuccessor;
        pSuccessor->pLeftChild = delNode->pLeftChild; // 삭제한 노드의 자식노드와 계승노드를 이어준다.
        pSuccessor->pRightChild = delNode->pRightChild;
    }
    free(delNode); // 할당 해제, 자식노드가 0개일 때는 고려할 것 없이 바로 할당해제 한다.
    delNode = NULL;
}
```

어떠한 노드가 삭제되었을 때 고려해야 할 것은

1. 원래 부모노드와 삭제한 노드의 서브트리를 이어줄 것
2. 삭제한 노드에 자식 노드가 0개일 때
   - 부모노드에 바로 이어주면 된다.
3. 삭제한 노드에 자식 노드가 1개일 때
   - 왼쪽인지 오른쪽인지 판별하여 이어준다.
4. 삭제한 노드에 자식 노드가 2개일 때 - 삭제한 노드가 root인지 - 삭제한 노드의 자식 노드에 자식 노드가 있는지 - 삭제한 노드의 부모노드의 왼쪽 자식이 될지 오른쪽이 될지 - 삭제한 노드의 서브트리를 이어준다.
   이다.

### Tree 삭제

```C
void    deleteBinSearchTree(BinSearchTree *pBinSearchTree) // 트리 삭제
{
    deleteBinSearchTreeNode(pBinSearchTree->pRootNode);
    free(pBinSearchTree);
    pBinSearchTree = NULL;
}

void    deleteBinSearchTreeNode(BinSearchTreeNode *pNode) // 노드 삭제
{
    if (pNode)
    {
        deleteBinSearchTreeNode(pNode->pLeftChild);
        deleteBinSearchTreeNode(pNode->pRightChild);
        free(pNode);
        pNode = NULL;
    }
}
```

recursive call을 이용해 하위 노드들을 먼저 끊어주었다.
