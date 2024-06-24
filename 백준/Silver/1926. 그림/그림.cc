#include <iostream>
#include <queue>

int paper[500][500] = { 0, };
bool visited[500][500] = { false, };

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n = 0, m = 0;

int bfs(int x, int y)
{
	std::queue<std::pair<int, int>> Q;
	int mymax = 0;

	Q.push(std::make_pair(x, y));
	visited[x][y] = true;

	while(!Q.empty())
	{
		++mymax;
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (1 != paper[nx][ny] || nx < 0 || ny < 0 || nx >= n || ny >= m || true == visited[nx][ny]) continue;
			if (0 == visited[nx][ny])
			{
				Q.push(std::make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
	return mymax;
}

int main()
{
	int tmp = 0, count = 0, maxwidth = 0;
	std::cin >> n >> m;
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cin >> tmp;
			if (1 == tmp)
			{
				paper[i][j] = 1;
			}
		}
	}
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (paper[i][j] == 1 && visited[i][j] == false)
			{
				int thismax = bfs(i, j);
				if (thismax > maxwidth)
				{
					maxwidth = thismax;
				}
				++count;
			}
		}
	}

	std::cout << count << '\n';
	std::cout << maxwidth;
	return 0;
}

