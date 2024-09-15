#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0; 
    // 1번 기사 무기의 철 무게
    ++answer;
    for(int num = 2; num<=number; ++num)
    {
        int count = 2; // 1과 자신은 항상 약수
        for(int i = 2; i < static_cast<int>(sqrt(num)) + 1; ++i)
        {
            if(num % i == 0)
            {
                if(i * i == num) ++count;
                else count += 2;
            }
        }
        if(count > limit)
        {
            count = power;
        }
        answer += count;
    }
    
    return answer;
}