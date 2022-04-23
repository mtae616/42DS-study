#include "./list/arraystack.h"

int checkBracketMatching(char *str)
{
    ArrayStack  *buf = createArrayStack(100);
    StackNode   temp;
    char        c;

    while(*str)
    {
        if (*str == '(' || *str == '{' || *str == '[')
        {
            temp.data = *str;
            pushAS(buf, temp);
        }
        else if(*str == ')' || *str == '}' || *str == ']')
        {
            temp = *popAS(buf);
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
