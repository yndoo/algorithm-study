#include <iostream>
#include <vector>
#include <queue>

struct Node
{
	int x, y, value;
	bool operator<(const Node& _other) const
	{
		return value > _other.value;
	}
};

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	int N = -1, problem = 1;

	while (true)
	{
		std::cin >> N;
		if (N == 0) break;
		std::vector<std::vector<int>> graph(N, std::vector<int>(N));
		std::vector<std::vector<int>> answer(N, std::vector<int>(N, 0x7fffffff));
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				std::cin >> graph[i][j];
			}
		}
		std::priority_queue<Node> pq;
		pq.push({ 0, 0, graph[0][0] });
		while (!pq.empty())
		{
			Node cur = pq.top();
			int x = cur.x;
			int y = cur.y;
			int val = cur.value;
			pq.pop();
			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				int next = val + graph[nx][ny];
				if (next < answer[nx][ny])
				{
					answer[nx][ny] = next;
					pq.push({ nx, ny, answer[nx][ny] });
				}
			}
		}
		std::cout << "Problem " << problem++ << ": " << answer[N - 1][N - 1] << std::endl;
	}
	return 0;
}