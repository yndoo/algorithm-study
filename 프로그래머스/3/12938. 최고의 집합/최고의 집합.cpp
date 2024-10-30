#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(n > s) return vector<int>(1, -1);
    
    int q = s / n, r = s % n;
    for(int i = 0; i < n - r; ++i)
    {
        answer. push_back(q);
    }
    for(int i = 0; i < r; ++i)
    {
        answer. push_back(q + 1);
    }
    return answer;
}