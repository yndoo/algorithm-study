#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool mycomp(pair<int, int> a, pair<int, int> b)
{
    if(a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first > b.first;
}

bool scomp(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genrecnt;
    map<string, vector<pair<int, int>>> rankingmap; //pair(횟수, 고유번호)
    for(int i = 0; i < genres.size(); ++i)
    {
        genrecnt[genres[i]] += plays[i];
        rankingmap[genres[i]].push_back(pair<int, int>(plays[i], i));
    }
    
    vector<pair<string, int>> cntvec(genrecnt.begin(), genrecnt.end());
    sort(cntvec.begin(), cntvec.end(), scomp);
    for(auto it = cntvec.begin(); it != cntvec.end(); it++)
    {
        sort(rankingmap[it->first].begin(),rankingmap[it->first].end(), mycomp);
        for(int i = 0; i < 2 && i < rankingmap[it->first].size(); ++i)
        {
            answer.push_back(rankingmap[it->first][i].second);
        }
    }
    
    return answer;
}