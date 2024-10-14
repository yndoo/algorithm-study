#include <string>
#include <vector>
#include <cmath>

using namespace std;

int CalcDigits(int b) // 자릿수 계산
{
    int count = 1;
    while(b / 10)
    {
        b /= 10;
        ++count;
    }
    return count;
}

int solution(int a, int b) {
    int Value1 = a * b * 2;
    int Value2 = -1;
    int bd = CalcDigits(b);
    while(bd)
    {
        --bd;
        a *= 10;
    }
    Value2 = a + b;
    
    return max(Value1, Value2);
}