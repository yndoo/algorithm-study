#include <string>
#include <vector>
#include <regex>
#include <map>
#include <set>
using namespace std;

set<set<string>> answers;

void FindCombi(int idx, set<string>& candi, const map<int, vector<string>>& matched_uid)
{
    if(candi.size() == matched_uid.size())
    {
        // 후보 마무리 작업
        answers.insert(candi);
        return;
    }
    for(string s : matched_uid.at(idx))
    {
        if(candi.find(s) == candi.end())
        {
            candi.insert(s);
            FindCombi(idx + 1, candi, matched_uid);
            candi.erase(s);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    map<int, vector<string>> matched_uid;
    for(int i = 0; i < banned_id.size(); ++i)
    {
        string bid = banned_id[i];
        string pattern = "^";
        for(char ch : bid)
        {
            if(ch == '*')
            {
                pattern += "[a-z0-9]";
            }
            else
            {
                pattern += ch;
            }
        }
        pattern += "$";
        regex reg(pattern);
        for (string uid : user_id)
        {
            if(regex_match(uid, reg))
            {
                // 매칭
                matched_uid[i].push_back(uid);
            }
        }
    }
    set<string> ss;
    FindCombi(0, ss, matched_uid);
    return answers.size();
}