#include <iostream>
#include <algorithm>
#include <vector>
int main()
{
	int N, M, L, K;
	std::cin >> N >> M >> L >> K;
    std::vector<std::pair<int, int>> stars(K);
    for (int i = 0; i < K; ++i) 
    {
        std::cin >> stars[i].first >> stars[i].second;
    }

    int res = 0;
    // 각 별똥별의 x나 y값을 사각형의 왼쪽 아래 모서리로 설정
    for (int i = 0; i < K; ++i) 
    {
        for (int j = 0; j < K; ++j) 
        {
            int x_start = stars[i].first;
            int y_start = stars[j].second;
            int curcnt = 0;

            // 사각형 범위 내의 별똥별을 카운트
            for (int k = 0; k < K; ++k) 
            {
                if (x_start <= stars[k].first && stars[k].first <= x_start + L &&
                    y_start <= stars[k].second && stars[k].second <= y_start + L) 
                {
                    ++curcnt;
                }
            }

            res = std::max(res, curcnt);
        }
    }

	std::cout << K - res;
	return 0;
}