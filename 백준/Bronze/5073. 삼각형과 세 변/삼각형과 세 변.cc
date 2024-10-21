#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
	int a, b, c;
	while(true)
	{
		std::vector<int> tri;
		tri.resize(3);
		for (int i = 0; i < 3; ++i)
		{
			std::cin >> tri[i];
		}
		sort(tri.begin(), tri.end());
		if (tri[2] == 0) break;
		if (tri[2] >= tri[0] + tri[1]) 
		{
			std::cout << "Invalid" << std::endl;
			continue;
		}
		if (tri[0] == tri[1] && tri[1] == tri[2])
		{
			std::cout << "Equilateral" << std::endl;
		}
		else if (tri[0] == tri[1] || tri[1] == tri[2])
		{
			std::cout << "Isosceles" << std::endl;
		}
		else
		{
			std::cout << "Scalene" << std::endl;
		}
	}
	return 0;
}