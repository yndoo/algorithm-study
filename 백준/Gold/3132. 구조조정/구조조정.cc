#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int iq[1001];

bool comp(int a, int b) {
	return iq[a] > iq[b];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<vector<int>> v(N + 1);
	
	for (int i = 1; i <= N; i++)
		cin >> iq[i];
	for (int i = 1; i < N; i++) {
		int m, e;
		cin >> m >> e;
		v[m].push_back(e);
	}
	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end(), comp);
		for (int j = 1; j < v[i].size(); j++) {
			cout << v[i][j - 1] << " " << v[i][j] << "\n";
		}
		if (v[i].size() > 0) cout << i << " " << v[i][0] << "\n";
	}
	return 0;
}