#include <iostream>
#include <algorithm>
#include <vector>

int N = -1, L = -1, R = -1;
std::vector<std::vector<int>> land;
std::vector<std::vector<bool>> visited;
//std::vector<std::pair<int, int>> area;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool population(int x, int y, std::vector<std::pair<int, int>>& area)
{
	if (x < 0 || x >= N || y < 0 || y >= N) return false;
	if (visited[x][y] == false)
	{
		area.push_back(std::pair<int, int>(x, y));
		visited[x][y] = true;
		bool flag = false;
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			int gap = abs(land[x][y] - land[nx][ny]);
			if (gap >= L && gap <= R) // 국경선 열기
			{
				population(nx, ny, area);
				flag = true;
			}
		}
		if (!flag) return false;
		return true;
	}
	return false;
}

int getSum(const std::vector<std::pair<int, int>>& area)
{
	int sum = 0;
	for (std::pair<int, int> zone : area)
	{
		sum += land[zone.first][zone.second];
	}
	return sum;
}

int main()
{
	std::cin >> N >> L >> R;
	land.resize(N);
	visited.resize(N);
	for (int i = 0; i < N; ++i)
	{
		visited[i].resize(N);
		land[i].resize(N);
		for (int j = 0; j < N; ++j)
		{
			std::cin >> land[i][j];
		}
	}

	int answer = 0;
	while(true)
	{
		bool flag = false;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				visited[i][j] = false;
			}
		}
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				std::vector<std::pair<int, int>> area;
				if (visited[i][j] == false && population(i, j, area) == true)
				{
					int sum = getSum(area), aSize = area.size();
					for (std::pair<int, int> zone : area)
					{
						land[zone.first][zone.second] = sum / aSize;
					}
					flag = true;
				}
			}
		}
		if (!flag) break;
		++answer;
	}
	std::cout << answer;
	return 0;
}