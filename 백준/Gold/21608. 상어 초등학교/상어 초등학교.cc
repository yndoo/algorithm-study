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