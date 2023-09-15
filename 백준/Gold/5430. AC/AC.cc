#include <bits/stdc++.h>
#include<string>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, n;
    cin>>T;
    while(T>0){
        string p, arr;
        bool errorflag = false;
        int n, r_cnt=0, d_cnt=0;
        deque<int> dq;
        cin>>p;
        cin>>n;
        cin>>arr;

        //배열 수 분리
        for(int i=0; i<arr.size(); i++){
            if (isdigit(arr[i])){
                int val = 0;
                while(i!=arr.size() && isdigit(arr[i])){
                    val = val*10 + (arr[i]-'0');
                    i++;
                }
                dq.push_back(val);
            }
        }
        
        //명령어 분석 
        for(int j=0; j<p.size(); j++){
            if(p[j]=='R') r_cnt++;
            else if(p[j]=='D') { 
                if (r_cnt%2==0){ //R이 짝수개일땐 정방향
                    if(!dq.empty()) dq.pop_front();
                    else errorflag = true; continue;
                }else{
                    if(!dq.empty()) dq.pop_back();
                    else errorflag = true; continue;
                }
            }
        }
        //출력
        if(!errorflag){
            cout<<"[";
            if(r_cnt%2==0){
                for(auto l=dq.begin(); l!=dq.end(); l++){
                    cout<< *l;
                    if(l!=dq.end()-1) cout<<",";
                }
            }else{
                for(auto l=dq.rbegin(); l!=dq.rend(); l++){
                    cout<< *l;
                    if(l!=dq.rend()-1) cout<<",";
                }
            }
            cout<<"]"<<'\n';
        } else{
            cout<<"error"<<'\n';
        }
        T--;
    } 

    return 0;
}