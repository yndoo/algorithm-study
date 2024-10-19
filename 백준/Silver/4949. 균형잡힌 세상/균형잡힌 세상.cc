#include <iostream>
#include <string>
#include <stack>
#include <set>
int main()
{
	while (true)
	{
		std::string input;
		getline(std::cin, input);
		if (input == ".") break;

		std::stack<char> s;
		bool check = true;
		for (char ch : input)
		{
			if (ch == '(' || ch == '[')
			{
				s.push(ch);
			}
			else if (ch == ')' || ch == ']')
			{
				if (s.empty())
				{
					check = false;
					break;
				}
				if (ch == ')' && s.top() == '(')
				{
					s.pop();
					continue;
				}
				else if (ch == ']' && s.top() == '[')
				{
					s.pop();
					continue;
				}
				check = false;
				break;
			}
		}
		if (check == false || !s.empty())
		{
			std::cout << "no" << std::endl;
		}
		else
		{
			std::cout << "yes" << std::endl;
		}
	}

	return 0;
}