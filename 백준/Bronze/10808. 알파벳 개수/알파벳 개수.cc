#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::vector<int> alpha;
	std::string word = "";

	std::cin >> word;

	alpha.resize(26);
	for (int i = 0; i < word.size(); i++)
	{
		char c = word[i];
		++alpha[c - 'a'];
	}

	for (int i = 0; i < 26; i++)
	{
		std::cout << alpha[i] << " ";
	}
	return 0;
}