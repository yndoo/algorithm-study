#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N = -1, answer = 0;
	std::cin >> N;
	std::vector<std::vector<int>> time(N, std::vector<int>(2));
	std::vector<int> table(N, 1);
	for (int i = 0; i < N; ++i)
	{
		std::cin >> time[i][1] >> time[i][0]; // 끝시간, 시작시간 반대로 받음
	}
	sort(time.begin(), time.end());
	int cur = time[0][0]; // 가장 먼저 끝나는 회의
	answer = 1;
	for (int i = 1; i < N; ++i)
	{
		if (cur <= time[i][1])
		{
			++answer;
			cur = time[i][0];
		}
	}
	std::cout << answer;
	return 0;
}