#include <string>
#include <vector>
#include<iostream>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    for(int i=1; i<food.size(); i++){
        for(int j=0; j<food[i]/2; j++) { //한 쪽 선수 음식만 배치, 각 음식 2로 나눈 몫만큼만 담기
            answer += to_string(i);
        }
    }
    string reverse_answer = "0"; //반대편 선수 음식 넣을 변수, 물 미리 넣어두기.
    for(int i=answer.size()-1; i>=0; i--){
        reverse_answer = reverse_answer + answer[i];
    }
    answer += reverse_answer; 
    return answer;
}