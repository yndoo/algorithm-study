#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> cake1;
    map<int, int> cake2;
    
    // 토핑 전체 map으로 옮겨두기
    for(int i = 0; i<topping.size(); ++i)
    {
        ++cake1[topping[i]];
    }
    // 토핑 하나씩 옮기며 개수 보기
    for(int i = 0; i < topping.size(); ++i)
    {
        ++cake2[topping[i]];
        --cake1[topping[i]];
        if(cake1[topping[i]] == 0)
        {
            cake1.erase(topping[i]);
        }
        
        if(cake1.size() == cake2.size())
        {
            ++answer;
        }
    }
    
    return answer;
}