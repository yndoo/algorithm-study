#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(int num : numbers)
    {
        answer.push_back(num * 2);
    }
    return answer;
}