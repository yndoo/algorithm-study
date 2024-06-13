#include <iostream>
#include <list>
int main()
{
	int N = 0;
	std::list<char> lst;
	char command = ' ';
	std::string word;
	std::cin >> word;
	for (int i = 0; i < word.size(); i++)
	{
		lst.push_back(word[i]);
	}

	std::list<char>::iterator cursor = lst.end();

	std::cin >> N;
	while (N) 
	{
		--N;
		std::cin >> command;
		switch (command)
		{
		case 'L':
			if(cursor != lst.begin()) 
			{
				--cursor;
			}
			break;
		case 'D':
			if (cursor != lst.end())
			{
				++cursor;
			}
			break;
		case 'B':
			if (cursor != lst.begin())
			{
				std::list<char>::iterator tmp = --cursor;
				++cursor;
				lst.erase(tmp);
			}
			break;
		case 'P':
			char ch;
			std::cin >> ch;
			lst.insert(cursor, ch);
			break;
		default:
			break;
		}
	}

	for (auto c : lst)
	{
		std::cout << c;
	}

	return 0;
}