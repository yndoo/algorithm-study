#include <iostream>
#include <map>
#include <string>
int main()
{
	int cnt = -1;
	char answer = ' ';
	bool sameFlag = false;
	std::string target;
	std::map<char, int> countMap;
	std::cin >> target;
	for (char ch : target)
	{
		if (ch >= 'a' && ch <= 'z')
		{
			ch += 'A' - 'a';
		}
		countMap[ch]++;
		if (cnt < countMap[ch])
		{
			cnt = countMap[ch];
			answer = ch;
			sameFlag = false;
		}
		else if (cnt == countMap[ch])
		{
			sameFlag = true;
		}
	}
	if (sameFlag) answer = '?';
	std::cout << answer;
	return 0;
}