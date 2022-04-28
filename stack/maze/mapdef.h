#ifndef _MAP_DEF_
#define _MAP_DEF_

#define WIDTH 8
#define HEIGHT 8

#define NUM_DIRECTIONS 4

#include "./stack-using-linkedlist/linkedstack.h"

// offset: x, y
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
	{0, -1},		// 북쪽
	{1, 0},			// 동쪽
	{0, 1},			// 남쪽
	{-1, 0}			// 서쪽
};

enum PosStatus { NOT_VISIT = 0, WALL = 1 , VISIT = 2  };

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPost, MapPosition endPos, LinkedStack *pStack);
int pushLSMapPosition(LinkedStack *pStack, MapPosition node);
void printMaze(int mazeArray[HEIGHT][WIDTH]);
void showPath(LinkedStack *pStack);
MapPosition makeNode(int x, int y, int dir);

#endif