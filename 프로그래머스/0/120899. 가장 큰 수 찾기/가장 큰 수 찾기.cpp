#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array) {
    int maxnum = -1, maxindex = -1;
    for(int i = 0; i < array.size(); ++i)
    {
        if(maxnum < array[i])
        {
            maxnum = array[i];
            maxindex = i;
        }
    }
    return {maxnum, maxindex};
}