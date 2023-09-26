#include<bits/stdc++.h>
using namespace std;
int N, M, sum;
int graph[500][500];
bool visited[500][500];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int answer = 0;

void tetromino(int x, int y, int sum, int cnt) {
	if (cnt == 4) {
		if (sum > answer) {
			answer = sum; return;
		}
		else return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		if (visited[nx][ny] == false) {
			visited[nx][ny] = true;
			tetromino(nx, ny, sum + graph[nx][ny], cnt + 1);
			visited[nx][ny] = false;
		}
	}
	return;
}
// ㅓ ㅏ ㅗ ㅜ 모양은 예외 처리!
void exception_blocks(int x, int y) {
	if (x + 1 < N && y + 2 < M) {	//ㅜ 모양
		answer = max(answer, graph[x][y] + graph[x][y + 1] + graph[x][y + 2] + graph[x + 1][y + 1]);
	}
	if (x - 1 >= 0 && y + 2 < M) {	//ㅗ 모양
		answer = max(answer, graph[x][y] + graph[x][y + 1] + graph[x][y + 2] + graph[x - 1][y + 1]);
	}
	if (x + 2 < N && y + 1 < M) {	//ㅏ 모양
		answer = max(answer, graph[x][y] + graph[x + 1][y] + graph[x + 2][y] + graph[x + 1][y + 1]);
	}
	if (x + 2 < N && y - 1 >= 0) {	//ㅓ 모양
		answer = max(answer, graph[x][y] + graph[x + 1][y] + graph[x + 2][y] + graph[x + 1][y - 1]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = true;
			tetromino(i, j, graph[i][j], 1);
			exception_blocks(i, j);
			visited[i][j] = false;
		}
	}
	cout << answer;
	return 0;
}