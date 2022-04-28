#include "mapdef.h"

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack)
{
    int         exit = FALSE;
    int         marked_map[HEIGHT][WIDTH] = {0, };
    StackNode   *temp;
    MapPosition buf;
    int         dir, x, y;

    pushLSMapPosition(pStack, startPos);
    marked_map[startPos.x][startPos.y] = TRUE;
    while(!exit)
    {
        temp = popLS(pStack);
        x = temp->data.x;
        y = temp->data.y;
        dir = temp->data.direction;
        while(dir < 4 && !exit)
        {
            int new_y = y + DIRECTION_OFFSETS[dir][0];
            int new_x = x + DIRECTION_OFFSETS[dir][1];
            if (new_y == endPos.y && new_x == endPos.x)
            {
                buf.x = new_x;
                buf.y = new_y;
                buf.direction = dir++;
                temp->data = buf;
                exit = TRUE;
                pushLSMapPosition(pStack, buf);
            }
            else if(mazeArray[new_y][new_x] == FALSE && marked_map[new_y][new_x] == FALSE)
            {
                marked_map[new_y][new_x] = TRUE;
                buf.x = new_x;
                buf.y = new_y;
                buf.direction = dir++;
                temp->data = buf;
                x = new_x;
                y = new_y;
                pushLSMapPosition(pStack, buf);
                dir = 0;
            }
            else
                dir++;
        }
        free(temp);
    }
    temp = pStack->pTopElement;
    for(int i = 0; i < pStack->currentElementCount; i++)
    {
        printf("\n%d %d\n", temp->data.y, temp->data.x);
        temp = temp->pLink;
    }
}

int pushLSMapPosition(LinkedStack *pStack, MapPosition node)
{
    StackNode   *new_one = calloc(1, sizeof(StackNode));

    new_one->data.x = node.x;
    new_one->data.y = node.y;
    new_one->data.direction = node.direction;
    new_one->pLink = pStack->pTopElement;
    pStack->pTopElement = new_one;
    pStack->currentElementCount += 1;
    return (TRUE);
}

void printMaze(int mazeArray[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            printf("%d ", mazeArray[i][j]);
        }
        printf("\n");
    }
}


// enum PosStatus { NOT_VISIT = 0, WALL = 1 , VISIT = 2  };

int main()
{
    LinkedStack *pStack = calloc(1, sizeof(LinkedStack));
    // y, x
    pStack = createLinkedStack();
    int mazeArray[8][8] = {
        {0, 0, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 0}
    };
    MapPosition startpos;

    startpos.y = 0;
    startpos.x = 0;
    startpos.direction = 2;

    MapPosition endpos;

    endpos.y = 7;
    endpos.x = 7;
    endpos.direction = 0;

    findPath(mazeArray, startpos, endpos, pStack);    
    printMaze(mazeArray);
    // free(pStack);
    // system("leaks a.out");
    return 0;
}
