#include <iostream>
#include <cmath>
using namespace std;

int solution(int n) {
    int calc = sqrt(n); // int로 받아서 내림 계산
    //cout<<sqrt(n)<<endl;
    for(int i = calc; i * i <= n; ++i)
    {
        if(i * i == n) return 1;
    }
    return 2;
}