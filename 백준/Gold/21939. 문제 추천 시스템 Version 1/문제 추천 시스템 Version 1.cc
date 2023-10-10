#include <iostream>
#include<queue>
#include <vector>
#include<string>
#include<algorithm>
#include<set>
using namespace std;
int N, M;
struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b) const{
		if (a.second == b.second) { //난이도가 같으면 번호 큰게 뒤로가야함
			return a.first < b.first;
		}
		return a.second < b.second;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int P, L;
	int num, p, l;
	string command;
	set<pair<int, int>, compare> s;
	set<int> trash;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P >> L;
		s.insert({ P, L }); //문제 번호, 난이도
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> command;
		if (command == "recommend") {
			cin >> num;
			if (num == 1) {
				while (!trash.empty() && (*--s.end()).first == *--trash.end()) {
					trash.erase(--trash.end());
					s.erase(--s.end());
				}
				cout << (*--s.end()).first << "\n";
			}
			else if (num == -1) {
				while (!trash.empty() && (*s.begin()).first == *trash.begin()) {
					trash.erase(trash.begin());
					s.erase(s.begin());
				}
				cout << (*s.begin()).first << "\n";
			}
		}
		else if (command == "add") {
			cin >> p >> l;
			s.insert({ p, l });
		}
		else if (command == "solved") {
			cin >> p;
			trash.insert(p);
		}

	}
	return 0;
}