#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, now; 
	long long answer = 0;
	stack<int> s;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> now;
		while (!s.empty() && s.top() <= now) {
			s.pop();
		}
		answer += s.size();
		s.push(now);
	}

	cout << answer;
	return 0;
}