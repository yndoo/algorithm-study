#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int ressize = number.size() - k;
    for(char ch : number)
    {
        while(!answer.empty() && k > 0 && ch > answer.back())
        {
            --k;
            answer.pop_back();
        }
        answer.push_back(ch);
    }
    if(answer.size() > ressize) answer.resize(ressize);
    return answer;
}