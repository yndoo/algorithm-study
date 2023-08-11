#include <iostream>
#include <vector>
#include<queue>

using namespace std;

struct compare {
    bool operator()(int a, int b){
        if (abs(a) == abs(b)){
            return a > b;
        }
        return abs(a) > abs(b);
    }
};

int main() {
    int N, num;
    vector<int> v;
    priority_queue<int, vector<int>, compare> q;
    cin>>N;
    for (int i=0; i<N; i++){
        cin>>num;
        if(num==0){
            if(q.empty()){
                cout<<0<<'\n';
                continue;
            }
            cout<<q.top()<<'\n';
            q.pop();
            continue;
        }
        q.push(num);
    }
    return 0;
}