#include "calculate.h"

int	calculate(LinkedStack *stack, char oper)
{
	int		a;
	int		b;
	int		res;
	StackNode	*temp;

	temp = popLS(stack);
	a = temp->data;
	temp = popLS(stack);
	b = temp->data;
	if (IS_PLUS(oper))
		res = b + a;
	else if(IS_MINUS(oper))
		res = b - a;
	else if (IS_MULTY(oper))
		res = b * a;
	else if (IS_DIV(oper))
		res = b / a;
	else
		res = 0;
	return (res);
}

int calcExpr(char *expr)
{
	LinkedStack	*stack;
	int			res;
	StackNode	*buf = malloc(sizeof(StackNode));
	
	stack = createLinkedStack();
	while(*expr)
	{
		res = 0;
		if (IS_SPACE(*expr))
			expr++;
		if(IS_DIGIT(*expr))
		{
			res += *expr - '0';
			buf->data = res;
			pushLS(stack, *buf);
		}
		else if(IS_OPER(*expr) && (IS_SPACE(*(expr + 1)) || *(expr + 1) == 0))
		{
			if (stack->currentElementCount >= 2)
			{
				res = calculate(stack, *expr);
				buf->data = res;
				pushLS(stack, *buf);
			}
			else
			{
				buf->data = *expr;
				pushLS(stack, *buf);
			}
		}
		expr++;
	}
	if (stack->currentElementCount == 1)
		res = stack->pTopElement->data;
	else
		res = 0;
	free(buf);
	deleteLinkedStack(stack);
	buf = NULL;
	stack = NULL;
	return (res);
}
