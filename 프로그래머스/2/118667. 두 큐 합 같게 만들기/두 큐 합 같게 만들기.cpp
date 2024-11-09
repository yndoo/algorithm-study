#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0, N = queue1.size();
    long long sum1 = 0, sum2 = 0;
    queue<long long> q1;
    queue<long long> q2;
    
    for(int one : queue1)
    {
        sum1 += one;
        q1.push(one);
    }
    for(int two : queue2)
    {
        sum2 += two;
        q2.push(two);
    }

    while(sum1 != sum2 && answer < 3 * N + 1)
    {
        if(sum1 > sum2)
        {
            long long tmp = q1.front();
            sum1 -= tmp;
            sum2 += tmp;
            q1.pop();
            q2.push(tmp);
        }
        else if (sum1 < sum2)
        {
            long long tmp = q2.front();
            sum1 += tmp;
            sum2 -= tmp;
            q2.pop();
            q1.push(tmp);
        }
        ++answer;
    }
    if(sum1 != sum2 && answer >= 3 * N + 1) return -1;
    return answer;
}