#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int sensor[10000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, K, answer = 0;
	vector<int> googan;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> sensor[i];
	}
	sort(&sensor[0], &sensor[N]);
	for (int i = 1; i < N; i++) {
		googan.push_back(sensor[i] - sensor[i - 1]);
	}
	sort(googan.begin(), googan.end());
	for (int i = 0; i < (N - 1) - (K - 1); i++) {
		answer += googan[i];
	}
	cout << answer;
	return 0;
}