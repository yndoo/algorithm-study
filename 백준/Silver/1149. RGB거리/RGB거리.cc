#include <iostream>
#include <vector>
int main()
{
	int N = -1;
	std::cin >> N;
	std::vector<std::vector<int>> rgb(N, std::vector<int>(3, 0));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cin >> rgb[i][j];
		}
	}
	for (int i = 1; i < N; ++i)
	{
		rgb[i][0] += std::min(rgb[i - 1][1], rgb[i - 1][2]);
		rgb[i][1] += std::min(rgb[i - 1][0], rgb[i - 1][2]);
		rgb[i][2] += std::min(rgb[i - 1][1], rgb[i - 1][0]);
	}

	std::cout << std::min(rgb[N - 1][0], std::min(rgb[N - 1][1], rgb[N - 1][2]));
	return 0;
}