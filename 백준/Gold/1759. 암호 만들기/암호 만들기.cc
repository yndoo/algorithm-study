#include<bits/stdc++.h>
using namespace std;

int L, C;
string arr[15];

void codes(vector<string> lst) {
	if (lst.size() == L) {
		//모음 최소 1개, 자음 최소 2개인지 확인
		int cnt1 = 0, cnt2 = 0; //각각 모음, 자음
		for (auto s : lst) {
			if (s == "a" || s == "e" || s == "i" || s == "o" || s == "u") cnt1++;
			else cnt2++;
		}
		if (cnt1 >= 1 && cnt2 >= 2) {
			//lst출력, 끝
			for (auto s : lst) {
				cout << s;
			}
			cout << '\n';
		}
		
		return;
	}
	for (int i = 0; i < C; i++) {
		if (!lst.empty() && arr[i] > lst.back()) {
			lst.push_back(arr[i]);
			codes(lst);
			lst.pop_back();
		}
		else if (lst.empty()) {
			lst.push_back(arr[i]);
			codes(lst);
			lst.pop_back();
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + C);
	vector<string> lst;
	codes(lst);

	return 0;
}