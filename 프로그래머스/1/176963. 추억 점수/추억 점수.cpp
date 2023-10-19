#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> m;
    for(int i=0; i < name.size(); i++){
        m[name[i]] = yearning[i];
    }
    for(auto v:photo){
        int tmp = 0;
        for(int i=0; i<v.size(); i++){
            if(m.find(v[i]) != m.end()) tmp += m[v[i]];
        }
        answer.push_back(tmp);
    }
    return answer;
}