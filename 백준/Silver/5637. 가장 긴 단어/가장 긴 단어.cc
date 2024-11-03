#include <iostream>
#include <regex>
#include <string>
#include <sstream>
	
int main()
{
	std::string Input, word;
	
	std::regex pattern("[a-zA-Z-]+");
	int mymax = 0;
	std::string answer = "";
	while (std::getline(std::cin, Input))
	{
		std::stringstream SS(Input);
		while (SS >> word)
		{
			word = std::regex_replace(word, std::regex("[^a-zA-Z-]"), "");
			if (std::regex_match(word, pattern))
			{
				if (mymax < word.size())
				{
					mymax = word.size();
					answer = word;
				}
			}
			if (word == "E-N-D")
			{
				for (int i = 0; i < mymax; ++i)
				{
					answer[i] = tolower(answer[i]);
				}
				std::cout << answer;
				return 0;
			}
		}
	}

	return 0;
}