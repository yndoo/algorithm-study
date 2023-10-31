#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, K, answer = 0, zeroCnt = 0;
bool visited[201];	//로봇 있는곳 체크
int move(int i) {	//뒷칸 계산(벨트 이동) <- 방향
	i--;
	if (i == 0) i = 2 * N;
	return i;
}
int next(int i) {	//벨트 고정, 로봇 이동 다음 칸 계산 -> 방향
	i++;
	if (i == 2 * N + 1) i = 1;
	return i;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	vector<int> belt(2 * N + 1);		//1~2N칸 벨트의 내구도 정보
	queue<int> robots;		//로봇 정보
	for (int i = 1; i <= 2 * N; i++)
		cin >> belt[i];
	int s, e; //각각 올리는 위치, 내리는 위치
	s = 1; e = N;
	while (true) {
		//zeroCnt = 0;
		answer++;
		//벨트 한칸이동
		s = move(s);
		e = move(e);
		int num = robots.size();
		while (num--) { 
			
			int cur = robots.front(); robots.pop();
			if (cur == e) { visited[cur] = false; continue; } //이미 내리는 위치인 것 내리기
			else if (belt[next(cur)] > 0 && !visited[next(cur)]) { //이동 가능하면 추가 이동
				visited[cur] = false;			//현재 위치 로봇 없애주고
				cur = next(cur);				//이동
				if (belt[cur] == 1) zeroCnt++;
				belt[cur]--;					//이동한 곳 내구도 감소
				if (cur == e) continue;			//이동한 게 내리는 위치면 추가하지 않고 내리기 (로봇 바로 내리기)
				
				robots.push(cur);				//새로운 로봇 위치로 추가
				visited[cur] = true;			//위치 저장
			}
			else { //이동 불가능하면 원래 위치 그대로 다시 넣음
				robots.push(cur);
			}
		}
		//올리는 위치에 로봇 올리기
		if (belt[s] > 0) {
			if (belt[s] == 1) zeroCnt++;
			robots.push(s);
			visited[s] = true;
			belt[s]--;
		}
		/* test 
		cout << answer << " : ";
		for (int i = 1; i <= 2 * N; i++)
			cout << belt[i] << " ";
		cout << "\n";
		*/

		//내구도 0인 칸 개수 K개 이상이면 종료
		/*for (int i = 1; i <= 2 * N; i++) {
			if (belt[i] == 0)zeroCnt++;
		}*/
		if (zeroCnt >= K) break;
	}
	cout << answer;
	return 0;
}