#include "linkedlist.h"

LinkedList* createLinkedList() // Linked list 생성
{
	LinkedList* buf;

	buf = malloc(sizeof(LinkedList));
	buf->currentElementCount = 0;
	buf->headerNode.data = 0;
	buf->headerNode.pLink = NULL;
	return (buf);
}

int addLLElement(LinkedList* pList, int position, ListNode element) // Node 추가
{
	int		i;
	ListNode	*buf;
	ListNode	*curr;
	ListNode	*prev;
	
	if (position < 0)
		return (FALSE);
	if(position == 0)
	{
		if (pList->currentElementCount == 0) // Header Node가 없을 때
		{
			pList->headerNode = element;
			pList->currentElementCount = 1;
			pList->headerNode.pLink = NULL;
		}
		else // Header Node가 있을 때
		{
			curr = malloc(sizeof(ListNode)); // 원래 header 의 데이터 복사
			curr->data = pList->headerNode.data;
			curr->pLink = pList->headerNode.pLink;
			element.pLink = curr; // 새로 들어온 element를 헤더로 바꾸기 위해 복사한 포인터를 next로 지칭
			pList->headerNode = element; // 새로 들어온 element를 헤더로 바꿔준다.
			pList->currentElementCount += 1;
		}
		return (TRUE);
	}
	buf = &(pList->headerNode);
	i = 0;
	while(buf && i < position)
	{
		if (i + 1 == position) // 새로 들어올 node를 위해 position 이전의 node의 주소를 저장한다.
			prev = buf;
		buf = buf->pLink;
		i++;
	}
	if (position == i) // Node 추가
	{
		curr = malloc(sizeof(ListNode)); // node 추가를 위한 데이터 복사
		curr->data = element.data;
		curr->pLink = buf; // 원래 위치의 node를 밀어내로
		prev->pLink = curr; // 원래 node 전의 node 의 next로 연결한다.
		pList->currentElementCount += 1;
		return (TRUE);
	}
	else
		return (FALSE);
}

int removeLLElement(LinkedList* pList, int position) // node를 지운다.
{
	size_t		i;
	ListNode	*buf;
	ListNode	*prev;
	ListNode	*next;

	if (!(position >= 0 && position < pList->currentElementCount))
		return (FALSE);
	i = 0;
	buf = &(pList->headerNode);
	if (position == 0) // Header Node일 때
	{
		if (!(buf->pLink)) // Header Node 의 Next가 없을 때
		{
			buf->data = 0x00;
			buf->pLink = NULL;
			pList->currentElementCount -= 1;
		}
		else // Header Node 의 Next가 있을 때
		{
			buf->data = 0x00;
			next = buf->pLink;
			pList->headerNode = *next; // Header Node Next로 교체한다.
			next = NULL;
			pList->currentElementCount -= 1;
		}
		return (TRUE);
	}
	while (buf != NULL && i < position)
	{
		if (i + 1 == position)
			prev = buf;
		buf = buf->pLink;
		i++;
	}
	if (buf && i == position) // Header Node가 아닐 때
	{
		next = buf->pLink; // 현재 위치 다음 것을
		prev->pLink = next; // 현재 위치 전의 것에 연결해준다.
		buf->data = 0x00;
		buf->pLink = NULL;
		free(buf);
		pList->currentElementCount -= 1;
		return (TRUE);
	}
	else
		return (FALSE);
}

ListNode* getLLElement(LinkedList* pList, int position) // 원하는 위치의 Node를 얻는다.
{
	ListNode *buf;

	// 위치가 음수인 것과 현재 엘리먼트 갯수보다 큰 위치의 노드는 없다!
    if (!(position >= 0 && position <= pList->currentElementCount))
        return (FALSE);
	buf = &(pList->headerNode);
	while(position--) // position 만큼 이동한다.
		buf = buf->pLink;
    return (buf);
}

void clearLinkedList(LinkedList* pList) // 내부 Node를 전부 없애준다.
{
	ListNode *buf;
	ListNode *next;

	buf = pList->headerNode.pLink;
	while(buf)
	{
		next = buf->pLink;
		buf->data = 0x00;
		free(buf);
        buf = NULL;
		buf = next;
	}
	pList->headerNode.data = 0x00;
	pList->headerNode.pLink = NULL;
	pList->currentElementCount = 0;
}

int getLinkedListLength(LinkedList* pList) // list 내부 Node의 개수 return
{
	return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList* pList) // List와 Node를 제거한다.
{
	clearLinkedList(pList);
	free(pList);
    pList = NULL;
}	
