#include "bst.h"

BinSearchTree   *makeBinSearchTree(BinSearchTreeNode rootNode) // 생성
{
    BinSearchTree   *temp = calloc(1, sizeof(BinSearchTree));
    temp->pRootNode = calloc(1, sizeof(BinSearchTreeNode));
    *temp->pRootNode = rootNode;
    temp->pRootNode->pRightChild = 0;
    temp->pRootNode->pLeftChild = 0;
    return (temp);
}

BinSearchTreeNode   *getRootNodeBST(BinSearchTree *pBinSearchTree)
{
    return (pBinSearchTree->pRootNode);
}

void    deleteBinSearchTree(BinSearchTree *pBinSearchTree) // 트리 삭제
{
    deleteBinSearchTreeNode(pBinSearchTree->pRootNode);
    free(pBinSearchTree);
    pBinSearchTree = NULL;
}

void    deleteBinSearchTreeNode(BinSearchTreeNode *pNode) // 개별 노드 삭제
{
    if (pNode)
    {
        deleteBinSearchTreeNode(pNode->pLeftChild);
        deleteBinSearchTreeNode(pNode->pRightChild);
        free(pNode);
        pNode = NULL;
    }
}

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
    BinSearchTreeNode   *temp, *delNode, *pSuccessor, *pPredecessor; // 각각 삭제할 노드의 부모노드, 삭제할 노드, 계승할 노드, 계승할 노드의 부모노드 이다.

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

BinSearchTreeNode   *getNodeBST(BinSearchTree *pBinSearchTree, int searchKey)
{
    BinSearchTreeNode   *temp;

    temp = pBinSearchTree->pRootNode;
    while (1)
    {
        if (!temp)
            return (NULL);
        if (temp->key == searchKey)
            return (temp);
        if (temp->key > searchKey)
            temp = temp->pLeftChild;
        else if (temp->key < searchKey)
            temp = temp->pRightChild;
    }
}

void preorderTraversalBinTree(BinSearchTreeNode* pNode)
{
    if (!pNode)
        return ;
    if (pNode->pLeftChild)
    {
        printf("%d ", pNode->key);
        preorderTraversalBinTree(pNode->pLeftChild);
        if (pNode->pRightChild)
            preorderTraversalBinTree(pNode->pRightChild);
    }
    else
    {
        printf("%d ", pNode->key);
        preorderTraversalBinTree(pNode->pRightChild);
    }
}

int main()
{
    BinSearchTreeNode   buf;
    BinSearchTreeNode   *root;
    
    buf.key = 30;
    BinSearchTree   *temp = makeBinSearchTree(buf);
    buf.key = 20;
    insertBST(temp, buf);
    buf.key = 40;
    insertBST(temp, buf);
    buf.key = 10;
    insertBST(temp, buf);
    buf.key = 24;
    insertBST(temp, buf);
    buf.key = 6;
    insertBST(temp, buf);
    buf.key = 14;
    insertBST(temp, buf);
    buf.key = 22;
    insertBST(temp, buf);
    buf.key = 34;
    insertBST(temp, buf);
    buf.key = 46;
    insertBST(temp, buf);
    
    // deleteBST(temp, 30);
    deleteBST(temp, 55);
    // deleteBST(temp, 46);

    preorderTraversalBinTree(temp->pRootNode);

    // BinSearchTreeNode   *test;
    // root = temp->pRootNode;
    // printf("%d ", root->key);
    // test = root->pLeftChild;
    // printf("%d ", test->key);
    // test = root->pRightChild;
    // printf("%d ", test->key);
    
    // test = root->pLeftChild->pLeftChild;
    // printf("%d ", test->key);
    // test = root->pLeftChild->pRightChild;
    // printf("%d ", test->key);

    // test = root->pRightChild->pLeftChild;
    // printf("%d ", test->key);
    // test = root->pRightChild->pRightChild;
    // printf("%d ", test->key);

    // test = root->pLeftChild->pLeftChild->pLeftChild;
    // printf("%d ", test->key);
    // test = root->pLeftChild->pLeftChild->pRightChild;
    // printf("%d ", test->key);

    // test = root->pLeftChild->pRightChild->pLeftChild;
    // printf("%d ", test->key);
    return 0;
}