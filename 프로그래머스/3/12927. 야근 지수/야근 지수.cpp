#include <string>
#include <vector>
#include <set>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    multiset<int> workset;
    for(int work : works)
    {
        workset.insert(work);
    }
    while(n)
    {
        int maxi = *(--workset.end());
        if(maxi == 0) return 0;
        workset.erase(--workset.end());
        workset.insert(maxi - 1);
        --n;
    }
    for(auto num : workset)
    {
        answer += num * num;
    }
    return answer;
}