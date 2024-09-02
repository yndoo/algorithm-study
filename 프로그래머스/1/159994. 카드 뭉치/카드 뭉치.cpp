#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int top1 = 0, top2 = 0, goaltop = 0;
    int maxindex = goal.size();
    
    while(top1 >= 0 || top1 < cards1.size() || top2 >= 0 || top2 < cards2.size())
    {
        if(goaltop == maxindex)
        {
            answer = "Yes";
            break;
        }
        if(cards1[top1] == goal[goaltop])
        {
            ++top1;
            ++goaltop;
        }
        else if(cards2[top2] == goal[goaltop])
        {
            ++top2;
            ++goaltop;
        }
        else
        {
            answer = "No";
            break;
        }
    }
    
    return answer;
}