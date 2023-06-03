#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<int> num(10,0);
    vector<int> res;
    for (int i=0; i<X.length(); i++){
        num[X[i]-48]+=1;
    }
    for (int j=0; j<Y.length(); j++){
        if (num[Y[j]-48]!=0){
            num[Y[j]-48]-=1;
            res.push_back(Y[j]-48);
        }
    }
    if (res.empty()) {return "-1";}
    sort(res.rbegin(),res.rend());
    if (res[0]==0){return "0";}
    
    for (int i=0; i<res.size(); i++){
        answer+=to_string(res[i]);
    }
    return answer;
}