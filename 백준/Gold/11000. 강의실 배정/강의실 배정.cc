#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
vector<pair<int, int>> timetable; //전체 수업 s, t를 저장해 둘 벡터
priority_queue<int, vector<int>, greater<int>> pq; //강의실 지정하는 우선순위 큐
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, s, t;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s >> t;
		timetable.push_back({ s, t });
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