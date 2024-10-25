#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited;
    stack<int> s;
    visited.resize(n);
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(visited[i] == false && computers[i][j] == 1)
            {
                ++answer;
                s.push(i);
                while(!s.empty())
                {
                    int cur = s.top();
                    s.pop();
                    visited[cur] = true;
                    for(int k = 0; k < n; ++k)
                    {
                        if(visited[k] == false && computers[cur][k] == 1)
                        {
                            s.push(k);
                        }
                    }
                }
            }
        }
    }
    return answer;
}