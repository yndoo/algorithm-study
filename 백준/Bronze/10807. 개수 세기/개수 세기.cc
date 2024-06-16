#include <iostream>
#include <map>

int main()
{
	std::map<int, int> CountMap;
	int N, v;
	std::cin >> N;
	while (N)
	{
		--N;
		int tmp;
		std::cin >> tmp;
		++CountMap[tmp];
	}
	std::cin >> v;
	std::cout << CountMap[v];
	return 0;
}