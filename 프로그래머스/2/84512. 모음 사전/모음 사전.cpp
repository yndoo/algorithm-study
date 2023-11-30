#include <iostream>
#include <string>
#include <vector>

using namespace std;

char vowels[5] = {'A', 'E', 'I', 'O', 'U'};
int visited[5]; //각 자릿수의 알파벳 표시
int cnt = 0;
int answer = 0;

void dfs(string target, string word){
    if(target == word){
        //cout << "in dfs : " << target <<"\n";
        //cout << cnt;
        answer = cnt;
    }
    for(int i = 0; i<5; i++){
        if(visited[target.size()] < i){
            cnt++;
            visited[target.size()] = i;
            dfs(target+vowels[i], word);
            visited[target.size()] = -1;
        }
    }
}

int solution(string word) {
    
    fill(visited, visited + 5, -1);
    dfs("", word);
    return answer;
}