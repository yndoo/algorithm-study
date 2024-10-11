#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    set<char> skillset;
    for(char ch : skill)
    {
        skillset.insert(ch);
    }
    
    for(string user : skill_trees)
    {
        vector<char> Preskill; // 각 유저의 스킬트리 중 선행 스킬 트리에 해당하는 스킬만 담는 벡터
        for(char sk : user)
        {
            if(skillset.find(sk) != skillset.end())
            {
                Preskill.push_back(sk);
            }
        }
        
        bool flag = true;
        for(int i = 0; i < Preskill.size(); ++i)
        {
            if(Preskill[i] != skill[i]) flag = false;
        }
        if(flag == true) ++answer;
    }

    
    return answer;
}