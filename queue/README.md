# Queue

- <a href="https://github.com/mtae616/42DS-study/tree/master/queue/arrayqueue">Queue using Array list</a>
- <a href="https://github.com/mtae616/42DS-study/tree/master/queue/arrayqueue">Queue using circular list</a>
- <a href="https://github.com/mtae616/42DS-study/tree/master/queue/linkeddeque">Queue using Linked list</a>
- <a href="https://github.com/mtae616/42DS-study/tree/master/queue/linkeddeque">Deque using Linked list</a>

<br />

## Queue와 Circular Queue

queue의 경우 크기가 제한되어 있고 빈 공간을 사용하려면 모든 자료를 꺼내거나 한 칸씩 옮겨야 한다. <br />
단, linked list를 활용할 경우 크기가 제한되거나 모든 자료를 꺼낼 필요는 없다. <br />
Circular queue의 경우 데이터 공간이 남아있는 것을 modular 연산을 통해 새로 indexing 하여 일반 queue의 단점을 보완할 수 있다. <br />

<br />

## Deque

FIFO구조를 무조건 지키는 queue를 보완하여 Front와 Rear를 설정해 앞과 뒤에서도 Enqueue 와 Dequeue를 수행한다.
