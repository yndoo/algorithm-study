#include <iostream>
#include <vector>
#include <string>
#define MOD 1000000

int main()
{
	std::string code;
	std::cin >> code;
	int N = code.size();
	std::vector<int> cases(N + 1);
	std::vector<int> num(N + 1);

	for (int i = 1; i <= N; ++i)
	{
		num[i] = code[i - 1] - '0';
	}
	cases[0] = 1;
	for (int i = 1; i <= N; ++i)
	{
		if (num[i] > 0)
		{
			cases[i] = (cases[i - 1] + cases[i]) % MOD;
		}
		int tmp = num[i - 1] * 10 + num[i];
		if (tmp >= 10 && tmp <= 26)
		{
			cases[i] = (cases[i - 2] + cases[i]) % MOD;
		}
	}
	std::cout << cases[N];
	return 0;
}