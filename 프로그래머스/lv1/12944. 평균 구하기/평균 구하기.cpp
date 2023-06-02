#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double n = arr.size();
    int sum = 0;
    for (int i=0; i<n; i++){
        sum += arr[i];
    }
    return sum/n;
}