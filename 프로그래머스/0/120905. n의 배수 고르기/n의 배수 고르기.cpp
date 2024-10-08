#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(int n, vector<int> numlist) {
    vector<int> answer;
    map<int, bool> multiNums;
    for(int i = 1; i * n < 100000; ++i)
    {
        multiNums[n * i] = true;
    }
    for(int num : numlist)
    {
        if(multiNums.find(num) != multiNums.end())
        {
            answer.push_back(num);
        }
    }
    return answer;
}