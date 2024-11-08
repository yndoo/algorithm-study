#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2, 0);
    set<string> Types;
    map<string, int> cur;
    int N = gems.size();
    for(string gem : gems)
    {
        Types.insert(gem);
    }
    
    int en = 0, len = 0x7fffffff;
    for(int st = 0; st < N; ++st)
    {
        while(cur.size() < Types.size() && en < N)
        {
            cur[gems[en]]++;
            ++en;
        }
        if(cur.size() == Types.size() && en - st + 1 < len)
        {
            len = en - st + 1;
            answer[0] = st + 1; // 0번부터라서 +1 해야 함
            answer[1] = en;
        }
        if(cur[gems[st]] == 1)
        {
            cur.erase(gems[st]);
        }
        else
        {
            cur[gems[st]]--;
        }
    }
    return answer;
}