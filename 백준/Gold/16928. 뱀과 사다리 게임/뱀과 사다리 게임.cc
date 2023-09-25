#include<bits/stdc++.h>
using namespace std;

int N, M;
int graph[101];
int visited[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<int> q;
	cin >> N >> M;
	int x, y, target, next;
	for (int i = 0; i < N + M; i++) {
		cin >> x >> y;
		graph[x] = y;
	}
	q.push(1);
	while (!q.empty()) {
		target = q.front(); q.pop();
		for (int i = 1; i <= 6; i++) {
			next = target + i;
			if (next > 100) break;
			if (graph[next]) next = graph[next];
			if (!visited[next]) {
				visited[next] = visited[target] + 1;
				q.push(next);
			}
		}
	}
	cout << visited[100];
	return 0;
}