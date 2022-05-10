#include "bintree.h"

void levelOrderTraversalBintree(BinTreeNode* pNode)
{
    if (!pNode)
        return ;
    if (pNode->pLeftChild)
    {
        levelOrderTraversalBintree(pNode->pLeftChild);
        printf("%c ", pNode->data);
        if (pNode->pRightChild)
            levelOrderTraversalBintree(pNode->pRightChild);
    }
    else
    {
        printf("%c ", pNode->data);
        if (pNode->pRightChild)
            levelOrderTraversalBintree(pNode->pRightChild);
    }
}