#include <iostream>
#include <vector>

int main()
{
	std::vector<int> nums;
	int A, B, C;

	std::cin >> A >> B >> C;
	int result = A * B * C;

	nums.resize(10);

	while(result > 0)
	{
		++nums[result % 10];
		result = result / 10;
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << nums[i] << '\n';
	}
	return 0;
}