#include "bintree.h"

BinTree* makeBinTree(BinTreeNode rootNode)
{
    BinTree *buf;

    buf = calloc(1, sizeof(BinTree));
    buf->pRootNode = calloc(1, sizeof(BinTreeNode));
    *buf->pRootNode = rootNode;
    return (buf);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
    return pBinTree->pRootNode;
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
    if ((pParentNode->pLeftChild && pParentNode->pRightChild) || pParentNode->pLeftChild)
        return (NULL);
    pParentNode->pLeftChild = calloc(1, sizeof(BinTreeNode));
    *pParentNode->pLeftChild = element;
    return (pParentNode->pLeftChild);
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
    if ((pParentNode->pLeftChild && pParentNode->pRightChild) || pParentNode->pRightChild)
        return (NULL);
    pParentNode->pRightChild = calloc(1, sizeof(BinTreeNode));
    *pParentNode->pRightChild = element;
    return (pParentNode->pRightChild);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
    return pNode->pLeftChild;
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
    return pNode->pRightChild;
}

void deleteBinTree(BinTree* pBinTree)
{
    if (pBinTree)
    {
        deleteBinTreeNode(pBinTree->pRootNode);
        free(pBinTree);
        pBinTree = NULL;
    }
}

void deleteBinTreeNode(BinTreeNode* pNode)
{
    if (pNode)
    {
        deleteBinTreeNode(pNode->pLeftChild);
        deleteBinTreeNode(pNode->pRightChild);
        free(pNode);
        pNode = NULL;
    }
}
