#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct MyCompare{
  bool operator()(vector<int> a, vector<int> b)
  {
      return a[1] < b [1];
  }
};

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int camera = -30001;
    sort(routes.begin(), routes.end(), MyCompare());
    /*for(const vector<int>& route : routes)
    {
        cout<<route[0]<<" "<<route[1]<<endl;
    }*/
    for(const vector<int>& route : routes)
    {
        if(camera < route[0])
        {
            camera = route[1];
            ++answer;
        }
    }
    return answer;
}