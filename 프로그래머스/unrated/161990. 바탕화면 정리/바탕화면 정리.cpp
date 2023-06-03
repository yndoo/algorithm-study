#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    vector<int> row;
    vector<int> col;
    
    for (int i=0; i<wallpaper.size(); i++){
        for (int j=0; j<wallpaper[i].length();j++){ //각 행 떼어서 보기
            if(wallpaper[i][j]=='#'){
                row.push_back(i);
                col.push_back(j);
            }
        }
    }
    sort(row.begin(),row.end());
    sort(col.begin(),col.end());
    answer.push_back(row[0]);
    answer.push_back(col[0]);
    answer.push_back(row[row.size()-1]+1);
    answer.push_back(col[col.size()-1]+1);
    
    return answer;
}