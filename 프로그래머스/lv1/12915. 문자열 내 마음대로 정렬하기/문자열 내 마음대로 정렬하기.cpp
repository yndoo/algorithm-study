#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
bool mycompare(string a, string b){
    if(a[N] == b[N]) return a < b;
    return a[N] < b[N];
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    N = n;
    sort(strings.begin(), strings.end(), mycompare);
    
    return strings;
}