#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define INF 1e9
typedef long long ll;

int N, M, st, en, co, A, B;
vector<pair<ll, int>> graph[1001];
ll d[1001];

void input() {
	cin >> N >> M;
	while(M--) {
		cin >> st >> en >> co;
		graph[st].push_back({ co, en });
	}
	cin >> A >> B;
}
void dijkstra() {
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	fill(d, d + N + 2, INF);
	d[A] = 0;
	pq.push({ d[A], A });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (cur.first != d[cur.second]) continue;
		for (auto nxt : graph[cur.second]) {
			if (d[nxt.second] <= d[cur.second] + nxt.first) continue;
			d[nxt.second] = d[cur.second] + nxt.first;
			pq.push({ d[nxt.second],nxt.second });
		}
	}
	cout << d[B];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	dijkstra();
	return 0;
}