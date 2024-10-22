#include <iostream>
#include <algorithm>
#include <vector>
int main()
{
	int N = -1;
	std::vector<int> nums;
	std::vector<int> LIS;
	std::cin >> N;
	nums.resize(N);
	LIS.resize(N);
	for (int i = 0; i < N; ++i)
	{
		std::cin >> nums[i];
	}
	LIS[0] = 1;
	for (int i = 1; i < N; ++i)
	{
		bool flag = false;
		int target = -1;
		for (int j = i - 1; j >= 0; --j)
		{
			if (nums[i] > nums[j] && target < LIS[j])
			{
				target = LIS[j];
				LIS[i] = LIS[j] + 1;
				flag = true;
			}
		}
		if (!flag) LIS[i] = 1;
	}
	std::cout << N - *max_element(LIS.begin(), LIS.end());
	return 0;
}