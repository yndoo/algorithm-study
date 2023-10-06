#include<bits/stdc++.h>
using namespace std;
bool numbers[10]; //0 ~ 9까지의 숫자 버튼

bool useButton(int channel) { //channel 채널이 버튼으로 모두 입력 가능한지 체크하는 함수
	//channel의 자릿수마다 확인
	int target;
	if (channel == 0) return numbers[0];
	while (channel > 0) {
		target = channel % 10;
		channel /= 10;
		if (!numbers[target]) return false;
	}
	return true;
}

int intSize(int num) { //num 숫자의 자릿수 세는 함수
	int cnt = 0;
	if (num == 0) return 1;
	while (num > 0) {
		num /= 10;
		cnt++;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M, tmp;
	fill(numbers, numbers + 10, true);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		numbers[tmp] = false;
	}
	int min_answer = abs(N - 100); //정답이 될 변수, +, - 버튼으로만 갈 수 있는 최소 넣어두기
	//N보다 큰 수 중에 가장 가까운 수를 버튼으로 누르는 시작
	for (int up = N; up < 1000000; up++) {
		if (useButton(up)) min_answer = min(min_answer, intSize(up) + up - N);
	}
	//N보다 작은 수 중에 가장 가까운 수를 버튼으로 누르는 시작
	for (int down = N - 1; down >= 0; down--) {
		if (useButton(down)) min_answer = min(min_answer, intSize(down) + N - down);
	}

	cout << min_answer;
	return 0;
}