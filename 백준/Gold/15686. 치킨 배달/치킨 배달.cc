#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<int> answer;
void calc(vector<int> lst) {
	int sum = 0;
	for (int i = 0; i < house.size(); i++) {
		int tmp = 1000000;
		for (auto v : lst) {
			tmp = min(tmp, abs(house[i].first - chicken[v].first) + abs(house[i].second - chicken[v].second));
		}
		sum += tmp;
	}
	answer.push_back(sum);
}
void pick(vector<int> lst) {
	if (lst.size() == M) {
		//거리 계산
		calc(lst); //선택된 치킨집을 매개변수로 넘김
	}
	else {
		for (int i = lst.back() + 1; i < chicken.size(); i++) {
			lst.push_back(i);
			pick(lst);
			lst.pop_back();
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	int num;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> num;
			if (num == 1) house.push_back({ i, j });
			else if (num == 2) chicken.push_back({ i,j });
		}
	}
	for (int i = 0; i < chicken.size(); i++) {
		vector<int> lst = { i };
		pick(lst); //치킨집 고르기
	}
	sort(answer.begin(), answer.end());
	cout << answer[0];
	return 0;
}