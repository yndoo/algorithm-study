#include<bits/stdc++.h>

using namespace std;

string split(string s, string sep){
    int pos = 0;
    while(pos<s.size()){
        int nxt_pos = s.find(sep, pos); //sep을 pos번째부터 찾기
        if(nxt_pos == -1){ nxt_pos = s.size();}
        if(nxt_pos - pos > 0) {
            string word = s.substr(pos, nxt_pos - pos);
            for(int i=0; i<word.size(); i++){
                if(i%2==0 && word[i]>='a'&& word[i]<='z'){ //짝수번째 글자가 소문자일경우
                    word[i] = word[i]-32;
                }
                if(i%2==1 && word[i]>='A'&& word[i]<='Z'){ //홀수번째 글자가 대문자일경우
                    word[i] = word[i]+32;
                }
            }
            s.replace(pos, nxt_pos - pos, word); //s에서 pos번째부터 nxt_pos-pos개의 문자를 word로 교체
        }
        pos = nxt_pos + sep.size();
    }
    return s;
}

string solution(string s) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string answer = split(s," ");

    
    return answer;
}