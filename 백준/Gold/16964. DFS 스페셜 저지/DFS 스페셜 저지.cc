#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int N;
bool check[100001];
int order[100001];
bool comp(int& a, int& b) {
	return order[a] > order[b];
}
bool dfs(vector<vector<int>> v) {
	int cnt = 1;
	stack<int> mystack;
	mystack.push(1);
	while (!mystack.empty()) {
		int x = mystack.top(); mystack.pop();
		if (check[x] == true) continue;
		check[x] = true;
		if (order[x] != cnt) return false;
		for (int y : v[x]) {
			if (!check[y]) mystack.push(y);
		}
		cnt++;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int s, e, target;
	cin >> N;
	vector<vector<int>> graph(N+1);
	for (int i = 0; i < N-1; i++) {
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	for (int i = 1; i <= N; i++) {
		cin >> target;
		order[target] = i; //순서 저장
	}
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end(), comp);
	}

	if (dfs(graph)) cout << 1;
	else cout << 0;

	return 0;
}