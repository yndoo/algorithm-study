#include <iostream>
#include <set>
#include <vector>

bool IsUsed[2000001] = { false, };
int main()
{
	int N, X, count = 0;
	int half = 0, turn = 0;
	std::set<int> nums;
	std::vector<int> NumsVector;
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		std::cin >> num;
		nums.insert(num);
	}
	for (auto num : nums)
	{
		NumsVector.push_back(num);
	}

	std::cin >> X;
	for (int i = 0; i < N; i++)
	{
		if (!IsUsed[NumsVector[i]] &&
			(X - NumsVector[i] > 0 && !IsUsed[X - NumsVector[i]])&&
			X - NumsVector[i] != NumsVector[i] &&
			nums.find(X - NumsVector[i]) != nums.end())
		{
			++count;
			IsUsed[i] = true;
			IsUsed[X - NumsVector[i]] = true;
		}
	}

	std::cout << count;
	return 0;
}