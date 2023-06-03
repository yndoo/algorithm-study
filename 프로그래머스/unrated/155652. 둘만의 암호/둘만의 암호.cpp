#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    for (int i=0; i<s.length(); i++){ //s 하나씩 +index할것임
        int x=1;
        while (x<=index){
            s[i] = (s[i] + 1 - 97)%26 + 97;
            if (skip.find(s[i])==string::npos){ // s[i]가 skip에 없으면 
                x++;
            }
        }
    }
    return s;
}