#include<iostream>
#include<queue>
#include<string>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, K;
	string com;
	long num;
	cin >> T;
	while (T-- > 0) {
		cin >> K;
		priority_queue<long, vector<long>, greater<long>> maxQ; // top이 최솟값이 됨
		priority_queue<long, vector<long>, greater<long>> minQ;
		priority_queue<long, vector<long>, greater<long>> maxTrash;
		priority_queue<long, vector<long>, greater<long>> minTrash;
		while (K-- > 0) {
			cin >> com >> num;
			if (com == "I") {
				maxQ.push((-1) * num);
				minQ.push(num);
			}
			else if (com == "D" && !maxQ.empty() && !minQ.empty()) {
				if (num == 1) { //최댓값 삭제
					minTrash.push(-maxQ.top());
					maxQ.pop();
				}
				else if (num == -1) {
					maxTrash.push(-minQ.top());
					minQ.pop();
				}
			}
			while (!minQ.empty() && !minTrash.empty() && minQ.top() == minTrash.top()) { minQ.pop(); minTrash.pop(); }
			while (!maxQ.empty() && !maxTrash.empty() && maxQ.top() == maxTrash.top()) { maxQ.pop(); maxTrash.pop(); }
		}
		if (!maxQ.empty() && !minQ.empty()) cout << (-1) * maxQ.top() << " " << minQ.top() << "\n";
		else if (maxQ.empty() && minQ.empty()) cout << "EMPTY\n";
	}
		
	return 0;
}