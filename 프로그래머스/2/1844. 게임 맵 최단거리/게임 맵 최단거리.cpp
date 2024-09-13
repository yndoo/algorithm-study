#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int solution(vector<vector<int> > maps)
{
    int CountingMap[100][100];
    int maxX = maps.size();
    int maxY = maps[0].size();
    
    fill(&CountingMap[0][0], &CountingMap[99][100], -1);
    
    queue<pair<int, int>> Q;
    Q.push(pair<int, int>(0, 0));
    CountingMap[0][0] = 1;
    while(!Q.empty())
    {
        pair<int, int> Cur = Q.front();
        Q.pop();
        for(int i = 0; i < 4; ++i)
        {
            int nx = Cur.first + dx[i];
            int ny = Cur.second + dy[i];
            if(nx < 0 || ny < 0 || nx >= maxX || ny >= maxY) continue;
            if(maps[nx][ny] == 0 || CountingMap[nx][ny] != -1) continue;
            CountingMap[nx][ny] = CountingMap[Cur.first][Cur.second] + 1;
            Q.push(pair<int, int>(nx, ny));
        }
    }
    
    //for(int i = 0; i < maxX; ++i)
    //{
    //    for(int j = 0; j < maxY; ++j)
    //    {
    //        cout<<CountingMap[i][j]<<" ";
    //    }
    //    cout<<endl;
    //}
    
    return CountingMap[maxX - 1][maxY - 1];
}