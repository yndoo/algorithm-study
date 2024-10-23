#include <iostream>
#include <vector>
int main()
{
	int N = -1, K = -1;
	std::vector<int> nums;
	std::cin >> N >> K;
	nums.resize(N);
	for (int i = 0; i < N; ++i)
	{
		std::cin >> nums[i];
	}

	int en = 0, cnt = 0, answer = 0;
	cnt = nums[0] % 2;
	for (int st = 0; st < N; ++st)
	{
		while (en + 1 < N && cnt + nums[en + 1] % 2 <= K)
		{
			++en;
			cnt += nums[en] % 2;
		}
		answer = std::max(answer, en - st + 1 - cnt);
		cnt -= nums[st] % 2;
	}
	std::cout << answer;
	return 0;
}