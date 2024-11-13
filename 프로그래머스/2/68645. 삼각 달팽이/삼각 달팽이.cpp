#include <string>
#include <vector>
#include<iostream>
using namespace std;
vector<vector<int>> triangle;

void func(int startvalue, int x, int y, int len)
{
    if(len <= 0) return;
    if(len == 1)
    {
        triangle[x][y] = startvalue;
        return;
    }
    int val = startvalue;
    for(int i = 0; i < len; ++i)
    {
        triangle[x++][y] = val++;
    }
    --x;
    --val;
    for(int i = 0; i < len; ++i)
    {
        triangle[x][y + i] = val++;
    }
    --x;
    for(int i = 1; i < len - 1; ++i)
    {
        triangle[x][x - y] = val++;
        --x;
    }
    func(val, x + 2, y + 1, len - 3);
}


vector<int> solution(int n) {
    int sum = n * (n + 1) / 2;
    vector<int> answer;
    //answer.resize(sum);
    triangle.resize(n);
    for (int i = 0; i < n; ++i) 
    {
        triangle[i].resize(i + 1);
    }
    func(1, 0, 0, n);
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j <= i; ++j) 
        {
            answer.push_back(triangle[i][j]);
            //cout<<triangle[i][j]<<" ";
        }
        //cout<<endl;
    }
    return answer;
}