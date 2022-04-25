#include "postfix.h"

int priotity(char *lst, LinkedStack *stack, StackNode *temp, int *i)
{
    temp = peekLS(stack);
    if (!temp)
        return (0);
    else if (temp->data == '*' || temp->data == '/')
    {
        while(temp->data == '*' || temp->data == '/')
        {
            temp = peekLS(stack);
            if (!temp)
                break ;
            if (temp->data == '*' || temp->data == '/')
            {
                temp = popLS(stack);
                printf("%c ", temp->data);
                lst[*i] = temp->data;
                *i += 1;
                lst[*i] = ' ';
                *i += 1;
            }
            else
                break ;
        }
    }
    return (1);
}

int check_up_len(char *str)
{
    int i = 0;
    while(*str)
    {
        if (*str != '(' && *str != ')')
            i++;
        str++;
    }
    return (i);
}

char    *convert_postfix(char *str)
{
    LinkedStack *stack = createLinkedStack();
    StackNode   *buf = calloc(1, sizeof(StackNode));
    StackNode   *temp;
    char        *lst = calloc(check_up_len(str), sizeof(char));
    int         i = 0;

    while(*str)
    {
        if (IS_DIGIT(*str))
        {
            lst[i++] = *str;
            lst[i++] = ' ';
            printf("%c ", *str);
        }
        else if (IS_CLOSE(*str))
        {
            temp = peekLS(stack);
            while(temp)
            {
                temp = popLS(stack);
                if (temp->data == '(')
                    break ;
                lst[i++] = temp->data;
                lst[i++] = ' ';
                printf("%c ", temp->data);
            }
        }
        if (*str == '+' || *str == '-')
            priotity(lst, stack, temp, &i);
        if (IS_OPER(*str) || IS_OPEN(*str))
        {
            buf->data = *str;
            pushLS(stack, *buf);
        }
        str++;
    }
    temp = peekLS(stack);
    while(temp)
    {
        temp = popLS(stack);
        if (!temp)
            break ;
        lst[i++] = temp->data;
        lst[i++] = ' ';
        printf("%c ", temp->data);
    }
    deleteLinkedStack(stack);
    free(buf);
    stack = NULL;
    buf = NULL;
    printf("\n");
    return (lst);
}

int main()
{
    convert_postfix("2 - (3 + 4) * 5");
    convert_postfix("2 + 3 * 9 / 7");
    int res = calcExpr(convert_postfix("2 * (3 + 4) + (6 * 9)"));
    printf("%d", res);
    return 0;
}