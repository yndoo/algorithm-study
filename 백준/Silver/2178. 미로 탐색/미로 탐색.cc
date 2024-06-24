#include <iostream>
#include <queue>

int main()
{
	int N, M;
	int graph[100][100] = { 0, };
	int visited[100][100] = { 0, };
	std::queue<std::pair<int, int>> Q;

	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { 1,-1,0,0 };


	std::cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		std::string row;
		std::cin >> row;

		for (int j = 0; j < M; ++j)
		{
			if (row[j] == '1')
			{
				graph[i][j] = 1;
			}
		}
	}

	Q.push(std::make_pair(0, 0));
	visited[0][0] = 1;
	while (!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (0 == graph[nx][ny] || 0 < visited[nx][ny] || nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			Q.push(std::make_pair(nx, ny));
			visited[nx][ny] = visited[x][y] + 1;
		}
	}


	std::cout << visited[N - 1][M - 1];
	return 0;
}