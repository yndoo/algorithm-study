#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int even = 0;
    int odd = 0;
    for(int i = num_list.size() - 1; i >= 0; --i)
    {
        if(num_list[i] % 2 == 0)
        {
            answer += num_list[i] * pow(10, even++);
        }
        else
        {
            answer += num_list[i] * pow(10, odd++);
        }
    }

    return answer;
}

//#include <string>
//#include <vector>
//#include <cmath>
//using namespace std;
//
//int solution(vector<int> num_list) {
//    int answer = 0;
//    vector<int> even;
//    vector<int> odd;
//    for (int num : num_list)
//    {
//        if (num % 2 == 0) even.push_back(num);
//        else odd.push_back(num);
//    }
//    for (int i = 0; i < even.size(); ++i)
//    {
//        answer += even[i] * pow(10, even.size() - i - 1);
//    }
//    for (int i = 0; i < odd.size(); ++i)
//    {
//        answer += odd[i] * pow(10, odd.size() - i - 1);
//    }
//    return answer;
//}
