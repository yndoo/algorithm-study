#include <iostream>
#include <vector>
int main()
{
	int T = -1, n = -1;
	std::cin >> T;
	while (T--)
	{
		std::cin >> n;
		std::vector<int> dp(300);
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for (int i = 4; i <= n; ++i)
		{
			dp[i] += dp[i - 1];
			dp[i] += dp[i - 2];
			dp[i] += dp[i - 3];
		}
		std::cout << dp[n] << std::endl;
	}
	return 0;
}