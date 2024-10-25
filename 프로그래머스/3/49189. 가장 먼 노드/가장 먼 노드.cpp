#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> graph;
    vector<bool> visited(n + 1, false);
    vector<int> depth(n + 1, 0);
    queue<int> q;
    graph.resize(n + 1);
    for(const vector<int>& eg : edge)
    {
        graph[eg[0]].push_back(eg[1]);
        graph[eg[1]].push_back(eg[0]);
    }
    
    q.push(1);
    depth[1] = 1;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        if(visited[cur] == false)
        {
            visited[cur] = true;
            for(int x : graph[cur])
            {
                if(visited[x] == true) continue;
                q.push(x);
                if(depth[x] == 0) depth[x] = depth[cur] + 1;
            }
        }
    }
    int tempmax = -1;
    for(int d : depth)
    {
        if(tempmax < d)
        {
            tempmax = d;
            answer = 1;
        }
        else if(tempmax == d)
        {
            ++answer;
        }
    }
    
    return answer;
}