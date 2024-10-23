#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> maxsum = triangle;
    
    for(int i = 1; i < triangle.size(); ++i)
    {
        for(int j = 0; j < triangle[i].size(); ++j)
        {
            if(j == 0)
            {
                maxsum[i][j] = triangle[i][j] + maxsum[i-1][j];
            }
            else if (j == triangle[i].size() - 1)
            {
                maxsum[i][j] = triangle[i][j] + maxsum[i-1][j-1];
            }
            else
            {
                maxsum[i][j] = triangle[i][j] + max(maxsum[i-1][j-1], maxsum[i-1][j]);
            }
            
        }
    }
    return *max_element(maxsum[maxsum.size() - 1].begin(), maxsum[maxsum.size() - 1].end());
}