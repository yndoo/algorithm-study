#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int last = 0 /*커버된 마지막 지점*/, term = 2 * w + 1;
    for(int station : stations)
    {
        int left = station - w;
        if(last < left)
        {
            int uncovered = left - last - 1;
            answer += (uncovered + term - 1) / term; // 올림계산
        }
        last = station + w;
    }
    if(last < n)
    {
        int uncovered = n - last;
        answer += (uncovered + term - 1) / term; // 올림계산
    }

    return answer;
}