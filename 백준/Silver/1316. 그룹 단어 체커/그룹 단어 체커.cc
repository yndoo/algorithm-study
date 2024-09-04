#include <iostream>
#include <map>
#include <string_view>

bool Check(std::string_view _str)
{
    std::map<char, int> cntmap;
    char before = _str[0];
    for (char c : _str)
    {
        if (before != c && cntmap[c] != 0)
        {
            return false;
        }
        before = c;
        ++cntmap[c];
    }

    return true;
}

int main()
{
    int N = -1, answer = 0;

    std::cin >> N;
    while (N > 0)
    {
        std::string target;
        std::cin >> target;
        answer += Check(target);
        --N;
    }

    std::cout << answer;

    return 0;
}