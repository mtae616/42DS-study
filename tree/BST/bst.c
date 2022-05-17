#include "bst.h"

BinSearchTree   *makeBinSearchTree(BinSearchTreeNode rootNode)
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

void    deleteBinSearchTree(BinSearchTree *pBinSearchTree)
{
    deleteBinSearchTreeNode(pBinSearchTree->pRootNode);
    free(pBinSearchTree);
    pBinSearchTree = NULL;
}

void    deleteBinSearchTreeNode(BinSearchTreeNode *pNode)
{
    if (pNode)
    {
        deleteBinSearchTreeNode(pNode->pLeftChild);
        deleteBinSearchTreeNode(pNode->pRightChild);
        free(pNode);
        pNode = NULL;
    }
}

BinSearchTreeNode   *insertBST(BinSearchTree *pBinSearchTree, BinSearchTreeNode element)
{
    BinSearchTreeNode   *buf;
    BinSearchTreeNode   *new_one = calloc(1, sizeof(BinSearchTreeNode));

    *new_one = element;
    new_one->pRightChild = 0;
    new_one->pLeftChild = 0;
    buf = pBinSearchTree->pRootNode;
    while(1)
    {
        if (buf->key > new_one->key)
        {
            if (!(buf->pLeftChild))
            {
                buf->pLeftChild = new_one;
                return (new_one);
            }
            else
                buf = buf->pLeftChild;
        }
        else if (buf->key < new_one->key)
        {
            if(!(buf->pRightChild))
            {
                buf->pRightChild = new_one;
                return (new_one);
            }
            else
                buf = buf->pRightChild;
        }
        else
            return (NULL);
    }
}

BinSearchTreeNode *LorR(BinSearchTreeNode *temp, int searchKey)
{
    BinSearchTreeNode   *buf;

    buf = NULL;
    if (searchKey == temp->pRightChild->key)
    {
        buf = temp->pRightChild;
        temp->pRightChild = NULL;
        if (buf->pLeftChild && !(buf->pRightChild)) // 자식 노드 1개
            temp->pRightChild = buf->pLeftChild;
        else if (!(buf->pLeftChild) && buf->pRightChild) // 자식 노드 1개
            temp->pRightChild = buf->pRightChild;
    }
    else if (searchKey == temp->pLeftChild->key)
    {
        buf = temp->pLeftChild;
        temp->pLeftChild = NULL;
        if (buf->pLeftChild && !(buf->pRightChild)) // 자식 노드 1개
            temp->pLeftChild = buf->pLeftChild;
        else if (!(buf->pLeftChild) && buf->pRightChild) // 자식 노드 1개
            temp->pLeftChild = buf->pRightChild;
    }
    return (buf);
}

void    deleteBST(BinSearchTree *pBinSearchTree, int searchKey)
{
    BinSearchTreeNode   *temp, *delNode, *pSuccessor, *pPredecessor;

    temp = pBinSearchTree->pRootNode;
    delNode = NULL;
    while (1)
    {
        if (temp->key == searchKey)
            delNode = temp;
        if ((temp->pRightChild && temp->pRightChild->key == searchKey) || (temp->pLeftChild && temp->pLeftChild->key == searchKey))
        {
            delNode = LorR(temp, searchKey);
            break ;
        }
        if (temp->pLeftChild && temp->key > searchKey)
            temp = temp->pLeftChild;
        else if (temp->pRightChild && temp->key < searchKey)
            temp = temp->pRightChild;
        else
            break ;
    }
    if (!delNode)
        return ;
    else if (delNode->pLeftChild && delNode->pRightChild) // 자식노드 2
    {
        pSuccessor = delNode->pLeftChild;
        while(pSuccessor->pRightChild)
        {
            pPredecessor = pSuccessor;
            pSuccessor = pSuccessor->pRightChild;
        }
        if (pSuccessor->pLeftChild)
            pPredecessor->pRightChild = pSuccessor->pLeftChild;
        else
            pPredecessor->pRightChild = NULL;
        if (pBinSearchTree->pRootNode->key == searchKey)
            pBinSearchTree->pRootNode = pSuccessor;
        else if (temp->key < pSuccessor->key)
            temp->pRightChild = pSuccessor;
        else if (temp->key > pSuccessor->key)
            temp->pLeftChild = pSuccessor;
        pSuccessor->pLeftChild = delNode->pLeftChild;
        pSuccessor->pRightChild = delNode->pRightChild;
    }
    free(delNode); // 자식노드 0, 1
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