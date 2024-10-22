#include <iostream>
#include <vector>
int main()
{
	int N = -1;
	std::vector<std::vector<int>> cage; // N행, 행마다 (0마리, 왼쪽1, 오른쪽1)
	std::cin >> N;
	cage.resize(N + 1);
	for (int i = 0; i <= N; ++i)
	{
		cage[i].resize(3);
	}
	cage[1][0] = 1;
	cage[1][1] = 1;
	cage[1][2] = 1;
	for (int i = 2; i <= N; ++i)
	{
		cage[i][0] = (cage[i - 1][0] + cage[i - 1][1] + cage[i - 1][2]) % 9901;
		cage[i][1] = (cage[i - 1][0] + cage[i - 1][2]) % 9901;
		cage[i][2] = (cage[i - 1][0] + cage[i - 1][1]) % 9901;
	}
	std::cout << (cage[N][0] + cage[N][1] + cage[N][2]) % 9901;
	return 0;
}