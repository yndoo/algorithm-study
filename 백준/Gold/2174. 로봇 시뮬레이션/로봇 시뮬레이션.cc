#include<iostream>
#include<string>
#include<vector>
using namespace std;
int dx[4] = { -1, 0, 1, 0 }; // 북동남서(+1방향이 시계방향)
int dy[4] = { 0, 1, 0, -1 };
int A, B, N, M; //가로, 세로, 로봇 수, 명령 수
int graph[101][101]; //로봇 위치 저장 1~100
int direction[101][101]; //로봇 방향 저장
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<pair<int, int>> robots; //로봇 번호별 위치 저장하기
	robots.push_back({ 0,0 }); //0번 로봇은 없으므로 아무거나 넣어두기.

	cin >> A >> B;
	cin >> N >> M;
	
	for (int n = 0; n < N; n++) {
		int x, y;
		string dir;
		cin >> y >> x >> dir; //문제와 배열 x, y축이 반대이기 때문에 반대로 받음 : y가 가로, x가 세로
		x = B - x + 1;
		graph[x][y] = n + 1;
		robots.push_back({ x, y });
		if (dir == "N") direction[x][y] = 0; 
		else if (dir == "E") direction[x][y] = 1;
		else if (dir == "S") direction[x][y] = 2; 
		else if (dir == "W") direction[x][y] = 3;
	}
	for (int m = 0; m < M; m++) {
		int x, y, robot, cnt;
		string command;
		cin >> robot >> command >> cnt; //robot번 로봇에 command를  cnt회 실행
		x = robots[robot].first;
		y = robots[robot].second;
		if (command == "L") { //왼쪽으로 회전 
			//cout << "이전 : " << direction[x][y] << "\n";
			direction[x][y] = (direction[x][y] + cnt * 3) % 4;
			//cout << "이후 : " << direction[x][y] << "\n";
		}
		else if (command == "R") {
			//cout << "이전 : " << direction[x][y] << "\n";
			direction[x][y] = (direction[x][y] + cnt) % 4;
			//cout << "이후 : " << direction[x][y] << "\n";
		}
		else if (command == "F") {
			int dirr = direction[x][y];
			for (int i = 0; i < cnt; i++) {
				int nx = x + dx[dirr];
				int ny = y + dy[dirr];
				if (nx <= 0 || nx > B || ny <= 0 || ny > A) {
					cout << "Robot " << robot << " crashes into the wall";
					return 0;
				}
				if (graph[nx][ny] == 0) { //이동할 칸이 비어있다면 로봇 위치 옮기기
					graph[x][y] = 0;
					graph[nx][ny] = robot; 
					direction[nx][ny] = direction[x][y]; //이전 칸 방향 초기화할 필요는 없음
					x = nx;
					y = ny;
					robots[robot].first = nx; 
					robots[robot].second = ny;
				}
				else if(graph[nx][ny] != 0){
					cout << "Robot " << robot << " crashes into robot " << graph[nx][ny];
					return 0;
				}	
			}
		}//F
		//test
		/*cout << "======\n";
		for (int k = 1; k <= B; k++) {
			for (int l = 1; l <= A; l++) {
				cout << graph[k][l] << " ";
			}
			cout << "\n";
		}
		cout << "======\n";
		for (int i = 1; i <= N; i++) {
			cout << robots[i].first << " " << robots[i].second << " \n";
		}*/
	} //for - m
	cout << "OK";
	return 0;
}