#include <iostream>

int main()
{
	int H, W, N, M;
	std::cin >> H >> W >> N >> M;

	int x = W % (M + 1) == 0 ? W / (M + 1) : W / (M + 1) + 1;
	int y = H % (N + 1) == 0 ? H / (N + 1) : H / (N + 1) + 1;
	
	std::cout << x * y;
	return 0;
}