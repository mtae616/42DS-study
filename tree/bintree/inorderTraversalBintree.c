#include "bintree.h"

void inorderTraversalBintree(BinTreeNode* pNode)
{
    if (pNode->pLeftChild)
    {
        inorderTraversalBintree(pNode->pLeftChild);
        if (pNode->pRightChild)
            inorderTraversalBintree(pNode->pRightChild);
        printf("%c ", pNode->data);
    }
    else
    {
        if (pNode->pRightChild)
            levelOrderTraversalBintree(pNode->pRightChild);
        printf("%c ", pNode->data);
    }
}