#include <iostream>
#include <vector>
#include <algorithm>

int Count = 1;

void CalcScores(int _N)
{
	std::vector<int> Scores;
	Scores.resize(_N);
	// 입력
	for (int i = 0; i < _N; ++i)
	{
		std::cin >> Scores[i];
	}

	// 정렬
	std::sort(Scores.begin(), Scores.end(), std::greater<int>());

	// 값 계산 
	int SMax = Scores[0];
	int SMin = Scores[_N - 1];
	int Lgap = -1;
	for (int i = 0; i < _N - 1; ++i)
	{
		if (Lgap < Scores[i] - Scores[i + 1])
		{
			Lgap = Scores[i] - Scores[i + 1];
		}
	}

	// 출력
	std::cout << "Class " << Count++ << std::endl;
	std::cout << "Max " << SMax << ", Min " << SMin << ", Largest gap " << Lgap << std::endl;
	int a = 0;
}

int main()
{
	int K = -1;

	std::cin >> K;
	while (K)
	{
		int N = -1;
		std::cin >> N;
		CalcScores(N);
		--K;
	}

	return 0;
}