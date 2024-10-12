#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(int n, string control) {
    int answer = n;
    map<char, int> matching;
    matching['w'] = 1;
    matching['s'] = -1;
    matching['d'] = 10;
    matching['a'] = -10;
    for(char ch : control)
    {
        answer += matching[ch];
    }
    return answer;
}