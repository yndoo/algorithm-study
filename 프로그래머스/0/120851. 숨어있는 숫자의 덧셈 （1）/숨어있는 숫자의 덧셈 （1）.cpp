#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string my_string) {
    int answer = 0;
    for(char ch : my_string)
    {
        int ctoi = ch - '0';
        if(ctoi >= 0 && ctoi <= 9)
        {
            answer += ctoi;
        }
    }
    return answer;
}