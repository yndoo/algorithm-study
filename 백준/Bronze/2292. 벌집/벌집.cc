#include <iostream>

int main()
{
	int N = -1, i = 0, sum = 1;
	std::cin >> N;
	while (true)
	{
		sum += (i++) * 6;
		if (N <= sum)
		{
			break;
		}
	}
	std::cout << i;
	return 0;
}