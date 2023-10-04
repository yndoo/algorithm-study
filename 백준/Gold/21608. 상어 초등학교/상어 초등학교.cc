#include<bits/stdc++.h>
using namespace std;
int N, num, answer = 0;
int classroom[20][20]; //자리 표
int likes[401][4]; //좋아하는 학생 배열 likes[학생번호-1][4]
int likedArr[20][20];	//주위 좋아하는 학생 수 세는 배열
int blanks[20][20];		//주위 빈칸 수 세는 배열
int dx[4] = { -1, 0, 1, 0 }; //상 좌 우 하
int dy[4] = { 0, -1, 0, 1 };

int mypow(int a, int b) { //int제곱 계산하는 함수
	int ans = 1;
	for (int i = 0; i < b; i++) {
		ans *= a;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	//1. 학생 번호와 좋아하는 학생 4명을 입력받으며 진행
	for (int student = 0; student < N * N; student++) {
		fill(&likedArr[0][0], &likedArr[19][20], 0);
		fill(&blanks[0][0], &blanks[19][20], 0);
		queue<pair<int, int>> q;//likes겹치는 애들 담아둘 큐
		int likesMax = -1;
		int blankMax = -1;
		cin >> num;
		num--;
		cin >> likes[num][0] >> likes[num][1] >> likes[num][2] >> likes[num][3];
		//classroom 빈칸 돌며 주위에 likes가 많은 자리 찾기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				//빈자리라면
				if (classroom[i][j] == 0) {

					//주위에 좋아하는 학생 수와 빈칸 수 세기
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						//likes에 해당하는게 있으면 likedArr++
						if (classroom[nx][ny] == likes[num][0] || classroom[nx][ny] == likes[num][1] || classroom[nx][ny] == likes[num][2] || classroom[nx][ny] == likes[num][3]) {
							likedArr[i][j]++;
						}
						if (classroom[nx][ny] == 0) blanks[i][j]++;
					}
					//주위 likes값이 많은 곳이 여러 곳이라면 그 중 빈칸 많은 곳을 찾아야 함
					//만약 max값보다 작으면 max값 대체, max값 같다면 담아두기(?)

					if (likesMax < likedArr[i][j]) {
						while (!q.empty()) q.pop(); //max값 갱신할땐 큐도 초기화
						likesMax = likedArr[i][j];
						q.push({ i,j });
					}
					else if (likesMax == likedArr[i][j]) {
						q.push({ i,j }); //like수 같은곳 있으면 큐에 담아두기
					}


				}//if 빈자리라면

			} //for - j
		}//for - i
		int ansX = 0, ansY = 0;
		while (!q.empty()) {
			//like수 같은애들중에 빈칸 많은 곳 찾기
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (blanks[x][y] > blankMax) {
				//빈칸 max 갱신할때가 자동으로 r,c 작은 최댓값자리(queue니까)
				blankMax = blanks[x][y];
				ansX = x;
				ansY = y;
			}
			else if (blanks[x][y] == blankMax) {
				if (ansX == x && ansY > y) {
					ansY = y;
				}
				else if (ansX > x) {
					ansX = x;
					ansY = y;
				}
			}
		}
		classroom[ansX][ansY] = num + 1; //자리에 앉히기
	}//for - student (1.)

	//2. 전체 classroom 돌면서 겹치는 likes개수 세서 만족도 계산

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int cnt = 0;
			int cur = classroom[i][j] - 1;
			for (int k = 0; k < 4; k++) {
				int nx2 = i + dx[k];
				int ny2 = j + dy[k];
				if (nx2 < 0 || nx2 >= N || ny2 < 0 || ny2 >= N) continue;
				//likes개수세기
				if (classroom[nx2][ny2] == likes[cur][0] || classroom[nx2][ny2] == likes[cur][1] || classroom[nx2][ny2] == likes[cur][2] || classroom[nx2][ny2] == likes[cur][3]) {
					cnt++;
				}
			}
			if (cnt > 0) answer += mypow(10, cnt - 1);
		}
	}
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << classroom[i][j] << " ";
		}
		cout << "\n";
	}*/
	cout << answer;
	return 0;
}

/*
문제 : 
학생들 자리에 앉히고 만족도 계산하기.
자리 앉히는 조건 :
1. 주변에 좋아하는 학생이 가장 많고
2. 1번이 여러곳이라면 그 중에 인접빈칸이 가장 많고
3. 2번도 여러곳라면 그중 row가 작거나, row도 같으면 col이 작은 곳

내 풀이 로직:
1. N*N명의 학생과 좋아하는 학생(4명) 정보를 입력받음. 
학생:num - num학생이 좋아하는 애들 - likes

1-1. classroom의 빈칸마다 인접 좋아하는 학생 수는 likedArr 배열에, 인접 빈칸 수는 blanks 배열에 세어두기
1-2. 해당 빈칸의 likedArr[i][j]가 현재 likesMax(인접 좋아하는 학생 수 여태까지의 최댓값)와 같으면 queue에 좌표를 push, or 
likedArr[i][j]가 현재 likesMax 보다 크면 queue를 초기화하고 그 빈칸의 좌표를 저장.
1-3. queue(likedArr최댓값인 자리들)을 돌며 해당 좌표의 blanks[x][y]값이 blankMax보다 크면 그때의 x, y값이 앉힐 자리!! → 앉히기.

2. 전체 classsroom을 다시 돌며 겹치는 likes개수 세서 만족도 계산.

어려움 겪은 곳 :
fill 함수 사용법을 틀리게 알고있었다. 배열의 범위를 잘못 설정해서 맞왜틀 엄청 오래 했다.!
*/
