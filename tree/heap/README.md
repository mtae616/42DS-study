# 힙 Heap

<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FHCwMb%2FbtrCwadYRzq%2FEQi526KSGI8sKxUK7RLBN1%2Fimg.png">

힙은 항상 완전 이진 트리 (위로부터 왼쪽 오른쪽 순서대로 쌓이는 것을 말한다.)의 형태를 지닌다.

부모의 값은 자식의 값보다 크거나(Max heap), 작아야(Min heap) 한다.

따라서 루트노드에는 항상 데이터 중 크거나 작은 값이 저장되어 있기 때문에 최대, 최소값 탐색에 O(1)이 걸린다.

데이터의 삽입과 삭제는 모두 O(log N)이 소요된다.

이러한 특성은 완전 이진 트리이며, 부모노드가 항상 크거나 작다는 확증에 기인한다.

## Max heap 구현

- 생성
- 삽입
- root node 반환, Pop
- Heap 삭제

### 생성

```C
typedef struct HeapNodeType
{
	int key;
} HeapNode;

typedef struct HeapType
{
	int maxElementCount;		// 최대 원소 개수
	int currentElementCount;	// 현재 원소의 개수
	HeapNode *pElement;	// 원소 저장을 위한 1차원 배열
} Heap;

Heap*	createHeap(int maxElementCount)
{
	Heap	*temp;

	temp = calloc(1, sizeof(Heap));
	temp->pElement = calloc(maxElementCount, sizeof(HeapNode));
	return temp;
}
```

배열리스트로 구현하는 만큼, pElement에는 Node가 들어갈 만큼 할당하여야 한다.

### 삽입

```C
int insertMaxHeapNode(Heap* hList, HeapNode element) // 삽입
{
	int	i;

	if (isMaxHeapFull(hList))
		return (FALSE);
	i = hList->currentElementCount; // 현재 Node 개수 저장
	while ((i != 0) && element.key > hList->pElement[i / 2].key) // 만약 부모노드가 element 보다 크다면 반복문을 멈춘다.
	{
		hList->pElement[i] = hList->pElement[i / 2]; // 부모노드를 자식 노드로 내려준다.
		i = i / 2;
	}
	hList->pElement[i] = element; // 마지막으로 남는 자리에 element를 할당한다.
	hList->currentElementCount += 1;
	return TRUE;
}
```

Max heap 이므로, 삽입을 위해서는 부모노드가 새로 삽입할 노드보다 크다는 것을 확정하여야 한다.
하여 만약 부모노드가 작다면, while문 내부에서 자식노드로 내려주는 연산을 통해 부모노드를 바꿀 수 있게 한다.
삽입된 만큼 아래로 내려준다는 이미지이다.

### Root node 반환, Pop

```C
HeapNode	popMaxHeapNode(Heap* hList) // root node 반환
{
	HeapNode	root, temp;
	int			i, parent, child;

	root = hList->pElement[0]; // Root node
	i = hList->currentElementCount;
	temp = hList->pElement[i - 1]; // 가장 마지막 노드
	hList->currentElementCount -= 1; // root 노드가 삭제되었으므로 한 개 뺀다.
	parent = 0; // Root
	child = 1; // child
	while(child <= hList->currentElementCount)
	{
		if((child < hList->currentElementCount) && hList->pElement[child].key < hList->pElement[child + 1].key) child += 1; // 만약 child + 1 이 더 크다면 부모는 child + 1이 될 수 있게 한다.
		if (temp.key >= hList->pElement[child].key) break; // temp가 더 크다면 부모에 Temp를 할당할 수 있게 한다.
		hList->pElement[parent] = hList->pElement[child]; // 자식을 부모로 올려준다.
		parent = child;
		child *= 2; // index 값을 다음 자식으로 변경한다.
	}
	hList->pElement[parent] = temp; // 남은 자리에 temp를 할당한다.
	return root;
}
```

Root가 빠졌으므로 빠진 부분을 채워야한다.
빠진 만큼 위로 올린다는 이미지이다.

### Heap 삭제

```C
void deleteMaxHeap(Heap* hList)
{
	free(hList->pElement);
	hList->pElement = NULL;
	free(hList);
	hList = NULL;
}

```

할당을 해제한다.
