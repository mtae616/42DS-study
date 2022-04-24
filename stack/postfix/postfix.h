#ifndef _POSTFIX_H_
#define _POSTFIX_H_

#include "./stack-using-linkedlist/linkedstack.h"
#include "./calculate/calculate.h"

// macro func
#define IS_DIGIT(x) ('0' <= x && x <= '9')
#define IS_OPER(x) (x == '+' || x == '-' || x == '*' || x == '/')
#define IS_BRACKET(x) (x == '(' || x == ')')
#define IS_OPEN(x) (x == '(')
#define IS_CLOSE(x) (x == ')')

#endif