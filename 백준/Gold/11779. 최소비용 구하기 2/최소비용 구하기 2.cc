#include<iostream>
#include<queue>
#include<vector>
#define INF 1e9
using namespace std;
int n, m, s, e, c;
int d[1001];
int pre[1001];
vector<pair<int, int>> graph[1001]; //cost, end
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> answer;
void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> s >> e >> c;
		graph[s].push_back({ c,e });
	}
	fill(&d[0], &d[1001], INF);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	int start, end;
	cin >> start >> end;
	d[start] = 0;
	pq.push({ d[start], start });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (d[cur.second] != cur.first) continue;
		for (auto nxt : graph[cur.second]) {
			if (d[nxt.second] <= d[cur.second] + nxt.first) continue;
			d[nxt.second] = d[cur.second] + nxt.first;
			pq.push({ d[nxt.second], nxt.second });
			pre[nxt.second] = cur.second;
		}
	}
	cout << d[end] << "\n";
	while (true) {
		answer.push_back(end);
		if (end == start) break;
		end = pre[end];
	}
	cout << answer.size() << "\n";
	for (auto it = answer.rbegin(); it < answer.rend(); it++) {
		cout << *it << " ";
	}
	return 0;
}