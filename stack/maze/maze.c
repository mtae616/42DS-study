#include "mapdef.h"

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack)
{
    size_t dir = 0;
    size_t i = 0; // y
    size_t j = 0; // x
    StackNode   *temp;
    
    while(i < HEIGHT)
    {
        if (startPos.x == endPos.x && startPos.y == endPos.y)
            break ;
        j = 0;
        while(j < WIDTH)
        {
            if (mazeArray[i][j] == 0)
                mazeArray[i][j] = 2;
            j++;
        }
        i++;
    }
    
    while(startPos.x != endPos.x && startPos.y != endPos.y)
    {
        int cnt = 0;
        if (mazeArray[startPos.x][startPos.y] == 2)
            pushLSMapPosition(pStack, startPos.x, startPos.y, startPos.direction);
        dir = 0;
        while(dir < 4)
        {
            if (startPos.y + DIRECTION_OFFSETS[dir][0] == 1 && startPos.x + DIRECTION_OFFSETS[dir][1] == 1)
                break ;
            if (startPos.y + DIRECTION_OFFSETS[dir][0] == 2 && startPos.x + DIRECTION_OFFSETS[dir][1] == 2)
            {
                cnt++;
                startPos.y += DIRECTION_OFFSETS[dir][0];
                startPos.x += DIRECTION_OFFSETS[dir][1];
                startPos.direction = dir;
                pushLSMapPosition(pStack, startPos.x, startPos.y, startPos.direction);
            }
            dir++;
        }
        if (cnt == 0)
            break ;
    }
    temp = pStack->pTopElement;
    for(int i = 0; i < pStack->currentElementCount; i++)
    {
        printf("the link %d %d \n", temp->data.x, temp->data.y);
        temp = temp->pLink;
    }
}

int pushLSMapPosition(LinkedStack *pStack, int y, int x, int direction)
{
    StackNode   *new_one = calloc(1, sizeof(StackNode));

    new_one->data.x = x;
    new_one->data.y = y;
    new_one->data.direction = direction;
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

    return 0;
}


// dir = 0;
// while(dir < 4)
// {
//     if (startPos.y + DIRECTION_OFFSETS[dir][0] >= 0 && startPos.x + DIRECTION_OFFSETS[dir][1] >= 0)
//     {
//         if (!(mazeArray[startPos.y + DIRECTION_OFFSETS[dir][0]][startPos.x + DIRECTION_OFFSETS[dir][1]]))
//         {
//             startPos.y += DIRECTION_OFFSETS[dir][0];
//             startPos.x += DIRECTION_OFFSETS[dir][1];
//             mazeArray[startPos.y][startPos.x] = 2;
//             pushLSMapPosition(pStack, startPos.y, startPos.x, dir);
//         }
//         // else
//         //     popLS(pStack);
//     }
//     dir++;

    // }
// startPos.x += j;