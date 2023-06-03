#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(s.length(),-1);
    
    for (int i = 1; i<s.length(); i++){
        for (int j=i-1; j>=0; j--){
            if(s[i]==s[j]){
                answer[i]=i-j;
                break;
            }
        }
    }
    return answer;
}