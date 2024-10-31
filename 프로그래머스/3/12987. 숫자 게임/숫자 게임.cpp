#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0, idx = 0;
    priority_queue<int> Bpq(B.begin(), B.end());
    sort(A.begin(), A.end(), greater<int>()); // A 내림차순
    while(idx < A.size())
    {
        if(A[idx] < Bpq.top())
        {
            //cout<<Bpq.top()<<endl;
            Bpq.pop();
            ++answer;
        }
        ++idx;
    }
    
    return answer;
}