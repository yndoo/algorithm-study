#include <iostream>
#include <vector>
int main()
{
	int N = -1;
	std::cin >> N;
	std::vector<std::string> words(N);
	std::vector<std::string> answer(2);
	for (int i = 0; i < N; ++i)
	{
		std::cin >> words[i];
	}
	int curmax = -1;
	for (int i = 0; i < N; ++i)
	{
		std::string cur = words[i];
		int curN = cur.size();
		for (int j = i + 1; j < N; ++j)
		{
			int curcnt = 0, M = std::min(curN, static_cast<int>(words[j].size()));
			for (int k = 0; k < M; ++k)
			{
				if (cur[k] != words[j][k])
				{
					break;
				}
				++curcnt;
			}
			if (curcnt > curmax)
			{
				curmax = curcnt;
				answer[0] = cur;
				answer[1] = words[j];
			}
		}
	}
	std::cout << answer[0] << "\n" << answer[1];
	return 0;
}