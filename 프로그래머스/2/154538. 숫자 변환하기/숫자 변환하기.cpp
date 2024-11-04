#include <string>
#include <vector>

using namespace std;
vector<int> makenum(3000001,0x7fffffff);
bool cannum[3000001];
int solution(int x, int y, int n) {
    cannum[x] = true;
    makenum[x] = 0;
    for(int i = x; i < 1000001; ++i)
    {
        if(cannum[i] == false) continue;
        makenum[i + n] = min(makenum[i + n], makenum[i] + 1);
        makenum[i*2] = min(makenum[i*2], makenum[i] + 1);
        makenum[i*3] = min(makenum[i*3], makenum[i] + 1);
        cannum[i + n] = true;
        cannum[i * 2] = true;
        cannum[i * 3] = true;
    }
    if(makenum[y] == 0x7fffffff) return -1;
    return makenum[y];
}