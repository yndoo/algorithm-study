#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> nums;
    while (n!=0){
        nums.push_back(n%10);
        n=n/10;
    }
    sort(nums.begin(),nums.end());
    int i = 0;
    while (!nums.empty()){
        answer += nums[0] * pow(10,i);
        i++;
        nums.erase(nums.begin());
    }
    return answer;
}