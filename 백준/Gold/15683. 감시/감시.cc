#include<bits/stdc++.h>
using namespace std;
int N, M;
int graph1[10][10];	//사무실 상태 원본 - 최초에 입력받은 정보
int graph2[10][10]; //사무실 상태 복사본 - gamshi 함수에서 사용(사각지대 개수 세기 위해 사용)
int dx[4] = {-1, 0, 1, 0}; //상 우 하 좌, 이게 dir의 0, 1, 2, 3을 나타나게 됨
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> cctv; //cctv위치 저장하는 벡터

int mypow(int a, int b) {	//정수제곱 함수 직접 구현(이게 pow사용보다 정확하다)
	int ans = 1;
	for (int i = 0; i < b; i++)
		ans *= a;
	return ans;
}

void gamshi(int x, int y, int dir) { //cctv가 감시 가능한 곳을 7로 표시하는 함수
	dir %= 4;
	while (true) {
		x += dx[dir];
		y += dy[dir];
		if (x < 0 || x >= N || y < 0 || y >= M || graph2[x][y] == 6) return; //out of bound거나 벽이면 그만 가기
		if (graph2[x][y] != 0) continue; //CCTV가 있을 경우 넘어감
		graph2[x][y] = 7; //볼 수 있는 곳은 7로 덮기
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int mn = 0; //사각지대 개수 세는 변수(정답이 될 변수)
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph1[i][j];
			if (graph1[i][j] != 0 && graph1[i][j] != 6) { cctv.push_back({ i, j }); }
			if (graph1[i][j] == 0) mn++; //CCTV가 없는 상황을 대비하여 처음 상태의 0 개수도 세어두기
		}
	}
	//4진수를 활용해 cctv의 네가지 방향 활용 
	//ex -> 1번 cctv가 3개라면 : 000, 001, 002, 003, 010, 011, ... , 332, 333 까지 총 64가지 경우의 수 표현 가능
	//cctv가 k개라면 4^k개의 방향
	for (int total = 0; total < mypow(4, cctv.size()); total++) { //4^k개의 경우의수 모두 확인하기
		//graph1을 graph2로 복사
		copy(&graph1[0][0], &graph1[9][9], &graph2[0][0]);
		int cctvs = total;
		for (int i = 0; i < cctv.size(); i++) {
			int dir = cctvs % 4; //4진수 쪼개기
			cctvs /= 4;
			int x = cctv[i].first;
			int y = cctv[i].second;
			if (graph1[x][y] == 1) { //1번 cctv
				gamshi(x, y, dir);
			}
			else if (graph1[x][y] == 2) {
				gamshi(x, y, dir);
				gamshi(x, y, dir + 2); //+2로 상하, 좌우 표현 가능, gamshi함수 내부에  dir%=4 해서 사용하기 때문에 4초과하는 숫자도 가능
			}
			else if (graph1[x][y] == 3) {
				gamshi(x, y, dir);
				gamshi(x, y, dir + 1);
			}
			else if (graph1[x][y] == 4) {
				gamshi(x, y, dir);
				gamshi(x, y, dir + 1);
				gamshi(x, y, dir + 2);
			}
			else if (graph1[x][y] == 5) {
				gamshi(x, y, dir);
				gamshi(x, y, dir + 1);
				gamshi(x, y, dir + 2);
				gamshi(x, y, dir + 3);
			}
		}
		int zeros = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (graph2[i][j] == 0) zeros++;
			}
		}
		mn = min(mn, zeros);
	}//for - total
	cout << mn;
	return 0;
}

/*
문제 : N*M 칸의 사무실에서 CCTV를 둘 때 사각지대의 최솟값을 구하라. 이때 CCTV는 5개의 종류가 있음.

- 바킹독 강의에서 본 방법으로 다시 풀어서 AC받음. 4진수 활용 방법.
- 예를 들어 1번 cctv가 3개 라면 이를 4진수로 000, 001, 002, … , 020, 021, …, 332, 333 으로 총 16가지 경우의 수를 표현할 수 있음. 0 - 북, 1 - 동, 2 - 남, 3 - 서 << 이런식으로 방향 정해서 사용.
- cctv 개수가 k개면 4^k개의 경우의 수 있음.


로직 : 

1. 사무실 정보를 grapg1에 입력받으며 cctv 벡터에 cctv 좌표를 넣어둠.
** 방향 경우의 수는 4^cctv.size(). → 이때 1번 cctv외에는 방향이 4가지 미만인데 이렇게 하는 이유는 구현이 편리해지기 때문이다.. 그리고 N과 M 범위가 작아서 시간이 매우 충분하다.
2. 4^cctv.size()를 돌면서 cctv벡터 돌면서 각 cctv들의 방향 처리. (이때 4진수로 계산해주면서 for문 돌려야함)
    cctv 좌표 : x, y
    dir = 4진수 쪼갠 값.
    graph2에 graph1을 복사.(초기화의 의미)
    
2-1. graph1[x][y] == 1일 때 gamshi(x, y, dir); //cctv가 1번이라는 뜻
** gamshi(x, y, dir)함수는 x, y에 있는 cctv가 dir방향(dx, dy배열 사용)으로 뻗어가는 것을 graph2에 기록하는 함수

2-2. graph1[x][y] == 2일 때 gamshi(x, y, dir); gamshi(x, y, dir+2);
** 감시함수를 이렇게 사용하면 dir의 경우의 수가 (0, 2) (1,3) (2,4) (3,5) 이렇게 있음. 감시함수 내에서 dir%=4; 해서 사용하기 때문에 괜찮음. dir+2인 이유는 dx, dy에 설정했듯이 수평 방향이기 때문에.

2-3, 2-4, 2-5. cctv 3,4,5번도 이런식으로 gamshi(감시)함수 사용.

2-6. 한 경우의 수 계산 끝날 때마다 graph2에서 0개수 세어서 mn 최솟값 갱신.

3. cout << mn;
*/
