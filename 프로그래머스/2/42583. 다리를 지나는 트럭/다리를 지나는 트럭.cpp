#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> brg;
    int sum = 0, i = 0;
    while(true)
    {
        if(brg.size() == bridge_length)
        {
            if(brg.front() != -1) sum -= brg.front();
            brg.pop();
        }
        if(i < truck_weights.size() && sum + truck_weights[i] <= weight)
        {
            brg.push(truck_weights[i]);
            sum += truck_weights[i];
            ++i;
        }
        else // 더 추가 못하는 상황
        {
            brg.push(-1);
        }
        ++answer;
        if(sum == 0 && brg.size() == bridge_length) break;
    }
    return answer;
}