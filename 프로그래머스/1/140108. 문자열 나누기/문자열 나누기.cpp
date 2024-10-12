#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char x = s[0];
    int xCount = 1, numCount = 0;
    for(int i = 1; i < s.size(); ++i)
    {
        if(s[i] == x) ++xCount;
        else ++numCount;
        
        if(xCount == numCount)
        {
            ++answer;
            xCount = 0;
            numCount = 0;
            if(i + 1 < s.size())
            {
                x = s[i + 1];
            }
        }
    }
    if(xCount > 0) ++answer;
    return answer;
}