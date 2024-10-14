#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    string Value1 = to_string(a) + to_string(b);
    string Value2 = to_string(b) + to_string(a);
    return max(stoi(Value1), stoi(Value2));
}