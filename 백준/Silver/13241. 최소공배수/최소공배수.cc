#include <iostream>

int main()
{
	long long A = -1, B = -1, gcd = -1;
	std::cin >> A >> B;

	for (int i = std::min(A, B); i > 0; --i)
	{
		if (A % i == 0 && B % i == 0)
		{
			gcd = i;
			break;
		}
	}
	std::cout << A * B / gcd;
	return 0;
}