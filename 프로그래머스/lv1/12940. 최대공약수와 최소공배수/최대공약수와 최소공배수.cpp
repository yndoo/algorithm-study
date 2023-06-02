#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int tmp = 0;
    if (m<n) {
        tmp = n;
        n = m;
        m = tmp;
    }
    for (int i=n; i>0; i--){
        if (n%i==0 && m%i==0) {answer.push_back(i); break;}
    }
    answer.push_back(n*m/answer[0]);
    return answer;
}