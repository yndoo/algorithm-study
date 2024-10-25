#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    deque<int> pq;
    for(string oper : operations)
    {
        char ch = oper[0];
        switch(ch)
        {
            case 'I':
                pq.push_front(stoi(oper.substr(2, oper.size() - 2)));
                break;
            case 'D':
                if(pq.empty()) continue;
                sort(pq.begin(), pq.end());
                if(stoi(oper.substr(2, oper.size() - 2)) == 1)
                {
                    pq.pop_back();
                }
                else
                {
                    pq.pop_front();
                }
                break;
            default:
                break;
        }
    }
    
    if(pq.empty()) return {0, 0};
    sort(pq.begin(), pq.end());
    return {pq.back(), pq.front()};
}