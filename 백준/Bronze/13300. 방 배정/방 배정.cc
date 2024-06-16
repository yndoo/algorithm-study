#include <iostream>
#include <vector>

int main()
{
	std::vector<std::vector<int>> students;
	students.resize(6);
	for (int i = 0; i < 6; i++) // 학년
	{
		for (int j = 0; j <= 1; j++) // 성별 0여, 1남
		{
			students[i].push_back(0);
		}
	}
	int N = 0, K = 0, S = 0, Y = 0, result = 0;
	std::cin >> N >> K;

	while (N)
	{
		--N;
		std::cin >> S >> Y;
		++students[Y - 1][S];
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j <= 1; j++)
		{
			result += students[i][j] / K;
			if (students[i][j] % K != 0)
			{
				++result;
			}
		}
	}
	std::cout << result;
	return 0;
}