#include <string>
#include <vector>
#include <bitset>
#include <iostream>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(long long num : numbers)
    {
        if(num % 2 == 1)
        {
            bitset<64> bn(num);
            for(int i = 0 ; i < 64; ++i)
            {
                if(bn.test(i) == 0)
                {
                    bn.set(i);
                    bn.reset(i - 1);
                    answer.push_back(bn.to_ullong());
                    break;
                }
            }
        }
        else
        {
            answer.push_back(num + 1);
        }
    }
    return answer;
}