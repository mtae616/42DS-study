#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "arraylist.h"

ArrayList* createArrayList(int maxElementCount)
{
    ArrayList *buf;

    if (maxElementCount < 0)
        return (FALSE);
    buf = malloc(sizeof(ArrayList *));
    // if (!buf)
    //     return(FALSE);
    buf->pElement = malloc(sizeof(int) * maxElementCount);
    // if (!(buf->pElement))
    //     return (FALSE);
    buf->maxElementCount = maxElementCount;
    buf->currentElementCount = 0;
    return (buf);
}

int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
    int i;

    if (pList->maxElementCount <= position) // max 넘겨 node 추가할 때
        return (FALSE);
    if (pList->maxElementCount < pList->currentElementCount) // 원소 + 1 <= maxCount
        return (FALSE);
    i = pList->currentElementCount + 1;
    while(i >= position) {
        pList->pElement[i].data = pList->pElement[i-1].data;
        i--;
    }
    pList->pElement[position].data = element.data;
    pList->currentElementCount += 1;
    return (TRUE);
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
    
    return &(pList->pElement[position]);
}

int isArrayListFull(ArrayList* pList)
{
    if (!pList)
        return (FALSE);
    return (pList->maxElementCount == pList->currentElementCount);
}

int removeALElement(ArrayList* pList, int position)
{
    int i;

    if (!pList)
        return (FALSE);
    i = position;
    pList->pElement[position].data = 0;
    while (i <= pList->currentElementCount - 1)
    {
        pList->pElement[i].data = pList->pElement[i + 1].data;
        i++;
    }
    pList->pElement[i].data = 0;
    pList->currentElementCount -= 1;
    return (TRUE);
}

void ft_putnbr(int n)
{
    char c;

    if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
    if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
    c = n % 10 + '0';
	write(1, &c, 1);
}

void displayArrayList(ArrayList* pList)
{
    size_t  i;

    if (!pList)
        write(1, "(null)", 6);
    write(1, "maxElementCount is ", 19);
    ft_putnbr(pList->maxElementCount);
    write(1, "\n", 1);
    write(1, "currentElementCount is ", 23);
    ft_putnbr(pList->currentElementCount);
    write(1, "\n", 1);
    i = 0;
    write(1, "Elements is \n", 13);
    while(pList->pElement[i].data)
    {
        ft_putnbr(i);
        write(1, " : ", 3);
        ft_putnbr(pList->pElement[i].data);
        write(1, "\n", 1);
        i++;
    }
}

void clearArrayList(ArrayList* pList)
{
    size_t  i;

    if(!pList)
        return ;
    i = 0;
    while (pList->pElement[i].data)
    {
        pList->pElement[i].data = 0;
        i++;
    }
    pList->currentElementCount = 0;
    free(pList->pElement);
    pList->pElement = NULL;
}

int getArrayListLength(ArrayList* pList)
{
    return (pList->currentElementCount);
}

void deleteArrayList(ArrayList* pList)
{
    if (!pList)
        return ;
    clearArrayList(pList);
    free(pList);
    pList = NULL;
}

int main()
{
    ArrayList *new_one;
    ArrayListNode a;
    ArrayListNode c;
    ArrayListNode d;
    ArrayListNode e;
    ArrayListNode f;
    ArrayListNode *b;

    a.data = 5;
    c.data = 99;
    d.data = 123;
    e.data = 888;
    f.data = 777;

    new_one = createArrayList(50);
    printf("%d\n", new_one->maxElementCount);

    addALElement(new_one, 0, a);
    addALElement(new_one, 1, c);
    addALElement(new_one, 2, d);
    addALElement(new_one, 3, e);
    addALElement(new_one, 4, f);

    deleteArrayList(new_one);

    // addALElement(new_one, 0, a);

    // printf("%d\n", new_one->pElement[0].data);
    // b = getALElement(new_one, 0);
    // printf("the data is %d\n", b->data);
    displayArrayList(new_one);
    // deleteArrayList(new_one);
    // clearArrayList(new_one);
    // printf("%d\n", new_one->pElement[3].data);
    // printf("the length is %d\n", getArrayListLength(new_one));
    // removeALElement(new_one, 2);
    // printf("%d\n", new_one->pElement[2].data);
    // free(new_one);
    // free(b);
    return 0;
}