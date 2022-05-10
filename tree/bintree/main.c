#include "bintree.h"

int main()
{
    BinTree *temp;
    BinTreeNode buf;
    BinTreeNode *root;
    BinTreeNode *b;
    BinTreeNode *c;
    BinTreeNode *d;
    BinTreeNode *e;
    BinTreeNode *f;
    BinTreeNode *g;

    buf.data = 'A';

    temp = makeBinTree(buf);
    buf.data = 'B';
    b = insertLeftChildNodeBT(temp->pRootNode, buf);
    
    buf.data = 'D';
    d = insertLeftChildNodeBT(b, buf);
    buf.data = 'H';
    insertLeftChildNodeBT(d, buf);
    buf.data = 'I';
    insertRightChildNodeBT(d, buf);

    buf.data = 'E';
    e = insertRightChildNodeBT(b, buf);
    buf.data = 'J';
    insertLeftChildNodeBT(e, buf);
    
    buf.data = 'C';
    c = insertRightChildNodeBT(temp->pRootNode, buf);
    
    buf.data = 'F';
    f = insertLeftChildNodeBT(c, buf);
    buf.data = 'K';
    insertRightChildNodeBT(f, buf);

    buf.data = 'G';
    g = insertRightChildNodeBT(c, buf);

    buf.data = 'L';
    insertLeftChildNodeBT(g, buf);
    buf.data = 'M';
    insertRightChildNodeBT(g, buf);

    preorderTraversalBinTree(temp->pRootNode);

    return 0;
}