#include "bintree.h"

void preorderTraversalBinTree(BinTreeNode* pNode)
{
    if (!pNode)
        return ;
    if (pNode->pLeftChild)
    {
        printf("%c\n", pNode->data);
        preorderTraversalBinTree(pNode->pLeftChild);
        if (pNode->pRightChild)
            preorderTraversalBinTree(pNode->pRightChild);
    }
    else
    {
        printf("%c\n", pNode->data);
        preorderTraversalBinTree(pNode->pRightChild);
    }
}