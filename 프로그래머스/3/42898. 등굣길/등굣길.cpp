#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> road(n, vector<int>(m, 0));
    road[0][0] = 1;
    for(const vector<int>& puddle : puddles)
    {
        road[puddle[1] - 1][puddle[0] - 1] = -1;
    }
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(road[i][j] == -1)
            {
                road[i][j] = 0;
                continue;
            }
            
            if(i > 0)
            {
                road[i][j] += road[i - 1][j];
                road[i][j] %= 1000000007;
            }
            if(j > 0)
            {
                road[i][j] += road[i][j - 1];
                road[i][j] %= 1000000007;
            }
        }
    }
    return road[n - 1][m - 1];
}