#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v(n+1,1); //소수인지 나타내는 플래그가 될 벡터, 0~n
    v[0] = 0; // 0과 1은 소수가 아님
    v[1] = 0;
    for (int i=2; i<=n; i++){
        if(v[i]==0){continue;} //이미 판단 된 건 넘어감
        //i 제외, i의 배수를 모두 제거
        int x = 2;
        while(i*x<=n){
            v[i * x] = 0;
            x++;
        }
    }
    
    answer = count(v.begin(), v.end(), 1);
    return answer;
}