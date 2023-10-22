#include<iostream>
using namespace std;
int dp[201][201];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N >> K;
	for (int n = 0; n <= N; n++)
		dp[1][n] = 1;

	for (int k = 2; k <= K; k++) {
		for (int n = 0; n <= N; n++) {
			for (int j = 0; j <= n; j++) {
				dp[k][n] += dp[k - 1][j];
				dp[k][n] %= 1000000000;
			}
		}
	}

	cout << dp[K][N] % 1000000000;
}