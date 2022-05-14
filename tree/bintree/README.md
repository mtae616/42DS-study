# 트리 Tree

<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FPFSfV%2FbtrB5AksSKd%2FwnS0MEbfZtuQYF1JTnT4c0%2Fimg.png" />

<br />

트리 구조(tree 構造, 문화어: 나무구조)란 그래프의 일종으로, 여러 노드가 한 노드를 가리킬 수 없는 구조이다.
간단하게는 회로가 없고, 서로 다른 두 노드를 잇는 길이 하나뿐인 그래프를 트리라고 부른다.

<br />

트리에서 최상위 노드를 루트 노드(root node 뿌리 노드)라고 한다. 
또한 노드 A가 노드 B를 가리킬 때 A를 B의 부모 노드(parent node), 
B를 A의 자식 노드(child node)라고 한다. 자식 노드가 없는 노드를 잎 노드(leaf node 리프 노드)라고 한다. 
잎 노드가 아닌 노드를 내부 노드(internal node)라고 한다.

<br />

## 용어 정리

### node(노드)

> 트리를 구성하고 있는 기본 요소
노드에는 키 또는 값과 하위 노드에 대한 포인터를 가지고 있다.
> 

### Edge(간선)

> 노드와 노드 간의 연결선
> 

### 트리에서의 위치

- Root Node (루트 노드)
    
    :  최상위 노드, 부모가 없는 노드
    
    - A
- Leaf Node (잎 노드), Teminal Node (터미널 노드) 혹은 단말 노드
    
    :  자식 노드가 없는 노드
    
- Internal Node (내부 노드)
    
    :  Leaf Node가 아닌 노드
    

### 노드 사이의 관계 관점

- Parent Node (부모 노드)
    
    :  자식 노드를 갖는 노드
    
    - A 가 B 를 가리킬 때, A 를 B의 부모 노드 라고 한다.
- Child Node (자식 노드)
    
    :  부모 노드를 갖는 노드
    
    - A 가 B 를 가리킬 때, B 를 A의 자식 노드 라고 한다.
- Ancestor node (선조 노드)
    
    :  부모 노드에서 루트 노드까지의 모든 부모 노드
    
    - I 의 선조 노드는 E, B, A
- Descendant node (자손 노드)
    
    :  자식 노드와 그 자식들의 자식들의 자식들.......
    
    - B 의 자손 노드는 E, F, I, M
- Sibling Node, Brother Node (형제 노드)
    
    :  동일한 부모를 갖는 노드
    
    - B 와 C는 A를 부모로하는 형제 노드

### 속성 관점

- 크기(size) : 자기 자신을 포함한 모든 자손 노드의 개수
- 깊이(depth) : 루트노드로부터 어떤 노드에 도달하기 위해 거쳐야할 가지의 개수
- 레벨(level) : 트리의 특정 깊이를 가지는 노드의 집합
- 차수(degree) : 하위 트리의 개수 / 간선 수 = 어떤 노드가 가진 가지의 수
- 높이(height) : 루트 노드에서 가장 깊숙히 있는 노드의 깊이
- 균형도(balance) : 이진트리에서 어떤 노드의 균형도는 ‘leftChild의 높이 - rightChild의 높이’ 이다. 균형도가 2이상인 노드가 존재하면, 불균형한 트리라고 판달할 수 있다.

<img src="https://user-images.githubusercontent.com/75446713/167810655-d1f7c243-35a0-43bd-ba87-7bca81e67de5.png" />

## Tree 구현
- 생성
- 반환
- 추가, Left or Right
- 삭제

### 생성

```C
typedef struct BinTreeNodeType
{
	char data;
	int visited;

	struct BinTreeNodeType* pLeftChild;
	struct BinTreeNodeType* pRightChild;
} BinTreeNode;

typedef struct BinTreeType
{
	struct BinTreeNodeType* pRootNode;
} BinTree;
```

구조체를 선언한 후

```C
BinTree* makeBinTree(BinTreeNode rootNode)
{
    BinTree *buf;

    buf = calloc(1, sizeof(BinTree));
    buf->pRootNode = calloc(1, sizeof(BinTreeNode));
    *buf->pRootNode = rootNode;
    return (buf);
}
```
생성해준다, 이 때 root노드를 인자로 받았으므로
루트노드를 할당해준다.

### 반환
```C
BinTreeNode* getRootNodeBT(BinTree* pBinTree) // root 반환
{
    return pBinTree->pRootNode;
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode) // left child 반환
{
    return pNode->pLeftChild;
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode) // right child 반환
{
    return pNode->pRightChild;
}
```

해당하는 node를 반환할 수 있게 한다.

### 추가
```C
BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element) // left child
{
    if ((pParentNode->pLeftChild && pParentNode->pRightChild) || pParentNode->pLeftChild) // 자식노드가 꽉 찼거나, leftchild가 이미 있을 때
        return (NULL);
    pParentNode->pLeftChild = calloc(1, sizeof(BinTreeNode));
    *pParentNode->pLeftChild = element;
    return (pParentNode->pLeftChild);
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
    if ((pParentNode->pLeftChild && pParentNode->pRightChild) || pParentNode->pRightChild) // 자식노드가 꽉 찼거나, rightchild가 이미 있을 때
        return (NULL);
    pParentNode->pRightChild = calloc(1, sizeof(BinTreeNode));
    *pParentNode->pRightChild = element;
    return (pParentNode->pRightChild);
}
```

자식노드가 이미 있거나, 해당하는 노드가 이미 자식으로 있을 때에는 추가할 수 없게 해준다.

### 삭제

```C
void deleteBinTree(BinTree* pBinTree) // 개별 노드 삭제
{
    if (pBinTree)
    {
        deleteBinTreeNode(pBinTree->pRootNode);
        free(pBinTree);
        pBinTree = NULL;
    }
}

void deleteBinTreeNode(BinTreeNode* pNode) // 전체 tree 삭제
{
    if (pNode)
    {
        deleteBinTreeNode(pNode->pLeftChild);
        deleteBinTreeNode(pNode->pRightChild);
        free(pNode);
        pNode = NULL;
    }
}
```
전체 node를 삭제할 때는 종단탐색을 통해서 끝에서부터 삭제할 수 있게 한다.