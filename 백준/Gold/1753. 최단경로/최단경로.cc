#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;

int V, E, K , u, v, w;
vector<pair<int, int>> graph[20001];
int d[20001]; //최단 거리 테이블
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> V >> E >> K;
	fill(&d[0], &d[20001], INF);
	while (E--) {
		cin >> u >> v >> w;
		graph[u].push_back({ w,v }); 
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[K] = 0; //자기 자신은 0
	pq.push({ d[K], K }); //{0, 시작점}
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop(); //비용, 정점 번호
		if (d[cur.second] != cur.first) continue; // 거리가 d에 있는 값과 다를 경우 넘어감
		for (auto nxt : graph[cur.second]) { // nxt.second : cur에서 갈 수 있는 다른 정점
			if (d[nxt.second] <= d[cur.second] + nxt.first) continue;
			//cur를 거쳐가는 것이 더 작은 값을 가질 경우 갱신하고 pq에 추가
			d[nxt.second] = d[cur.second] + nxt.first;
			pq.push({ d[nxt.second], nxt.second });
		}
	}
	for (int i = 1; i <= V; i++) {
		if (d[i] == INF) cout << "INF\n";
		else cout << d[i] << "\n";
	}
	return 0;
}
