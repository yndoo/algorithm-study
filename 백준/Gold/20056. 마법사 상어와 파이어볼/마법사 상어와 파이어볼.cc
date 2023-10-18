#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct fb {
	int r;
	int c;
	int m;
	int s;
	int d;
};

int N, M, K, r, c, m, s, d;
vector<fb> fireballs;	//fireball 갖고있는 벡터
vector<fb> arr[51][51]; //한 칸에 여러 볼이 있을 수 있는 2차원배열벡터
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 }; //0~7 방향
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void clearArr() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j].clear();
		}
	}
}

void Move() {
	for (int i = 0; i < fireballs.size(); i++) {
		int m = fireballs[i].m;
		int s = fireballs[i].s;
		int d = fireballs[i].d;
		
		int nx = fireballs[i].r + dx[d] * (s % N);
		if (nx > 0) nx = (nx - 1) % N + 1;
		else nx = N + nx;
		int ny = fireballs[i].c + dy[d] * (s % N);
		if (ny > 0)ny = (ny - 1) % N + 1;
		else ny = N + ny;

		arr[nx][ny].push_back({ nx, ny, m, s, d });
		fireballs[i].r = nx;
		fireballs[i].c = ny;
	}
}

void AfterMove() {
	vector<fb> tmp;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j].size() >= 2) {
				int mSum = 0;
				int sSum = 0;
				bool odd = true;	//홀짝 플래그
				bool even = true; 
				for (int k = 0; k < arr[i][j].size(); k++) {
					mSum += arr[i][j][k].m;
					sSum += arr[i][j][k].s;
					if (arr[i][j][k].d % 2 == 0) odd = false;
					else if (arr[i][j][k].d % 2 == 1) even = false;
				}
				mSum /= 5;
				sSum = sSum / arr[i][j].size();
				if (mSum == 0) continue;
				if (odd || even) {
					for (int newD = 0; newD <= 6; newD += 2) {
						tmp.push_back({ i, j, mSum, sSum, newD });
					}
				}
				else {
					for (int newD = 1; newD <= 7; newD += 2) {
						tmp.push_back({ i, j, mSum, sSum, newD });
					}
				}
			}
			else if (arr[i][j].size() == 1) {
				tmp.push_back(arr[i][j][0]);
			}
		}
	}
	fireballs = tmp;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> m >> s >> d;
		fireballs.push_back({ r,c,m,s,d });
	}
	for (int i = 0; i < K; i++) { //K : 명령 횟수
		if (i != 0) clearArr();
		//1. 이동
		Move();
		//2. 파이어볼이 2개 이상 있는 칸에서는 나누어진다.
		AfterMove();
	}
	//정답 계산
	int answer = 0;
	for (int i = 0; i < fireballs.size(); i++) {
		answer += fireballs[i].m;
	}
	cout << answer;
	return 0;
}