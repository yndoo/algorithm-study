#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
	int N = -1, S = -1;
	std::vector<int> Vec;
	std::cin >> N >> S;
	Vec.resize(N);
	for (int i = 0; i < N; ++i)
	{
		std::cin >> Vec[i];
	}

	int en = 0, answer = 0x7fffffff, sum = Vec[0];
	for(int st = 0; st < N; ++st)
	{
		while (en < N && sum < S)
		{
			++en;
			if (en != N) sum += Vec[en];
		}
		if (en == N) break;
		sum -= Vec[st];
		answer = std::min(answer, en - st + 1);
	}
	if (answer == 0x7fffffff) answer = 0;
	std::cout << answer;
	return 0;
}