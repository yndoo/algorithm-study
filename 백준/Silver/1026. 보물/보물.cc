#include <iostream>
#include<algorithm>
#include <vector>

using namespace std;

int main() {
    int N, num, S=0;
    vector<int> A;
    vector<int> B;

    cin>>N;
    for (int i=0; i<N; i++){
        cin>>num;
        A.push_back(num);
    }
    for (int i=0; i<N; i++){
        cin>>num;
        B.push_back(num);
    }

    sort(A.begin(),A.end());
    sort(B.begin(), B.end(), greater<int>());
    
    for (int i=0; i<N; i++){
        S += A[i]*B[i];
    }
    cout<<S;
    return 0;
}