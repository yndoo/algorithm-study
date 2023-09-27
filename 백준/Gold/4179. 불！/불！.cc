#include<bits/stdc++.h>
using namespace std;
int R, C;
string graph[1000][1000];
int fireVisited[1000][1000];
int personVisited[1000][1000];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string line, tmp;
	queue<pair<int, int>> fireQ;
	queue<pair<int, int>> personQ;
	fill(&fireVisited[0][0], &fireVisited[999][999], -1);
	fill(&personVisited[0][0], &personVisited[999][999], -1);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> line;
		for(int j = 0; j < C; j++){
			tmp = line.substr(j, 1);
			graph[i][j] = tmp;
			if (tmp == "F") {
				//불 큐에 넣기
				fireQ.push({ i,j });
				fireVisited[i][j] = 0;
			}
			if (tmp == "J") {
				//지훈이 큐에 넣기
				personQ.push({ i,j });
				personVisited[i][j] = 0;
			}
		}
	}
	//불 번지는 시간 저장해두는 BFS
	int x, y, nx, ny, firetime=0;
	while (!fireQ.empty()) {
		for (int f = 0; f < fireQ.size(); f++) { //불 여러개임을 감안
			x = fireQ.front().first;
			y = fireQ.front().second;
			fireQ.pop();
			for (int i = 0; i < 4; i++) {
				nx = x + dx[i];
				ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
				if (graph[nx][ny] != "#" && fireVisited[nx][ny] < 0) {
					fireVisited[nx][ny] = fireVisited[x][y] + 1;
					fireQ.push({ nx, ny });
				}
			}
		}
	}
	//지훈이가 불을 피해 탈출하는 BFS
	while (!personQ.empty()) {
		x = personQ.front().first;
		y = personQ.front().second;
		personQ.pop();
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C) {
				//지훈 범위 벗어난 것은 탈출 성공임
				cout << personVisited[x][y] + 1;
				return 0;
			}
			if (graph[nx][ny] != "#" && (fireVisited[nx][ny] == -1 || fireVisited[nx][ny] > personVisited[x][y]+1) && personVisited[nx][ny] < 0) {
				personVisited[nx][ny] = personVisited[x][y] + 1;
				personQ.push({ nx, ny });
			}
		}
	}

	cout << "IMPOSSIBLE"; //여기까지 도달하면 탈출 실패

	//for (int i = 0; i < R; i++) {
	//	for (int j = 0; j < C; j++) {
	//		cout << fireVisited[i][j];
	//	}
	//	cout << "\n";
	//}
	//for (int i = 0; i < R; i++) {
	//	for (int j = 0; j < C; j++) {
	//		cout << personVisited[i][j];
	//	}
	//	cout << "\n";
	//}
	return 0;
}