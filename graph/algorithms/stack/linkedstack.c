#include "linkedstack.h"

LinkedStack* createLinkedStack()
{
    LinkedStack *buf;

    buf = calloc(1, sizeof(LinkedStack));
    return (buf);
}