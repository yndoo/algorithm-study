#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>> maxPQ; //{난이도, 문제 번호} first가 같으면 second도 큰 순으로
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minPQ; //first가 같으면 second도 작은 순
priority_queue<int, vector<int>> maxTrash;
priority_queue<int, vector<int>, greater<int>> minTrash;
int N, M, P, L;
string command;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P >> L;
		maxPQ.push({ L, P });
		minPQ.push({ L, P });
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> command;
		if (command == "add") {
			cin >> P >> L;
			maxPQ.push({ L, P });
			minPQ.push({ L, P });
		}
		else if (command == "recommend") {
			int num;
			cin >> num;
			if (num == 1) { //가장 어려운 문제 추천
				while (!maxTrash.empty() && maxTrash.top() == maxPQ.top().second) {
					maxTrash.pop();
					maxPQ.pop();
				}
				cout << maxPQ.top().second << "\n";
			}
			else if (num == -1) { //가장 쉬운 문제 추천
				while (!minTrash.empty() && minTrash.top() == minPQ.top().second) {
					minTrash.pop();
					minPQ.pop();
				}
				cout << minPQ.top().second << "\n";
			}
		}
		else if (command == "solved") {
			cin >> P;
			maxTrash.push(P);
			minTrash.push(P);
		}
	}
	return 0;
}