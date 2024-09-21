#include <string>
#include <vector>

using namespace std;
bool painted[100001];
int solution(int n, int m, vector<int> section) {
    int answer = 0;
    for(int num : section)
    {
        if(painted[num] == true)
        {
            continue;
        }
        for(int i = 0; i < m && num + i < 100001 ; ++i)
        {
            painted[num + i] = true;
        }
        ++answer;
    }
    
    return answer;
}