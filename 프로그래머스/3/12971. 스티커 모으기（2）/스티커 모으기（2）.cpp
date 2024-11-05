#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0, N = sticker.size();
    if(N == 1) return sticker[0];
    
    vector<int> arr1(N, 0);
    arr1[0] = sticker[0];
    arr1[1] = sticker[0];
    for(int i = 2; i < N - 1; ++i)
    {
        arr1[i] = max(arr1[i - 2] + sticker[i], arr1[i - 1]);
    }
    
    vector<int> arr2(N, 0);
    arr2[1] = sticker[1];
    for(int i = 2; i < N; ++i)
    {
        arr2[i] = max(arr2[i - 2] + sticker[i], arr2[i - 1]);
    }
    
    answer = max(arr1[N-2], arr2[N-1]);
    return answer;
}