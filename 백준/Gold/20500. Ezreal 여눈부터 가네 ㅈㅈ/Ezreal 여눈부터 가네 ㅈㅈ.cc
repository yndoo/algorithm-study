#include<iostream>
using namespace std;
int dp[1516][3]; //dp[i][j] => i자리 수 중에 15로 나눴을 때 나머지가 5^j(0,5,10)인 수의 개수
int N;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	//1, 5로 이루어진 한 자릿수 숫자 중에 15로 나눌 때 나머지가 0, 5, 10인 수의 개수 : 0, 1, 0
	dp[1][1] = 1;

	for (int i = 2; i < N + 1; i++) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % 1000000007;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 1000000007;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 1000000007;
	}
	cout << dp[N][0];
	return 0;
}