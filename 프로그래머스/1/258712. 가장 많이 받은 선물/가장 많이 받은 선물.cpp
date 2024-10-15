#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

map<string, int> Index;

int solution(vector<string> friends, vector<string> gifts) {
    // 답을 모을 벡터
    vector<int> answer;
    int AllFriends = friends.size();
    answer.resize(AllFriends);
    // 이름별 인덱스 : Index
    for(int i =0; i < AllFriends; ++i)
    {   
        Index[friends[i]] = i; 
    }
    // 주고 받은 선물 표 : Table
    vector<vector<int>> Table;
    Table.resize(AllFriends);
    for(int i = 0; i < AllFriends; ++i)
    {
        Table[i].resize(AllFriends);
    }
    // 이름별 준 선물, 받은 선물, 선물 지수 표 : Counting
    vector<vector<int>> Counting;
    Counting.resize(AllFriends);
    for(int i = 0; i < AllFriends; ++i)
    {
        Counting[i].resize(3);
    }
    
    // 여기부터 실제 데이터 넣기
    for(string gift : gifts)
    {
        int split = gift.find(' '); 
        // 주고받음표에 저장
        int giver = Index[gift.substr(0, split)];
        int receiver = Index[gift.substr(split + 1, gift.size() - split)];
        Table[giver][receiver] += 1;
        // 이름별 표에 저장
        Counting[giver][0] += 1;
        Counting[receiver][1] += 1;
    }
    // 선물 지수 계산
    for(int i = 0; i < AllFriends; ++i)
    {
        Counting[i][2] = Counting[i][0] - Counting[i][1];
    }
    
    // 다음달 받을 선물 계산
    for(int i = 0; i < AllFriends; ++i)
    {
        for(int j = 0; j < AllFriends; ++j)
        {
            if(i == j) continue;
            if(Table[i][j] > Table[j][i])
            {
                ++answer[i];
            }
            else if(Table[i][j] == Table[j][i])
            {
                if(Counting[i][2] > Counting[j][2]) ++answer[i];
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer[AllFriends - 1];
}