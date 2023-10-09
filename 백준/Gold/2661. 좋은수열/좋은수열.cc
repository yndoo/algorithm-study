#include<iostream>
#include<string>
using namespace std;
int N;
string answer;
bool flag = false;
bool check(string numstr) { //인접한 동일 부분 수열이 있는지 체크하는 함수
	for (int i = 0; i < numstr.size(); i++) {
		for (int j = 1; j < numstr.size() - i; j++) {
			// numstr의 i번째에서 j개 자른 부분수열이 i+j 뒷쪽에 또 있으면 안 됨
			if (numstr.substr(i+j, j).find(numstr.substr(i, j)) != string::npos) {
				return false;
			}
			
		}
	}
		return true;
}
void number(string num, int cnt) { //N 자릿수의 최소 좋은 수열을 만들어가는 함수
	if (check(num) && !flag) {
		if (cnt == N) {
			flag = true;
			answer = num; //최소 숫자가 가장 먼저 들어오기 때문에 flag로 한 번만 갱신
			return;
		}
		else {
			//마지막 숫자와 안 겹치는 가장 작은 수 넣어 재귀
			for (int i = 1; i <= 3; i++) {
				if (i != num[0]) number(num + to_string(i), cnt + 1);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	number("1", 1);
	cout << answer;
	return 0;
}