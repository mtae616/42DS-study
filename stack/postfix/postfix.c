#include "postfix.h"

int convert_postfix(char *str)
{
    LinkedStack *stack = createLinkedStack();
    StackNode   *buf = calloc(1, sizeof(StackNode));
    StackNode   *temp;

    while(*str)
    {
        if (IS_DIGIT(*str))
            printf("%c ", *str);
        else if (IS_CLOSE(*str))
        {
            temp = peekLS(stack);
            while(temp)
            {
                temp = popLS(stack);
                if (temp->data == '(')
                    break ;
                printf("%c ", temp->data);
            }
        }
        else if (*str == '+' || *str == '-')
        {
            temp = peekLS(stack);
            if (!temp)
                continue ;
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
                    }
                    else
                        break ;
                }
            }
        }
        if (IS_OPER(*str) || IS_OPEN(*str))
        {
            buf->data = *str;
            pushLS(stack, *buf);
        }
        str++;
    }
    while(temp)
    {
        temp = popLS(stack);
        if (!temp)
            break ;
        printf("%c ", temp->data);
    }
    free(stack);
    free(buf);
    stack = NULL;
    buf = NULL;
    return 0;
}

int main()
{
    convert_postfix("2 * (3 + 4) + (6 * 9)");
    return 0;
}