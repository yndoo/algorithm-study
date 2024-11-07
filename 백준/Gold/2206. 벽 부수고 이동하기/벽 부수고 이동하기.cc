#include <iostream>
#include <queue>
#include <vector>

struct Tile
{
	int x, y, dist;
	bool blockChance = false;
};

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main()
{
	int N = -1, M = -1;
	std::string input;
	std::cin >> N >> M;
	std::vector<std::vector<int>> graph(N, std::vector<int>(M, 0));
	std::vector<std::vector<std::vector<bool>>> visited(N, std::vector<std::vector<bool>>(M, std::vector<bool>(2, false)));
	for (int i = 0; i < N; ++i)
	{
		std::cin >> input;
		for (int j = 0; j < M; ++j)
		{
			graph[i][j] = input[j] - '0';
		}
	}
	std::queue<Tile> q;
	q.push({ 0, 0, 1, false });
	visited[0][0][false] = true; // 0,0 칸에 블록안깨고 방문완료
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int dist = q.front().dist;
		bool chance = q.front().blockChance;
		q.pop();
		if (x == N - 1 && y == M - 1)
		{
			std::cout << dist;
			return 0;
		}
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (graph[nx][ny] == 0 && visited[nx][ny][chance] == false)
			{
				visited[nx][ny][chance] = true;
				q.push({ nx, ny, dist + 1, chance });
			}
			else if (graph[nx][ny] == 1 && visited[nx][ny][true] == false && chance == false)
			{
				visited[nx][ny][true] = true;
				q.push({ nx, ny, dist + 1, true });
			}
		}
	}

	std::cout << -1;
	return 0;
}