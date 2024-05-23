#include<iostream>0
using namespace std;

int front = -1;
int rear = -1;
int playTime = 0;


struct snakeTrail {
	int y; //행 정보
	int x; //열 정보
};

snakeTrail queue[10100];

int snakeBody[100][100] = { 0, };


void enqueue(int direction) {
	int a = 0, b = 0;
	if (direction == 0) {
		a = queue[rear].y;
		b = queue[rear].x + 1;
	}	
	else if (direction == 1) {
		a = queue[rear].y + 1;
		b = queue[rear].x;
	}	
	else if (direction == 2) {
		a = queue[rear].y;
		b = queue[rear].x - 1;
	}	
	else if (direction == 3) {
		a = queue[rear].y - 1;
		b = queue[rear].x;
	}

	queue[++rear].y = a;
	queue[rear].x = b;
	snakeBody[a][b]++;
	playTime++;
}

void dequeue() {
	front++;
	snakeBody[queue[front].y][queue[front].x] = 0;
}

//방향전환은 int dir = 0; (0, 1, 2, 3 == 우, 하, 좌, 상). dir++%4 혹은 dir--%4로 방향전환한다.


int main() {
	int N, appleCount, turnCount, gameCount = 0, direction = 0, t = 0; //t는 0부터 방향바뀔때마다 1씩 증가
	int tempx, tempy;
	bool play = 1;
	cin >> N >> appleCount;


	//2차원 맵 생성과 초기화
	bool** mapVisited = new bool*[N];
	for (int i = 0; i < N; i++) {
		mapVisited[i] = new bool[N];
		for (int j = 0; j < N; j++)
			mapVisited[i][j] = 0;
	}

	//사과 위치 표시
	bool** mapApple = new bool* [N];
	for (int i = 0; i < N; i++) {
		mapApple[i] = new bool[N];
		for (int j = 0; j < N; j++)
			mapApple[i][j] = 0;
	}

	//사과 위치 받아서 맵에 표시
	for (int i = 0; i < appleCount; i++) {
		cin >> tempx >> tempy;
		mapApple[tempx - 1][tempy - 1] = 1;
	}

	//방향전환정보 입력받아 저장
	cin >> turnCount;
	int* turnSec = new int[turnCount];
	char* turnDir = new char[turnCount];
	for (int i = 0; i < turnCount; i++) {
		cin >> turnSec[i] >> turnDir[i];
	}


	//뱀 위치 초기화
	queue[0] = { 0, 0 };
	rear = 0;
	snakeBody[0][0] = 1;

	//게임 시작
	while (play) { //벽이나 자기 몸과 만나면 play가 0이 되며 게임 종료 후 플레이타임 출력
		gameCount++;
		if (((queue[rear].y == 0 && direction == 3) || (queue[rear].y == N - 1 && direction == 1)) || ((queue[rear].x == 0 && direction == 2) || (queue[rear].x == N - 1 && direction == 0))) {
			play = 0;
			break;
		}
		enqueue(direction);
		if (snakeBody[queue[rear].y][queue[rear].x] > 1) {
			play = 0;
			break;
		}
		else if (mapApple[queue[rear].y][queue[rear].x] == 1) {
			mapApple[queue[rear].y][queue[rear].x] = 0;
		}
		else
			dequeue();
		
		if ((t < turnCount) && (gameCount == turnSec[t])) {
			if (turnDir[t] == 'D')
				direction = (direction + 1) % 4;
			else
				direction = (direction + 3) % 4;
			t++;
		}

	}


	cout << gameCount;


	//2차원 맵 할당 해제
	for (int i = 0; i < N; i++)
		delete[] mapVisited[i];
	delete[] mapVisited;
	for (int i = 0; i < N; i++)
		delete[] mapApple[i];
	delete[] mapApple;

	//방향전환정보 할당 해제
	delete[] turnSec;
	delete[] turnDir;

}