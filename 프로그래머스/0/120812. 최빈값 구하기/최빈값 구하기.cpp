#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> array) {
    int answer = -1, tmp = -1;
    map<int, int> frequency;
    for(int num : array)
    {
        ++frequency[num];
        if(frequency[num] > tmp)
        {
            tmp = frequency[num];
            answer = num;
        }
        else if (frequency[num] == tmp)
        {
            answer = -1;
        }
    }
    return answer;
}