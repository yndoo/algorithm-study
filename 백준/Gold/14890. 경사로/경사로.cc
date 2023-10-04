#include<bits/stdc++.h>
using namespace std;
int graph[100][100]; //전체 지도
bool stairs[100][100]; //경사로가 있는부분을 표시
bool isflat_row(int row, int start, int end) {	//start~end까지 평평한지 알려주는 함수
	//경사로 이미 있는지 확인
	for (int i = start; i <= end; i++) {
		if (stairs[row][i]) return false; //있으면 놓을 수 없음
	}
	//평평 확인
	for (int i = start; i < end; i++) {
		if (graph[row][i] != graph[row][i + 1]) return false;
	}
	return true;
}
bool isflat_col(int col, int start, int end) {	//start~end까지 평평한지 알려주는 함수
	//경사로 이미 있는지 확인
	for (int i = start; i <= end; i++) {
		if (stairs[i][col]) return false; //있으면 놓을 수 없음
	}
	//평평 확인
	for (int i = start; i < end; i++) {
		if (graph[i][col] != graph[i + 1][col]) return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, L;
	int answer = 0; //정답 - 길 개수
	cin >> N >> L; 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];			//지도 입력받기
		}
	}
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}*/
	//1. 가로 길 확인
	for (int row = 0; row < N; row++) {
		int cnt_row = 0;
		//1-1. 올라가는 경사로 확인
		for (int i = L; i < N; i++) {
			if (graph[row][i] == graph[row][i - 1] + 1) {
				if (isflat_row(row,i-L,i-1)) { //L 평평 유지 - 경사로 개수 추가
					for (int check = i - L; check <= i - 1; check++) {
						stairs[row][check] = true;
					}
					cnt_row++;
				}
			}
		}
		//1-2. 내려가는 경사로 확인
		for (int i = 0; i < N - L; i++) {
			if (graph[row][i] - 1 == graph[row][i+1]) {
				if (isflat_row(row, i + 1, i + L)) {
					for (int check = i + 1; check <= i + L; check++) {
						stairs[row][check] = true;
					}
					cnt_row++;
				}
			}
		}
		//1-3. 평평한 길 확인
		for (int flat = 0; flat < N-1; flat++) {
			if (graph[row][flat] == graph[row][flat + 1]) cnt_row++;
		}
		//cout << cnt_row<< " \n";
		if (cnt_row == N-1) answer++; //길건너기 가능하면 정답 1 추가
	}
	fill(&stairs[0][0], &stairs[99][99], false);
	//2. 세로 길 확인
	for (int col = 0; col < N; col++) {
		int cnt_col = 0;
		//2 - 1. 올라가는 경사로 확인
		for (int i = L; i < N; i++) {
			if (graph[i][col] == graph[i - 1][col] + 1) {
				if (isflat_col(col, i-L, i-1)) { //L길이만큼 같은 높이 유지됐을 경우 경사로 추가
					for (int check = i - L; check <= i - 1; check++) {
						stairs[check][col] = true;
					}
					cnt_col++;
				}
			}
		}
		//2-2. 내려가는 경사로 확인
		for (int i = 0; i < N - L; i++) {
			if (graph[i][col] - 1 == graph[i + 1][col]) {
				if (isflat_col(col, i + 1, i + L)) {
					for (int check = i + 1; check <= i + L; check++) {
						stairs[check][col] = true;
					}
					cnt_col++;
				}
			}
		}
		//2-3. 평평한 길 확인
		for (int flat = 0; flat < N - 1; flat++) {
			if (graph[flat][col] == graph[flat + 1][col]) cnt_col++;
		}
		//cout << cnt_col<< " \n";
		if (cnt_col == N-1) answer++; //평평하면 정답 1 추가
	}
	
	cout << answer;
	return 0;
}

/*
문제 : 가로 세로길을 지나갈 수 있는지? + 조건 만족하면 L길이의 경사로 놓고 지나갈 수 있음
각 길을 한 칸씩 지나갈 수 있는지 세어서 그 개수가 N개가 되면 answer++;

0.graph에 지도 입력받기

1. 가로 방향 확인하는 for문
1-1. 올라가는 경사로 방향 확인 → 두 계단사이 1만큼 증가한다면 isflat_row(row, start, end) 함수 돌리기 → 경사로를 둘 수 있으면 cnt_row++; stairs[][] = true;
** isflat_row 함수에서는 start부터 end까지가 평평한지 확인하며, 이미 그곳에 경사로가 놓아졌는지도 확인해줌. 모두 경사로를 새로 둘수있으며, 전부 평평하면 true반환. 
** stairs 배열은 경사로가 놓여지는 곳을 기록하는 배열.
1-2. 내려가는 경사로 확인 → 두 계단사이 1만큼 감소한다면 isflat_row(row, start, end) 함수 돌리기→ 경사로를 둘 수 있으면 cnt_row++; stairs[][] = true;
1-3. 경사로 없이 평평한 길 몇개있는지 확인, 있으면 cnt_row++;
1-4. cnt_row가 N-1개라면 길건너기 가능. answer++;
1-5. 세로 길 확인하기전에 이미 경사로가 있는지 확인하는 stairs배열을 초기화해야함.(가로와 세로 경사로가 따로이기 때문)

2. 세로 방향 for문
2-1. 올라가는 경사로  확인 → 두 계산사이 1증가하면 isflat_col(col, start, end) → 경사로 둘 수 있으면 cnt_col++; stairs[][] = true;
2-2. 내려가는 경사로 → 두 계산사이 1감소하면 isflat_col(col, start, end) → 경사로 둘 수 있으면 cnt_col++; stairs[][] = true;
2-3. 평평한 길 개수 cnt_col++;
2-4. cnt_col == N-1 라면 answer++;

3. cout<<answer;
*/
