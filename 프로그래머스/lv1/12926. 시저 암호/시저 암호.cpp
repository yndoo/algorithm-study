#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    //대문자 65~90, 소문자 97~122
    string answer = "";
    int tmp=0;
    for(auto c:s){
        if(c>=65 && c<=90 && c+n>90){ tmp = 65 + (c+n-90) - 1;} //한 바퀴 도는 대문자
        else if(c>=97 && c<=122 && c+n>122) {tmp = 97 + (c+n-122) - 1;} //한 바퀴 도는 소문자
        else if (c==' ') { //공백
            answer+=c;
            continue;
        }else{ //한 바퀴 안 도는 대소문자 공통
            tmp = c+n;
        }
        answer+=tmp;
    }
    return answer;
}