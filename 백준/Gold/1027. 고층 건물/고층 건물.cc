#include <iostream>
#include <vector>
#include <cfloat>

int main()
{
	int N = -1, answer = -1;
	std::cin >> N;
	std::vector<int> building(N + 1, -1);
	for (int i = 0; i < N; ++i)
	{
		std::cin >> building[i + 1];
	}

	for (int i = 1; i <= N; ++i) // 각 빌딩에서 좌우로 보이는 빌딩 세기
	{
		double RightMax = -DBL_MAX;
		double LeftMax = DBL_MAX;
		int cnt = 0;
		for (int right = i + 1; right <= N; ++right)
		{
			double d = static_cast<double>(building[right] - building[i]) / (right - i);
			if (RightMax < d) // 더 높은 기울기의 빌딩들만 보임
			{
				RightMax = d;
				++cnt;
			}
		}
		for (int left = i - 1; left >= 1; --left)
		{
			double d = static_cast<double>(building[left] - building[i]) / (left - i);
			if (LeftMax > d) // 더 낮은 기울기의 빌딩들만 보임
			{
				LeftMax = d;
				++cnt;
			}
		}

		answer = std::max(answer, cnt);
	}
	std::cout << answer;
	return 0;
}