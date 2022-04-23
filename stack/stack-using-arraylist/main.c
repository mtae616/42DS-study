#include "arraystack.h"

int main()
{
    ArrayStack   *temp;
    StackNode   a;
    StackNode   b;
    StackNode   c;
    StackNode   *buf;


    temp = createArrayStack(10);
    a.data = 'a';
    pushAS(temp, a);
    b.data = 'b';
    pushAS(temp, b);
    c.data = 'c';
    pushAS(temp, c);
    buf = popAS(temp);
    printf("the buf is %c\n", buf->data);
    for(int i = 0; i < temp->currentElementCount; i++)
    {
        printf("%d %c\n", i, temp->pElement[i].data);
    }
    buf = peekAS(temp);
    printf("the buf is %c\n", buf->data);
    deleteArrayStack(temp);
    int aa = isArrayStackEmpty(temp);
    printf("the res %d\n", aa);
}