#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    long long tmp=0;
    if(a>b) {
        tmp = a;
        a = b;
        b = tmp;
    }
    for (int i=a; i<b+1; i++){
        answer+=i;
    }
    return answer;
}