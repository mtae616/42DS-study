#include "./list/linkedstack.h"

int checkBracketMatching(char *str)
{
    LinkedStack  *buf = createLinkedStack();
    StackNode   temp;
    char        c;

    while(*str)
    {
        if (*str == '(' || *str == '{' || *str == '[')
        {
            temp.data = *str;
            pushLS(buf, temp);
        }
        else if(*str == ')' || *str == '}' || *str == ']')
        {
            temp = *popLS(buf);
            c = temp.data;
            if (!c)
                return (FALSE);
            else
            {
                if (c == '(' && *str != ')')
                    return (FALSE);
                else if (c == '{' && *str != '}')
                    return (FALSE);
                else if (c == '[' && *str != ']')
                    return (FALSE);
            }
        }
        str++;
    }
    return (buf->currentElementCount > 0 ? (FALSE) : (TRUE));
}

int main()
{
    int a = checkBracketMatching("((A * B) / C) - {(D + E) && (F - G )}");
    printf("%d", a);
}