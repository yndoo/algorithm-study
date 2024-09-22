#include <string>
#include <vector>

using namespace std;

int solution(int price) {
    float sale = 0;
    if(price >= 500000) sale = 0.8;
    else if(price >= 300000) sale = 0.9;
    else if(price >= 100000) sale = 0.95;
    else sale = 1.f;
    return static_cast<int>(price * sale);
}