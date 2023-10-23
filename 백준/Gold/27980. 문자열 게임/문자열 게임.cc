#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int N, M;
string board;
string mystr;
int dp[5000][5000]; //dp[M][N]? M회만큼 꼭 돈다.
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	cin >> board;
	cin >> mystr;
	for (int n = 0; n < N; n++)
		if (board[n] == mystr[0]) dp[0][n]++;
	for (int m = 1; m < M; m++) {
		for (int n = 0; n < N; n++) {
			if (n == 0) dp[m][n] = dp[m - 1][n + 1];
			else if (n == N - 1) dp[m][n] = dp[m - 1][n - 1];
			else dp[m][n] = max(dp[m - 1][n - 1], dp[m - 1][n + 1]);
			if (board[n] == mystr[m]) dp[m][n]++;
		}
	}
	cout << *max_element(dp[M - 1], dp[M - 1] + N);
	return 0;
}

/*
* 다돌면 시간초과남
* 
#include<iostream>
#include<string>
using namespace std;
int N, M;
string board;
string mystr;
int answer = -1;
void playing(int boardNum, int mystrNum, int score) {
	if (board[boardNum] == mystr[mystrNum]) score++;
	if (mystrNum + 1 == M) {
		if (answer < score) answer = score;
		return;
	}
	if (boardNum + 1 < N)playing(boardNum + 1, mystrNum + 1, score);
	if (boardNum - 1 >= 0)playing(boardNum - 1, mystrNum + 1, score);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	cin >> board;
	cin >> mystr;

	for (int i = 0; i < N; i++) {
		playing(i, 0, 0);
	}
	cout << answer;
	return 0;
}
*/