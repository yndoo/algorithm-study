#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<int, string> ranking;   // 순위 - 이름
    map<string, int> note;      // 이름 - 순위
    for(int i = 0; i < players.size(); ++i)
    {
        ranking[i + 1] = players[i];
        note[players[i]] = i + 1;
    }
    for(int i = 0; i < callings.size(); ++i)
    {
        
        int cur = note[callings[i]]--;   // 부른 선수의 순위
        string loseP = ranking[cur - 1];// 추월당한 앞 선수의 이름
        
        note[loseP]++;
        ranking[cur] = loseP;
        ranking[cur - 1] = callings[i];
    }
    
    vector<string> answer;
    for(map<int, string>::iterator it = ranking.begin(); it != ranking.end(); it++)
    {
        answer.push_back((*it).second);
    }
    return answer;
}