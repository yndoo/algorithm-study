#include <string>
#include <vector>

using namespace std;

vector<int> answer(2, 0);

void Quadtree(int sx, int sy, int ex, int ey, const vector<vector<int>>& arr)
{
    int IsSame = arr[sx][sy];
    for(int i = sx; i < ex; ++i)
    {
        for(int j = sy; j < ey; ++j)
        {
            if(arr[i][j] != IsSame) // 모든 수가 같은 값이 아님
            {
                // 영역 쪼개기
                int mx = (sx + ex) / 2;
                int my = (sy + ey) / 2;
                Quadtree(sx, sy, mx, my, arr);
                Quadtree(sx, my, mx, ey, arr);
                Quadtree(mx, sy, ex, my, arr);
                Quadtree(mx, my, ex, ey, arr);
                return;
            }
        }
    }
    // 모두 같은 값임 => 압축
    answer[IsSame]++;
}

vector<int> solution(vector<vector<int>> arr) {
    Quadtree(0, 0, arr.size(), arr.size(), arr);
    return answer;
}