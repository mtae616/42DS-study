큐는 주로 데이터가 입력된 **시간 순서대로 처리**해야 할 필요가 있는 상황에 이용한다.

### 1.  우선순위가 같은 작업 예약 (프린터의 인쇄 대기열)
### 2.  은행 업무 -> 과제 !
### 3.  콜센터 고객 대기시간 -> 과제 ! 
### 4.  프로세스 관리
 프로세스 스케줄링 = CPU 스케줄링
  
   컴퓨터 시스템에서 성능을 이야기할 때, 단위 시간동안 많은 작업을 할 수 있어야 하고 (CPU를 놀리지 말아야 하고) 하나의 작업은 빨리 끝나야 한다.

>  **프로세스란 ?**
     메모리에 적재되어 CPU에서 실행중인 프로그램.
     컴퓨터 하드웨어인 CPU는 여러개의 프로세스를 동시에 실행할 수 없다.
     언제나 한순간에 오직 1개의 프로세스를 수행한다.
      다만, 운영체제의 멀티태스킹(Multi tasking)과 스케줄링 기법으로 여러개의 프로세스가 동시에 실행되는 것처럼 보일뿐이다.   
Code: 실행 명령을 포함하는 코드 영역  
Data: static, grobal 변수 영역  
Heap: 동적 메모리 영역  
Stack: 지역변수, 매개변수 등 일시적인 데이터 영역  

> **프로세스 제어 블록 (Process Control Block, PCB)**
     프로세스의 실행을 제어하는데 사용하기 위한 자료구조


   *  Job queue : 시스템 안에 존재하는 프로세스들
   *  Ready queue : 메모리 상 존재하며 실행 준비가 되어 있는 프로세스들
   *  Device queue : 입출력 장치의 사용을 기다리는 프로세스들

![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FcfQK5z%2FbtqJCt69UHK%2F0wvymmPLWkObHGgMVAq6B1%2Fimg.png)


>  **쓰레드란 ?**
 프로세스 내에서 실제로 작업을 수행하는 주체 ( 실행 흐름의 최소 단위 )  
 멀티스레드 프로세스는 여러 스레드가 같은 프로세스 내에서 자원을 공유하면서 작업을 하기 때문에 발생할 수 있는 동기화(synchronization), 교착상태(deadlock) 같은 문제들을 고려해야 함   

멀티프로세스와 멀티스레드는 양쪽 모두 여러 흐름이 동시에 진행된다는 공통점을 가지고 있다. 하지만 멀티프로세스에서 각 프로세스는 독립적으로 실행되며 각각 별개의 메모리를 차지하고 있는 것과 달리 멀티스레드는 프로세스 내의 메모리를 공유해 사용할 수 있다. 또한 프로세스 간의 전환 속도보다 스레드 간의 전환 속도가 빠르다. 

 ![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fn7oHR%2Fbtq85fiqK5x%2FVLf4EKQUPYlYSjmTkQnHI0%2Fimg.png)


### 5.  너비 우선 탐색(BFS, Breadth-First Search) 구현
 : 루트 노드(혹은 다른 임의의 노드)에서 시작해서 인접한 노드를 먼저 탐색하는 방법
![bfs vs. dfs](https://github.com/42-DataStructure-2022-2-3/wiki/blob/main/Screen%20Shot%202022-05-09%20at%204.24.36%20PM.png?raw=true)
### 6.  캐시(Cache) 구현
 : 자주 사용하는 데이터나 값을 미리 복사해 놓는 임시 장소.  
     &nbsp; 반복적으로 데이터를 불러오는 경우에, 지속적으로 DBMS 혹은 서버에 요청하는 것이 아니라 Memory에 데이터를 저장하였다가 불러다 쓰는 것


***
***

<< 은행 시뮬레이션 >> 

은행원 1명 ! -> 쓰레드 1개  
은행원 여러명 -> 멀티쓰레드 ~~ ? 멀티 프로세스 ~~ ?

![](https://github.com/42-DataStructure-2022-2-3/wiki/blob/main/Screen%20Shot%202022-05-09%20at%206.46.52%20PM.png)
