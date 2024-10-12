#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    int index = num_list.size() - 1;
    int num = num_list[index] > num_list[index - 1] ? num_list[index] - num_list[index - 1] : num_list[index] * 2;
    num_list.push_back(num);
    return num_list;
}