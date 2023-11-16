#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
#include<string>

#define INF 1e9

using namespace std;
int N, M;
int graph[101][101];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int d[101][101];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

void input() {
	//cout << "===in input()1===\n";
	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			graph[i][j + 1] = (s[j] - '0');
		}
	}
	fill(&d[0][0], &d[100][101], INF);
	//cout << "===in input()2===\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	d[1][1] = 0;
	pq.push({ d[1][1],1,1 });

	int cost, x, y;
	while (!pq.empty()) {
		//cout << "@@ in while @@\n";
		tie(cost, x, y) = pq.top(); pq.pop();
		//cout << cost << " " << x << " " << y << "\n";
		if (d[x][y] != cost) continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
			int nc = graph[nx][ny];
			if (d[nx][ny] <= d[x][y] + nc) continue;
			d[nx][ny] = d[x][y] + nc;
			pq.push({ d[nx][ny], nx, ny});
		}
	}
	cout << d[N][M];

	return 0;
}