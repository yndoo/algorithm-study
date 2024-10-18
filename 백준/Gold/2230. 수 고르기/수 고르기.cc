#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
	int N = -1, M = -1;
	std::vector<int> nums;
	std::cin >> N >> M;
	
	nums.resize(N);
	for(int i = 0; i < N; ++i)
	{
		std::cin >> nums[i];
	}
	sort(nums.begin(), nums.end());

	int st = 0, en = 0, answer = 0x7fffffff;
	while (true)
	{
		if (nums[en] - nums[st] < M)
		{
			++en;
		}
		else
		{
			answer = std::min(answer, nums[en] - nums[st]);
			++st;
		}
		if (st > en || st >= N || en >= N) break;
	}
	std::cout << answer;
	return 0;
}