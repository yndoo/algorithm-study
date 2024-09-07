#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(vector<int> command : commands)
    {
        vector<int> copyArr = array;
        sort(copyArr.begin() + (command[0] - 1), copyArr.begin() + command[1]);
        answer.push_back(copyArr[command[0] + command[2] - 2]);
    }
    
    return answer;
}