#include<iostream>
#include<queue>
#include<vector>
#define INF 1e9
using namespace std;
int N, M, X, s, e, t;
int d[1001]; // 최단 시간 저장
int answer = 0;
vector<pair<int, int>> graph[1001]; //도로 정보

int party(int start, int end) {
	fill(&d[0], &d[N + 1], INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[start] = 0;
	pq.push({ d[start], start });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (d[cur.second] != cur.first) continue;
		for (auto nxt : graph[cur.second]) {
			if (d[nxt.second] <= d[cur.second] + nxt.first) continue;
			d[nxt.second] = d[cur.second] + nxt.first;
			pq.push({ d[nxt.second], nxt.second });
		}
	}
	return d[end];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> X;
	while (M--) {
		cin >> s >> e >> t;
		graph[s].push_back({ t, e });
	}
	for (int i = 1; i <= N; i++) {
		if (i == X) continue;
		int sum = 0;
		sum += party(i, X);
		sum += party(X, i);
		if (answer < sum) answer = sum;
	}
	cout << answer;
	return 0;
}