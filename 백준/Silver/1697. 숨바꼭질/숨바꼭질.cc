#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int graph[200001];
    int visited[200001];
    int N, K;
    cin>>N>>K;
    queue<int> q;
    q.push(N);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        if (cur==K){
            cout<<visited[K];
            break;
        }
        if(cur-1>=0 && cur-1<=200001 && visited[cur-1]==0){
            visited[cur-1] = visited[cur]+1;
            q.push(cur-1);
        }
        if(cur+1>=0 && cur+1<=200001 && visited[cur+1]==0){
            visited[cur+1] = visited[cur]+1;
            q.push(cur+1);
        }
        if(cur*2>=0 && cur*2<=200001 && visited[cur*2]==0){
            visited[cur*2] = visited[cur]+1;
            q.push(cur*2);
        }
    }
    return 0;
}