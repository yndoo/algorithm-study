#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int N;
priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> timetable;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num, s, e;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num >> s >> e;
		timetable.push_back({ s, e });
	}
	sort(timetable.begin(), timetable.end());
	pq.push(timetable[0].second);
	for (int i = 1; i < N; i++) {
		if (pq.top() <= timetable[i].first) {
			pq.pop();
			pq.push(timetable[i].second);
		}
		else {
			pq.push(timetable[i].second);
		}
	}
	cout << pq.size();
	return 0;
}