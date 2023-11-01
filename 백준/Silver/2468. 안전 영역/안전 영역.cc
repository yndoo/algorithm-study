#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int N, high = 0, low = 101, answer = 0;
int graph[100][100]; //주어진 높이 정보
bool visited[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool dfs(int x, int y, int k) {
	if (graph[x][y] <= k || visited[x][y]) return false;
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny] || graph[nx][ny] <= k) continue;
		dfs(nx, ny, k);
	}
	return true;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//입력받기
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
		high = max(high, *max_element(&graph[i][0], &graph[i][N]));
		low = min(low, *min_element(&graph[i][0], &graph[i][N]));
	}
	//low ~ high 사이의 높이별로 dfs
	for (int k = low - 1; k < high; k++) {
		fill(&visited[0][0], &visited[99][100], false);
		//dfs돌리기
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (dfs(i, j, k)) {
					cnt++;
				}
			}
		}
		//cnt 맥스 비교해서 답 갱신
		answer = max(answer, cnt);
	}
	cout << answer;
	return 0;
}
