#ifndef _BST_H_
#define _BST_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct BinSearchTreeNodeType
{
	int key;
	int visited;

	struct BinSearchTreeNodeType* pLeftChild;
	struct BinSearchTreeNodeType* pRightChild;
} BinSearchTreeNode;

typedef struct BinTreeType
{
	struct BinSearchTreeNodeType* pRootNode;
} BinSearchTree;

// 이진 탐색 트리 생성
BinSearchTree   *makeBinSearchTree(BinSearchTreeNode rootNode);

BinSearchTreeNode   *getRootNodeBST(BinSearchTree *pBinSearchTree);

// 이진 탐색 트리 삭제
void    deleteBinSearchTreeNode(BinSearchTreeNode *pNode);
void    deleteBinSearchTree(BinSearchTree *pBinSearchTree);
// 자료 추가
BinSearchTreeNode	*insertBST(BinSearchTree *pBinSearchTree, BinSearchTreeNode element);
// 자료 제거
void    deleteBST(BinSearchTree *pBinSearchTree, int searchKey);
// 검색
BinSearchTreeNode   *getNodeBST(BinSearchTree *pBinSearchTree, int searchKey);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif