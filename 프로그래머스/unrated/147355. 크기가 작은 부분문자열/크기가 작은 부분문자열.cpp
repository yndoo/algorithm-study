#include<bits/stdc++.h>

using namespace std;

int solution(string t, string p) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int answer = 0;
    for(int i =0; i<t.size()-p.size()+1; i++){
        long long target = stoll(t.substr(i, p.size()));
        if(target<=stoll(p)) answer++;
    }
    return answer;
}