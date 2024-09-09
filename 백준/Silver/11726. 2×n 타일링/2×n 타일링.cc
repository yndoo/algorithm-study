#include <iostream>
#include <vector>

int main()
{
	int n = -1;
	std::cin >> n;

	std::vector<int> Tile;
	Tile.resize(n + 1);
	Tile[0] = 0; Tile[1] = 1; Tile[2] = 2;
	for (int i = 3; i <= n; ++i)
	{
		Tile[i] = Tile[i - 2] % 10007 + Tile[i - 1] % 10007;
	}
	
	std::cout << Tile[n] % 10007;
	return 0;
}