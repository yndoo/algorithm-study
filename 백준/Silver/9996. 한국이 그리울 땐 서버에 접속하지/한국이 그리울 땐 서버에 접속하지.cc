#include <string>
#include <vector>
#include <regex>
#include <iostream>

int main() 
{
    int N = -1;
    std::string inputpat = "", target = "";
    std::string regpattern = "^";
    std::cin >> N >> inputpat;
    for (int i = 0; i < inputpat.size(); ++i)
    {
        if (inputpat[i] == '*')
        {
            regpattern += ".*";
        }
        else
        {
            regpattern += inputpat[i];
        }
    }
    regpattern += "$";

    std::regex pat(regpattern);
    while (N--)
    {
        std::cin >> target;
        if (std::regex_match(target, pat))
        {
            std::cout << "DA" << std::endl;
        }
        else
        {
            std::cout << "NE" << std::endl;
        }
    }
    return 0;
}
