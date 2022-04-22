#include "doublylist.h"

DoublyList	*createDoublyList() // list 생성
{
	DoublyList	*buf;

	buf = (DoublyList *)calloc(1, sizeof(DoublyList)); // calloc으로 초기화 하면서 생성
	NULLCHECK(buf);
	return (buf);
}