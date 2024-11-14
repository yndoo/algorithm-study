#include <iostream>
#include <vector>

#define BUSMAX 100000 * 99 + 1

int main()
{
	int n = -1, m = -1;
	std::cin >> n >> m;
	std::vector<std::vector<int>> graph(n + 1, std::vector<int>(n + 1, BUSMAX));
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		graph[a][b] = std::min(c, graph[a][b]);
	}
	for (int i = 1; i <= n; ++i)
	{
		graph[i][i] = 0;
	}
	for (int mid = 1; mid <= n; ++mid)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				graph[i][j] = std::min(graph[i][j], graph[i][mid] + graph[mid][j]);
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (graph[i][j] == BUSMAX) graph[i][j] = 0;
			std::cout << graph[i][j] << " ";
		}
		std::cout << '\n';
	}
	return 0;
}