#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    // 어떤 알파벳을 입력하기 위해 눌러야 하는 키 최솟값 구해두기
    map<char, int> MinTouch;
    for(string key : keymap)
    {
        for(int i = 0; i < key.size(); ++i)
        {
            if(MinTouch.find(key[i]) == MinTouch.end())
            {
                MinTouch[key[i]] = i + 1;
            }
            else if(MinTouch[key[i]] > i + 1)
            {
                MinTouch[key[i]] = i + 1;
            }
        }
    }
    for(string target : targets)
    {
        int res = 0;
        for(char ch : target)
        {
            if(MinTouch.find(ch) == MinTouch.end())
            {
                res = -1;
                break;
            }
            else
            {
                res += MinTouch[ch];
            }
        }
        answer.push_back(res);
    }
    return answer;
}