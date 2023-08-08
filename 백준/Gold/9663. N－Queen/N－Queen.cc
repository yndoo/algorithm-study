#include <iostream>
#define MAX 15
using namespace std;

int col[MAX];
int N, answer=0;


bool isokay(int i){
    int k=0;
    while (k<i){
        if (col[i]==col[k] || abs(col[i]-col[k])==i-k){
            return false;
        }
        k++;
    }
    return true;
}

void finding(int i){
    if (i==N){
        answer ++;
    } else {
        for (int j=0; j<N; j++) {
            col[i] = j;
            if (isokay(i))
                finding(i+1);
        }
    }
}

int main() {
    cin >> N;
    finding(0);
    cout<<answer;
    
}