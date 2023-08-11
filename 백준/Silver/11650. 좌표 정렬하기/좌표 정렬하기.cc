#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, x, y;
    vector<pair<int,int>> v;
    cin>>N;

    for(int i=0; i<N; i++){
        cin>>x>>y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());

    for(int i=0; i<N; i++) {
        cout<<v[i].first <<" "<< v[i].second<<'\n';
    }
    return 0;
}