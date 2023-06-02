#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int xx=x;
    int sum = 0;
    while (x) {
        sum += x%10;
        x =x/10;
    }
    return !bool(xx%sum);
}