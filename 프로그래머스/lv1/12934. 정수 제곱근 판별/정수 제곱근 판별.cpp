#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(long long n) {
    long long answer = -1;
    if (sqrt(n)==int(sqrt(n)))
        answer = pow((sqrt(n)+1),2);
    return answer;
}