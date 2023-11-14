#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9
using namespace std;
int N, E, a, b, c, v1, v2;
vector<pair<int, int>> graph[801];
long long d[801];
long long move(int start, int end) { //start에서 end까지 최단 거리로 이동
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	fill(&d[0], &d[801], INF);
	d[start] = 0;
	pq.push({ d[start], start });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (d[cur.second] != cur.first) continue; //거리가 d에 있는 값과 다르면 넘어감
		for (auto nxt : graph[cur.second]) {
			//cur를 거쳐 nxt에 가는게 더 멀면 갱신하지 않고 넘어감 
			if (d[nxt.second] <= d[cur.second] + nxt.first) continue; 
			d[nxt.second] = d[cur.second] + nxt.first;
			pq.push({ d[nxt.second],nxt.second });
		}
	}
	return d[end];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> E;
	while (E--) {
		cin >> a >> b >> c;
		graph[a].push_back({ c,b });
		graph[b].push_back({ c,a });
	}
	cin >> v1 >> v2;
	long long sum1 = move(1, v1) + move(v1, v2) + move(v2, N);
	long long sum2 = move(1, v2) + move(v2, v1) + move(v1, N);
	long long answer = min(sum1, sum2);
	if (answer >= INF) cout << -1;
	else cout << answer;
	return 0;
}