#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>
using namespace std;

vector<bool> visited;
set<int> found; // 이미 찾아본 숫자들
int answer = 0;


void papers(string curstr, const string& numbers, vector<bool> visited)
{
    // 소수인지 알아보기
    int target = stoi(curstr);
    //cout<<target<<endl;
    if(found.find(target) == found.end() && target != 0 && target != 1)
    {
        bool flag = true;
        for(int i = 2; i < sqrt(target) + 1; ++i)
        {
            if(target % i == 0)
            {
                flag = false;
            }
        }
        if(target == 2 || flag)
        {
            ++answer;
        }
        found.insert(target);
    }
    // 찾기
    for(int i = 0; i < numbers.size(); ++i)
    {
        if(visited[i] == false)
        {
            visited[i] = true;
            papers(curstr+numbers[i], numbers, visited);
            visited[i] = false;
        }
    }
}

int solution(string numbers) {
    visited.resize(numbers.size());
    papers("0", numbers, visited);
    return answer;
}