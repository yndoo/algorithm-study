#include <iostream>
#include <vector>
#include <cmath>
int main()
{
	int N;
	std::vector<int> prime; // 소수
	std::cin >> N;
	// 소수 모아두기
	prime.push_back(2);
	for (int i = 2; i < 4000000; ++i)
	{
		bool flag = true;
		for (int j = 2; j < sqrt(i) + 1; ++j)
		{
			if (i % j == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag) prime.push_back(i);
	}
	// 소수 연속합 계산
	int st = 0, en = 0, sum = prime[0], answer = 0;
	int pSize = prime.size();
	while (true)
	{
		if (st >= pSize || en >= pSize || st > en) break;
		if (sum < N)
		{
			++en;
			if (en != pSize) sum += prime[en];
		}
		else if (sum > N)
		{
			sum -= prime[st];
			++st;
		}
		else if (sum == N)
		{
			++answer;
			++en;
			if (en != pSize) sum += prime[en];
		}
	}
	std::cout << answer;
	return 0;
}