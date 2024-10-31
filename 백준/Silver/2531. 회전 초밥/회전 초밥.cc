#include <vector>
#include <iostream>
#include <map>
int main()
{
	std::vector<int> belt;
	int N, d, k, c;
	std::cin >> N >> d >> k >> c;
	belt.resize(N);
	for (int i = 0; i < N; ++i)
	{
		std::cin >> belt[i];
	}
	for (int i = N; i < N + k; ++i)
	{
		belt.push_back(belt[i - N]); // 회전벨트에서 가능한 모든 경우의 수 찾기 위해 덧붙여둠
	}

	std::map<int, int> event; // 행사 참여 초밥
	int en = 0, curmax = -1, curcnt = 0, curcoupon = 0 /*쿠폰 무료 초밥이 k개 안에 몇개 포함되어있는지*/;
	for (int st = 0; st < N + k; ++st)
	{
		while (en - st + 1 <= k && en < N + k)
		{
			++event[belt[en]];
			if (event[belt[en]] == 1) // 새로운 종류 추가
			{
				if (belt[en] == c) // 쿠폰 초밥인가
				{
					++curcoupon;
				}
				++curcnt;
			}
			if (curcoupon == 0) curmax = std::max(curmax, curcnt + 1);
			else curmax = std::max(curmax, curcnt);
			++en;
		}
		if (event[belt[st]]-- == 1)
		{
			if (belt[st] == c)
			{
				--curcoupon;
			}
			--curcnt;
		}
	}

	std::cout << curmax;
	return 0;
}