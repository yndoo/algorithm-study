#include <bits/stdc++.h>

using namespace std;

string graph[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    int visited[101][101];
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>graph[i];
    }    
    for(int i=0; i<N; i++)
        fill(visited[i],visited[i]+M,0);
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0]=1;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int nx,ny;
            nx = cur.first + dx[i];
            ny = cur.second + dy[i];
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if (visited[nx][ny]!=0 || graph[nx][ny]=='0') continue;
            visited[nx][ny]= visited[cur.first][cur.second]+1;
            q.push({nx,ny});
        }
    }
    cout<<visited[N-1][M-1];
    return 0;
}