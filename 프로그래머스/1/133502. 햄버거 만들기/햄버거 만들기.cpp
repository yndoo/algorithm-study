#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> box;
    for(int i : ingredient)
    {
        box.push_back(i);
        if(box.size() >= 4)
        {
            int boxlast = box.size() - 1;
            if(box[boxlast - 3] == 1 && box[boxlast - 2] == 2 && box[boxlast - 1] == 3 && box[boxlast] == 1)
            {
                box.pop_back();
                box.pop_back();
                box.pop_back();
                box.pop_back();
                ++answer;
            }
        }
    }
    return answer;
}