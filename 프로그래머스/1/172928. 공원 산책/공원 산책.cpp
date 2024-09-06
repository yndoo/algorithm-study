#include <iostream>

#include <string>
#include <vector>
#include <map>

using namespace std;

// 방향 데이터들. (남, 북, 동, 서 순서임.)
int dx[4] = {0, 0, 1, -1}; // 가로 
int dy[4] = {1, -1, 0, 0}; // 세로
map<char, int> Direction = { {'S', 0}, {'N', 1}, {'E', 2}, {'W', 3} };

pair<int, int> CurIndex;    // 현재 인덱스
int H = -1, W = -1;         // 공원 높이, 너비

pair<int, int> FindStart(vector<string> &park)
{
    int i = -1, j = -1;
    
    for(string row : park)
    {
        ++i;
        j = -1;
        for(char ch : row)
        {
            ++j;
            if(ch == 'S')
            {
                return pair<int, int>(i, j);
            }
        }
    }
    
    return pair<int, int>(-1, -1);
}

bool CanGo(vector<string>& _park, int _DirIndex, int _num)
{
    pair<int, int> _CurIndex = CurIndex;
    while(_num > 0)
    {
        --_num;
        int nx = _CurIndex.second + dx[_DirIndex];
        int ny = _CurIndex.first + dy[_DirIndex];
        if(nx < 0 || ny < 0 || nx >= W || ny >= H) return false;
        if(_park[ny][nx] == 'X') return false;  
        _CurIndex.second = nx;
        _CurIndex.first = ny;
    }
    return true;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    CurIndex = FindStart(park);
    H = park.size();
    W = park[0].size();
    
    for(string route : routes)
    {
        int DirIndex = Direction[route[0]];
        int num = static_cast<int>(route[2]) - '0';
        if(true == CanGo(park, DirIndex, num))
        {
            CurIndex.first += dy[DirIndex] * num;
            CurIndex.second += dx[DirIndex] * num;
        }
    }
    
    
    vector<int> answer = {CurIndex.first, CurIndex.second};
    return answer;
}