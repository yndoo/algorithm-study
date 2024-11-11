#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	int N = -1, turn = 3;
	while (turn--)
	{
		int sum = 0, goal = 0;
		std::cin >> N;
		std::vector<std::pair<int, int>> coins(N);
		std::vector<bool> data(50001, false);
		for (int i = 0; i < N; ++i)
		{
			std::cin >> coins[i].first >> coins[i].second;
			sum += coins[i].first * coins[i].second;
		}
		if (sum % 2 != 0)
		{
			std::cout << 0 << std::endl;
			continue;
		}
		goal = sum / 2;
		data[0] = true; // 0
		for (int i = 0; i < N; ++i)
		{
			int coin = coins[i].first;
			int cnt = coins[i].second;
			for (int j = goal; j >= 0; --j) 
			{
				if (data[j]) 
				{
					for (int k = 1; k <= cnt; ++k) 
					{
						int cur = j + k * coin;
						if (cur > goal) 
						{
							break;
						}
						data[cur] = true;
					}
				}
			}
		}
		if (data[goal])
		{
			std::cout << 1 << std::endl;
		}
		else
		{
			std::cout << 0 << std::endl;
		}
	}

	return 0;
}