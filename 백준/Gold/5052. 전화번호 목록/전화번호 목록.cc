#include<bits/stdc++.h>
using namespace std;
int t, n;
string cur_numbers, tmpstr;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	//test case t회
	for (int turn = 0; turn < t; turn++) {
		bool answer_flag = true;
		map<string, int> m;		//전화번호부와 순서
		string numArr[10000];	//전체 전화번호부
		cin >> n;				//각 tc별 전화번호 수
		//1. 전화번호가 1~9자리면 map에 등록
		for (int nums = 0; nums < n; nums++) {
			cin >> cur_numbers;
			numArr[nums] = cur_numbers;
			m[cur_numbers] = nums; //전화번호부에 등록
		}

		//2. 전체 전화번호 돌면서 map에 해당하는 곳이 있는지 확인
		for (int i = 0; i < n; i++) {
			tmpstr = numArr[i];
			for (int tmpsize = 1; tmpsize < tmpstr.size()+1; tmpsize++) { //tmpstr의 문자열을 개수별로 검색
				if (m.find(tmpstr.substr(0, tmpsize)) != m.end() && i!=m[tmpstr.substr(0, tmpsize)]) {
					//존재하면 일관성이 없으므로 "NO"
					answer_flag = false;
				}
			}
		}
		if (answer_flag) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}

/*
- 문제 : 전화번호 목록에서 일관성이 있는지 없는지 판단, 이 문제에서 일관성이란 → 전화번호가 다른 전화번호의 접두어가 되면 안 됨.
- 전체 전화번호를 map 자료구조에 등록
- 전화번호를 tmpsize = 1~size까지 for문 돌며 tmpSize자릿수만큼이 map에 있는지 확인
- 본인 외에 확인되면 일광성 없으므로 “NO”
*/
