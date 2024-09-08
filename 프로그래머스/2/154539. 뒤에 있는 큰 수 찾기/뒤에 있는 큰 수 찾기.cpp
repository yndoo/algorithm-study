#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer = vector<int>(numbers.size(), -1);
    stack<int> Stack;
    for(int i = numbers.size() - 2; i >= 0; --i)
    {
        Stack.push(numbers[i + 1]);
        bool flag = false;
        while(!Stack.empty())
        {
            if(Stack.top() > numbers[i])
            {
                answer[i] = Stack.top();
                Stack.pop();
                flag = true;
                break;
            }
            Stack.pop();
        }
        if(true == flag)
        {
            Stack.push(answer[i]);
        }
        Stack.push(numbers[i]);
    }
    
    return answer;
}