#include "mapdef.h"

void showPath(LinkedStack *pStack)
{
    int temp[HEIGHT][WIDTH] = {0, };
    StackNode   *buf;
    StackNode   *next;

    for (int i = pStack->currentElementCount; i > 0; i--)
    {
        buf = popLS(pStack);

        next = buf->pLink;
        temp[buf->data.y][buf->data.x] = 2;
        free(buf);
        buf = next;
    }
    printMaze(temp);
}

void    stack_swap(LinkedStack *pStack)
{
    LinkedStack *new_stack = createLinkedStack();
    StackNode   *temp;
    StackNode   *next;

    for(int idx = pStack->currentElementCount; idx > 0; idx--)
    {
        temp = popLS(pStack);
        next = temp->pLink;
        pushLSMapPosition(new_stack, temp->data);
        free(temp);
        temp = next;
    }
    showPath(new_stack);
    deleteLinkedStack(new_stack);
}

int is_valid(int x, int y)
{
    return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT);
}

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack)
{
    int         exit = FALSE;
    int         marked_map[HEIGHT][WIDTH] = {0, };
    StackNode   *temp;
    MapPosition buf;
    int         dir = 0, x = 0, y = 0;

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
            int new_y = y + DIRECTION_OFFSETS[dir][1];
            int new_x = x + DIRECTION_OFFSETS[dir][0];
            if (new_y == endPos.y && new_x == endPos.x)
            {
                pushLSMapPosition(pStack, makeNode(x, y, dir));
                pushLSMapPosition(pStack, makeNode(new_x, new_y, dir));
                exit = TRUE;
            }
            else if(mazeArray[new_y][new_x] == FALSE && marked_map[new_y][new_x] == FALSE && is_valid(new_x, new_y))
            {
                marked_map[new_y][new_x] = TRUE;
                pushLSMapPosition(pStack, makeNode(x, y, dir));
                x = new_x;
                y = new_y;
                dir = 0;
            }
            else
                dir++;
        }
        free(temp);
    }
    stack_swap(pStack);
}

MapPosition makeNode(int x, int y, int dir)
{
    MapPosition buf;

    buf.x = x;
    buf.y = y;
    buf.direction = dir;
    return (buf);
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

int main()
{
    LinkedStack *pStack;
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
    startpos.direction = 0;

    MapPosition endpos;

    endpos.y = 7;
    endpos.x = 7;
    endpos.direction = 0;

    findPath(mazeArray, startpos, endpos, pStack);
    deleteLinkedStack(pStack);
    system("leaks a.out");
    return 0;
}
