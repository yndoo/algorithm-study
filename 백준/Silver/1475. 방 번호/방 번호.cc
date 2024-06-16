#include <iostream>
#include <vector>

int main()
{
	std::vector<int> SetCount;
	int nums = 0, maxnum = -1;
	SetCount.resize(10);
	std::cin >> nums;

	while (nums != 0)
	{
		int n = nums % 10;
		if (n == 6 || n == 9)
		{
			if (maxnum > SetCount[6])	// 있는 세트로 해결 가능
			{
				++SetCount[6];
			}
			else if (maxnum > SetCount[9])	// 있는 세트로 해결 가능
			{
				++SetCount[9];
			}
			else if (maxnum <= SetCount[6]) // 새로운 세트 쓰기
			{
				++SetCount[6];
				maxnum = SetCount[6];
			}
		}
		else
		{
			if (maxnum <= SetCount[n]) // 새로운 세트 쓰기
			{
				++SetCount[n];
				maxnum = SetCount[n];
			}
			else if (maxnum > SetCount[n])	// 있는 세트로 해결 가능
			{
				++SetCount[n];
			}
		}


		nums /= 10;
	}

	std::cout << maxnum;
	return 0;
}