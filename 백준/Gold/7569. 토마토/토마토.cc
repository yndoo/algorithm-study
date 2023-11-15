#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
int M, N, H, answer = 0, cnt = 0;
int box[100][100][100]; //H N M
int visited[100][100][100]; //H N M
int dz[6] = { 0,0,0,0,1,-1 }; //우 하 좌 상 윗층 아랫층
int dx[6] = { 1,0,-1,0,0,0 };
int dy[6] = { 0,1,0,-1,0,0 };
queue<tuple<int, int, int>> tomatoQ;
void input() {
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> box[i][j][k];
				if (box[i][j][k] == 1) {
					cnt++; tomatoQ.push({ i,j,k });
				}
				else if (box[i][j][k] == 0) visited[i][j][k] = -1;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	//애초에 모두 익지 못하는 상황인지 확인
	if (cnt == 0) {
		cout << -1; return 0;
	}
	//토마토 익히기
	while (!tomatoQ.empty()) {
		auto cur = tomatoQ.front(); tomatoQ.pop();
		int x, y, z;
		tie(z, x, y) = cur;
		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i];
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nz < 0 || nz >= H || nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (visited[nz][nx][ny] >= 0) continue;
			visited[nz][nx][ny] = visited[z][x][y] + 1;
			tomatoQ.push({ nz, nx, ny });
		}
	}

	//정답확인
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (visited[i][j][k] == -1) {
					cout << -1;
					return 0;
				}
				answer = max(answer, visited[i][j][k]);
			}
		}
	}
	cout << answer;
	return 0;
}