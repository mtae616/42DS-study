#ifndef _CALCULATE_H_
#define _CALCULATE_H_

#include "./stack-using-linkedlist/linkedstack.h"

// macro func
#define IS_DIGIT(x) ('0' <= x && x <= '9')
#define IS_ALPHA_LOWER(x) ('a' <= x && x <= 'z')
#define IS_ALPHA_UPPER(x) ('A' <= x && x <= 'Z')
#define IS_OPER(x) (x == '+' || x == '-' || x == '*' || x == '/')
#define IS_PLUS(x) (x == '+')
#define IS_MINUS(x) (x == '-')
#define IS_MULTY(x) (x == '*')
#define IS_DIV(x) (x == '/')
#define IS_SPACE(x) (x == ' ')

#endif