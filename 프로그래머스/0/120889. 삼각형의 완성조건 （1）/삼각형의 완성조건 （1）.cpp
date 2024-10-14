#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    int answer = 2;
    int longIndex = 0;
    for(int i = 0; i < 3; ++i)
    {
        if(sides[i] > sides[longIndex])
        {
            longIndex = i;
        }
    }
    int sum = 0;
    for(int i = 0; i < 3; ++i)
    {
        if(i != longIndex) sum += sides[i];
    }
    if(sum > sides[longIndex]) answer = 1;
    return answer;
}