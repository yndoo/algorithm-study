#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> v;
    v.resize(n + 1);
    v[1] = 1;
    v[2] = 2;
    v[3] = 3;
    for(int i = 4; i <= n; ++i)
    {
        v[i] = (v[i - 1] + v[i - 2]) % 1000000007;
    }
    return v[n];
}