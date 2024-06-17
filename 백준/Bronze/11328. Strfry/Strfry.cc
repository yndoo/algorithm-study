#include <iostream>
#include <map>
int main()
{
	int N;
	std::string str1, str2;
	std::cin >> N;
	while (N)
	{
		std::map<char, int> str1map;
		std::map<char, int> str2map;
		std::cin >> str1 >> str2;

		for (int i = 0; i < str1.size(); i++)
		{
			++str1map[str1[i]];
		}
		for (int i = 0; i < str2.size(); i++)
		{
			++str2map[str2[i]];
		}

		bool IsPossible = true;
		for (int i = 0; i < str2.size(); i++)
		{
			if (str1map[str2[i]] != str2map[str2[i]])
			{
				IsPossible = false;
			}
		}
		if(IsPossible)
		{
			std::cout << "Possible\n";
		}
		else 
		{
			std::cout << "Impossible\n";
		}
		--N;
	}
	return 0;
}