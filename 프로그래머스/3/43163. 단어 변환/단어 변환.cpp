#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    if(find(words.begin(), words.end(), target) == words.end()) return 0;
    
    int N = words.size();
    vector<int> visited(N, -1);
    queue<int> q;
    
    { // 첫 단어 찾기
        for(int i = 0; i < N; ++i)
        {
            int cnt = 0; // 알파벳 1개 빼고 같아야 함
            for(int j = 0; j < begin.size(); ++j)
            {
                if (begin[j] == words[i][j]) ++cnt;
            }
            if(cnt == begin.size() - 1)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        string curstr = words[cur];
        for(int i = 0; i < N; ++i)
        {
            if(visited[i] != -1) continue;
            int cnt = 0; // 알파벳 1개 빼고 같아야 함
            for(int j = 0; j < curstr.size(); ++j)
            {
                if (curstr[j] == words[i][j]) ++cnt;
            }
            if(cnt == curstr.size() - 1)
            {
                if(words[i] == target) return visited[cur] + 1;
                q.push(i);
                visited[i] = visited[cur] + 1;
            }
        }
    }
    
    for(int i = 0; i < N; ++i)
    {
        if(words[i] == target)
        {
            return visited[i];
        }
    }
    return 0;
}