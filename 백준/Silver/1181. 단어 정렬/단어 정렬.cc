#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool compare(string a, string b){
    if (a.size()==b.size()){ // 길이가 같으면, 사전 순
        return a < b;
    } else {                //길이 다르면, 길이 짧은 순
        return a.size() < b.size();
    }
}

int main() {
    int N;
    string s;
    vector<string> sorting;
    map<string, int> count;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>s;
        if(count[s]==1)    //s가 이미 있으면 벡터에 추가 안 함
            continue; 
        sorting.push_back(s);
        count[s] = 1;
    }
    sort(sorting.begin(), sorting.end(), compare);

    for(int i=0; i<sorting.size(); i++){
        cout<<sorting[i]<<endl;
    }
    return 0;
}