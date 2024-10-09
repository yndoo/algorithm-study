#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    int wMax = max(wallet[0], wallet[1]);
    int wMin = min(wallet[0], wallet[1]);
    while(true)
    {
        int bMin = min(bill[0], bill[1]);
        int bMax = max(bill[0], bill[1]);
        if(bMin <= wMin && bMax <= wMax) break;
        if(bill[0] > bill[1])
        {
            ++answer;
            bill[0] /= 2;
        }
        else if (bill[0] < bill[1])
        {
            ++answer;
            bill[1] /= 2;
        }
    }
    return answer;
}