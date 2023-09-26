#include<bits/stdc++.h>
using namespace std;
int answer=0; //답이되는 최초 년 수
int N, M;
int graph[300][300];
int tmp[300][300];
int visited[300][300];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void melting() {	//동서남북 방향 바다있는만큼 녹이기
	copy(&graph[0][0], &graph[299][299], &tmp[0][0]);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//한칸씩 보기
			//각 칸의 네방향
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				if (tmp[nx][ny] == 0 && graph[i][j]>0) { graph[i][j]--; }
			}
		}
	}
}

bool mycount(int x, int y) {	//덩어리 개수 세기, 빙산이 없는지?
	if (graph[x][y] != 0 &&  visited[x][y] == false) {
		visited[x][y] = true;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (graph[nx][ny] != 0 && visited[nx][ny] == false) {
				mycount(nx, ny);
			}
		}
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}
	while (true) {
		int cnt = 0; //덩어리 개수
		fill(&visited[0][0], &visited[299][299], false);//visited 초기화
		//덩어리 개수 세기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (mycount(i, j)) { 
					//cout <<answer<<" 년, " << i << " " << j << " 덩어리\n";
					cnt++;
				}
			}
		}
		if (cnt >= 2) {
			cout << answer;
			break;
		}
		else if (cnt == 0) { //빙산이 다 녹을 때까지 분리되지 않는 경우
			cout << 0;
			break;
		}
		else {
			answer++;
		}
		//녹이기
		melting();
	}
	return 0;
}