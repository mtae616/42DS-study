#include "doublylist.h"

DoublyList	*createDoublyList()
{
	DoublyList	*buf;

	buf = (DoublyList *)calloc(1, sizeof(DoublyList));
	NULLCHECK(buf);
	return (buf);
}