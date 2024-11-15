#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N = -1, answer = 0;
	std::cin >> N;
	std::vector<int> ropes(N);
	for (int i = 0; i < N; ++i)
	{
		std::cin >> ropes[i];
	}
	sort(ropes.begin(), ropes.end());
	for (int i = 0; i < N; ++i)
	{
		answer = std::max(answer, ropes[i] * (N - i));
	}
	std::cout << answer;
	return 0;
}