#include<iostream>
#include<vector>
#include<queue>

#define INF 0xffffffffffff

typedef long long ll;

using namespace std;
int N, M, K, U, V, C, tmp;
ll d[100001];
vector<int> interview;
vector<pair<int, int>> graph[100001];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
void input() {
	cin >> N >> M >> K;
	fill(d, d + N + 2, INF);
	while (M--) {
		cin >> U >> V >> C;
		graph[V].push_back({ C,U });
	}
	while (K--) {
		cin >> tmp;
		d[tmp] = 0;
		pq.push({ d[tmp], tmp });
		interview.push_back(tmp);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (d[cur.second] != cur.first) continue;
		for (auto nxt : graph[cur.second]) {
			if (d[nxt.second] <= d[cur.second] + nxt.first) continue;
			d[nxt.second] = d[cur.second] + nxt.first;
			pq.push({ d[nxt.second], nxt.second });
		}
	}
	int answer = -1;
	for (int i = N; i > 0; i--) {
		if (d[answer] <= d[i]) answer = i;
	}
	cout << answer << "\n" << d[answer];
	return 0;
}