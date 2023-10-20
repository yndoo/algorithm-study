#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> HallOfFame;
    
    for(int i=0; i<score.size(); i++){
        if(HallOfFame.size() < k) HallOfFame.push_back(score[i]);
        else if (HallOfFame[k-1] < score[i]) {
            HallOfFame.pop_back();
            HallOfFame.push_back(score[i]);
        }
        
        sort(HallOfFame.rbegin(), HallOfFame.rend());
        answer.push_back(HallOfFame[HallOfFame.size()-1]);
    }
    
    
    return answer;
}